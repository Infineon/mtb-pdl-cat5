/***************************************************************************//**
* \file cy_device.h
* \version 2.30
*
* This file specifies the structure for core and peripheral block HW base
* addresses, versions, and parameters.
*
********************************************************************************
* \copyright
* Copyright 2021-2022 Cypress Semiconductor Corporation
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

#ifndef CY_DEVICE_H_
#define CY_DEVICE_H_

#include <stdint.h>
#include <stddef.h>

#include "cy_pdl_device.h"

/******************************************************************************
 *                                IP Constants
 ******************************************************************************/

#define TCPWM0      ((TCPWM_Type*) tcpwm_adr_base)
#define SCB0        ((CySCB_Type*) scb0_adr_base)
#define SCB1        ((CySCB_Type*) scb1_adr_base)
#define SCB2        ((CySCB_Type*) scb2_adr_base)
#define TDM0        ((TDM_Type*) mxtdm_adr_base)
#define TDM1        ((TDM_Type*) (mxtdm_adr_base + 0x200))

// Needed for triggers code
#define CY_IP_MXSPERI                       (1)

#define CY_IP_MXSCB_INSTANCES               (3)
#define CY_IP_MXS40ADCMIC_INSTANCES         (1)
#define CY_IP_MXLPCOMP_INSTANCES            (2)
#define CY_IP_MXSMIF_INSTANCES              (1)
#define CY_IP_MXTCPWM_INSTANCES             (1)
#define CY_IP_MXTDM_INSTANCES               (2)

#define CY_IP_PL061_ARM_GPIO_INSTANCES      (3)
#define CY_IP_SP804_TIMER_INSTANCES         (2)
#define CY_IP_SP805_WATCHDOG_INSTANCES      (1)
#define CY_IP_PL081_8CH_DMAC_INSTANCES      (1)


/******************************************************************************
 *                                Clocks
 ******************************************************************************/

/* These are only for compilation purposes with existing PSoC drivers. They're not used. */
#define CY_SYSCLK_SUCCESS                       0
#define CYHAL_CLOCK_BLOCK_PERIPHERAL_8BIT       0
#define CYHAL_CLOCK_BLOCK_PERIPHERAL_16BIT      0
#define CYHAL_CLOCK_BLOCK_PERIPHERAL_16_5BIT    0
#define CYHAL_CLOCK_BLOCK_PERIPHERAL_24_5BIT    0

typedef int32_t en_clk_dst_t;


/******************************************************************************
 *                                Interrupts
 ******************************************************************************/

// Repurposed PSoC interrupt indexes for compatibility with existing drivers
#define scb_0_interrupt_IRQn            0
#define scb_1_interrupt_IRQn            1
#define scb_2_interrupt_IRQn            2
#define tcpwm_0_interrupts_0_IRQn       3       /* Not defined by lower level driver */
#define tcpwm_0_interrupts_256_IRQn     4       /* Not defined by lower level driver */
#define tdm_0_interrupts_IRQn           BTSS_SYSTEM_INTERRUPT_MXTDM0
#define tdm_1_interrupts_IRQn           BTSS_SYSTEM_INTERRUPT_MXTDM1

#endif /* CY_DEVICE_H_ */

/* [] END OF FILE */
