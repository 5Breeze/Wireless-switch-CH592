/********************************** (C) COPYRIGHT *******************************
 * File Name          : broadcaster.h
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2018/12/11
 * Description        :
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#ifndef BROADCASTER_H
#define BROADCASTER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * INCLUDES
 */
#include "CH59x_pwr.h"
/*********************************************************************
 * CONSTANTS
 */


 #define STATUS_FLAG_FULL_BATTERY           100  // 前两位表示电池状态
 #define STATUS_FLAG_MEDIUM_BATTERY         60  // 中等电量
 #define STATUS_FLAG_LOW_BATTERY            30  // 低电量
 #define STATUS_FLAG_CRITICALLY_LOW_BATTERY 10  // 严重低电量

// Simple BLE Broadcaster Task Events
#define SBP_START_DEVICE_EVT         0x0001
#define SBP_PERIODIC_EVT             0x0002
#define SBP_ADV_IN_CONNECTION_EVT    0x0004

#define SBP_GPIO_IQR_KEY_1_EVT    0x0008
#define SBP_GPIO_IQR_KEY_2_EVT    0x0010
#define SBP_GPIO_IQR_KEY_3_EVT    0x0020
#define SBP_GPIO_IQR_KEY_4_EVT    0x0040

#define SBP_UPDATE_ADV_EVT    0x0080
#define SBP_CLOSE_ADV_EVT     0x0100
// 广播间隔 (units of 625us, min is 32 = 20ms)
#define DEFAULT_ADVERTISING_INTERVAL 3200

// 广播暂停间隔
#define SBP_PERIODIC_EVT_PERIOD 6400

/* Delay between advertisement. Advertisment will only be transmitted for a short period of time (20ms) and the device will go to sleep.
Higher delay = less power consumption, but more inaccurate tracking
 */
#define DELAY_IN_S 60
/* Define how often (long) a key will be reused after switching to the next one
This is for using less keys after all. The interval for one key is (DELAY_IN_S * REUSE_CYCLES => 60s * 30 cycles = changes key every 30 min)
Smaller number of cycles = key changes more often, but more keys needed.
 */
#define REUSE_CYCLES 30
#define REUSE_MAX_KEY 50
//电压粗调校准循环次数
#define BAT_MAX_COUNTS 200

#define REUSE_CYCLES 30

#define MAX_KEYS 50
// Create space for MAX_KEYS public keys
static volatile const char public_key[28] = {
    "OFFLINEFINDINGPUBLICKEYHERE!"
};

// ADC 采样粗调偏差值
static signed short RoughCalib_Value = 0;

// 电池电量标志
static uint8_t status_flag;

// 广播开启状态标志
static uint8_t adv_flag = 1;

// 广播预关闭状态标志
static uint8_t pre_adv_flag;

//按键状态标志位
static uint8_t FLAG_key1, FLAG_key2, FLAG_key3, FLAG_key4;

//按键状态计数位
static uint8_t Count_key1, Count_key2, Count_key3, Count_key4;

//按键状态事件位 0无关 1单次 2长按
static uint8_t Event_key1, Event_key2, Event_key3, Event_key4;

// Task ID for internal task/event processing
static uint8_t Broadcaster_TaskID;

/** 广播载荷 */
static uint8_t advertData[] = {
    /* BTHOME报头 */
    0x02, 0x01, 0x06, 
    
    //数据有效载荷
    0x12, /* 长度 */
    0x16, /* 16 位 UUID */
    0xd2, 0xfc, /* UUID */
    0x44, /* 不规律数据、不加密 */
    0x01, 0x00, /* 电池状态，百分比 bit10*/
    0x0c, 0x00, 0x00, /* 电压 0.001v bit12-bit13*/
    0x3a, 0x00, /* 开关1 00释放 01按下 02双击 bit15*/
    0x3a, 0x00, /* 开关2 00释放 01按下 02双击 bit17*/
    0x3a, 0x00, /* 开关3 00释放 01按下 02双击 bit19*/
    0x3a, 0x00, /* 开关4 00释放 01按下 02双击 bit21*/

    /* 蓝牙名称：“Wireless-switch” */
    0x11, 0x09, 0x57, 0x69, 0x72, 0x65, 0x6c, 0x65, 0x73, 0x73, 0x2d, 0x73, 0x77, 0x69, 0x74, 0x63, 0x68, 

};
/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * FUNCTIONS
 */

/*
 * Task Initialization for the BLE Broadcaster Application
 */
extern void Broadcaster_Init(void);

/*
 * Task Event Processor for the BLE Broadcaster Application
 */
extern uint16_t Broadcaster_ProcessEvent(uint8_t task_id, uint16_t events);

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif
