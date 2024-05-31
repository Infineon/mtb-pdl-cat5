/***************************************************************************//**
* \file cy_scb.h
*
* Provides API declarations of the SCB driver related to BTSS integration.
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


#ifndef __CY_SCB_H__
#define __CY_SCB_H__

#include "cy_pdl_device.h"

#if defined (CY_IP_MXSCB)

#include "cy_scb_common.h"
#include "cy_scb_uart.h"
#include "cy_scb_spi.h"
#include "cy_scb_i2c.h"
#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef FIX_CYW55900A0_690
#define HCLK_SLOW_MAX_VALUE   96000000u
#endif  //FIX_CYW55900A0_690

/** \brief SCB - Interrupt Callback from IRQ Thread */
typedef void(*CY_SCB_IRQ_THREAD_CB_t)(void);

/**
 * Function Cy_SCB_EnableClock
 *
 * Configure TCPWM IP clock frequency
 *
 * \param[in]    base          : SCB IP instance base address
 * \param[in]    scb_clk_freq  : Desired Frequency
 * \param[in]    hw_reset      : Full IP reset - all registers & HW back to
 *                               initial state
 *
 * \return       Result - Divided clock
 */
uint32_t Cy_SCB_EnableClock(CySCB_Type *base, uint32 scb_clk_freq, BOOL8 hw_reset);

/**
 * Function Cy_SCB_RegisterInterruptCallback
 *
 * Register interrupt callback for all SCB interrupts
 *
 * \param[in]    base          : SCB IP instance base address
 * \param[in]    irqCb         : Callback function
 *
 * \return       Result - Pass or Fail
 */
BOOL32 Cy_SCB_RegisterInterruptCallback(CySCB_Type *base, CY_SCB_IRQ_THREAD_CB_t irqCb);

/**
 * Function Cy_SCB_EnableInterrupt
 *
 * Enable SCB interrupt
 *
 * \param[in]    base          : SCB IP instance base address
 *
 * \return       none
 */
void Cy_SCB_EnableInterrupt    (CySCB_Type *base);

/**
 * Function Cy_SCB_DisableInterrupt
 *
 * Disable SCB interrupt
 *
 * \param[in]    base          : SCB IP instance base address
 *
 * \return       none
 */
void Cy_SCB_DisableInterrupt    (CySCB_Type *base);

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXSCB */

#endif /* __CY_SCB_H__ */

/* [] END OF FILE */
