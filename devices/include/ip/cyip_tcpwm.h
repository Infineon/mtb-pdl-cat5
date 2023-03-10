/***************************************************************************//**
* \file cyip_tcpwm.h
*
* \brief
* TCPWM IP definitions
*
* \note
* Generator version: 1.6.0.264
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

#ifndef _CYIP_TCPWM_H_
#define _CYIP_TCPWM_H_

#include "cy_pdl_wrapper.h"

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM_CNT_SECTION_SIZE                  0x00000040u
#define TCPWM_SECTION_SIZE                      0x00010000u

/**
  * \brief Timer/Counter/PWM Counter Module (TCPWM_CNT)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Counter control register */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Counter status register */
  __IOM uint32_t COUNTER;                       /*!< 0x00000008 Counter count register */
  __IOM uint32_t CC;                            /*!< 0x0000000C Counter compare/capture register */
  __IOM uint32_t CC_BUFF;                       /*!< 0x00000010 Counter buffered compare/capture register */
  __IOM uint32_t PERIOD;                        /*!< 0x00000014 Counter period register */
  __IOM uint32_t PERIOD_BUFF;                   /*!< 0x00000018 Counter buffered period register */
   __IM uint32_t RESERVED;
  __IOM uint32_t TR_CTRL0;                      /*!< 0x00000020 Counter trigger control register 0 */
  __IOM uint32_t TR_CTRL1;                      /*!< 0x00000024 Counter trigger control register 1 */
  __IOM uint32_t TR_CTRL2;                      /*!< 0x00000028 Counter trigger control register 2 */
   __IM uint32_t RESERVED1;
  __IOM uint32_t INTR;                          /*!< 0x00000030 Interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000034 Interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000038 Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000003C Interrupt masked request register */
} TCPWM_CNT_Type;                               /*!< Size = 64 (0x40) */

/**
  * \brief Timer/Counter/PWM (TCPWM)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 TCPWM control register */
  __IOM uint32_t CTRL_CLR;                      /*!< 0x00000004 TCPWM control clear register */
  __IOM uint32_t CTRL_SET;                      /*!< 0x00000008 TCPWM control set register */
  __IOM uint32_t CMD_CAPTURE;                   /*!< 0x0000000C TCPWM capture command register */
  __IOM uint32_t CMD_RELOAD;                    /*!< 0x00000010 TCPWM reload command register */
  __IOM uint32_t CMD_STOP;                      /*!< 0x00000014 TCPWM stop command register */
  __IOM uint32_t CMD_START;                     /*!< 0x00000018 TCPWM start command register */
   __IM uint32_t INTR_CAUSE;                    /*!< 0x0000001C TCPWM Counter interrupt cause register */
   __IM uint32_t RESERVED[56];
        TCPWM_CNT_Type CNT[32];                 /*!< 0x00000100 Timer/Counter/PWM Counter Module */
} TCPWM_Type;                                   /*!< Size = 2304 (0x900) */


/* TCPWM_CNT.CTRL */
#define TCPWM_CNT_CTRL_AUTO_RELOAD_CC_Pos       0u
#define TCPWM_CNT_CTRL_AUTO_RELOAD_CC_Msk       0x1u
#define TCPWM_CNT_CTRL_AUTO_RELOAD_PERIOD_Pos   1u
#define TCPWM_CNT_CTRL_AUTO_RELOAD_PERIOD_Msk   0x2u
#define TCPWM_CNT_CTRL_PWM_SYNC_KILL_Pos        2u
#define TCPWM_CNT_CTRL_PWM_SYNC_KILL_Msk        0x4u
#define TCPWM_CNT_CTRL_PWM_STOP_ON_KILL_Pos     3u
#define TCPWM_CNT_CTRL_PWM_STOP_ON_KILL_Msk     0x8u
#define TCPWM_CNT_CTRL_GENERIC_Pos              8u
#define TCPWM_CNT_CTRL_GENERIC_Msk              0xFF00u
#define TCPWM_CNT_CTRL_UP_DOWN_MODE_Pos         16u
#define TCPWM_CNT_CTRL_UP_DOWN_MODE_Msk         0x30000u
#define TCPWM_CNT_CTRL_ONE_SHOT_Pos             18u
#define TCPWM_CNT_CTRL_ONE_SHOT_Msk             0x40000u
#define TCPWM_CNT_CTRL_QUADRATURE_MODE_Pos      20u
#define TCPWM_CNT_CTRL_QUADRATURE_MODE_Msk      0x300000u
#define TCPWM_CNT_CTRL_MODE_Pos                 24u
#define TCPWM_CNT_CTRL_MODE_Msk                 0x7000000u
/* TCPWM_CNT.STATUS */
#define TCPWM_CNT_STATUS_DOWN_Pos               0u
#define TCPWM_CNT_STATUS_DOWN_Msk               0x1u
#define TCPWM_CNT_STATUS_GENERIC_Pos            8u
#define TCPWM_CNT_STATUS_GENERIC_Msk            0xFF00u
#define TCPWM_CNT_STATUS_RUNNING_Pos            31u
#define TCPWM_CNT_STATUS_RUNNING_Msk            0x80000000u
/* TCPWM_CNT.COUNTER */
#define TCPWM_CNT_COUNTER_COUNTER_Pos           0u
#define TCPWM_CNT_COUNTER_COUNTER_Msk           0xFFFFFFFFu
/* TCPWM_CNT.CC */
#define TCPWM_CNT_CC_CC_Pos                     0u
#define TCPWM_CNT_CC_CC_Msk                     0xFFFFFFFFu
/* TCPWM_CNT.CC_BUFF */
#define TCPWM_CNT_CC_BUFF_CC_Pos                0u
#define TCPWM_CNT_CC_BUFF_CC_Msk                0xFFFFFFFFu
/* TCPWM_CNT.PERIOD */
#define TCPWM_CNT_PERIOD_PERIOD_Pos             0u
#define TCPWM_CNT_PERIOD_PERIOD_Msk             0xFFFFFFFFu
/* TCPWM_CNT.PERIOD_BUFF */
#define TCPWM_CNT_PERIOD_BUFF_PERIOD_Pos        0u
#define TCPWM_CNT_PERIOD_BUFF_PERIOD_Msk        0xFFFFFFFFu
/* TCPWM_CNT.TR_CTRL0 */
#define TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Pos      0u
#define TCPWM_CNT_TR_CTRL0_CAPTURE_SEL_Msk      0xFu
#define TCPWM_CNT_TR_CTRL0_COUNT_SEL_Pos        4u
#define TCPWM_CNT_TR_CTRL0_COUNT_SEL_Msk        0xF0u
#define TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Pos       8u
#define TCPWM_CNT_TR_CTRL0_RELOAD_SEL_Msk       0xF00u
#define TCPWM_CNT_TR_CTRL0_STOP_SEL_Pos         12u
#define TCPWM_CNT_TR_CTRL0_STOP_SEL_Msk         0xF000u
#define TCPWM_CNT_TR_CTRL0_START_SEL_Pos        16u
#define TCPWM_CNT_TR_CTRL0_START_SEL_Msk        0xF0000u
/* TCPWM_CNT.TR_CTRL1 */
#define TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Pos     0u
#define TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE_Msk     0x3u
#define TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Pos       2u
#define TCPWM_CNT_TR_CTRL1_COUNT_EDGE_Msk       0xCu
#define TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Pos      4u
#define TCPWM_CNT_TR_CTRL1_RELOAD_EDGE_Msk      0x30u
#define TCPWM_CNT_TR_CTRL1_STOP_EDGE_Pos        6u
#define TCPWM_CNT_TR_CTRL1_STOP_EDGE_Msk        0xC0u
#define TCPWM_CNT_TR_CTRL1_START_EDGE_Pos       8u
#define TCPWM_CNT_TR_CTRL1_START_EDGE_Msk       0x300u
/* TCPWM_CNT.TR_CTRL2 */
#define TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Pos    0u
#define TCPWM_CNT_TR_CTRL2_CC_MATCH_MODE_Msk    0x3u
#define TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Pos    2u
#define TCPWM_CNT_TR_CTRL2_OVERFLOW_MODE_Msk    0xCu
#define TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Pos   4u
#define TCPWM_CNT_TR_CTRL2_UNDERFLOW_MODE_Msk   0x30u
/* TCPWM_CNT.INTR */
#define TCPWM_CNT_INTR_TC_Pos                   0u
#define TCPWM_CNT_INTR_TC_Msk                   0x1u
#define TCPWM_CNT_INTR_CC_MATCH_Pos             1u
#define TCPWM_CNT_INTR_CC_MATCH_Msk             0x2u
/* TCPWM_CNT.INTR_SET */
#define TCPWM_CNT_INTR_SET_TC_Pos               0u
#define TCPWM_CNT_INTR_SET_TC_Msk               0x1u
#define TCPWM_CNT_INTR_SET_CC_MATCH_Pos         1u
#define TCPWM_CNT_INTR_SET_CC_MATCH_Msk         0x2u
/* TCPWM_CNT.INTR_MASK */
#define TCPWM_CNT_INTR_MASK_TC_Pos              0u
#define TCPWM_CNT_INTR_MASK_TC_Msk              0x1u
#define TCPWM_CNT_INTR_MASK_CC_MATCH_Pos        1u
#define TCPWM_CNT_INTR_MASK_CC_MATCH_Msk        0x2u
/* TCPWM_CNT.INTR_MASKED */
#define TCPWM_CNT_INTR_MASKED_TC_Pos            0u
#define TCPWM_CNT_INTR_MASKED_TC_Msk            0x1u
#define TCPWM_CNT_INTR_MASKED_CC_MATCH_Pos      1u
#define TCPWM_CNT_INTR_MASKED_CC_MATCH_Msk      0x2u


/* TCPWM.CTRL */
#define TCPWM_CTRL_COUNTER_ENABLED_Pos          0u
#define TCPWM_CTRL_COUNTER_ENABLED_Msk          0xFFFFFFFFu
/* TCPWM.CTRL_CLR */
#define TCPWM_CTRL_CLR_COUNTER_ENABLED_Pos      0u
#define TCPWM_CTRL_CLR_COUNTER_ENABLED_Msk      0xFFFFFFFFu
/* TCPWM.CTRL_SET */
#define TCPWM_CTRL_SET_COUNTER_ENABLED_Pos      0u
#define TCPWM_CTRL_SET_COUNTER_ENABLED_Msk      0xFFFFFFFFu
/* TCPWM.CMD_CAPTURE */
#define TCPWM_CMD_CAPTURE_COUNTER_CAPTURE_Pos   0u
#define TCPWM_CMD_CAPTURE_COUNTER_CAPTURE_Msk   0xFFFFFFFFu
/* TCPWM.CMD_RELOAD */
#define TCPWM_CMD_RELOAD_COUNTER_RELOAD_Pos     0u
#define TCPWM_CMD_RELOAD_COUNTER_RELOAD_Msk     0xFFFFFFFFu
/* TCPWM.CMD_STOP */
#define TCPWM_CMD_STOP_COUNTER_STOP_Pos         0u
#define TCPWM_CMD_STOP_COUNTER_STOP_Msk         0xFFFFFFFFu
/* TCPWM.CMD_START */
#define TCPWM_CMD_START_COUNTER_START_Pos       0u
#define TCPWM_CMD_START_COUNTER_START_Msk       0xFFFFFFFFu
/* TCPWM.INTR_CAUSE */
#define TCPWM_INTR_CAUSE_COUNTER_INT_Pos        0u
#define TCPWM_INTR_CAUSE_COUNTER_INT_Msk        0xFFFFFFFFu


#endif /* _CYIP_TCPWM_H_ */


/* [] END OF FILE */
