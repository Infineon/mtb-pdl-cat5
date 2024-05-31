/***************************************************************************//**
* \file btss_system.h
*
* Provides API declarations of the BTSS System.
*
********************************************************************************
* \copyright
* Copyright 2022 Infineon Technologies
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef __BTSS_SYSTEM_H__
#define __BTSS_SYSTEM_H__



#include "bt_types.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \brief BTSS Sytem CPU clock request types */
 typedef enum
{
    BTSS_SYSTEM_CPU_CLK_REQ_NEED_UPTO,         /* Update CPU to match new (usually more) clock frequency requirement */
    BTSS_SYSTEM_CPU_CLK_REQ_RELEASE_FROM,      /* Release previously requeseted freqency requirement. */
    BTSS_SYSTEM_CPU_CLK_REQ_LOCK_TO_SPEED,     /* Lock to the specified cpu - should only be called by one client */
    BTSS_SYSTEM_CPU_CLK_REQ_UNLOCK_FROM_SPEED, /* Unlock the locked speed - should only be called by one client */
} BTSS_SYSTEM_CPU_CLK_REQ_t;

/** \brief BTSS Sytem CPU clock request supported frequencies */
typedef enum {
    BTSS_SYSTEM_CPU_CLK_48MHZ ,  /* Min clock frequency request supported by H1A1 */
    BTSS_SYSTEM_CPU_CLK_96MHZ ,
    BTSS_SYSTEM_CPU_CLK_192MHZ,  /* Max clock frequency request supported by H1A1 */
} BTSS_SYSTEM_CPU_CLK_FREQ_t;

/** \brief BTSS Sytem Audio pll request types */
typedef enum {
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_LOCK_TO_SPEED     = 0, /* Recommended to check against supported audio PLL frequences when Bluetooth Audio is used. */
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_UNLOCK_TO_SPEED   = 1, /* Recommended to check against supported audio PLL frequences when Bluetooth Audio is used. */
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_PPM_ADJUST        = 2, /* Adjusts audio PLL by requested ppm for audio synchronization use cases */
} BTSS_SYSTEM_AUDIO_PLL_REQ_t;

/** \brief BTSS Sytem Audio pll request - specific pll frequencies for audio use cases. */
typedef enum {
    BTSS_SYSTEM_AUDIO_PLL_FREQ_44_1KHZ_MCLK = 67737600u, /* PLL frequency for 44.1KHz sampling rate */
    BTSS_SYSTEM_AUDIO_PLL_FREQ_GENERIC_MCLK = 73728000u, /* PLL frequency for 48/32/16/8KHz sampling rate */
} BTSS_SYSTEM_AUDIO_PLL_FREQ_t;

/** \brief BTSS Sytem Interrupt sources for Applications */
typedef enum {
    BTSS_SYSTEM_INTERRUPT_GPIO,
    BTSS_SYSTEM_INTERRUPT_A_GPIO,
    BTSS_SYSTEM_INTERRUPT_B_GPIO,
    BTSS_SYSTEM_INTERRUPT_T2_TIMER1,
    BTSS_SYSTEM_INTERRUPT_T2_TIMER2,
    BTSS_SYSTEM_INTERRUPT_SCB0,
    BTSS_SYSTEM_INTERRUPT_SCB1,
    BTSS_SYSTEM_INTERRUPT_SCB2,
    BTSS_SYSTEM_INTERRUPT_ADCCOMP,
    BTSS_SYSTEM_INTERRUPT_MXTDM0,
    BTSS_SYSTEM_INTERRUPT_MXTDM1,
    BTSS_SYSTEM_INTERRUPT_DMIC,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G0_C0,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G0_C1,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C0,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C1,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C2,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C3,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C4,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C5,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C6,
} BTSS_SYSTEM_INTERRUPT_t;

/** \brief BTSS Sytem - Random number request type */
typedef enum
{
    BTSS_SYSTEM_RANDOM_NUM_REQ_PRNG,   /* Pseudo-random number */
    BTSS_SYSTEM_RANDOM_NUM_REQ_TRNG,   /* True random number */
} BTSS_SYSTEM_RANDOM_NUM_REQ_t;

/** \brief BTSS Sytem - Sleep Configurations */
typedef enum
{
    BTSS_SYSTEM_SLEEP_MODE_DISABLE,         /**< Disable sleep mode */
    BTSS_SYSTEM_SLEEP_MODE_NO_TRANSPORT,    /**< To be used only when HCI UART transport is not connected to host */
    BTSS_SYSTEM_SLEEP_MODE_WITH_TRANSPORT   /**< This mode allows sleep when HCI UART transport is connected to host and uses device wake line to wake up*/
} BTSS_SYSTEM_SLEEP_CONFIG_t;

/** \brief BTSS Sytem -  Active level for Wake through GPIO */
typedef enum
{
    BTSS_SYSTEM_SLEEP_WAKE_ACTIVE_LOW, /**< Active low interrupt wakes the chip/host */
    BTSS_SYSTEM_SLEEP_WAKE_ACTIVE_HIGH /**< Active high interrupt wakes the chip/host */
} BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t;

typedef enum
{
    //! sleep is not allowed
    BTSS_SYSTEM_PMU_SLEEP_NOT_ALLOWED = 0,
    //! sleep is not disabling any part of HW, just doing processor sleep
    BTSS_SYSTEM_PMU_SLEEP_WITH_XTAL_ON = 1,
    //! same as PMU_SLEEP_WITH_XTAL but XTAL is disabled
    BTSS_SYSTEM_PMU_SLEEP_WITH_XTAL_OFF = 2,
    //! Unused entry
    BTSS_SYSTEM_PMU_SLEEP_RESERVED = 3,
    //! PDS sleep is disabling part of HW during sleep but isolation is not enabled
    BTSS_SYSTEM_PMU_SLEEP_PDS = 4,
    //! EPDS sleep is disabling most of HW during sleep, RAM is powered ON, after sleep system reboots at wake up.
    BTSS_SYSTEM_PMU_SLEEP_EPDS = 5,
    //! Max sleep mode
    BTSS_SYSTEM_PMU_SLEEP_MAX = BTSS_SYSTEM_PMU_SLEEP_EPDS
} BTSS_SYSTEM_PMU_SLEEP_MODE_t;

typedef enum
{
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_UART_RTS_N = 1,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_UART_CTS_N = 3,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_UART_RXD = 5,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_0 = 7,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_HOST_WAKE = 9,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_2 = 11,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_3 = 13,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_4 = 15,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_5 = 17,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_6 = 19,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_7 = 21,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_19 = 23,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_18 = 25,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_16 = 27,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_17 = 29,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_8 = 32,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_9 = 34,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_10 = 36,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_11 = 38,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_MCK = 70,
    BTSS_SYSTEM_PMU_WAKE_SRC_DMIC_DQ = 74,
    BTSS_SYSTEM_PMU_WAKE_SRC_DMIC_CK = 76,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_DO = 78,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_DI = 80,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_MCK = 82,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_SCK = 84,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_WS = 86,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_CLK = 88,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_SYNC = 90,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_IN = 92,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_OUT = 94,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_2 = 96,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_3 = 98,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_4 = 100,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_5 = 102,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_6 = 104,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_7 = 106,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_8 = 108,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_9 = 110,
} BTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t;

typedef enum
{
    BTSS_SYSTEM_NVRAM_OTA_ERR_NONE                          = 0x00,
    BTSS_SYSTEM_NVRAM_OTA_ERR_ADDR_OUT_OF_RANGE             = 0x01,
    BTSS_SYSTEM_NVRAM_OTA_ERR_CRYPTO_FAILED                 = 0x02,
    BTSS_SYSTEM_NVRAM_OTA_ERR_FLASH_WRITE_FAILED            = 0x03,
    BTSS_SYSTEM_NVRAM_OTA_ERR_FLASH_ERASE_FAILED            = 0x04,
    BTSS_SYSTEM_NVRAM_OTA_ERR_BUFFER_NOT_ALLOCATED          = 0x05,
    BTSS_SYSTEM_NVRAM_OTA_ERR_CRYPTO_INVALID_KEY            = 0x06,
    BTSS_SYSTEM_NVRAM_OTA_ERR_CERT_VALIDATION_FAILED        = 0x07,
    BTSS_SYSTEM_NVRAM_OTA_ERR_NO_ACCESS                     = 0x08,
} BTSS_SYSTEM_NVRAM_OTA_ERR_t;

/** Header fields for OTA upgrade feature */
typedef struct
{
    UINT32 address;
    UINT32 length;
    UINT32 flags;
} BTSS_SYSTEM_NVRAM_OTA_HEADER_t;

/** Sleep configuration parameters */
typedef struct
{
    BTSS_SYSTEM_SLEEP_CONFIG_t                  sleep_config;             /**< Requested sleep mode */

    /* host_wake_mode, device_wake_mode are applicable only
    in case of BTSS_SYSTEM_SLEEP_MODE_TRANSPORT. For BTSS_SYSTEM_SLEEP_MODE_NO_TRANSPORT
    use case, application should configure other wake sources wake pin using
    btss_system_setSleepWakeSource API*/
    BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t                  host_wake_mode;         /**< Active level for host wake */
    BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t                  device_wake_mode;       /**< Active level for device wake */
} BTSS_SYSTEM_SLEEP_PARAMS_t;

/** \brief Pre-Sleep Callback from PMU thread */
typedef BTSS_SYSTEM_PMU_SLEEP_MODE_t(*BTSS_SYSTEM_PRE_SLEEP_CB_t)(BTSS_SYSTEM_PMU_SLEEP_MODE_t sleep_mode, UINT32 sleep_time_in_lpo_cycles);
/** \brief Post-Sleep Callback from PMU thread */
typedef void(*BTSS_SYSTEM_POST_SLEEP_CB_t)(BTSS_SYSTEM_PMU_SLEEP_MODE_t sleep_mode);


/**
 * Function btss_system_cpuclockRequest
 *
 * Requests change in CPU clock frequency
 *
 * \param[in]    req           : Request type
 * \param[in]    freq          : Desired Frequency
 *
 * \return       Result - Pass or Fail
 */
BOOL32 btss_system_clockRequestForCpu(BTSS_SYSTEM_CPU_CLK_REQ_t req, BTSS_SYSTEM_CPU_CLK_FREQ_t freq);

/**
 * Function btss_system_clockGetCpuFreq
 *
 * Get current CPU frequency.
 *
 * \return       CPU frequency
 */
BTSS_SYSTEM_CPU_CLK_FREQ_t btss_system_clockGetCpuFreq(void);

/**
 * Function btss_system_getRpuBaseClock
 *
 * Get RPU base frequency. This goes as input clock to all peripherals.
 *
 * \return       RPU frequency
 */
UINT32 btss_system_getRpuBaseClock(void);

/**
 * Function btss_system_clockRequestForAudioPll
 *
 * Requests change in Audio PLL frequency.
 * Recommended to consider Bluetooth Audio requirements when changing Audio PLL base frequency.
 *
 * \param[in]    req           : Request type
 * \param[in]    freq          : Desired Frequency
 *
 * \return       Result - Pass or Fail
 */
BOOL32 btss_system_clockRequestForAudioPll(BTSS_SYSTEM_AUDIO_PLL_REQ_t req, UINT32 freq);

/**
 * Function btss_system_clockGetAudioPllFreq
 *
 * Get Audio PLL Frequency.
 *
 * \return       freq - Audio PLL Frequency
 */
UINT32 btss_system_clockGetAudioPllFreq(void);

/**
 * Function btss_system_getSystemTimeMicroseconds
 *
 * Get current system up time in microseconds
 *
 * \return       System time in us
 */
UINT64 btss_system_getSystemTimeMicroseconds(void);

/**
 * Function btss_system_getRandomNumber
 *
 * Get random number
 *
 * \param[in]    req  : Request type - PRNG or TRNG
 *
 * \return       Random number
 */
UINT32 btss_system_getRandomNumber( BTSS_SYSTEM_RANDOM_NUM_REQ_t req );

/**
 * Function btss_system_forceSystemReset
 *
 * Forces system reset
 *
 * \return       none
 */
void btss_system_forceSystemReset(void);

/**
 * Function btss_system_intEnable
 *
 * Enable interrupt for peripheral
 *
 * \param[in]    interrupt       : interrupt source
 *
 * \return       Status
 */
BOOL32 btss_system_intEnable(BTSS_SYSTEM_INTERRUPT_t interrupt);

/**
 * Function btss_system_intDisable
 *
 * Disable interrupt for peripheral
 *
 * \param[in]    interrupt       : interrupt source
 *
 * \return       Status
 */
BOOL32 btss_system_intDisable(BTSS_SYSTEM_INTERRUPT_t interrupt);

/**
 * Function btss_system_intClearPending
 *
 * Clear pending interrupts for peripheral
 *
 * \param[in]    interrupt       : interrupt source
 *
 * \return       Status
 */
BOOL32 btss_system_intClearPending(BTSS_SYSTEM_INTERRUPT_t interrupt);

/**
 * Function btss_system_enterCriticalSection
 *
 * Enter critical section
 *
 * \return       Current interrupt state
 */
UINT32 btss_system_enterCriticalSection(void);

/**
 * Function btss_system_exitCriticalSection
 *
 * Clear pending interrupts for peripheral
 *
 * \param[in]    interrupt_state       : Interrupt state returned
 *                                       in btss_system_enterCriticalSection
 *
 * \return       None
 */
void btss_system_exitCriticalSection(UINT32 interrupt_state);

/**
 * Function btss_system_sleepInit
 *
 * Initializes sleep feature with Application callbacks.
 *
 * \param[in]    preSleepCb       : Callback before sleep entry. Returns allowed sleep mode.
 * \param[in]    postSleepCb      : Callback after wake up from sleep.
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepInit(BTSS_SYSTEM_PRE_SLEEP_CB_t preSleepCb, BTSS_SYSTEM_POST_SLEEP_CB_t postSleepCb);

/**
 * Function btss_system_sleepInit
 *
 * Enables sleep feature.
 *
 * \param[in]    params       : Sleep configuration parameters.
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepEnable(BTSS_SYSTEM_SLEEP_PARAMS_t *params);

/**
 * Function btss_system_sleepAllowMode
 *
 * Allows application to set the maximum sleep allowed to enter
 *
 * \param[in]    sleepMode       : Maximum allowed sleep mode.
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepAllowMode(BTSS_SYSTEM_PMU_SLEEP_MODE_t sleepMode);

/**
 * Function btss_system_sleepEnableWakeSource
 *
 * Enables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 * \param[in]    activeState      : Level to trigger wake signal (High/Low)
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepEnableWakeSource(BTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource, BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t activeState);

/**
 * Function btss_system_sleepDisableWakeSource
 *
 * Disables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepDisableWakeSource(BTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource);

#include "bt_types.h"

#if defined(__cplusplus)
}
#endif

#endif //__BTSS_SYSTEM_H__

/* [] END OF FILE */
