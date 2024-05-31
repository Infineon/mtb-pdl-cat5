/***************************************************************************//**
* \file cyip_adccomp.h
*
* \brief
* ADCCOMP IP definitions
*
* \note
* Generator version: 1.6.0.409
*
********************************************************************************
* \copyright
* Copyright 2016-2020 Cypress Semiconductor Corporation
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

#ifndef _CYIP_ADCCOMP_H_
#define _CYIP_ADCCOMP_H_

#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

/*******************************************************************************
*                                     ADCCOMP
*******************************************************************************/

/**
  * \brief ADCCOMP Block (CyADCCOMP)
  */
typedef struct {
  __IOM uint32_t CIC_CTRL;                /*!< 0x00000000 Controls the operation of the CIC block */
  __IOM uint32_t CIC_GAIN;                /*!< 0x00000004 Controls the amount of gain for CIC operation */
  __IOM uint32_t CIC_STATUS;              /*!< 0x00000008 Computed CIC value */
  __IOM uint32_t ADC_CLOCK_CTRL;          /*!< 0x0000000C Control the clocks in the ADC block */
  __IOM uint32_t ADC_TST_CTRL;            /*!< 0x00000010 ADC Test Control */
   __IM uint32_t RESERVED[5];
  __IOM uint32_t ADC_CAL_CTRL_1;          /*!< 0x00000028 ADC calibration Control */
  __IOM uint32_t ADC_CAL_CTRL_2;          /*!< 0x0000002C ADC PGA(i.e. MIC Gain) Control */
   __IM uint32_t ADC_STATUS;               /*!< 0x00000030 Status of ADC */
  __IOM uint32_t LPCOMP_CTRL;             /*!< 0x00000034 Controls the operation of LPCOMP */
  __IOM uint32_t PD_CTRL;                 /*!< 0x00000038 Controls power down */
  __IOM uint32_t CLK_CTRL;                /*!< 0x0000003C Controls the clock generation in ADC */
  __IOM uint32_t PDM_DATA_CTRL;   /*!< 0x00000040 Controls the capture of pdm data from ADC */
  __IOM uint32_t CLK_M_N_CTRL;    /*!< 0x00000044 Controls the divide ratio for M/N Divider */
  __IOM uint32_t CLK_DIV_CTRL;    /*!< 0x00000048 Controls the divide ratio for programmable Divider */
  __IOM uint32_t TIMER_CTRL;      /*!< 0x0000004C Controls the timer */
  __IOM uint32_t PAD_CTRL;        /*!< 0x00000050 Controls the pad enables */
  __IM  uint32_t RESERVED1[43];
  __IOM uint32_t TRIGGER_CTRL;    /*!< 0x000000100 CIC Trigger control */
  __IOM uint32_t TRIGGER;         /*!< 0x000000104 Trigger */
   __IM uint32_t RESERVED2[1];
  __IOM uint32_t TRIGGER_SET;     /*!< 0x00000010C Trigger set */
  __IOM uint32_t INTR;            /*!< 0x000000110 Interrupt */
  __IOM uint32_t INTR_SET;        /*!< 0x000000114 Force Interrupt set. Debug purpose only */
  __IOM uint32_t INTR_MASK;       /*!< 0x000000118 Interrupt Mask */
   __IM uint32_t INTR_MASKED;      /*!< 0x00000011C Interrupt Masked. Equals to INTR & INTR_MASK */
} CyADCCOMP_Type;      /*!< Size = 34816 (0x8800). TBD Change this value as per above */


/* ADCCOMP LPCOMP CTRL */
#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_HYS_Pos                   0u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_HYS_Msk                   0xFu
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_HYS_Pos                   4u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_HYS_Msk                   0xF0u

#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_HYS_X2_Pos                8u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_HYS_X2_Msk                0x100u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_HYS_X2_Pos                9u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_HYS_X2_Msk                0x200u

#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_NTD_EN_Pos                10u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_NTD_EN_Msk                0x400u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_NTD_EN_Pos                11u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_NTD_EN_Msk                0x800u

#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_RST_OUTPUT_Pos            12u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP1_RST_OUTPUT_Msk            0x1000u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_RST_OUTPUT_Pos            13u
#define ADCCOMP_LPCOMP_CTRL_LPCOMP2_RST_OUTPUT_Msk            0x2000u

#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_Pos                    15u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_Msk                    0xFFFF8000u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_ADC_Pos                15u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_ADC_Msk                0xF8000u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP2_N_Pos            20u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP2_N_Msk            0x700000u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP2_P_Pos            23u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP2_P_Msk            0x3800000u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP1_N_Pos            26u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP1_N_Msk            0x1C000000u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP1_P_Pos            29u
#define ADCCOMP_LPCOMP_CTRL_AMUX_SEL_LPCOMP1_P_Msk            0xE0000000u

/* ADCCOMP PD CTRL */
#define ADCCOMP_PD_CTRL_PD_LPCOMP1_Pos                           0u
#define ADCCOMP_PD_CTRL_PD_LPCOMP1_Msk                           0x1u
#define ADCCOMP_PD_CTRL_PD_LPCOMP2_Pos                           1u
#define ADCCOMP_PD_CTRL_PD_LPCOMP2_Msk                           0x2u
#define ADCCOMP_PD_CTRL_PD_ADC_Pos                             2u
#define ADCCOMP_PD_CTRL_PD_ADC_Msk                             0x4u
#define ADCCOMP_PD_CTRL_PD_ADC_GMC_CAL_Pos                     3u
#define ADCCOMP_PD_CTRL_PD_ADC_GMC_CAL_Msk                     0x8u
#define ADCCOMP_PD_CTRL_PD_ADC_DC_CAL_Pos                      4u
#define ADCCOMP_PD_CTRL_PD_ADC_DC_CAL_Msk                      0x10u
#define ADCCOMP_PD_CTRL_PD_ADC_CLK_EN_Pos                      5u
#define ADCCOMP_PD_CTRL_PD_ADC_CLK_EN_Msk                      0x20u

/* ADCCOMP ADC CLOCK CTRL */
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_CLK_IN_DIV2_CTRL_Pos         0u
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_CLK_IN_DIV2_CTRL_Msk         0x1u
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_FS_2048_CTRL_Pos             1u
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_FS_2048_CTRL_Msk             0x2u
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_XTAL_CAL_CLK_EN_Pos          2u
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_XTAL_CAL_CLK_EN_Msk          0x4u
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_CAL_CLK_SEL_Pos              4u
#define ADCCOMP_ADC_CLOCK_CTRL_ADC_CAL_CLK_SEL_Msk              0xF0u

/* ADCCOMP ADC CAL CTRL 2 */
#define ADCCOMP_ADC_CAL_CTRL_2_ADC_PGA_CTRL_Pos                 0u
#define ADCCOMP_ADC_CAL_CTRL_2_ADC_PGA_CTRL_Msk                 0xFu

/* ADCCOMP INTR MASK */
#define ADCCOMP_INTR_MASK_INTR_LPCOMP1_Pos                    0u
#define ADCCOMP_INTR_MASK_INTR_LPCOMP1_Msk                    0x1u
#define ADCCOMP_INTR_MASK_INTR_LPCOMP2_Pos                    1u
#define ADCCOMP_INTR_MASK_INTR_LPCOMP2_Msk                    0x2u
#define ADCCOMP_INTR_MASK_INTR_CIC_Pos                      2u
#define ADCCOMP_INTR_MASK_INTR_CIC_Msk                      0x4u
#define ADCCOMP_INTR_MASK_INTR_TIMER_Pos                    3u
#define ADCCOMP_INTR_MASK_INTR_TIMER_Msk                    0x8u

#define ADCCOMP_TIMER_CTRL_TIMER_LIMIT_Pos                    0u
#define ADCCOMP_TIMER_CTRL_TIMER_LIMIT_Msk                    0xFFFFu
#define ADCCOMP_TIMER_CTRL_TIMER_INTR_SRC_Pos                 28u
#define ADCCOMP_TIMER_CTRL_TIMER_INTR_SRC_Msk                 0x10000000u
#define ADCCOMP_TIMER_CTRL_CLK_TIMER_GATE_OFF_Pos       29u
#define ADCCOMP_TIMER_CTRL_CLK_TIMER_GATE_OFF_Msk       0x20000000u
#define ADCCOMP_TIMER_CTRL_CLK_TIMER_SEL_Pos            30u
#define ADCCOMP_TIMER_CTRL_CLK_TIMER_SEL_Msk            0x40000000u
#define ADCCOMP_TIMER_CTRL_TIMER_EN_Pos            31u
#define ADCCOMP_TIMER_CTRL_TIMER_EN_Msk            0x80000000u

#define ADCCOMP_CIC_STATUS_CIC_Pos          0u
#define ADCCOMP_CIC_STATUS_CIC_Msk          0xFFFFu
#define ADCCOMP_CIC_STATUS_DC_OFFSET_Pos    16u
#define ADCCOMP_CIC_STATUS_DC_OFFSET_Msk    0xFFFF0000u

#endif /* _CYIP_ADCCOMP_H_ */


/* [] END OF FILE */
