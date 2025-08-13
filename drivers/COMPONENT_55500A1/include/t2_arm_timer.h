/***************************************************************************//**
* \file t2_arm_timer.h
*
* Provides API declarations of the ARM Timer2 driver.
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

#ifndef _T2_ARM_TIMERS_H_
#define _T2_ARM_TIMERS_H_

#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/** ARM HW Timer */
typedef enum
{
    //! ARM Aux timer1.
    T2_ARM_TIMER_AUX_1 = 0,

    //! ARM Aux timer2.
    T2_ARM_TIMER_AUX_2 = 1,

    //! Number of aux timers.
    T2_ARM_TIMER_AUX_COUNT
} T2_ARM_TIMER_AUX_t;

/** Timer enable bit. Maps to TimerXControl[7] */
typedef enum
{
    //! 0 = Timer module disabled (default)
    T2_ARM_TIMER_EN_DISABLE = 0,

    //! 1 = Timer module enabled.
    T2_ARM_TIMER_EN_ENABLE = 1 << 7
} T2_ARM_TIMER_EN_t;

/** Timer mode buit. Maps to TimerXControl[6] */
typedef enum
{
    //! 0 = Timer module is in free-running mode (default)
    T2_ARM_TIMER_MODE_FREERUNNING = 0,

    //! 1 = Timer module is in periodic mode.
    T2_ARM_TIMER_MODE_PERIODIC = 1 << 6
} T2_ARM_TIMER_MODE_t;

/** Timer int enable bit. Maps to TimerXControl[5] */
typedef enum
{
    //! 0 = Timer module Interrupt disabled
    T2_ARM_TIMER_INT_EN_DISABLE = 0,

    //! 1 = Timer module Interrupt enabled (default).
    T2_ARM_TIMER_INT_EN_ENABLE = 1 << 5
} T2_ARM_TIMER_INT_EN_t;

/** Timer prescale bits. Maps to TimerXControl[3:2] */
typedef enum
{
    //! 00 = 0 stages of prescale, clock is divided by 1 (default).
    T2_ARM_TIMER_DIVISOR_1 = 0,

    //! 01 = 4 stages of prescale, clock is divided by 16.
    T2_ARM_TIMER_DIVISOR_16 = 1 << 2,

    //! 10 = 8 stages of prescale, clock is divided by 256.
    T2_ARM_TIMER_DIVISOR_256 = 2 << 2
} T2_ARM_TIMER_DIVISOR_t;

/** Timer bit counter width. Maps to TimerXControl[1] */
typedef enum
{
    //! 0 = 16-bit counter (default)
    T2_ARM_TIMER_SIZE_16_BIT = 0,

    //! 1 = 32-bit counter.
    T2_ARM_TIMER_SIZE_32_BIT = 1 << 1
} T2_ARM_TIMER_SIZE_t;

/** Timer counter mode. Maps to TimerXControl[0] */
typedef enum
{
    //! 0 = wrapping mode (default)
    T2_ARM_TIMER_COUNTER_MODE_WRAPPING = 0,

    //! 1 = one-shot mode
    T2_ARM_TIMER_COUNTER_MODE_ONESHOT = 1
} T2_ARM_TIMER_COUNTER_MODE_t;

/**
 * Function clock_auxTimerStart
 *
 * Start or restart the aux timer. Can be invoked in interrupt or thread context.
 *
 * \param[in]    timeout_us    : Timeout in timer counts. Base counter 1us - prescaled by clock choice.
 * \param[in]    options       : Timer configuration options. This must be a Bitwise OR of
 *                               ARM_TIMER_EN, ARM_TIMER_MODE, ARM_TIMER_INT_EN, ARM_TIMER_DIVISOR,
 *                               ARM_TIMER_SIZE and ARM_TIMER_COUNTER_MODE. Other bits are ignored.
 * \param[in]    timerCallback : The argument passed back to timerCallback when it is invoked.
 * \param[in]    arg           : buffer to for the read data
 *
 * \return       Status - 1 for success, 0 for failure.
 */
UINT32 clock_auxTimerStart( T2_ARM_TIMER_AUX_t which_timer, UINT32 timeout_count,
                           UINT32 options, void (*timerCallback)(INT32 arg), INT32 arg );

/**
 * Function clock_auxTimerStop
 *
 * Stop aux timer.
 *
 * \param[in]    which_timer   : Instance of the timer to stop.
 *
 * \return       Status - 1 for success, 0 for failure.
 */
UINT32 clock_auxTimerStop(T2_ARM_TIMER_AUX_t which_timer);

/**
 * Function clock_auxTimerUsToExpiry
 *
 * Reads the number of microseconds to expiry. Valid only when aux timer is running.
 * Since the underlying timer continues to run, return value could be stale.
 *
 * \param[in]    which_timer   : Instance of the timer to read out
 *
 * \return       Number of microseconds till timer1 expires.
 */
UINT32 clock_auxTimerUsToExpiry(T2_ARM_TIMER_AUX_t which_timer);

#if defined(__cplusplus)
}
#endif

#endif //_T2_ARM_TIMERS_H_

/* [] END OF FILE */

