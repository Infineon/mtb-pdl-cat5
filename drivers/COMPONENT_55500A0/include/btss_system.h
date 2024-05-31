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
    BTSS_SYSTEM_CPU_CLK_24MHZ ,  /* Not recommended when Bluetooth functions are in use */
    BTSS_SYSTEM_CPU_CLK_32MHZ ,  /* Not recommended when Bluetooth functions are in use */
    BTSS_SYSTEM_CPU_CLK_48MHZ ,
    BTSS_SYSTEM_CPU_CLK_96MHZ ,
    BTSS_SYSTEM_CPU_CLK_192MHZ,
} BTSS_SYSTEM_CPU_CLK_FREQ_t;

/** \brief BTSS Sytem Audio pll request types */
typedef enum {
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_LOCK_TO_SPEED   = 0, /* Recommended to check against supported audio PLL frequences when Bluetooth Audio is used. */
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_UNLOCK_TO_SPEED = 1, /* Recommended to check against supported audio PLL frequences when Bluetooth Audio is used. */
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_PPM_ADJUST      = 2, /* Adjusts audio PLL by requested ppm for audio synchronization use cases */
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
 * Function btss_system_clockRequestForAudioPll
 *
 * Requests change in Audio PLL frequency.
 * Recommended to consider Bluetooth Audio requirements when changing Audio PLL base frequency.
 * Recommended PLL VCO outputs - 270.950MHz, 294.912MHz and respective
 * Div4 frequencies are 67.737600MHz & 73.728000MHz. Refer BTSS_SYSTEM_AUDIO_PLL_FREQ_t.
 *
 * Audio PLL Connections - Fixed routing in HW
 * Div1  - VCO/2 => RPU, SMIF
 * Div2  - VCO/4 => MXTDM CLK_IF_SRSS[0]
 * Div4  - VCO/4 => MXTDM CLK_IF_SRSS[1]
 * Div6  - VCO/4 => MXTDM CLK_IF_SRSS[2]
 * Div8  - VCO/4 => MXTDM CLK_IF_SRSS[3]
 * Div18 - VCO/4 => PDM (8.192MHz from 294.912MHz)
 * Div36 - VCO/4 => PDM, ADC (4.096MHz from 294.912MHz)
 *
 * \param[in]    req           : Request type
 * \param[in]    freq          : Desired Div4 Frequency
 *
 * \return       Result - Pass or Fail
 */
BOOL32 btss_system_clockRequestForAudioPll(BTSS_SYSTEM_AUDIO_PLL_REQ_t req, UINT32 freq);

/**
 * Function btss_system_clockGetAudioPllFreq
 *
 * Get Audio PLL Div4 Frequency. PLL_VCO_OUT/4.
 *
 * \return       freq - Audio PLL Div4 Frequency
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
 * Function btss_system_getRpuBaseClock
 *
 * Get base system clock which goes into SCB and TCPWM as IP clock.
 *
 * \return       Current RPU system clock
 */
UINT32 btss_system_getRpuBaseClock(void);

#include "bt_types.h"

#if defined(__cplusplus)
}
#endif

#endif //__BTSS_SYSTEM_H__

/* [] END OF FILE */
