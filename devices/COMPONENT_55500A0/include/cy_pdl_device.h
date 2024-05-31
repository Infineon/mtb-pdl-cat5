/***************************************************************************//**
* \file cy_pdl_device.h
* \version 2.20
*
* This file specifies the structure for core and peripheral block HW base
* addresses, versions, and parameters.
*
********************************************************************************
* \copyright
* Copyright 2018-2020 Cypress Semiconductor Corporation
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
/**
* \section group_device_MISRA MISRA-C Compliance
* <table class="doxtable">
*   <tr>
*     <th>MISRA Rule</th>
*     <th>Rule Class (Required/Advisory)</th>
*     <th>Rule Description</th>
*     <th>Description of Deviation(s)</th>
*   </tr>
*   <tr>
*     <td>10.1</td>
*     <td>R</td>
*     <td>The value of an expression of integer type shall not be implicitly converted to a different underlying type
*         under some circumstances.</td>
*     <td>An operand of essentially enum type is being converted to unsigned type as a result of an arithmetic or
*         conditional operation. The conversion does not have any unintended effect.</td>
*   </tr>
*   <tr>
*     <td>20.6</td>
*     <td>R</td>
*     <td>The macro offsetof, in library <stddef.h>, shall not be used.</td>
*     <td>The only HW block register offsets are defined using this macro.</td>
*   </tr>
* </table>
*/

#ifndef CY_PDL_DEVICE_H_
#define CY_PDL_DEVICE_H_

#include "cy_pdl_wrapper.h"

#define tcpwm_adr_base        0x8f340000
#define scb0_adr_base         0x8f360000
#define scb1_adr_base         0x8f370000
#define scb2_adr_base         0x8f390000
#define mxtdm_adr_base        0x8f3a0000
#define sram_adr_base         0x80400000
#define cc312_adr_base        0x8e000000
#define driver_cfg_adr_base   0x8f380000

#define BCM55500  1

/******************************************************************************
 * IP List
*****************************************************************************/
#ifdef TCPWM
#define CY_IP_MXTCPWM           1
#define CY_IP_MXTCPWM_VERSION   TCPWM_IP_VER
#endif

#ifdef SCB
#define CY_IP_MXSCB             1
#define CY_IP_MXSCB_VERSION     SCB_IP_VER
#endif

#ifdef SMIF_CY
#define CY_IP_MXSMIF            1
#define CY_IP_MXSMIF_VERSION    3 //SMIF_CY_IP_VER
#endif

#if defined(MXTDM_SUPPORT) || defined(MXTDM_PDL_DRIVER)
#define CY_IP_MXTDM             1
#define CY_IP_MXTDM_VERSION     1
#endif


/******************************************************************************
 * TCPWM IP Parameters for the device
*****************************************************************************/
#ifdef TCPWM
#if (CY_IP_MXTCPWM_VERSION == 1)

#include "cyip_tcpwm.h"
#define CyTCPWM_Type    CyTCPWM_V1_Type

#error CY_IP_MXTCPWM_VERSION=1 device configuration is not present!

#elif (CY_IP_MXTCPWM_VERSION == 2U)

#include "cyip_tcpwm_v2.h"

#define CyTCPWM_Type           CyTCPWM_V2_Type


/* Maximum number of counters in a group */
// TODO: This was changed from 256 to 2. This appears to work, but should be checked.
#define TCPWM_GRP_CNT_NR                2u


/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define TCPWM_MASTER_WIDTH              8u
/* Number of TCPWM counter groups (1..4) */
#define TCPWM_GRP_NR                    2u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */

#if defined(BCM55560)
/* TCPWM Group 0 Configuration */
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR0_CNT_GRP_CNT_WIDTH   32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT 1u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR0_GRP_GRP_CNT_NR      2u

/* TCPWM Group 1 Configuration */
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR1_CNT_GRP_CNT_WIDTH   32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR1_GRP_GRP_CNT_NR      2u
#endif

#if defined(BCM55500)
/* TCPWM Group 0 Configuration */
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR0_CNT_GRP_CNT_WIDTH   32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT 0u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR0_GRP_GRP_CNT_NR      2u

/* TCPWM Group 1 Configuration */
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM_GRP_NR1_CNT_GRP_CNT_WIDTH   16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM_GRP_NR1_GRP_GRP_CNT_NR      7u
#endif

/* Number of input triggers per counter only routed to one counter (0..8) */
#define TCPWM_TR_ONE_CNT_NR    3u
/* Number of input triggers routed to all counters (0..254) */
#define TCPWM_TR_ALL_CNT_NR    8u

/**
 * Total number of triggers for a counter
 *  - Input trigger 0 is always '0' and input trigger 1 is always '1'.
 *  - one-to-one trigger inputs "TCPWM_TR_ONE_CNT_NR" (different to each counter) are selected by setting 2 and above.
 *  - general purpose triggers TCPWM_TR_ALL_CNT_NR connected to all counters selected by 2 + TCPWM_TR_ONE_CNT_NR and above.
 */
#define TCPWM_TR_CNT_NR        (2u + TCPWM_TR_ONE_CNT_NR + TCPWM_TR_ALL_CNT_NR)

#define TCPWM_TR_WGPO_MUX_LOGIC  4u
#define TCPWM_TR_LGPO_MUX_LOGIC  4u

#else
#error Unsupported version of TCPWM
#endif /* CY_IP_MXTCPWM_VERSION */
#endif /* TCPWM */

/******************************************************************************
* SCB IP Parameters for the device
*****************************************************************************/
#ifdef SCB
/* Maximum system clock to SCB module from TPORT */
#define SCB_IP_SYS_CLK_MAX_FREQUENCY    192000000u
#define SCB_IP_SYS_CLK_MAX_DIVIDER      127u
/* Hardware FIFO size: EZ_DATA_NR / 4 = (512 / 4) = 128 */
#define SCB_IP_FIFO_SIZE                128u

#define SCB_SPI_MIN_OVERSAMPLE          4u
#define SCB_UART_MIN_OVERSAMPLE         8u
#define SCB_I2C_FIXED_OVERSAMPLE        8u

#if (CY_IP_MXSCB_VERSION == 1)
#include "cyip_scb.h"
#define CySCB_Type    CySCB_V1_Type
#elif (CY_IP_MXSCB_VERSION == 3)
#include "cyip_scb_v3.h"
#define CySCB_Type    CySCB_V3_Type
#else
#error Unsupported version of SCB
#endif /* CY_IP_MXSCB_VERSION */
#endif /* SCB */

/******************************************************************************
* SMIF IP Parameters for the device
*****************************************************************************/
#ifdef SMIF_CY
#include "cyip_smif.h"

#define SMIF_Type SMIF_V1_Type
#define SMIF_DEVICE_Type SMIF_DEVICE_V1_Type

#define SMIF_BTFW_CHANGES  1
#endif /* SMIF_CY */

/*******************************************************************************
*                SCB
*******************************************************************************/
#if CY_IP_MXSCB

#define SCB_CTRL(base)                      (((CySCB_Type*) (base))->CTRL)
#define SCB_SPI_CTRL(base)                  (((CySCB_Type*) (base))->SPI_CTRL)
#define SCB_SPI_STATUS(base)                (((CySCB_Type*) (base))->SPI_STATUS)
#define SCB_SPI_TX_CTRL(base)              (((CySCB_Type*) (base))->SPI_TX_CTRL)
#define SCB_SPI_RX_CTRL(base)              (((CySCB_Type*) (base))->SPI_RX_CTRL)
#define SCB_UART_CTRL(base)                 (((CySCB_Type*) (base))->UART_CTRL)
#define SCB_UART_TX_CTRL(base)              (((CySCB_Type*) (base))->UART_TX_CTRL)
#define SCB_UART_RX_CTRL(base)              (((CySCB_Type*) (base))->UART_RX_CTRL)
#define SCB_UART_FLOW_CTRL(base)            (((CySCB_Type*) (base))->UART_FLOW_CTRL)
#define SCB_I2C_CTRL(base)                  (((CySCB_Type*) (base))->I2C_CTRL)
#define SCB_I2C_STATUS(base)                (((CySCB_Type*) (base))->I2C_STATUS)
#define SCB_I2C_M_CMD(base)                 (((CySCB_Type*) (base))->I2C_M_CMD)
#define SCB_I2C_S_CMD(base)                 (((CySCB_Type*) (base))->I2C_S_CMD)
#define SCB_I2C_CFG(base)                   (((CySCB_Type*) (base))->I2C_CFG)
#define SCB_TX_CTRL(base)                   (((CySCB_Type*) (base))->TX_CTRL)
#define SCB_TX_FIFO_CTRL(base)              (((CySCB_Type*) (base))->TX_FIFO_CTRL)
#define SCB_TX_FIFO_STATUS(base)            (((CySCB_Type*) (base))->TX_FIFO_STATUS)
#define SCB_TX_FIFO_WR(base)                (((CySCB_Type*) (base))->TX_FIFO_WR)
#define SCB_RX_CTRL(base)                   (((CySCB_Type*) (base))->RX_CTRL)
#define SCB_RX_FIFO_CTRL(base)              (((CySCB_Type*) (base))->RX_FIFO_CTRL)
#define SCB_RX_FIFO_STATUS(base)            (((CySCB_Type*) (base))->RX_FIFO_STATUS)
#define SCB_RX_MATCH(base)                  (((CySCB_Type*) (base))->RX_MATCH)
#define SCB_RX_FIFO_RD(base)                (((CySCB_Type*) (base))->RX_FIFO_RD)
#define SCB_INTR_CAUSE(base)                (((CySCB_Type*) (base))->INTR_CAUSE)
#define SCB_INTR_I2C_EC(base)               (((CySCB_Type*) (base))->INTR_I2C_EC)
#define SCB_INTR_I2C_EC_MASK(base)          (((CySCB_Type*) (base))->INTR_I2C_EC_MASK)
#define SCB_INTR_I2C_EC_MASKED(base)        (((CySCB_Type*) (base))->INTR_I2C_EC_MASKED)
#define SCB_INTR_SPI_EC(base)               (((CySCB_Type*) (base))->INTR_SPI_EC)
#define SCB_INTR_SPI_EC_MASK(base)          (((CySCB_Type*) (base))->INTR_SPI_EC_MASK)
#define SCB_INTR_SPI_EC_MASKED(base)        (((CySCB_Type*) (base))->INTR_SPI_EC_MASKED)
#define SCB_INTR_M(base)                    (((CySCB_Type*) (base))->INTR_M)
#define SCB_INTR_M_SET(base)                (((CySCB_Type*) (base))->INTR_M_SET)
#define SCB_INTR_M_MASK(base)               (((CySCB_Type*) (base))->INTR_M_MASK)
#define SCB_INTR_M_MASKED(base)             (((CySCB_Type*) (base))->INTR_M_MASKED)
#define SCB_INTR_S(base)                    (((CySCB_Type*) (base))->INTR_S)
#define SCB_INTR_S_SET(base)                (((CySCB_Type*) (base))->INTR_S_SET)
#define SCB_INTR_S_MASK(base)               (((CySCB_Type*) (base))->INTR_S_MASK)
#define SCB_INTR_S_MASKED(base)             (((CySCB_Type*) (base))->INTR_S_MASKED)
#define SCB_INTR_TX(base)                   (((CySCB_Type*) (base))->INTR_TX)
#define SCB_INTR_TX_SET(base)               (((CySCB_Type*) (base))->INTR_TX_SET)
#define SCB_INTR_TX_MASK(base)              (((CySCB_Type*) (base))->INTR_TX_MASK)
#define SCB_INTR_TX_MASKED(base)            (((CySCB_Type*) (base))->INTR_TX_MASKED)
#define SCB_INTR_RX(base)                   (((CySCB_Type*) (base))->INTR_RX)
#define SCB_INTR_RX_SET(base)               (((CySCB_Type*) (base))->INTR_RX_SET)
#define SCB_INTR_RX_MASK(base)              (((CySCB_Type*) (base))->INTR_RX_MASK)
#define SCB_INTR_RX_MASKED(base)            (((CySCB_Type*) (base))->INTR_RX_MASKED)

#endif /* CY_IP_MXSCB */

/*******************************************************************************
*                TCPWM
*******************************************************************************/
#if CY_IP_MXTCPWM

#define TCPWM_CTRL_SET(base)                (((TCPWM_Type *)(base))->CTRL_SET)
#define TCPWM_CTRL_CLR(base)                (((TCPWM_Type *)(base))->CTRL_CLR)
#define TCPWM_CMD_START(base)               (((TCPWM_Type *)(base))->CMD_START)
#define TCPWM_CMD_RELOAD(base)              (((TCPWM_Type *)(base))->CMD_RELOAD)
#define TCPWM_CMD_STOP(base)                (((TCPWM_Type *)(base))->CMD_STOP)
#define TCPWM_CMD_CAPTURE(base)             (((TCPWM_Type *)(base))->CMD_CAPTURE)

#define TCPWM_CNT_CTRL(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].CTRL)
#define TCPWM_CNT_CC(base, cntNum)           (((TCPWM_Type *)(base))->CNT[cntNum].CC)
#define TCPWM_CNT_CC_BUFF(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].CC_BUFF)
#define TCPWM_CNT_COUNTER(base, cntNum)      (((TCPWM_Type *)(base))->CNT[cntNum].COUNTER)
#define TCPWM_CNT_PERIOD(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD)
#define TCPWM_CNT_PERIOD_BUFF(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].PERIOD_BUFF)
#define TCPWM_CNT_STATUS(base, cntNum)       (((TCPWM_Type *)(base))->CNT[cntNum].STATUS)
#define TCPWM_CNT_INTR(base, cntNum)         (((TCPWM_Type *)(base))->CNT[cntNum].INTR)
#define TCPWM_CNT_INTR_SET(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].INTR_SET)
#define TCPWM_CNT_INTR_MASK(base, cntNum)    (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASK)
#define TCPWM_CNT_INTR_MASKED(base, cntNum)  (((TCPWM_Type *)(base))->CNT[cntNum].INTR_MASKED)
#define TCPWM_CNT_TR_CTRL0(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL0)
#define TCPWM_CNT_TR_CTRL1(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL1)
#define TCPWM_CNT_TR_CTRL2(base, cntNum)     (((TCPWM_Type *)(base))->CNT[cntNum].TR_CTRL2)


#define TCPWM_GRP_CC1_PRESENT_STATUS (TCPWM_GRP_NR0_CNT_GRP_CC1_PRESENT | TCPWM_GRP_NR1_CNT_GRP_CC1_PRESENT << 1)
#define TCPWM_GRP_AMC_PRESENT_STATUS (TCPWM_GRP_NR0_CNT_GRP_AMC_PRESENT | TCPWM_GRP_NR1_CNT_GRP_AMC_PRESENT << 1)
#define TCPWM_GRP_SMC_PRESENT_STATUS (TCPWM_GRP_NR0_CNT_GRP_SMC_PRESENT | TCPWM_GRP_NR1_CNT_GRP_SMC_PRESENT << 1)

#define TCPWM_GRP_CC1(base, grp) ((BOOL8)((TCPWM_GRP_CC1_PRESENT_STATUS >> (grp)) & 0x01u))
#define TCPWM_GRP_AMC(base, grp) ((BOOL8)((TCPWM_GRP_AMC_PRESENT_STATUS >> (grp)) & 0x01u))
#define TCPWM_GRP_SMC(base, grp) ((BOOL8)((TCPWM_GRP_SMC_PRESENT_STATUS >> (grp)) & 0x01u))

#define TCPWM_GRP_CNT_GET_GRP(cntNum)        ((cntNum )/ TCPWM_GRP_CNT_NR)

#define TCPWM_GRP_CNT_CTRL(base, grp, cntNum)           (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].CTRL)
#define TCPWM_GRP_CNT_STATUS(base, grp, cntNum)         (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].STATUS)
#define TCPWM_GRP_CNT_COUNTER(base, grp, cntNum)        (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].COUNTER)
#define TCPWM_GRP_CNT_CC0(base, grp, cntNum)            (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].CC0)
#define TCPWM_GRP_CNT_CC0_BUFF(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].CC0_BUFF)
#define TCPWM_GRP_CNT_CC1(base, grp, cntNum)            (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].CC1)
#define TCPWM_GRP_CNT_CC1_BUFF(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].CC1_BUFF)
#define TCPWM_GRP_CNT_PERIOD(base, grp, cntNum)         (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].PERIOD)
#define TCPWM_GRP_CNT_PERIOD_BUFF(base, grp, cntNum)    (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].PERIOD_BUFF)
#define TCPWM_GRP_CNT_LINE_SEL(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].LINE_SEL)
#define TCPWM_GRP_CNT_LINE_SEL_BUFF(base, grp, cntNum)  (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].LINE_SEL_BUFF)
#define TCPWM_GRP_CNT_DT(base, grp, cntNum)             (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].DT)
#define TCPWM_GRP_CNT_TR_CMD(base, grp, cntNum)         (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].TR_CMD)
#define TCPWM_GRP_CNT_TR_IN_SEL0(base, grp, cntNum)     (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].TR_IN_SEL0)
#define TCPWM_GRP_CNT_TR_IN_SEL1(base, grp, cntNum)     (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].TR_IN_SEL1)
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL(base, grp, cntNum) (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].TR_IN_EDGE_SEL)
#define TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum)    (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].TR_PWM_CTRL)
#define TCPWM_GRP_CNT_TR_OUT_SEL(base, grp, cntNum)     (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].TR_OUT_SEL)
#define TCPWM_GRP_CNT_INTR(base, grp, cntNum)           (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].INTR)
#define TCPWM_GRP_CNT_INTR_SET(base, grp, cntNum)       (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].INTR_SET)
#define TCPWM_GRP_CNT_INTR_MASK(base, grp, cntNum)      (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].INTR_MASK)
#define TCPWM_GRP_CNT_INTR_MASKED(base, grp, cntNum)    (((TCPWM_Type *)(base))->GRP[grp].CNT[((cntNum) % TCPWM_GRP_CNT_NR)].INTR_MASKED)

#if (CY_IP_MXTCPWM_VERSION >= 2u)
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC0_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC0_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC0_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC0_Msk
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC1_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC1_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC1_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC1_Msk
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_PERIOD_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_PERIOD_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_PERIOD_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_PERIOD_Msk
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_LINE_SEL_Pos TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_LINE_SEL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_LINE_SEL_Msk TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_LINE_SEL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_UP_EN_Pos TCPWM_GRP_CNT_CTRL_CC0_MATCH_UP_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_UP_EN_Msk TCPWM_GRP_CNT_CTRL_CC0_MATCH_UP_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_DOWN_EN_Pos TCPWM_GRP_CNT_CTRL_CC0_MATCH_DOWN_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_DOWN_EN_Msk TCPWM_GRP_CNT_CTRL_CC0_MATCH_DOWN_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_UP_EN_Pos TCPWM_GRP_CNT_CTRL_CC1_MATCH_UP_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_UP_EN_Msk TCPWM_GRP_CNT_CTRL_CC1_MATCH_UP_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_DOWN_EN_Pos TCPWM_GRP_CNT_CTRL_CC1_MATCH_DOWN_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_DOWN_EN_Msk TCPWM_GRP_CNT_CTRL_CC1_MATCH_DOWN_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_IMM_KILL_Pos  TCPWM_GRP_CNT_CTRL_PWM_IMM_KILL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_IMM_KILL_Msk  TCPWM_GRP_CNT_CTRL_PWM_IMM_KILL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_STOP_ON_KILL_Pos TCPWM_GRP_CNT_CTRL_PWM_STOP_ON_KILL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_STOP_ON_KILL_Msk TCPWM_GRP_CNT_CTRL_PWM_STOP_ON_KILL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_SYNC_KILL_Pos TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_SYNC_KILL_Msk TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_Msk
#define TCPWM_GRP_CNT_V2_CTRL_PWM_DISABLE_MODE_Pos TCPWM_GRP_CNT_CTRL_PWM_DISABLE_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_PWM_DISABLE_MODE_Msk TCPWM_GRP_CNT_CTRL_PWM_DISABLE_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE_Pos  TCPWM_GRP_CNT_CTRL_UP_DOWN_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE_Msk  TCPWM_GRP_CNT_CTRL_UP_DOWN_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_ONE_SHOT_Pos      TCPWM_GRP_CNT_CTRL_ONE_SHOT_Pos
#define TCPWM_GRP_CNT_V2_CTRL_ONE_SHOT_Msk      TCPWM_GRP_CNT_CTRL_ONE_SHOT_Msk
#define TCPWM_GRP_CNT_V2_CTRL_QUAD_ENCODING_MODE_Pos TCPWM_GRP_CNT_CTRL_QUAD_ENCODING_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_QUAD_ENCODING_MODE_Msk TCPWM_GRP_CNT_CTRL_QUAD_ENCODING_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_MODE_Pos          TCPWM_GRP_CNT_CTRL_MODE_Pos
#define TCPWM_GRP_CNT_V2_CTRL_MODE_Msk          TCPWM_GRP_CNT_CTRL_MODE_Msk
#define TCPWM_GRP_CNT_V2_CTRL_DBG_FREEZE_EN_Pos TCPWM_GRP_CNT_CTRL_DBG_FREEZE_EN_Pos
#define TCPWM_GRP_CNT_V2_CTRL_DBG_FREEZE_EN_Msk TCPWM_GRP_CNT_CTRL_DBG_FREEZE_EN_Msk
#define TCPWM_GRP_CNT_V2_CTRL_ENABLED_Pos       TCPWM_GRP_CNT_CTRL_ENABLED_Pos
#define TCPWM_GRP_CNT_V2_CTRL_ENABLED_Msk       TCPWM_GRP_CNT_CTRL_ENABLED_Msk
/* TCPWM_GRP_CNT.STATUS */
#define TCPWM_GRP_CNT_V2_STATUS_DOWN_Pos        TCPWM_GRP_CNT_STATUS_DOWN_Pos
#define TCPWM_GRP_CNT_V2_STATUS_DOWN_Msk        TCPWM_GRP_CNT_STATUS_DOWN_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE0_Pos TCPWM_GRP_CNT_STATUS_TR_CAPTURE0_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE0_Msk TCPWM_GRP_CNT_STATUS_TR_CAPTURE0_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_COUNT_Pos    TCPWM_GRP_CNT_STATUS_TR_COUNT_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_COUNT_Msk    TCPWM_GRP_CNT_STATUS_TR_COUNT_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_RELOAD_Pos   TCPWM_GRP_CNT_STATUS_TR_RELOAD_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_RELOAD_Msk   TCPWM_GRP_CNT_STATUS_TR_RELOAD_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_STOP_Pos     TCPWM_GRP_CNT_STATUS_TR_STOP_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_STOP_Msk     TCPWM_GRP_CNT_STATUS_TR_STOP_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_START_Pos    TCPWM_GRP_CNT_STATUS_TR_START_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_START_Msk    TCPWM_GRP_CNT_STATUS_TR_START_Msk
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE1_Pos TCPWM_GRP_CNT_STATUS_TR_CAPTURE1_Pos
#define TCPWM_GRP_CNT_V2_STATUS_TR_CAPTURE1_Msk TCPWM_GRP_CNT_STATUS_TR_CAPTURE1_Msk
#define TCPWM_GRP_CNT_V2_STATUS_LINE_OUT_Pos    TCPWM_GRP_CNT_STATUS_LINE_OUT_Pos
#define TCPWM_GRP_CNT_V2_STATUS_LINE_OUT_Msk    TCPWM_GRP_CNT_STATUS_LINE_OUT_Msk
#define TCPWM_GRP_CNT_V2_STATUS_LINE_COMPL_OUT_Pos TCPWM_GRP_CNT_STATUS_LINE_COMPL_OUT_Pos
#define TCPWM_GRP_CNT_V2_STATUS_LINE_COMPL_OUT_Msk TCPWM_GRP_CNT_STATUS_LINE_COMPL_OUT_Msk
#define TCPWM_GRP_CNT_V2_STATUS_RUNNING_Pos     TCPWM_GRP_CNT_STATUS_RUNNING_Pos
#define TCPWM_GRP_CNT_V2_STATUS_RUNNING_Msk     TCPWM_GRP_CNT_STATUS_RUNNING_Msk
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_L_Pos    TCPWM_GRP_CNT_STATUS_DT_CNT_L_Pos
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_L_Msk    TCPWM_GRP_CNT_STATUS_DT_CNT_L_Msk
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_H_Pos    TCPWM_GRP_CNT_STATUS_DT_CNT_H_Pos
#define TCPWM_GRP_CNT_V2_STATUS_DT_CNT_H_Msk    TCPWM_GRP_CNT_STATUS_DT_CNT_H_Msk
/* TCPWM_GRP_CNT.COUNTER */
#define TCPWM_GRP_CNT_V2_COUNTER_COUNTER_Pos    TCPWM_GRP_CNT_COUNTER_COUNTER_Pos
#define TCPWM_GRP_CNT_V2_COUNTER_COUNTER_Msk    TCPWM_GRP_CNT_COUNTER_COUNTER_Msk
/* TCPWM_GRP_CNT.CC0 */
#define TCPWM_GRP_CNT_V2_CC0_CC_Pos             TCPWM_GRP_CNT_CC0_CC_Pos
#define TCPWM_GRP_CNT_V2_CC0_CC_Msk             TCPWM_GRP_CNT_CC0_CC_Msk
/* TCPWM_GRP_CNT.CC0_BUFF */
#define TCPWM_GRP_CNT_V2_CC0_BUFF_CC_Pos        TCPWM_GRP_CNT_CC0_BUFF_CC_Pos
#define TCPWM_GRP_CNT_V2_CC0_BUFF_CC_Msk        TCPWM_GRP_CNT_CC0_BUFF_CC_Msk
/* TCPWM_GRP_CNT.CC1 */
#define TCPWM_GRP_CNT_V2_CC1_CC_Pos             TCPWM_GRP_CNT_CC1_CC_Pos
#define TCPWM_GRP_CNT_V2_CC1_CC_Msk             TCPWM_GRP_CNT_CC1_CC_Msk
/* TCPWM_GRP_CNT.CC1_BUFF */
#define TCPWM_GRP_CNT_V2_CC1_BUFF_CC_Pos        TCPWM_GRP_CNT_CC1_BUFF_CC_Pos
#define TCPWM_GRP_CNT_V2_CC1_BUFF_CC_Msk        TCPWM_GRP_CNT_CC1_BUFF_CC_Msk
/* TCPWM_GRP_CNT.PERIOD */
#define TCPWM_GRP_CNT_V2_PERIOD_PERIOD_Pos      TCPWM_GRP_CNT_PERIOD_PERIOD_Pos
#define TCPWM_GRP_CNT_V2_PERIOD_PERIOD_Msk      TCPWM_GRP_CNT_PERIOD_PERIOD_Msk
/* TCPWM_GRP_CNT.PERIOD_BUFF */
#define TCPWM_GRP_CNT_V2_PERIOD_BUFF_PERIOD_Pos TCPWM_GRP_CNT_PERIOD_BUFF_PERIOD_Pos
#define TCPWM_GRP_CNT_V2_PERIOD_BUFF_PERIOD_Msk TCPWM_GRP_CNT_PERIOD_BUFF_PERIOD_Msk
/* TCPWM_GRP_CNT.LINE_SEL */
#define TCPWM_GRP_CNT_V2_LINE_SEL_OUT_SEL_Pos   TCPWM_GRP_CNT_LINE_SEL_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_OUT_SEL_Msk   TCPWM_GRP_CNT_LINE_SEL_OUT_SEL_Msk
#define TCPWM_GRP_CNT_V2_LINE_SEL_COMPL_OUT_SEL_Pos TCPWM_GRP_CNT_LINE_SEL_COMPL_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_COMPL_OUT_SEL_Msk TCPWM_GRP_CNT_LINE_SEL_COMPL_OUT_SEL_Msk
/* TCPWM_GRP_CNT.LINE_SEL_BUFF */
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_OUT_SEL_Pos TCPWM_GRP_CNT_LINE_SEL_BUFF_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_OUT_SEL_Msk TCPWM_GRP_CNT_LINE_SEL_BUFF_OUT_SEL_Msk
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_COMPL_OUT_SEL_Pos TCPWM_GRP_CNT_LINE_SEL_BUFF_COMPL_OUT_SEL_Pos
#define TCPWM_GRP_CNT_V2_LINE_SEL_BUFF_COMPL_OUT_SEL_Msk TCPWM_GRP_CNT_LINE_SEL_BUFF_COMPL_OUT_SEL_Msk
/* TCPWM_GRP_CNT.DT */
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_L_Pos   TCPWM_GRP_CNT_DT_DT_LINE_OUT_L_Pos
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_L_Msk   TCPWM_GRP_CNT_DT_DT_LINE_OUT_L_Msk
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_H_Pos   TCPWM_GRP_CNT_DT_DT_LINE_OUT_H_Pos
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_H_Msk   TCPWM_GRP_CNT_DT_DT_LINE_OUT_H_Msk
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_COMPL_OUT_Pos TCPWM_GRP_CNT_DT_DT_LINE_COMPL_OUT_Pos
#define TCPWM_GRP_CNT_V2_DT_DT_LINE_COMPL_OUT_Msk TCPWM_GRP_CNT_DT_DT_LINE_COMPL_OUT_Msk
/* TCPWM_GRP_CNT.TR_CMD */
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE0_Pos    TCPWM_GRP_CNT_TR_CMD_CAPTURE0_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE0_Msk    TCPWM_GRP_CNT_TR_CMD_CAPTURE0_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_RELOAD_Pos      TCPWM_GRP_CNT_TR_CMD_RELOAD_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_RELOAD_Msk      TCPWM_GRP_CNT_TR_CMD_RELOAD_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_STOP_Pos        TCPWM_GRP_CNT_TR_CMD_STOP_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_STOP_Msk        TCPWM_GRP_CNT_TR_CMD_STOP_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_START_Pos       TCPWM_GRP_CNT_TR_CMD_START_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_START_Msk       TCPWM_GRP_CNT_TR_CMD_START_Msk
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE1_Pos    TCPWM_GRP_CNT_TR_CMD_CAPTURE1_Pos
#define TCPWM_GRP_CNT_V2_TR_CMD_CAPTURE1_Msk    TCPWM_GRP_CNT_TR_CMD_CAPTURE1_Msk
/* TCPWM_GRP_CNT.TR_IN_SEL0 */
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_CAPTURE0_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_CAPTURE0_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_CAPTURE0_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_CAPTURE0_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_COUNT_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_COUNT_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_COUNT_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_COUNT_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_RELOAD_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_RELOAD_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_RELOAD_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_RELOAD_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_STOP_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL0_STOP_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL0_STOP_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL0_STOP_SEL_Msk
/* TCPWM_GRP_CNT.TR_IN_SEL1 */
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_START_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL1_START_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_START_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL1_START_SEL_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_CAPTURE1_SEL_Pos TCPWM_GRP_CNT_TR_IN_SEL1_CAPTURE1_SEL_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_SEL1_CAPTURE1_SEL_Msk TCPWM_GRP_CNT_TR_IN_SEL1_CAPTURE1_SEL_Msk
/* TCPWM_GRP_CNT.TR_IN_EDGE_SEL */
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_COUNT_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_COUNT_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_COUNT_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_COUNT_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_RELOAD_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_RELOAD_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_RELOAD_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_RELOAD_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_STOP_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_STOP_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_STOP_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_STOP_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_START_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_START_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_START_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_START_EDGE_Msk
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Pos TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Pos
#define TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Msk TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Msk
/* TCPWM_GRP_CNT.TR_PWM_CTRL */
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC0_MATCH_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_CC0_MATCH_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC0_MATCH_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_CC0_MATCH_MODE_Msk
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_OVERFLOW_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_OVERFLOW_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_OVERFLOW_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_OVERFLOW_MODE_Msk
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_UNDERFLOW_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_UNDERFLOW_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_UNDERFLOW_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_UNDERFLOW_MODE_Msk
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC1_MATCH_MODE_Pos TCPWM_GRP_CNT_TR_PWM_CTRL_CC1_MATCH_MODE_Pos
#define TCPWM_GRP_CNT_V2_TR_PWM_CTRL_CC1_MATCH_MODE_Msk TCPWM_GRP_CNT_TR_PWM_CTRL_CC1_MATCH_MODE_Msk
/* TCPWM_GRP_CNT.TR_OUT_SEL */
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT0_Pos    TCPWM_GRP_CNT_TR_OUT_SEL_OUT0_Pos
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT0_Msk    TCPWM_GRP_CNT_TR_OUT_SEL_OUT0_Msk
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT1_Pos    TCPWM_GRP_CNT_TR_OUT_SEL_OUT1_Pos
#define TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT1_Msk    TCPWM_GRP_CNT_TR_OUT_SEL_OUT1_Msk
/* TCPWM_GRP_CNT.INTR */
#define TCPWM_GRP_CNT_V2_INTR_TC_Pos            TCPWM_GRP_CNT_INTR_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_TC_Msk            TCPWM_GRP_CNT_INTR_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_CC0_MATCH_Pos     TCPWM_GRP_CNT_INTR_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_CC0_MATCH_Msk     TCPWM_GRP_CNT_INTR_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_CC1_MATCH_Pos     TCPWM_GRP_CNT_INTR_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_CC1_MATCH_Msk     TCPWM_GRP_CNT_INTR_CC1_MATCH_Msk
/* TCPWM_GRP_CNT.INTR_SET */
#define TCPWM_GRP_CNT_V2_INTR_SET_TC_Pos        TCPWM_GRP_CNT_INTR_SET_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_SET_TC_Msk        TCPWM_GRP_CNT_INTR_SET_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_SET_CC0_MATCH_Pos TCPWM_GRP_CNT_INTR_SET_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_SET_CC0_MATCH_Msk TCPWM_GRP_CNT_INTR_SET_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_SET_CC1_MATCH_Pos TCPWM_GRP_CNT_INTR_SET_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_SET_CC1_MATCH_Msk TCPWM_GRP_CNT_INTR_SET_CC1_MATCH_Msk
/* TCPWM_GRP_CNT.INTR_MASK */
#define TCPWM_GRP_CNT_V2_INTR_MASK_TC_Pos       TCPWM_GRP_CNT_INTR_MASK_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASK_TC_Msk       TCPWM_GRP_CNT_INTR_MASK_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC0_MATCH_Pos TCPWM_GRP_CNT_INTR_MASK_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC0_MATCH_Msk TCPWM_GRP_CNT_INTR_MASK_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC1_MATCH_Pos TCPWM_GRP_CNT_INTR_MASK_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASK_CC1_MATCH_Msk TCPWM_GRP_CNT_INTR_MASK_CC1_MATCH_Msk
/* TCPWM_GRP_CNT.INTR_MASKED */
#define TCPWM_GRP_CNT_V2_INTR_MASKED_TC_Pos     TCPWM_GRP_CNT_INTR_MASKED_TC_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASKED_TC_Msk     TCPWM_GRP_CNT_INTR_MASKED_TC_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC0_MATCH_Pos TCPWM_GRP_CNT_INTR_MASKED_CC0_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC0_MATCH_Msk TCPWM_GRP_CNT_INTR_MASKED_CC0_MATCH_Msk
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC1_MATCH_Pos TCPWM_GRP_CNT_INTR_MASKED_CC1_MATCH_Pos
#define TCPWM_GRP_CNT_V2_INTR_MASKED_CC1_MATCH_Msk TCPWM_GRP_CNT_INTR_MASKED_CC1_MATCH_Msk

/* For backward compatibility, we set TCPWM_CNT_STATUS_RUNNING_Pos with TCPWM_GRP_CNT_V2_STATUS_RUNNING
we need to define this for version 2 only. */
#define TCPWM_CNT_STATUS_RUNNING_Pos 31u
#endif

#endif /* CY_IP_MXTCPWM */


#ifdef SMIF_CY
/*******************************************************************************
*                SMIF
*******************************************************************************/

#undef SMIF_CTL
#undef SMIF_STATUS
#undef SMIF_TX_DATA_MMIO_FIFO_CTL
#undef SMIF_RX_DATA_MMIO_FIFO_CTL
#undef SMIF_TX_DATA_MMIO_FIFO_WR1
#undef SMIF_TX_DATA_MMIO_FIFO_WR2
#undef SMIF_TX_DATA_MMIO_FIFO_WR4
#undef SMIF_TX_DATA_MMIO_FIFO_WR1ODD
#undef SMIF_RX_DATA_MMIO_FIFO_RD1
#undef SMIF_RX_DATA_MMIO_FIFO_RD2
#undef SMIF_RX_DATA_MMIO_FIFO_RD4
#undef SMIF_TX_CMD_MMIO_FIFO_WR
#undef SMIF_TX_CMD_MMIO_FIFO_STATUS
#undef SMIF_TX_CMD_FIFO_WR
#undef SMIF_TX_CMD_FIFO_STATUS
#undef SMIF_RX_DATA_MMIO_FIFO_STATUS
#undef SMIF_RX_DATA_FIFO_STATUS
#undef SMIF_TX_DATA_MMIO_FIFO_STATUS
#undef SMIF_TX_DATA_FIFO_STATUS
#undef SMIF_INTR
#undef SMIF_INTR_SET
#undef SMIF_INTR_MASK
#undef SMIF_INTR_MASKED
#undef SMIF_CRYPTO_INPUT0
#undef SMIF_CRYPTO_INPUT1
#undef SMIF_CRYPTO_INPUT2
#undef SMIF_CRYPTO_INPUT3
#undef SMIF_CRYPTO_KEY0
#undef SMIF_CRYPTO_KEY1
#undef SMIF_CRYPTO_KEY2
#undef SMIF_CRYPTO_KEY3
#undef SMIF_CRYPTO_OUTPUT0
#undef SMIF_CRYPTO_OUTPUT1
#undef SMIF_CRYPTO_OUTPUT2
#undef SMIF_CRYPTO_OUTPUT3
#undef SMIF_CRYPTO_CMD
#undef SMIF_SLOW_CA_CTL
#undef SMIF_FAST_CA_CTL
#undef SMIF_SLOW_CA_CMD
#undef SMIF_FAST_CA_CMD


#define SMIF_DEVICE_CTL(base)               (((SMIF_DEVICE_V1_Type *)(base))->CTL)
#define SMIF_DEVICE_ADDR(base)              (((SMIF_DEVICE_V1_Type *)(base))->ADDR)
#define SMIF_DEVICE_ADDR_CTL(base)          (((SMIF_DEVICE_V1_Type *)(base))->ADDR_CTL)
#define SMIF_DEVICE_MASK(base)              (((SMIF_DEVICE_V1_Type *)(base))->MASK)
#define SMIF_DEVICE_RD_CMD_CTL(base)        (((SMIF_DEVICE_V1_Type *)(base))->RD_CMD_CTL)
#define SMIF_DEVICE_RD_ADDR_CTL(base)       (((SMIF_DEVICE_V1_Type *)(base))->RD_ADDR_CTL)
#define SMIF_DEVICE_RD_MODE_CTL(base)       (((SMIF_DEVICE_V1_Type *)(base))->RD_MODE_CTL)
#define SMIF_DEVICE_RD_DUMMY_CTL(base)      (((SMIF_DEVICE_V1_Type *)(base))->RD_DUMMY_CTL)
#define SMIF_DEVICE_RD_DATA_CTL(base)       (((SMIF_DEVICE_V1_Type *)(base))->RD_DATA_CTL)
#define SMIF_DEVICE_WR_CMD_CTL(base)        (((SMIF_DEVICE_V1_Type *)(base))->WR_CMD_CTL)
#define SMIF_DEVICE_WR_ADDR_CTL(base)       (((SMIF_DEVICE_V1_Type *)(base))->WR_ADDR_CTL)
#define SMIF_DEVICE_WR_MODE_CTL(base)       (((SMIF_DEVICE_V1_Type *)(base))->WR_MODE_CTL)
#define SMIF_DEVICE_WR_DUMMY_CTL(base)      (((SMIF_DEVICE_V1_Type *)(base))->WR_DUMMY_CTL)
#define SMIF_DEVICE_WR_DATA_CTL(base)       (((SMIF_DEVICE_V1_Type *)(base))->WR_DATA_CTL)

#define SMIF_DEVICE_IDX(base, deviceIndex)                 (((SMIF_V1_Type *)(base))->DEVICE[deviceIndex])

#define SMIF_DEVICE_IDX_CTL(base, deviceIndex)             (SMIF_DEVICE_IDX(base, deviceIndex).CTL)
#define SMIF_DEVICE_IDX_ADDR(base, deviceIndex)            (SMIF_DEVICE_IDX(base, deviceIndex).ADDR)
#define SMIF_DEVICE_IDX_ADDR_CTL(base, deviceIndex)        (SMIF_DEVICE_IDX(base, deviceIndex).ADDR_CTL)
#define SMIF_DEVICE_IDX_MASK(base, deviceIndex)            (SMIF_DEVICE_IDX(base, deviceIndex).MASK)
#define SMIF_DEVICE_IDX_RD_CMD_CTL(base, deviceIndex)      (SMIF_DEVICE_IDX(base, deviceIndex).RD_CMD_CTL)
#define SMIF_DEVICE_IDX_RD_ADDR_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).RD_ADDR_CTL)
#define SMIF_DEVICE_IDX_RD_MODE_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).RD_MODE_CTL)
#define SMIF_DEVICE_IDX_RD_DUMMY_CTL(base, deviceIndex)    (SMIF_DEVICE_IDX(base, deviceIndex).RD_DUMMY_CTL)
#define SMIF_DEVICE_IDX_RD_DATA_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).RD_DATA_CTL)
#define SMIF_DEVICE_IDX_WR_CMD_CTL(base, deviceIndex)      (SMIF_DEVICE_IDX(base, deviceIndex).WR_CMD_CTL)
#define SMIF_DEVICE_IDX_WR_ADDR_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).WR_ADDR_CTL)
#define SMIF_DEVICE_IDX_WR_MODE_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).WR_MODE_CTL)
#define SMIF_DEVICE_IDX_WR_DUMMY_CTL(base, deviceIndex)    (SMIF_DEVICE_IDX(base, deviceIndex).WR_DUMMY_CTL)
#define SMIF_DEVICE_IDX_WR_DATA_CTL(base, deviceIndex)     (SMIF_DEVICE_IDX(base, deviceIndex).WR_DATA_CTL)

#define SMIF_CTL(base)                      (((SMIF_V1_Type *)(base))->CTL)
#define SMIF_STATUS(base)                   (((SMIF_V1_Type *)(base))->STATUS)
#define SMIF_TX_DATA_MMIO_FIFO_CTL(base)    (((SMIF_V1_Type *)(base))->TX_DATA_MMIO_FIFO_CTL)
#define SMIF_RX_DATA_MMIO_FIFO_CTL(base)    (((SMIF_V1_Type *)(base))->RX_DATA_MMIO_FIFO_CTL)
#define SMIF_TX_DATA_MMIO_FIFO_WR1(base)    (((SMIF_V1_Type *)(base))->TX_DATA_MMIO_FIFO_WR1)
#define SMIF_TX_DATA_MMIO_FIFO_WR2(base)    (((SMIF_V1_Type *)(base))->TX_DATA_MMIO_FIFO_WR2)
#define SMIF_TX_DATA_MMIO_FIFO_WR4(base)    (((SMIF_V1_Type *)(base))->TX_DATA_MMIO_FIFO_WR4)
#define SMIF_TX_DATA_MMIO_FIFO_WR1ODD(base) (((SMIF_V1_Type *)(base))->TX_DATA_MMIO_FIFO_WR1ODD)
#define SMIF_RX_DATA_MMIO_FIFO_RD1(base)    (((SMIF_V1_Type *)(base))->RX_DATA_MMIO_FIFO_RD1)
#define SMIF_RX_DATA_MMIO_FIFO_RD2(base)    (((SMIF_V1_Type *)(base))->RX_DATA_MMIO_FIFO_RD2)
#define SMIF_RX_DATA_MMIO_FIFO_RD4(base)    (((SMIF_V1_Type *)(base))->RX_DATA_MMIO_FIFO_RD4)
#define SMIF_TX_CMD_MMIO_FIFO_WR(base)      (((SMIF_V1_Type *)(base))->TX_CMD_MMIO_FIFO_WR)
#define SMIF_TX_CMD_MMIO_FIFO_STATUS(base)  (((SMIF_V1_Type *)(base))->TX_CMD_MMIO_FIFO_STATUS)
#define SMIF_TX_CMD_FIFO_STATUS(base)       (((SMIF_V1_Type *)(base))->TX_CMD_FIFO_STATUS)
#define SMIF_RX_DATA_MMIO_FIFO_STATUS(base) (((SMIF_V1_Type *)(base))->RX_DATA_MMIO_FIFO_STATUS)
#define SMIF_RX_DATA_FIFO_STATUS(base)      (((SMIF_V1_Type *)(base))->RX_DATA_FIFO_STATUS)
#define SMIF_TX_DATA_MMIO_FIFO_STATUS(base) (((SMIF_V1_Type *)(base))->TX_DATA_MMIO_FIFO_STATUS)
#define SMIF_TX_DATA_FIFO_STATUS(base) (((SMIF_V1_Type *)(base))->TX_DATA_FIFO_STATUS)
#define SMIF_INTR(base)                     (((SMIF_V1_Type *)(base))->INTR)
#define SMIF_INTR_SET(base)                 (((SMIF_V1_Type *)(base))->INTR_SET)
#define SMIF_INTR_MASK(base)                (((SMIF_V1_Type *)(base))->INTR_MASK)
#define SMIF_INTR_MASKED(base)              (((SMIF_V1_Type *)(base))->INTR_MASKED)
#define SMIF_CRYPTO_INPUT0(base)            (((SMIF_V1_Type *)(base))->CRYPTO_INPUT0)
#define SMIF_CRYPTO_INPUT1(base)            (((SMIF_V1_Type *)(base))->CRYPTO_INPUT1)
#define SMIF_CRYPTO_INPUT2(base)            (((SMIF_V1_Type *)(base))->CRYPTO_INPUT2)
#define SMIF_CRYPTO_INPUT3(base)            (((SMIF_V1_Type *)(base))->CRYPTO_INPUT3)
#define SMIF_CRYPTO_KEY0(base)              (((SMIF_V1_Type *)(base))->CRYPTO_KEY0)
#define SMIF_CRYPTO_KEY1(base)              (((SMIF_V1_Type *)(base))->CRYPTO_KEY1)
#define SMIF_CRYPTO_KEY2(base)              (((SMIF_V1_Type *)(base))->CRYPTO_KEY2)
#define SMIF_CRYPTO_KEY3(base)              (((SMIF_V1_Type *)(base))->CRYPTO_KEY3)
#define SMIF_CRYPTO_OUTPUT0(base)           (((SMIF_V1_Type *)(base))->CRYPTO_OUTPUT0)
#define SMIF_CRYPTO_OUTPUT1(base)           (((SMIF_V1_Type *)(base))->CRYPTO_OUTPUT1)
#define SMIF_CRYPTO_OUTPUT2(base)           (((SMIF_V1_Type *)(base))->CRYPTO_OUTPUT2)
#define SMIF_CRYPTO_OUTPUT3(base)           (((SMIF_V1_Type *)(base))->CRYPTO_OUTPUT3)
#define SMIF_CRYPTO_CMD(base)               (((SMIF_V1_Type *)(base))->CRYPTO_CMD)
#define SMIF_SLOW_CA_CTL(base)              (((SMIF_V1_Type *)(base))->SLOW_CA_CTL)
#define SMIF_FAST_CA_CTL(base)              (((SMIF_V1_Type *)(base))->FAST_CA_CTL)
#define SMIF_SLOW_CA_CMD(base)              (((SMIF_V1_Type *)(base))->SLOW_CA_CMD)
#define SMIF_FAST_CA_CMD(base)              (((SMIF_V1_Type *)(base))->FAST_CA_CMD)
#endif // SMIF_CY

#if defined(MXTDM_SUPPORT) || defined(MXTDM_PDL_DRIVER)
#include "cyip_tdm.h"

#define TDM0_BASE                               mxtdm_adr_base
//#define TDM0                                    ((TDM_Type*) TDM0_BASE)
#define TDM0_TDM_STRUCT0                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[0])
#define TDM0_TDM_STRUCT0_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_TX_STRUCT)
#define TDM0_TDM_STRUCT0_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_RX_STRUCT)

#define TDM1_BASE                               (mxtdm_adr_base + 0x200)
//#define TDM1                                    ((TDM_Type*) TDM1_BASE)
#define TDM1_TDM_STRUCT0                        ((TDM_TDM_STRUCT_Type*) &TDM1->TDM_STRUCT[0])
#define TDM1_TDM_STRUCT0_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM1->TDM_STRUCT[0].TDM_TX_STRUCT)
#define TDM1_TDM_STRUCT0_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM1->TDM_STRUCT[0].TDM_RX_STRUCT)

/* Number of AHB-Lite "hmaster[]" bits ([4, 8]). */
#define TDM_MASTER_WIDTH                8u
/* Number of TDM structures ({1, 2, 3, 4}]). */
#define TDM_NR                          2u
/* Number of channels per TDM structure. */
#define TDM_NR_CH_NR                    2u
/* Number of channels per TDM structure. */
#define TDM_NR_TDM_RX_STRUCT_CH_NR      2u
/* Number of channels per TDM structure. */
#define TDM_NR_TDM_TX_STRUCT_CH_NR      2u
/* Spare Enable 0=no spare, 1=max, 2=min */
#define TDM_SPARE_EN                    1u
/* 0=ULL65, 1=MXS40-ULP, 2=MXS40E, 3=M0S8, 4=MXS40-HD, 5=F45, 6=MXS40v2, 7=T28HPM,
   8=T28HPL, 9=T28HPC */
#define TDM_PLATFORM_VARIANT            7u
/* SRAM vendor ({0=Cypress, 1=Synopsys, 2=ARM, 3=BRCM}) */
#define TDM_RAM_VEND                    1u
/* Use mxsramwrap IP */
#define TDM_MXSRAMWRAP_EN               1u
/* Number of connected clocks at the IP's top level ([1, 4]). */
#define TDM_CHIP_TOP_CLK_NR             4u
/* Replay functionality for transmitter. This functionality adds significant
   silicon area. */
#define TDM_TDM_TX_STRUCT_REPLAY_PRESENT 0u

/*******************************************************************************
*               TDM
*******************************************************************************/

#define TDM_STRUCT_Type                               TDM_TDM_STRUCT_Type
#define TDM_TX_STRUCT_Type                            TDM_TDM_STRUCT_TDM_TX_STRUCT_Type
#define TDM_RX_STRUCT_Type                            TDM_TDM_STRUCT_TDM_RX_STRUCT_Type
#define TDM_STRUCT0                                   TDM0_TDM_STRUCT0
#define TDM_STRUCT0_TX                                TDM0_TDM_STRUCT0_TDM_TX_STRUCT
#define TDM_STRUCT0_RX                                TDM0_TDM_STRUCT0_TDM_RX_STRUCT
#define TDM_STRUCT1                                   TDM1_TDM_STRUCT0
#define TDM_STRUCT1_TX                                TDM1_TDM_STRUCT0_TDM_TX_STRUCT
#define TDM_STRUCT1_RX                                TDM1_TDM_STRUCT0_TDM_RX_STRUCT
#define TDM_STRUCT_TX_CTL(base)                     (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_CTL)
#define TDM_STRUCT_TX_IF_CTL(base)                     (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_IF_CTL)
#define TDM_STRUCT_TX_CH_CTL(base)                     (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_CH_CTL)
#define TDM_STRUCT_TX_TEST_CTL(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_TEST_CTL)
#define TDM_STRUCT_TX_ROUTE_CTL(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_ROUTE_CTL)
#define TDM_STRUCT_TX_FIFO_CTL(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_FIFO_CTL)
#define TDM_STRUCT_TX_FIFO_STATUS(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_FIFO_STATUS)
#define TDM_STRUCT_TX_FIFO_WR(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->TX_FIFO_WR)
#define TDM_STRUCT_TX_INTR_TX(base)                 (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX)
#define TDM_STRUCT_TX_INTR_TX_SET(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX_SET)
#define TDM_STRUCT_TX_INTR_TX_MASK(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX_MASK)
#define TDM_STRUCT_TX_INTR_TX_MASKED(base)             (((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type *)(base))->INTR_TX_MASKED)

#define TDM_STRUCT_RX_CTL(base)                     (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_CTL)
#define TDM_STRUCT_RX_IF_CTL(base)                     (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_IF_CTL)
#define TDM_STRUCT_RX_CH_CTL(base)                     (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_CH_CTL)
#define TDM_STRUCT_RX_TEST_CTL(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_TEST_CTL)
#define TDM_STRUCT_RX_ROUTE_CTL(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_ROUTE_CTL)
#define TDM_STRUCT_RX_FIFO_CTL(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_CTL)
#define TDM_STRUCT_RX_FIFO_STATUS(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_STATUS)
#define TDM_STRUCT_RX_FIFO_RD(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_RD)
#define TDM_STRUCT_RX_FIFO_RD_SILENT(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->RX_FIFO_RD_SILENT)
#define TDM_STRUCT_RX_INTR_RX(base)                 (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX)
#define TDM_STRUCT_RX_INTR_RX_SET(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX_SET)
#define TDM_STRUCT_RX_INTR_RX_MASK(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX_MASK)
#define TDM_STRUCT_RX_INTR_RX_MASKED(base)             (((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type *)(base))->INTR_RX_MASKED)

#endif

#endif /* CY_PDL_DEVICE_H_ */

/* [] END OF FILE */
