/********************************** (C) COPYRIGHT *******************************
 * File Name          : broadcaster.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : 广播应用程序，初始化广播连接参数，然后处于广播态一直广播

 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CONFIG.h"
#include "devinfoservice.h"
#include "broadcaster.h"

/*********************************************************************
 * LOCAL FUNCTIONS
 */
static void Broadcaster_ProcessTMOSMsg(tmos_event_hdr_t* pMsg);
static void Broadcaster_StateNotificationCB(gapRole_States_t newState);
extern bStatus_t GAP_UpdateAdvertisingData(uint8_t taskID, uint8_t adType, uint16_t dataLen, uint8_t* pAdvertData);

/*********************************************************************
 * PROFILE CALLBACKS
 */

// GAP Role Callbacks
static gapRolesBroadcasterCBs_t Broadcaster_BroadcasterCBs = {
    Broadcaster_StateNotificationCB, // Profile State Change Callbacks
    NULL
};

/*********************************************************************
 * PUBLIC FUNCTIONS
 */

// 电池电压采样
__HIGH_CODE
uint16_t sample_battery_voltage()
{
    // VINA 实际电压值 1050±15mV
    const int vref = 1050;
    ADC_InterBATSampInit();
    static uint8_t calib_count = 0;
    calib_count++;
    if (calib_count == 1) {
        RoughCalib_Value = ADC_DataCalib_Rough();
    }
    calib_count %= BAT_MAX_COUNTS;
    ADC_ChannelCfg(CH_INTE_VBAT);
    return (ADC_ExcutSingleConver() + RoughCalib_Value) * vref / 512 - 3 * vref;
}

__HIGH_CODE
void set_battery()
{
    uint16_t battery_level = sample_battery_voltage();
    if(battery_level > 3000){
        status_flag = STATUS_FLAG_FULL_BATTERY; // 满电量
    } else if(battery_level > 2800){
        status_flag = STATUS_FLAG_MEDIUM_BATTERY; // 中等电量
    } else if(battery_level > 2500){
        status_flag = STATUS_FLAG_LOW_BATTERY;    // 低电量
    } else {
        status_flag = STATUS_FLAG_CRITICALLY_LOW_BATTERY; // 严重低电量
    }
}


__HIGH_CODE
void update_key_event(uint8_t* event_key, uint8_t* advert_data_pos) {
    switch (*event_key) {
        case 1:
        case 4:
            *advert_data_pos = *event_key;
            *event_key = 0;
            break;
        default:
            *advert_data_pos = 0;
            break;
    }
}

__HIGH_CODE
void update_advert_data() {
    // 更新广播包中的电量数据
    set_battery();
    advertData[10] = status_flag;
    // 更新按键状态
    update_key_event(&Event_key1, &advertData[12]);
    update_key_event(&Event_key2, &advertData[14]);
    update_key_event(&Event_key3, &advertData[16]);
    update_key_event(&Event_key4, &advertData[18]);
}


/*********************************************************************
 * @fn      Broadcaster_Init
 *
 * @brief   Initialization function for the Broadcaster App
 *          Task. This is called during initialization and should contain
 *          any application specific initialization (ie. hardware
 *          initialization/setup, table initialization, power up
 *          notificaiton ... ).
 *
 * @param   task_id - the ID assigned by TMOS.  This ID should be
 *                    used to send messages and set timers.
 *
 * @return  none
 */
void Broadcaster_Init()
{
    Broadcaster_TaskID = TMOS_ProcessEventRegister(Broadcaster_ProcessEvent);

    // Setup the GAP Broadcaster Role Profile
    {
        // Device starts advertising upon initialization，默认使用所有信道
        uint8_t initial_advertising_enable = TRUE;
        uint8_t initial_adv_event_type = GAP_ADTYPE_ADV_NONCONN_IND; // 不可连接的非定向广播
        uint8_t initial_adv_filter_type = GAP_FILTER_POLICY_ALL; //允许来自任何设备的扫描和连接请求
        
        // Set the GAP Role Parameters
        GAPRole_SetParameter(GAPROLE_ADV_FILTER_POLICY, sizeof(uint8_t), &initial_adv_filter_type);
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &initial_advertising_enable);
        GAPRole_SetParameter(GAPROLE_ADV_EVENT_TYPE, sizeof(uint8_t), &initial_adv_event_type);
        GAPRole_SetParameter(GAPROLE_ADVERT_DATA, sizeof(advertData), advertData);
    }

    // Set advertising interval
    {
        // 广播时间
        uint16_t advInt = DEFAULT_ADVERTISING_INTERVAL;
        GAP_SetParamValue(TGAP_DISC_ADV_INT_MIN, advInt);
        GAP_SetParamValue(TGAP_DISC_ADV_INT_MAX, advInt);
    }

    update_advert_data();

    //开机后初始化蓝牙广播
    tmos_set_event(Broadcaster_TaskID, SBP_START_DEVICE_EVT); 

    // 设置定时读取电压并更新广播
    tmos_start_task(Broadcaster_TaskID, SBP_UPDATE_ADV_EVT, 3200);//开机后2s第一次执行初始化广播数据任务
}


__HIGH_CODE
void handle_key_event(uint32_t pin, uint8_t* count, uint16_t event, uint8_t* event_val) {
    DelayMs(20);
    if (GPIOB_ReadPortPin(pin) == 0) {
        (*count)++;
        tmos_start_task(Broadcaster_TaskID, event, 160);
    } else {
        if (*count > 5) *event_val = 4;
        else *event_val = 1;
        *count = 0;
        GPIOB_ITModeCfg(pin, GPIO_ITMode_FallEdge);
        tmos_set_event(Broadcaster_TaskID, SBP_UPDATE_ADV_EVT);
    }
}

/*********************************************************************
 * @fn      Broadcaster_ProcessEvent
 *
 * @brief   Broadcaster Application Task event processor. This
 *          function is called to process all events for the task. Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id  - The TMOS assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  events not processed
 */
uint16_t Broadcaster_ProcessEvent(uint8_t task_id, uint16_t events)
{
    if (events & SYS_EVENT_MSG) {
        uint8_t* pMsg;

        if ((pMsg = tmos_msg_receive(Broadcaster_TaskID)) != NULL) {
            Broadcaster_ProcessTMOSMsg((tmos_event_hdr_t*)pMsg);

            // Release the TMOS message
            tmos_msg_deallocate(pMsg);
        }

        // return unprocessed events
        return (events ^ SYS_EVENT_MSG);
    }

    //蓝牙初始化
    if (events & SBP_START_DEVICE_EVT) {
        // Start the Device
        GAPRole_BroadcasterStartDevice(&Broadcaster_BroadcasterCBs);

        return (events ^ SBP_START_DEVICE_EVT);
    }

    //广播更新
    if (events & SBP_UPDATE_ADV_EVT) {
        //如果当前广播关闭，则开启，并在开启中更新数据，否则只更新数据
        if (adv_flag == 0)
        {
            adv_flag = 1;
            tmos_start_task(Broadcaster_TaskID, SBP_OPEN_ADV_EVT, 16);
        }
        else
        {
          // 数据采集并更新广播
          update_advert_data();
          GAP_UpdateAdvertisingData(0, TRUE, sizeof(advertData), advertData);

        }

        return (events ^ SBP_UPDATE_ADV_EVT);
    }


    //关闭广播数据，并启动60s一次的定时广播
    if(events & SBP_CLOSE_ADV_EVT)
    {
        uint8_t initial_advertising_enable = 0;
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &initial_advertising_enable);

        tmos_start_task(Broadcaster_TaskID, SBP_UPDATE_ADV_EVT, 1600*60);

        adv_flag = 0;
        return (events ^ SBP_CLOSE_ADV_EVT);
    }

    //开启广播
    if(events & SBP_OPEN_ADV_EVT)
    {
        tmos_start_task(Broadcaster_TaskID, SBP_CLOSE_ADV_EVT, 1600*10);

        uint8_t initial_advertising_enable = 1;
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &initial_advertising_enable);
        tmos_start_task(Broadcaster_TaskID, SBP_UPDATE_ADV_EVT, 16);

        return (events ^ SBP_OPEN_ADV_EVT);
    }

    //按键服务程序
    if (events & SBP_GPIO_IQR_KEY_1_EVT) {
      handle_key_event(GPIO_Pin_12, &Count_key1, SBP_GPIO_IQR_KEY_1_EVT, &Event_key1);
        return (events ^ SBP_GPIO_IQR_KEY_1_EVT);
    }

    if (events & SBP_GPIO_IQR_KEY_2_EVT) {
      handle_key_event(GPIO_Pin_13, &Count_key2, SBP_GPIO_IQR_KEY_2_EVT, &Event_key2);
        return (events ^ SBP_GPIO_IQR_KEY_2_EVT);
    }

    if (events & SBP_GPIO_IQR_KEY_3_EVT) {
      handle_key_event(GPIO_Pin_14, &Count_key3, SBP_GPIO_IQR_KEY_3_EVT, &Event_key3);
        return (events ^ SBP_GPIO_IQR_KEY_3_EVT);
    }

    if (events & SBP_GPIO_IQR_KEY_4_EVT) {
      handle_key_event(GPIO_Pin_15, &Count_key4, SBP_GPIO_IQR_KEY_4_EVT, &Event_key4);
        return (events ^ SBP_GPIO_IQR_KEY_4_EVT);
    }


    return 0;
}

/*********************************************************************
 * @fn      Broadcaster_ProcessTMOSMsg
 *
 * @brief   Process an incoming task message.
 *
 * @param   pMsg - message to process
 *
 * @return  none
 */
static void Broadcaster_ProcessTMOSMsg(tmos_event_hdr_t* pMsg)
{
    switch (pMsg->event) {
    default:
        break;
    }
}

/*********************************************************************
 * @fn      Broadcaster_StateNotificationCB
 *
 * @brief   Notification from the profile of a state change.
 *
 * @param   newState - new state
 *
 * @return  none
 */
static void Broadcaster_StateNotificationCB(gapRole_States_t newState)
{
    switch (newState) {
    case GAPROLE_STARTED:
        PRINT("Initialized..\n");
        break;

    case GAPROLE_ADVERTISING:
        PRINT("Advertising..\n");
        break;

    case GAPROLE_WAITING:
        PRINT("Waiting for advertising..\n");
        break;

    case GAPROLE_ERROR:
        PRINT("Error..\n");
        break;

    default:
        break;
    }
}
