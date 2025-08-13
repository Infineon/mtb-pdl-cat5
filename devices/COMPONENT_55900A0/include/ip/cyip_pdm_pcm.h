/***************************************************************************//**
* \file cyip_pdm_pcm.h
*
* \brief
* PDMPCM IP definitions
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

#ifndef _CYIP_PDM_PCM_H_
#define _CYIP_PDM_PCM_H_

#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

/**
  * \brief PDM PCM
  */
typedef struct {
    __IOM uint32_t CTRL_SEL;            /*!< 0x00000000 PDMPCM Control selection */
    __IOM uint32_t COEF1_SEL;           /*!< 0x00000004 BQ filters coefficients 1 selection*/
    __IOM uint32_t COEF2_SEL;           /*!< 0x00000008 BQ filters coefficients 2 selection */
    __IOM uint32_t COEF3_SEL;           /*!< 0x0000000C BQ filters coefficients 3 selection */
    __IOM uint32_t COEF4_SEL;           /*!< 0x00000010 BQ filters coefficients 4 selection */
    __IOM uint32_t COEF5_SEL;           /*!< 0x00000014 BQ filters coefficients 5 selection */
    __IOM uint32_t DF2_RAM_CTRL_SEL;    /*!< 0x00000018 DF2 RAM Control selection */
    __IM uint32_t STATUS;               /*!< 0x0000001C PDMPCM Status */
    __IOM uint32_t CLM_SEL;             /*!< 0x00000020 Clock mode Selection */
    __IOM uint32_t INF_CTRL_SEL;        /*!< 0x00000024 Interface(i.e. latch PDM data on which clock phase and sync +ve or -ve edge) selection */
} CyPdmPcm_Type;                        /*!< Size = 40 (0x28) */

//pdm2pcm ctrl sel
#define PDM_PCM_CTRL_SEL_PDM2PCM_EN_Pos         0u
#define PDM_PCM_CTRL_SEL_PDM2PCM_EN_Msk         0x1u
#define PDM_PCM_CTRL_SEL_CIC_SHIFT_Pos          1u
#define PDM_PCM_CTRL_SEL_CIC_SHIFT_Msk          0xE
#define PDM_PCM_CTRL_SEL_CIC_R_Pos              4u
#define PDM_PCM_CTRL_SEL_CIC_R_Msk              0x30u
#define PDM_PCM_CTRL_SEL_FILTER_SELECT_Pos      6u
#define PDM_PCM_CTRL_SEL_FILTER_SELECT_Msk      0x40u
#define PDM_PCM_CTRL_SEL_DF2_SEL_Pos            7u
#define PDM_PCM_CTRL_SEL_DF2_SEL_Msk            0x80u
#define PDM_PCM_CTRL_SEL_PDM2PCM_DEBUG_SEL_Pos  8u
#define PDM_PCM_CTRL_SEL_PDM2PCM_DEBUG_SEL_Msk  0x1F00u

//pdm2pcm bq coeff filter sel macros
#define PDM_PCM_COEFF_1_SEL_BQ1_A2_Pos          0u
#define PDM_PCM_COEFF_1_SEL_BQ1_A2_Msk          0xFFFFu
#define PDM_PCM_COEFF_1_SEL_BQ2_A2_Pos          16u
#define PDM_PCM_COEFF_1_SEL_BQ2_A2_Msk          0xFFFF0000u

#define PDM_PCM_COEFF_2_SEL_BQ1_A3_Pos          0u
#define PDM_PCM_COEFF_2_SEL_BQ1_A3_Msk          0xFFFFu
#define PDM_PCM_COEFF_2_SEL_BQ2_A3_Pos          16u
#define PDM_PCM_COEFF_2_SEL_BQ2_A3_Msk          0xFFFF0000u

#define PDM_PCM_COEFF_3_SEL_BQ1_B1_Pos          0u
#define PDM_PCM_COEFF_3_SEL_BQ1_B1_Msk          0xFFFFu
#define PDM_PCM_COEFF_3_SEL_BQ2_B1_Pos          16u
#define PDM_PCM_COEFF_3_SEL_BQ2_B1_Msk          0xFFFF0000u

#define PDM_PCM_COEFF_4_SEL_BQ1_B2_Pos          0u
#define PDM_PCM_COEFF_4_SEL_BQ1_B2_Msk          0xFFFFu
#define PDM_PCM_COEFF_4_SEL_BQ2_B2_Pos          16u
#define PDM_PCM_COEFF_4_SEL_BQ2_B2_Msk          0xFFFF0000u

#define PDM_PCM_COEFF_5_SEL_BQ1_B3_Pos          0u
#define PDM_PCM_COEFF_5_SEL_BQ1_B3_Msk          0xFFFFu
#define PDM_PCM_COEFF_5_SEL_BQ2_B3_Pos          16u
#define PDM_PCM_COEFF_5_SEL_BQ2_B3_Msk          0xFFFF0000u

//pdmpcm status register
#define PDM_CM_STATUS_SEL_DOUT_Pos              0u
#define PDM_CM_STATUS_SEL_DOUT_Msk              0xFFFFu
#define PDM_CM_STATUS_SEL_WREN_BACK_Pos         16u
#define PDM_CM_STATUS_SEL_WREN_BACK_Msk         0x10000u
#define PDM_CM_STATUS_SEL_RDEN_BACK_Pos         17u
#define PDM_CM_STATUS_SEL_RDEN_BACK_Msk         0x20000u

//pdmpcm clm sel
#define PDM_PCM_CLM_SEL_CLK_SEL_Pos             0u
#define PDM_PCM_CLM_SEL_CLK_SEL_Msk             0x3u
#define PDM_PCM_CLM_SEL_DMIC_CLK_EN_Pos         2u
#define PDM_PCM_CLM_SEL_DMIC_CLK_EN_Msk         0x4u
#define PDM_PCM_CLM_SEL_PDM_8M_CLK_EN_Pos       3u
#define PDM_PCM_CLM_SEL_PDM_8M_CLK_EN_Msk       0x8u
#define PDM_PCM_CLM_SEL_PDM_4M_CLK_EN_Pos       4u
#define PDM_PCM_CLM_SEL_PDM_4M_CLK_EN_Msk       0x10u
#define PDM_PCM_CLM_SEL_ADC_CLK_EN_Pos          5u
#define PDM_PCM_CLM_SEL_ADC_CLK_EN_Msk          0x20u
#define PDM_PCM_CLM_SEL_GPIO_ADC_CLK_EN_Pos     6u
#define PDM_PCM_CLM_SEL_GPIO_ADC_CLK_EN_Msk     0x40u
#define PDM_PCM_CLM_ADC_XTAL_CAL_CLK_EN_Pos     7u
#define PDM_PCM_CLM_ADC_XTAL_CAL_CLK_EN_Msk     0x80u

//pdm pcm inf ctrl
#define PDM_PCM_INF_CTRL_COUNT_PERIOD_Pos               0u
#define PDM_PCM_INF_CTRL_COUNT_PERIOD_msk               0xFu
#define PDM_PCM_INF_CTRL_PHASE_CHOSEN_NEG_Pos           4u
#define PDM_PCM_INF_CTRL_PHASE_CHOSEN_NEG_msk           0xF0u
#define PDM_PCM_INF_CTRL_PHASE_CHOSEN_POS_Pos           8u
#define PDM_PCM_INF_CTRL_PHASE_CHOSEN_POS_msk           0xF00u
#define PDM_PCM_INF_CTRL_ADC_OR_PDM_Pos                 12u
#define PDM_PCM_INF_CTRL_ADC_OR_PDM_msk                 0x1000u
#define PDM_PCM_INF_CTRL_CLK_INV_SEL_Pos                13u
#define PDM_PCM_INF_CTRL_CLK_INV_SEL_msk                0x2000u
#define PDM_PCM_INF_CTRL_POS_NEG_SEL_Pos                14u
#define PDM_PCM_INF_CTRL_POS_NEG_SEL_msk                0x4000u
#define PDM_PCM_INF_CTRL_POS_PDM_INT_EN_Pos             15u
#define PDM_PCM_INF_CTRL_POS_PDM_INT_EN_msk             0x8000u
#define PDM_PCM_INF_CTRL_NEG_PDM_INT_EN_Pos             16u
#define PDM_PCM_INF_CTRL_NEG_PDM_INT_EN_msk             0x10000u
#define PDM_PCM_INF_CTRL_POS_SYNC_EN_Pos                17u
#define PDM_PCM_INF_CTRL_POS_SYNC_EN_msk                0x20000u
#define PDM_PCM_INF_CTRL_NEG_SYNC_EN_Pos                18u
#define PDM_PCM_INF_CTRL_NEG_SYNC_EN_msk                0x40000u
#define PDM_PCM_INF_CTRL_POS_SYNC_OVERRIDE_Pos          19u
#define PDM_PCM_INF_CTRL_POS_SYNC_OVERRIDE_msk          0x80000u
#define PDM_PCM_INF_CTRL_POS_SYNC_OVERRIDE_VALUE_Pos    20u
#define PDM_PCM_INF_CTRL_POS_SYNC_OVERRIDE_VALUE_msk    0xF00000u
#define PDM_PCM_INF_CTRL_NEG_SYNC_OVERRIDE_Pos          24u
#define PDM_PCM_INF_CTRL_NEG_SYNC_OVERRIDE_msk          0x1000000u
#define PDM_PCM_INF_CTRL_NEG_SYNC_OVERRIDE_VALUE_Pos    25u
#define PDM_PCM_INF_CTRL_NEG_SYNC_OVERRIDE_VALUE_msk    0x1E000000u
#define PDM_PCM_INF_CTRL_ALLOW_POS_SYNC_Pos             29u
#define PDM_PCM_INF_CTRL_ALLOW_POS_SYNC_msk             0x20000000u
#define PDM_PCM_INF_CTRL_ALLOW_NEG_SYNC_Pos             30u
#define PDM_PCM_INF_CTRL_ALLOW_NEG_SYNC_msk             0x40000000u

#endif //_CYIP_PDM_PCM_H_

/* [] END OF FILE */

