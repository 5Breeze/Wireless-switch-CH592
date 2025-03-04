/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : 广播应用主函数及任务系统初始化
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/******************************************************************************/
/* 头文件包含 */
#include "CONFIG.h"
#include "HAL.h"
#include "broadcaster.h"

/*********************************************************************
 * GLOBAL TYPEDEFS
 */
__attribute__((aligned(4))) uint32_t MEM_BUF[BLE_MEMHEAP_SIZE / 4];

#if (defined(BLE_MAC)) && (BLE_MAC == TRUE)
const uint8_t MacAddr[6] = { 0x84, 0xC2, 0xE4, 0x03, 0x02, 0x02 };
#endif

/*********************************************************************
 * @fn      Main_Circulation
 *
 * @brief   主循环
 *
 * @return  none
 */
__HIGH_CODE
__attribute__((noinline)) void Main_Circulation()
{
    while (1) {
        TMOS_SystemProcess();
        if(FLAG_key1 == 1)
        {
            FLAG_key1 = 0;
            tmos_start_task(Broadcaster_TaskID, SBP_GPIO_IQR_KEY_1_EVT, 16);//10ms
        }
        if(FLAG_key2 == 1)
        {
            FLAG_key1 = 0;
            tmos_start_task(Broadcaster_TaskID, SBP_GPIO_IQR_KEY_2_EVT, 16);
        }
        if(FLAG_key3 == 1)
        {
            FLAG_key1 = 0;
            tmos_start_task(Broadcaster_TaskID, SBP_GPIO_IQR_KEY_3_EVT, 16);
        }
        if(FLAG_key4 == 1)
        {
            FLAG_key1 = 0;
            tmos_start_task(Broadcaster_TaskID, SBP_GPIO_IQR_KEY_4_EVT, 16);
        }
    }
}

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数
 *
 * @return  none
 */
int main(void)
{
#if (defined(DCDC_ENABLE)) && (DCDC_ENABLE == TRUE)
    PWR_DCDCCfg(ENABLE);
#endif
    SetSysClock(CLK_SOURCE_PLL_60MHz);
#if (defined(HAL_SLEEP)) && (HAL_SLEEP == TRUE)
    GPIOA_ModeCfg(GPIO_Pin_All, GPIO_ModeIN_PU);
    GPIOB_ModeCfg(GPIO_Pin_All, GPIO_ModeIN_PU);
#endif

    /* 配置唤醒源为 GPIO - PB12-15 */
    GPIOB_ModeCfg(GPIO_Pin_12, GPIO_ModeIN_PU);
    GPIOB_ITModeCfg(GPIO_Pin_12, GPIO_ITMode_FallEdge); // 下降沿唤醒
    GPIOB_ModeCfg(GPIO_Pin_13, GPIO_ModeIN_PU);
    GPIOB_ITModeCfg(GPIO_Pin_13, GPIO_ITMode_FallEdge); // 下降沿唤醒
    GPIOB_ModeCfg(GPIO_Pin_14, GPIO_ModeIN_PU);
    GPIOB_ITModeCfg(GPIO_Pin_14, GPIO_ITMode_FallEdge); // 下降沿唤醒
    GPIOB_ModeCfg(GPIO_Pin_15, GPIO_ModeIN_PU);
    GPIOB_ITModeCfg(GPIO_Pin_15, GPIO_ITMode_FallEdge); // 下降沿唤醒

    PFIC_EnableIRQ(GPIO_B_IRQn);
    PWR_PeriphWakeUpCfg(ENABLE, RB_SLP_GPIO_WAKE, RB_SLP_GPIO_WAKE);

#ifdef DEBUG
    GPIOA_SetBits(bTXD1);
    GPIOA_ModeCfg(bTXD1, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
#endif
    PRINT("%s\n", VER_LIB);
    CH59x_BLEInit();
    HAL_Init();
    GAPRole_BroadcasterInit();
    Broadcaster_Init();
    Main_Circulation();
}

//中断引脚判断
__INTERRUPT
__HIGH_CODE
void GPIOB_IRQHandler( void )
{
    if(GPIOB_ReadITFlagBit(GPIO_Pin_12))
    {
        FLAG_key1 = 1;
        GPIOB_ClearITFlagBit(GPIO_Pin_12);
        GPIOB_DisableIT(GPIO_Pin_12);
    }

    if(GPIOB_ReadITFlagBit(GPIO_Pin_13))
    {
        FLAG_key2 = 1;
        GPIOB_ClearITFlagBit(GPIO_Pin_13);
        GPIOB_DisableIT(GPIO_Pin_13);
    }

    if(GPIOB_ReadITFlagBit(GPIO_Pin_14))
    {
        FLAG_key3 = 1;
        GPIOB_ClearITFlagBit(GPIO_Pin_14);
        GPIOB_DisableIT(GPIO_Pin_14);
    }

    if(GPIOB_ReadITFlagBit(GPIO_Pin_15))
    {
        FLAG_key4 = 1;
        GPIOB_ClearITFlagBit(GPIO_Pin_15);
        GPIOB_DisableIT(GPIO_Pin_15);
    }
}
/******************************** endfile @ main ******************************/
