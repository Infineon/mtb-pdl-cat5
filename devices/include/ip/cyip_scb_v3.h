/***************************************************************************//**
* \file cyip_scb_v3.h
*
* \brief
* SCB IP definitions
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

#ifndef _CYIP_SCB_V3_H_
#define _CYIP_SCB_V3_H_

#include "cy_pdl_wrapper.h"

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB_SECTION_SIZE                        0x00010000u

/**
  * \brief Serial Communications Block (SPI/UART/I2C) (CySCB)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Generic control */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Generic status */
  __IOM uint32_t CMD_RESP_CTRL;                 /*!< 0x00000008 Command/response control */
   __IM uint32_t CMD_RESP_STATUS;               /*!< 0x0000000C Command/response status */
   __IM uint32_t RESERVED[4];
  __IOM uint32_t SPI_CTRL;                      /*!< 0x00000020 SPI control */
   __IM uint32_t SPI_STATUS;                    /*!< 0x00000024 SPI status */
  __IOM uint32_t SPI_TX_CTRL;                   /*!< 0x00000028 SPI transmitter control */
  __IOM uint32_t SPI_RX_CTRL;                   /*!< 0x0000002C SPI receiver control */
   __IM uint32_t RESERVED1[4];
  __IOM uint32_t UART_CTRL;                     /*!< 0x00000040 UART control */
  __IOM uint32_t UART_TX_CTRL;                  /*!< 0x00000044 UART transmitter control */
  __IOM uint32_t UART_RX_CTRL;                  /*!< 0x00000048 UART receiver control */
   __IM uint32_t UART_RX_STATUS;                /*!< 0x0000004C UART receiver status */
  __IOM uint32_t UART_FLOW_CTRL;                /*!< 0x00000050 UART flow control */
   __IM uint32_t RESERVED2[3];
  __IOM uint32_t I2C_CTRL;                      /*!< 0x00000060 I2C control */
   __IM uint32_t I2C_STATUS;                    /*!< 0x00000064 I2C status */
  __IOM uint32_t I2C_M_CMD;                     /*!< 0x00000068 I2C master command */
  __IOM uint32_t I2C_S_CMD;                     /*!< 0x0000006C I2C slave command */
  __IOM uint32_t I2C_CFG;                       /*!< 0x00000070 I2C configuration */
  __IOM uint32_t I2C_STRETCH_CTRL;              /*!< 0x00000074 I2C stretch control */
   __IM uint32_t I2C_STRETCH_STATUS;            /*!< 0x00000078 I2C stretch status */
   __IM uint32_t RESERVED3;
  __IOM uint32_t I2C_CTRL_HS;                   /*!< 0x00000080 I2C control for High-Speed mode */
   __IM uint32_t RESERVED4[95];
  __IOM uint32_t TX_CTRL;                       /*!< 0x00000200 Transmitter control */
  __IOM uint32_t TX_FIFO_CTRL;                  /*!< 0x00000204 Transmitter FIFO control */
   __IM uint32_t TX_FIFO_STATUS;                /*!< 0x00000208 Transmitter FIFO status */
   __IM uint32_t RESERVED5[13];
   __OM uint32_t TX_FIFO_WR;                    /*!< 0x00000240 Transmitter FIFO write */
   __IM uint32_t RESERVED6[47];
  __IOM uint32_t RX_CTRL;                       /*!< 0x00000300 Receiver control */
  __IOM uint32_t RX_FIFO_CTRL;                  /*!< 0x00000304 Receiver FIFO control */
   __IM uint32_t RX_FIFO_STATUS;                /*!< 0x00000308 Receiver FIFO status */
   __IM uint32_t RESERVED7;
  __IOM uint32_t RX_MATCH;                      /*!< 0x00000310 Slave address and mask */
   __IM uint32_t RESERVED8[11];
   __IM uint32_t RX_FIFO_RD;                    /*!< 0x00000340 Receiver FIFO read */
   __IM uint32_t RX_FIFO_RD_SILENT;             /*!< 0x00000344 Receiver FIFO read silent */
   __IM uint32_t RESERVED9[46];
  __IOM uint32_t EZ_DATA[512];                  /*!< 0x00000400 Memory buffer */
   __IM uint32_t RESERVED10[128];
   __IM uint32_t INTR_CAUSE;                    /*!< 0x00000E00 Active clocked interrupt signal */
   __IM uint32_t RESERVED11[31];
  __IOM uint32_t INTR_I2C_EC;                   /*!< 0x00000E80 Externally clocked I2C interrupt request */
   __IM uint32_t RESERVED12;
  __IOM uint32_t INTR_I2C_EC_MASK;              /*!< 0x00000E88 Externally clocked I2C interrupt mask */
   __IM uint32_t INTR_I2C_EC_MASKED;            /*!< 0x00000E8C Externally clocked I2C interrupt masked */
   __IM uint32_t RESERVED13[12];
  __IOM uint32_t INTR_SPI_EC;                   /*!< 0x00000EC0 Externally clocked SPI interrupt request */
   __IM uint32_t RESERVED14;
  __IOM uint32_t INTR_SPI_EC_MASK;              /*!< 0x00000EC8 Externally clocked SPI interrupt mask */
   __IM uint32_t INTR_SPI_EC_MASKED;            /*!< 0x00000ECC Externally clocked SPI interrupt masked */
   __IM uint32_t RESERVED15[12];
  __IOM uint32_t INTR_M;                        /*!< 0x00000F00 Master interrupt request */
  __IOM uint32_t INTR_M_SET;                    /*!< 0x00000F04 Master interrupt set request */
  __IOM uint32_t INTR_M_MASK;                   /*!< 0x00000F08 Master interrupt mask */
   __IM uint32_t INTR_M_MASKED;                 /*!< 0x00000F0C Master interrupt masked request */
   __IM uint32_t RESERVED16[12];
  __IOM uint32_t INTR_S;                        /*!< 0x00000F40 Slave interrupt request */
  __IOM uint32_t INTR_S_SET;                    /*!< 0x00000F44 Slave interrupt set request */
  __IOM uint32_t INTR_S_MASK;                   /*!< 0x00000F48 Slave interrupt mask */
   __IM uint32_t INTR_S_MASKED;                 /*!< 0x00000F4C Slave interrupt masked request */
   __IM uint32_t RESERVED17[12];
  __IOM uint32_t INTR_TX;                       /*!< 0x00000F80 Transmitter interrupt request */
  __IOM uint32_t INTR_TX_SET;                   /*!< 0x00000F84 Transmitter interrupt set request */
  __IOM uint32_t INTR_TX_MASK;                  /*!< 0x00000F88 Transmitter interrupt mask */
   __IM uint32_t INTR_TX_MASKED;                /*!< 0x00000F8C Transmitter interrupt masked request */
   __IM uint32_t RESERVED18[12];
  __IOM uint32_t INTR_RX;                       /*!< 0x00000FC0 Receiver interrupt request */
  __IOM uint32_t INTR_RX_SET;                   /*!< 0x00000FC4 Receiver interrupt set request */
  __IOM uint32_t INTR_RX_MASK;                  /*!< 0x00000FC8 Receiver interrupt mask */
   __IM uint32_t INTR_RX_MASKED;                /*!< 0x00000FCC Receiver interrupt masked request */
} CySCB_V3_Type;                                   /*!< Size = 4048 (0xFD0) */


/* SCB.CTRL */
#define SCB_CTRL_OVS_Pos                        0u
#define SCB_CTRL_OVS_Msk                        0xFu
#define SCB_CTRL_EC_AM_MODE_Pos                 8u
#define SCB_CTRL_EC_AM_MODE_Msk                 0x100u
#define SCB_CTRL_EC_OP_MODE_Pos                 9u
#define SCB_CTRL_EC_OP_MODE_Msk                 0x200u
#define SCB_CTRL_EZ_MODE_Pos                    10u
#define SCB_CTRL_EZ_MODE_Msk                    0x400u
#define SCB_CTRL_CMD_RESP_MODE_Pos              12u
#define SCB_CTRL_CMD_RESP_MODE_Msk              0x1000u
#define SCB_CTRL_MEM_WIDTH_Pos                  14u
#define SCB_CTRL_MEM_WIDTH_Msk                  0xC000u
#define SCB_CTRL_ADDR_ACCEPT_Pos                16u
#define SCB_CTRL_ADDR_ACCEPT_Msk                0x10000u
#define SCB_CTRL_BLOCK_Pos                      17u
#define SCB_CTRL_BLOCK_Msk                      0x20000u
#define SCB_CTRL_MODE_Pos                       24u
#define SCB_CTRL_MODE_Msk                       0x3000000u
#define SCB_CTRL_EC_ACCESS_Pos                  28u
#define SCB_CTRL_EC_ACCESS_Msk                  0x10000000u
#define SCB_CTRL_ENABLED_Pos                    31u
#define SCB_CTRL_ENABLED_Msk                    0x80000000u
/* SCB.STATUS */
#define SCB_STATUS_EC_BUSY_Pos                  0u
#define SCB_STATUS_EC_BUSY_Msk                  0x1u
/* SCB.CMD_RESP_CTRL */
#define SCB_CMD_RESP_CTRL_BASE_RD_ADDR_Pos      0u
#define SCB_CMD_RESP_CTRL_BASE_RD_ADDR_Msk      0x1FFu
#define SCB_CMD_RESP_CTRL_BASE_WR_ADDR_Pos      16u
#define SCB_CMD_RESP_CTRL_BASE_WR_ADDR_Msk      0x1FF0000u
/* SCB.CMD_RESP_STATUS */
#define SCB_CMD_RESP_STATUS_CURR_RD_ADDR_Pos    0u
#define SCB_CMD_RESP_STATUS_CURR_RD_ADDR_Msk    0x1FFu
#define SCB_CMD_RESP_STATUS_CURR_WR_ADDR_Pos    16u
#define SCB_CMD_RESP_STATUS_CURR_WR_ADDR_Msk    0x1FF0000u
#define SCB_CMD_RESP_STATUS_CMD_RESP_EC_BUS_BUSY_Pos 30u
#define SCB_CMD_RESP_STATUS_CMD_RESP_EC_BUS_BUSY_Msk 0x40000000u
#define SCB_CMD_RESP_STATUS_CMD_RESP_EC_BUSY_Pos 31u
#define SCB_CMD_RESP_STATUS_CMD_RESP_EC_BUSY_Msk 0x80000000u
/* SCB.SPI_CTRL */
#define SCB_SPI_CTRL_SSEL_CONTINUOUS_Pos        0u
#define SCB_SPI_CTRL_SSEL_CONTINUOUS_Msk        0x1u
#define SCB_SPI_CTRL_SELECT_PRECEDE_Pos         1u
#define SCB_SPI_CTRL_SELECT_PRECEDE_Msk         0x2u
#define SCB_SPI_CTRL_CPHA_Pos                   2u
#define SCB_SPI_CTRL_CPHA_Msk                   0x4u
#define SCB_SPI_CTRL_CPOL_Pos                   3u
#define SCB_SPI_CTRL_CPOL_Msk                   0x8u
#define SCB_SPI_CTRL_LATE_MISO_SAMPLE_Pos       4u
#define SCB_SPI_CTRL_LATE_MISO_SAMPLE_Msk       0x10u
#define SCB_SPI_CTRL_SCLK_CONTINUOUS_Pos        5u
#define SCB_SPI_CTRL_SCLK_CONTINUOUS_Msk        0x20u
#define SCB_SPI_CTRL_SSEL_POLARITY0_Pos         8u
#define SCB_SPI_CTRL_SSEL_POLARITY0_Msk         0x100u
#define SCB_SPI_CTRL_SSEL_POLARITY1_Pos         9u
#define SCB_SPI_CTRL_SSEL_POLARITY1_Msk         0x200u
#define SCB_SPI_CTRL_SSEL_POLARITY2_Pos         10u
#define SCB_SPI_CTRL_SSEL_POLARITY2_Msk         0x400u
#define SCB_SPI_CTRL_SSEL_POLARITY3_Pos         11u
#define SCB_SPI_CTRL_SSEL_POLARITY3_Msk         0x800u
#define SCB_SPI_CTRL_SSEL_SETUP_DEL_Pos         12u
#define SCB_SPI_CTRL_SSEL_SETUP_DEL_Msk         0x1000u
#define SCB_SPI_CTRL_SSEL_HOLD_DEL_Pos          13u
#define SCB_SPI_CTRL_SSEL_HOLD_DEL_Msk          0x2000u
#define SCB_SPI_CTRL_SSEL_INTER_FRAME_DEL_Pos   14u
#define SCB_SPI_CTRL_SSEL_INTER_FRAME_DEL_Msk   0x4000u
#define SCB_SPI_CTRL_LOOPBACK_Pos               16u
#define SCB_SPI_CTRL_LOOPBACK_Msk               0x10000u
#define SCB_SPI_CTRL_MODE_Pos                   24u
#define SCB_SPI_CTRL_MODE_Msk                   0x3000000u
#define SCB_SPI_CTRL_SSEL_Pos                   26u
#define SCB_SPI_CTRL_SSEL_Msk                   0xC000000u
#define SCB_SPI_CTRL_MASTER_MODE_Pos            31u
#define SCB_SPI_CTRL_MASTER_MODE_Msk            0x80000000u
/* SCB.SPI_STATUS */
#define SCB_SPI_STATUS_BUS_BUSY_Pos             0u
#define SCB_SPI_STATUS_BUS_BUSY_Msk             0x1u
#define SCB_SPI_STATUS_SPI_EC_BUSY_Pos          1u
#define SCB_SPI_STATUS_SPI_EC_BUSY_Msk          0x2u
#define SCB_SPI_STATUS_CURR_EZ_ADDR_Pos         8u
#define SCB_SPI_STATUS_CURR_EZ_ADDR_Msk         0xFF00u
#define SCB_SPI_STATUS_BASE_EZ_ADDR_Pos         16u
#define SCB_SPI_STATUS_BASE_EZ_ADDR_Msk         0xFF0000u
/* SCB.SPI_TX_CTRL */
#define SCB_SPI_TX_CTRL_PARITY_Pos              4u
#define SCB_SPI_TX_CTRL_PARITY_Msk              0x10u
#define SCB_SPI_TX_CTRL_PARITY_ENABLED_Pos      5u
#define SCB_SPI_TX_CTRL_PARITY_ENABLED_Msk      0x20u
#define SCB_SPI_TX_CTRL_MOSI_IDLE_HIGH_Pos      16u
#define SCB_SPI_TX_CTRL_MOSI_IDLE_HIGH_Msk      0x10000u
/* SCB.SPI_RX_CTRL */
#define SCB_SPI_RX_CTRL_PARITY_Pos              4u
#define SCB_SPI_RX_CTRL_PARITY_Msk              0x10u
#define SCB_SPI_RX_CTRL_PARITY_ENABLED_Pos      5u
#define SCB_SPI_RX_CTRL_PARITY_ENABLED_Msk      0x20u
#define SCB_SPI_RX_CTRL_DROP_ON_PARITY_ERROR_Pos 8u
#define SCB_SPI_RX_CTRL_DROP_ON_PARITY_ERROR_Msk 0x100u
/* SCB.UART_CTRL */
#define SCB_UART_CTRL_LOOPBACK_Pos              16u
#define SCB_UART_CTRL_LOOPBACK_Msk              0x10000u
#define SCB_UART_CTRL_MODE_Pos                  24u
#define SCB_UART_CTRL_MODE_Msk                  0x3000000u
/* SCB.UART_TX_CTRL */
#define SCB_UART_TX_CTRL_STOP_BITS_Pos          0u
#define SCB_UART_TX_CTRL_STOP_BITS_Msk          0x7u
#define SCB_UART_TX_CTRL_PARITY_Pos             4u
#define SCB_UART_TX_CTRL_PARITY_Msk             0x10u
#define SCB_UART_TX_CTRL_PARITY_ENABLED_Pos     5u
#define SCB_UART_TX_CTRL_PARITY_ENABLED_Msk     0x20u
#define SCB_UART_TX_CTRL_RETRY_ON_NACK_Pos      8u
#define SCB_UART_TX_CTRL_RETRY_ON_NACK_Msk      0x100u
/* SCB.UART_RX_CTRL */
#define SCB_UART_RX_CTRL_STOP_BITS_Pos          0u
#define SCB_UART_RX_CTRL_STOP_BITS_Msk          0x7u
#define SCB_UART_RX_CTRL_PARITY_Pos             4u
#define SCB_UART_RX_CTRL_PARITY_Msk             0x10u
#define SCB_UART_RX_CTRL_PARITY_ENABLED_Pos     5u
#define SCB_UART_RX_CTRL_PARITY_ENABLED_Msk     0x20u
#define SCB_UART_RX_CTRL_POLARITY_Pos           6u
#define SCB_UART_RX_CTRL_POLARITY_Msk           0x40u
#define SCB_UART_RX_CTRL_DROP_ON_PARITY_ERROR_Pos 8u
#define SCB_UART_RX_CTRL_DROP_ON_PARITY_ERROR_Msk 0x100u
#define SCB_UART_RX_CTRL_DROP_ON_FRAME_ERROR_Pos 9u
#define SCB_UART_RX_CTRL_DROP_ON_FRAME_ERROR_Msk 0x200u
#define SCB_UART_RX_CTRL_MP_MODE_Pos            10u
#define SCB_UART_RX_CTRL_MP_MODE_Msk            0x400u
#define SCB_UART_RX_CTRL_LIN_MODE_Pos           12u
#define SCB_UART_RX_CTRL_LIN_MODE_Msk           0x1000u
#define SCB_UART_RX_CTRL_SKIP_START_Pos         13u
#define SCB_UART_RX_CTRL_SKIP_START_Msk         0x2000u
#define SCB_UART_RX_CTRL_BREAK_WIDTH_Pos        16u
#define SCB_UART_RX_CTRL_BREAK_WIDTH_Msk        0xF0000u
#define SCB_UART_RX_CTRL_BREAK_LEVEL_Pos        24u
#define SCB_UART_RX_CTRL_BREAK_LEVEL_Msk        0x1000000u
/* SCB.UART_RX_STATUS */
#define SCB_UART_RX_STATUS_BR_COUNTER_Pos       0u
#define SCB_UART_RX_STATUS_BR_COUNTER_Msk       0xFFFu
/* SCB.UART_FLOW_CTRL */
#define SCB_UART_FLOW_CTRL_TRIGGER_LEVEL_Pos    0u
#define SCB_UART_FLOW_CTRL_TRIGGER_LEVEL_Msk    0xFFu
#define SCB_UART_FLOW_CTRL_RTS_POLARITY_Pos     16u
#define SCB_UART_FLOW_CTRL_RTS_POLARITY_Msk     0x10000u
#define SCB_UART_FLOW_CTRL_CTS_POLARITY_Pos     24u
#define SCB_UART_FLOW_CTRL_CTS_POLARITY_Msk     0x1000000u
#define SCB_UART_FLOW_CTRL_CTS_ENABLED_Pos      25u
#define SCB_UART_FLOW_CTRL_CTS_ENABLED_Msk      0x2000000u
/* SCB.I2C_CTRL */
#define SCB_I2C_CTRL_HIGH_PHASE_OVS_Pos         0u
#define SCB_I2C_CTRL_HIGH_PHASE_OVS_Msk         0xFu
#define SCB_I2C_CTRL_LOW_PHASE_OVS_Pos          4u
#define SCB_I2C_CTRL_LOW_PHASE_OVS_Msk          0xF0u
#define SCB_I2C_CTRL_M_READY_DATA_ACK_Pos       8u
#define SCB_I2C_CTRL_M_READY_DATA_ACK_Msk       0x100u
#define SCB_I2C_CTRL_M_NOT_READY_DATA_NACK_Pos  9u
#define SCB_I2C_CTRL_M_NOT_READY_DATA_NACK_Msk  0x200u
#define SCB_I2C_CTRL_S_GENERAL_IGNORE_Pos       11u
#define SCB_I2C_CTRL_S_GENERAL_IGNORE_Msk       0x800u
#define SCB_I2C_CTRL_S_READY_ADDR_ACK_Pos       12u
#define SCB_I2C_CTRL_S_READY_ADDR_ACK_Msk       0x1000u
#define SCB_I2C_CTRL_S_READY_DATA_ACK_Pos       13u
#define SCB_I2C_CTRL_S_READY_DATA_ACK_Msk       0x2000u
#define SCB_I2C_CTRL_S_NOT_READY_ADDR_NACK_Pos  14u
#define SCB_I2C_CTRL_S_NOT_READY_ADDR_NACK_Msk  0x4000u
#define SCB_I2C_CTRL_S_NOT_READY_DATA_NACK_Pos  15u
#define SCB_I2C_CTRL_S_NOT_READY_DATA_NACK_Msk  0x8000u
#define SCB_I2C_CTRL_LOOPBACK_Pos               16u
#define SCB_I2C_CTRL_LOOPBACK_Msk               0x10000u
#define SCB_I2C_CTRL_SLAVE_MODE_Pos             30u
#define SCB_I2C_CTRL_SLAVE_MODE_Msk             0x40000000u
#define SCB_I2C_CTRL_MASTER_MODE_Pos            31u
#define SCB_I2C_CTRL_MASTER_MODE_Msk            0x80000000u
/* SCB.I2C_STATUS */
#define SCB_I2C_STATUS_BUS_BUSY_Pos             0u
#define SCB_I2C_STATUS_BUS_BUSY_Msk             0x1u
#define SCB_I2C_STATUS_I2C_EC_BUSY_Pos          1u
#define SCB_I2C_STATUS_I2C_EC_BUSY_Msk          0x2u
#define SCB_I2C_STATUS_I2CS_IC_BUSY_Pos         2u
#define SCB_I2C_STATUS_I2CS_IC_BUSY_Msk         0x4u
#define SCB_I2C_STATUS_S_READ_Pos               4u
#define SCB_I2C_STATUS_S_READ_Msk               0x10u
#define SCB_I2C_STATUS_M_READ_Pos               5u
#define SCB_I2C_STATUS_M_READ_Msk               0x20u
#define SCB_I2C_STATUS_CURR_EZ_ADDR_Pos         8u
#define SCB_I2C_STATUS_CURR_EZ_ADDR_Msk         0xFF00u
#define SCB_I2C_STATUS_BASE_EZ_ADDR_Pos         16u
#define SCB_I2C_STATUS_BASE_EZ_ADDR_Msk         0xFF0000u
#define SCB_I2C_STATUS_HS_MODE_Pos              24u
#define SCB_I2C_STATUS_HS_MODE_Msk              0x1000000u
/* SCB.I2C_M_CMD */
#define SCB_I2C_M_CMD_M_START_Pos               0u
#define SCB_I2C_M_CMD_M_START_Msk               0x1u
#define SCB_I2C_M_CMD_M_START_ON_IDLE_Pos       1u
#define SCB_I2C_M_CMD_M_START_ON_IDLE_Msk       0x2u
#define SCB_I2C_M_CMD_M_ACK_Pos                 2u
#define SCB_I2C_M_CMD_M_ACK_Msk                 0x4u
#define SCB_I2C_M_CMD_M_NACK_Pos                3u
#define SCB_I2C_M_CMD_M_NACK_Msk                0x8u
#define SCB_I2C_M_CMD_M_STOP_Pos                4u
#define SCB_I2C_M_CMD_M_STOP_Msk                0x10u
/* SCB.I2C_S_CMD */
#define SCB_I2C_S_CMD_S_ACK_Pos                 0u
#define SCB_I2C_S_CMD_S_ACK_Msk                 0x1u
#define SCB_I2C_S_CMD_S_NACK_Pos                1u
#define SCB_I2C_S_CMD_S_NACK_Msk                0x2u
#define SCB_I2C_S_CMD_S_TX_ONES_ON_EMPTY_Pos    2u
#define SCB_I2C_S_CMD_S_TX_ONES_ON_EMPTY_Msk    0x4u
#define SCB_I2C_S_CMD_S_STRETCH_HS_Pos          8u
#define SCB_I2C_S_CMD_S_STRETCH_HS_Msk          0x100u
/* SCB.I2C_CFG */
#define SCB_I2C_CFG_SDA_IN_FILT_TRIM_Pos        0u
#define SCB_I2C_CFG_SDA_IN_FILT_TRIM_Msk        0x3u
#define SCB_I2C_CFG_SDA_IN_FILT_SEL_Pos         4u
#define SCB_I2C_CFG_SDA_IN_FILT_SEL_Msk         0x10u
#define SCB_I2C_CFG_SCL_IN_FILT_TRIM_Pos        8u
#define SCB_I2C_CFG_SCL_IN_FILT_TRIM_Msk        0x300u
#define SCB_I2C_CFG_SCL_IN_FILT_SEL_Pos         12u
#define SCB_I2C_CFG_SCL_IN_FILT_SEL_Msk         0x1000u
#define SCB_I2C_CFG_SDA_OUT_FILT0_TRIM_Pos      16u
#define SCB_I2C_CFG_SDA_OUT_FILT0_TRIM_Msk      0x30000u
#define SCB_I2C_CFG_SDA_OUT_FILT1_TRIM_Pos      18u
#define SCB_I2C_CFG_SDA_OUT_FILT1_TRIM_Msk      0xC0000u
#define SCB_I2C_CFG_SDA_OUT_FILT2_TRIM_Pos      20u
#define SCB_I2C_CFG_SDA_OUT_FILT2_TRIM_Msk      0x300000u
#define SCB_I2C_CFG_SDA_OUT_FILT_SEL_Pos        28u
#define SCB_I2C_CFG_SDA_OUT_FILT_SEL_Msk        0x30000000u
/* SCB.I2C_STRETCH_CTRL */
#define SCB_I2C_STRETCH_CTRL_STRETCH_THRESHOLD_Pos 0u
#define SCB_I2C_STRETCH_CTRL_STRETCH_THRESHOLD_Msk 0xFu
/* SCB.I2C_STRETCH_STATUS */
#define SCB_I2C_STRETCH_STATUS_STRETCH_COUNT_Pos 0u
#define SCB_I2C_STRETCH_STATUS_STRETCH_COUNT_Msk 0xFu
#define SCB_I2C_STRETCH_STATUS_STRETCH_DETECTED_Pos 4u
#define SCB_I2C_STRETCH_STATUS_STRETCH_DETECTED_Msk 0x10u
#define SCB_I2C_STRETCH_STATUS_SYNC_DETECTED_Pos 5u
#define SCB_I2C_STRETCH_STATUS_SYNC_DETECTED_Msk 0x20u
#define SCB_I2C_STRETCH_STATUS_STRETCHING_Pos   8u
#define SCB_I2C_STRETCH_STATUS_STRETCHING_Msk   0x100u
/* SCB.I2C_CTRL_HS */
#define SCB_I2C_CTRL_HS_HOVS_HS_Pos             0u
#define SCB_I2C_CTRL_HS_HOVS_HS_Msk             0xFu
#define SCB_I2C_CTRL_HS_LOVS_HS_Pos             4u
#define SCB_I2C_CTRL_HS_LOVS_HS_Msk             0xF0u
#define SCB_I2C_CTRL_HS_HS_ENABLED_Pos          31u
#define SCB_I2C_CTRL_HS_HS_ENABLED_Msk          0x80000000u
/* SCB.TX_CTRL */
#define SCB_TX_CTRL_DATA_WIDTH_Pos              0u
#define SCB_TX_CTRL_DATA_WIDTH_Msk              0x1Fu
#define SCB_TX_CTRL_MSB_FIRST_Pos               8u
#define SCB_TX_CTRL_MSB_FIRST_Msk               0x100u
#define SCB_TX_CTRL_OPEN_DRAIN_Pos              16u
#define SCB_TX_CTRL_OPEN_DRAIN_Msk              0x10000u
#define SCB_TX_CTRL_OPEN_DRAIN_SCL_Pos          17u
#define SCB_TX_CTRL_OPEN_DRAIN_SCL_Msk          0x20000u
/* SCB.TX_FIFO_CTRL */
#define SCB_TX_FIFO_CTRL_TRIGGER_LEVEL_Pos      0u
#define SCB_TX_FIFO_CTRL_TRIGGER_LEVEL_Msk      0xFFu
#define SCB_TX_FIFO_CTRL_CLEAR_Pos              16u
#define SCB_TX_FIFO_CTRL_CLEAR_Msk              0x10000u
#define SCB_TX_FIFO_CTRL_FREEZE_Pos             17u
#define SCB_TX_FIFO_CTRL_FREEZE_Msk             0x20000u
/* SCB.TX_FIFO_STATUS */
#define SCB_TX_FIFO_STATUS_USED_Pos             0u
#define SCB_TX_FIFO_STATUS_USED_Msk             0x1FFu
#define SCB_TX_FIFO_STATUS_SR_VALID_Pos         15u
#define SCB_TX_FIFO_STATUS_SR_VALID_Msk         0x8000u
#define SCB_TX_FIFO_STATUS_RD_PTR_Pos           16u
#define SCB_TX_FIFO_STATUS_RD_PTR_Msk           0xFF0000u
#define SCB_TX_FIFO_STATUS_WR_PTR_Pos           24u
#define SCB_TX_FIFO_STATUS_WR_PTR_Msk           0xFF000000u
/* SCB.TX_FIFO_WR */
#define SCB_TX_FIFO_WR_DATA_Pos                 0u
#define SCB_TX_FIFO_WR_DATA_Msk                 0xFFFFFFFFu
/* SCB.RX_CTRL */
#define SCB_RX_CTRL_DATA_WIDTH_Pos              0u
#define SCB_RX_CTRL_DATA_WIDTH_Msk              0x1Fu
#define SCB_RX_CTRL_MSB_FIRST_Pos               8u
#define SCB_RX_CTRL_MSB_FIRST_Msk               0x100u
#define SCB_RX_CTRL_MEDIAN_Pos                  9u
#define SCB_RX_CTRL_MEDIAN_Msk                  0x200u
/* SCB.RX_FIFO_CTRL */
#define SCB_RX_FIFO_CTRL_TRIGGER_LEVEL_Pos      0u
#define SCB_RX_FIFO_CTRL_TRIGGER_LEVEL_Msk      0xFFu
#define SCB_RX_FIFO_CTRL_CLEAR_Pos              16u
#define SCB_RX_FIFO_CTRL_CLEAR_Msk              0x10000u
#define SCB_RX_FIFO_CTRL_FREEZE_Pos             17u
#define SCB_RX_FIFO_CTRL_FREEZE_Msk             0x20000u
/* SCB.RX_FIFO_STATUS */
#define SCB_RX_FIFO_STATUS_USED_Pos             0u
#define SCB_RX_FIFO_STATUS_USED_Msk             0x1FFu
#define SCB_RX_FIFO_STATUS_SR_VALID_Pos         15u
#define SCB_RX_FIFO_STATUS_SR_VALID_Msk         0x8000u
#define SCB_RX_FIFO_STATUS_RD_PTR_Pos           16u
#define SCB_RX_FIFO_STATUS_RD_PTR_Msk           0xFF0000u
#define SCB_RX_FIFO_STATUS_WR_PTR_Pos           24u
#define SCB_RX_FIFO_STATUS_WR_PTR_Msk           0xFF000000u
/* SCB.RX_MATCH */
#define SCB_RX_MATCH_ADDR_Pos                   0u
#define SCB_RX_MATCH_ADDR_Msk                   0xFFu
#define SCB_RX_MATCH_MASK_Pos                   16u
#define SCB_RX_MATCH_MASK_Msk                   0xFF0000u
/* SCB.RX_FIFO_RD */
#define SCB_RX_FIFO_RD_DATA_Pos                 0u
#define SCB_RX_FIFO_RD_DATA_Msk                 0xFFFFFFFFu
/* SCB.RX_FIFO_RD_SILENT */
#define SCB_RX_FIFO_RD_SILENT_DATA_Pos          0u
#define SCB_RX_FIFO_RD_SILENT_DATA_Msk          0xFFFFFFFFu
/* SCB.EZ_DATA */
#define SCB_EZ_DATA_EZ_DATA_Pos                 0u
#define SCB_EZ_DATA_EZ_DATA_Msk                 0xFFu
/* SCB.INTR_CAUSE */
#define SCB_INTR_CAUSE_M_Pos                    0u
#define SCB_INTR_CAUSE_M_Msk                    0x1u
#define SCB_INTR_CAUSE_S_Pos                    1u
#define SCB_INTR_CAUSE_S_Msk                    0x2u
#define SCB_INTR_CAUSE_TX_Pos                   2u
#define SCB_INTR_CAUSE_TX_Msk                   0x4u
#define SCB_INTR_CAUSE_RX_Pos                   3u
#define SCB_INTR_CAUSE_RX_Msk                   0x8u
#define SCB_INTR_CAUSE_I2C_EC_Pos               4u
#define SCB_INTR_CAUSE_I2C_EC_Msk               0x10u
#define SCB_INTR_CAUSE_SPI_EC_Pos               5u
#define SCB_INTR_CAUSE_SPI_EC_Msk               0x20u
/* SCB.INTR_I2C_EC */
#define SCB_INTR_I2C_EC_WAKE_UP_Pos             0u
#define SCB_INTR_I2C_EC_WAKE_UP_Msk             0x1u
#define SCB_INTR_I2C_EC_EZ_STOP_Pos             1u
#define SCB_INTR_I2C_EC_EZ_STOP_Msk             0x2u
#define SCB_INTR_I2C_EC_EZ_WRITE_STOP_Pos       2u
#define SCB_INTR_I2C_EC_EZ_WRITE_STOP_Msk       0x4u
#define SCB_INTR_I2C_EC_EZ_READ_STOP_Pos        3u
#define SCB_INTR_I2C_EC_EZ_READ_STOP_Msk        0x8u
/* SCB.INTR_I2C_EC_MASK */
#define SCB_INTR_I2C_EC_MASK_WAKE_UP_Pos        0u
#define SCB_INTR_I2C_EC_MASK_WAKE_UP_Msk        0x1u
#define SCB_INTR_I2C_EC_MASK_EZ_STOP_Pos        1u
#define SCB_INTR_I2C_EC_MASK_EZ_STOP_Msk        0x2u
#define SCB_INTR_I2C_EC_MASK_EZ_WRITE_STOP_Pos  2u
#define SCB_INTR_I2C_EC_MASK_EZ_WRITE_STOP_Msk  0x4u
#define SCB_INTR_I2C_EC_MASK_EZ_READ_STOP_Pos   3u
#define SCB_INTR_I2C_EC_MASK_EZ_READ_STOP_Msk   0x8u
/* SCB.INTR_I2C_EC_MASKED */
#define SCB_INTR_I2C_EC_MASKED_WAKE_UP_Pos      0u
#define SCB_INTR_I2C_EC_MASKED_WAKE_UP_Msk      0x1u
#define SCB_INTR_I2C_EC_MASKED_EZ_STOP_Pos      1u
#define SCB_INTR_I2C_EC_MASKED_EZ_STOP_Msk      0x2u
#define SCB_INTR_I2C_EC_MASKED_EZ_WRITE_STOP_Pos 2u
#define SCB_INTR_I2C_EC_MASKED_EZ_WRITE_STOP_Msk 0x4u
#define SCB_INTR_I2C_EC_MASKED_EZ_READ_STOP_Pos 3u
#define SCB_INTR_I2C_EC_MASKED_EZ_READ_STOP_Msk 0x8u
/* SCB.INTR_SPI_EC */
#define SCB_INTR_SPI_EC_WAKE_UP_Pos             0u
#define SCB_INTR_SPI_EC_WAKE_UP_Msk             0x1u
#define SCB_INTR_SPI_EC_EZ_STOP_Pos             1u
#define SCB_INTR_SPI_EC_EZ_STOP_Msk             0x2u
#define SCB_INTR_SPI_EC_EZ_WRITE_STOP_Pos       2u
#define SCB_INTR_SPI_EC_EZ_WRITE_STOP_Msk       0x4u
#define SCB_INTR_SPI_EC_EZ_READ_STOP_Pos        3u
#define SCB_INTR_SPI_EC_EZ_READ_STOP_Msk        0x8u
/* SCB.INTR_SPI_EC_MASK */
#define SCB_INTR_SPI_EC_MASK_WAKE_UP_Pos        0u
#define SCB_INTR_SPI_EC_MASK_WAKE_UP_Msk        0x1u
#define SCB_INTR_SPI_EC_MASK_EZ_STOP_Pos        1u
#define SCB_INTR_SPI_EC_MASK_EZ_STOP_Msk        0x2u
#define SCB_INTR_SPI_EC_MASK_EZ_WRITE_STOP_Pos  2u
#define SCB_INTR_SPI_EC_MASK_EZ_WRITE_STOP_Msk  0x4u
#define SCB_INTR_SPI_EC_MASK_EZ_READ_STOP_Pos   3u
#define SCB_INTR_SPI_EC_MASK_EZ_READ_STOP_Msk   0x8u
/* SCB.INTR_SPI_EC_MASKED */
#define SCB_INTR_SPI_EC_MASKED_WAKE_UP_Pos      0u
#define SCB_INTR_SPI_EC_MASKED_WAKE_UP_Msk      0x1u
#define SCB_INTR_SPI_EC_MASKED_EZ_STOP_Pos      1u
#define SCB_INTR_SPI_EC_MASKED_EZ_STOP_Msk      0x2u
#define SCB_INTR_SPI_EC_MASKED_EZ_WRITE_STOP_Pos 2u
#define SCB_INTR_SPI_EC_MASKED_EZ_WRITE_STOP_Msk 0x4u
#define SCB_INTR_SPI_EC_MASKED_EZ_READ_STOP_Pos 3u
#define SCB_INTR_SPI_EC_MASKED_EZ_READ_STOP_Msk 0x8u
/* SCB.INTR_M */
#define SCB_INTR_M_I2C_ARB_LOST_Pos             0u
#define SCB_INTR_M_I2C_ARB_LOST_Msk             0x1u
#define SCB_INTR_M_I2C_NACK_Pos                 1u
#define SCB_INTR_M_I2C_NACK_Msk                 0x2u
#define SCB_INTR_M_I2C_ACK_Pos                  2u
#define SCB_INTR_M_I2C_ACK_Msk                  0x4u
#define SCB_INTR_M_I2C_STOP_Pos                 4u
#define SCB_INTR_M_I2C_STOP_Msk                 0x10u
#define SCB_INTR_M_I2C_BUS_ERROR_Pos            8u
#define SCB_INTR_M_I2C_BUS_ERROR_Msk            0x100u
#define SCB_INTR_M_SPI_DONE_Pos                 9u
#define SCB_INTR_M_SPI_DONE_Msk                 0x200u
#define SCB_INTR_M_I2C_HS_ENTER_Pos             24u
#define SCB_INTR_M_I2C_HS_ENTER_Msk             0x1000000u
#define SCB_INTR_M_I2C_HS_EXIT_Pos              25u
#define SCB_INTR_M_I2C_HS_EXIT_Msk              0x2000000u
/* SCB.INTR_M_SET */
#define SCB_INTR_M_SET_I2C_ARB_LOST_Pos         0u
#define SCB_INTR_M_SET_I2C_ARB_LOST_Msk         0x1u
#define SCB_INTR_M_SET_I2C_NACK_Pos             1u
#define SCB_INTR_M_SET_I2C_NACK_Msk             0x2u
#define SCB_INTR_M_SET_I2C_ACK_Pos              2u
#define SCB_INTR_M_SET_I2C_ACK_Msk              0x4u
#define SCB_INTR_M_SET_I2C_STOP_Pos             4u
#define SCB_INTR_M_SET_I2C_STOP_Msk             0x10u
#define SCB_INTR_M_SET_I2C_BUS_ERROR_Pos        8u
#define SCB_INTR_M_SET_I2C_BUS_ERROR_Msk        0x100u
#define SCB_INTR_M_SET_SPI_DONE_Pos             9u
#define SCB_INTR_M_SET_SPI_DONE_Msk             0x200u
#define SCB_INTR_M_SET_I2C_HS_ENTER_Pos         24u
#define SCB_INTR_M_SET_I2C_HS_ENTER_Msk         0x1000000u
#define SCB_INTR_M_SET_I2C_HS_EXIT_Pos          25u
#define SCB_INTR_M_SET_I2C_HS_EXIT_Msk          0x2000000u
/* SCB.INTR_M_MASK */
#define SCB_INTR_M_MASK_I2C_ARB_LOST_Pos        0u
#define SCB_INTR_M_MASK_I2C_ARB_LOST_Msk        0x1u
#define SCB_INTR_M_MASK_I2C_NACK_Pos            1u
#define SCB_INTR_M_MASK_I2C_NACK_Msk            0x2u
#define SCB_INTR_M_MASK_I2C_ACK_Pos             2u
#define SCB_INTR_M_MASK_I2C_ACK_Msk             0x4u
#define SCB_INTR_M_MASK_I2C_STOP_Pos            4u
#define SCB_INTR_M_MASK_I2C_STOP_Msk            0x10u
#define SCB_INTR_M_MASK_I2C_BUS_ERROR_Pos       8u
#define SCB_INTR_M_MASK_I2C_BUS_ERROR_Msk       0x100u
#define SCB_INTR_M_MASK_SPI_DONE_Pos            9u
#define SCB_INTR_M_MASK_SPI_DONE_Msk            0x200u
#define SCB_INTR_M_MASK_I2C_HS_ENTER_Pos        24u
#define SCB_INTR_M_MASK_I2C_HS_ENTER_Msk        0x1000000u
#define SCB_INTR_M_MASK_I2C_HS_EXIT_Pos         25u
#define SCB_INTR_M_MASK_I2C_HS_EXIT_Msk         0x2000000u
/* SCB.INTR_M_MASKED */
#define SCB_INTR_M_MASKED_I2C_ARB_LOST_Pos      0u
#define SCB_INTR_M_MASKED_I2C_ARB_LOST_Msk      0x1u
#define SCB_INTR_M_MASKED_I2C_NACK_Pos          1u
#define SCB_INTR_M_MASKED_I2C_NACK_Msk          0x2u
#define SCB_INTR_M_MASKED_I2C_ACK_Pos           2u
#define SCB_INTR_M_MASKED_I2C_ACK_Msk           0x4u
#define SCB_INTR_M_MASKED_I2C_STOP_Pos          4u
#define SCB_INTR_M_MASKED_I2C_STOP_Msk          0x10u
#define SCB_INTR_M_MASKED_I2C_BUS_ERROR_Pos     8u
#define SCB_INTR_M_MASKED_I2C_BUS_ERROR_Msk     0x100u
#define SCB_INTR_M_MASKED_SPI_DONE_Pos          9u
#define SCB_INTR_M_MASKED_SPI_DONE_Msk          0x200u
#define SCB_INTR_M_MASKED_I2C_HS_ENTER_Pos      24u
#define SCB_INTR_M_MASKED_I2C_HS_ENTER_Msk      0x1000000u
#define SCB_INTR_M_MASKED_I2C_HS_EXIT_Pos       25u
#define SCB_INTR_M_MASKED_I2C_HS_EXIT_Msk       0x2000000u
/* SCB.INTR_S */
#define SCB_INTR_S_I2C_ARB_LOST_Pos             0u
#define SCB_INTR_S_I2C_ARB_LOST_Msk             0x1u
#define SCB_INTR_S_I2C_NACK_Pos                 1u
#define SCB_INTR_S_I2C_NACK_Msk                 0x2u
#define SCB_INTR_S_I2C_ACK_Pos                  2u
#define SCB_INTR_S_I2C_ACK_Msk                  0x4u
#define SCB_INTR_S_I2C_WRITE_STOP_Pos           3u
#define SCB_INTR_S_I2C_WRITE_STOP_Msk           0x8u
#define SCB_INTR_S_I2C_STOP_Pos                 4u
#define SCB_INTR_S_I2C_STOP_Msk                 0x10u
#define SCB_INTR_S_I2C_START_Pos                5u
#define SCB_INTR_S_I2C_START_Msk                0x20u
#define SCB_INTR_S_I2C_ADDR_MATCH_Pos           6u
#define SCB_INTR_S_I2C_ADDR_MATCH_Msk           0x40u
#define SCB_INTR_S_I2C_GENERAL_Pos              7u
#define SCB_INTR_S_I2C_GENERAL_Msk              0x80u
#define SCB_INTR_S_I2C_BUS_ERROR_Pos            8u
#define SCB_INTR_S_I2C_BUS_ERROR_Msk            0x100u
#define SCB_INTR_S_SPI_EZ_WRITE_STOP_Pos        9u
#define SCB_INTR_S_SPI_EZ_WRITE_STOP_Msk        0x200u
#define SCB_INTR_S_SPI_EZ_STOP_Pos              10u
#define SCB_INTR_S_SPI_EZ_STOP_Msk              0x400u
#define SCB_INTR_S_SPI_BUS_ERROR_Pos            11u
#define SCB_INTR_S_SPI_BUS_ERROR_Msk            0x800u
#define SCB_INTR_S_I2C_RESTART_Pos              16u
#define SCB_INTR_S_I2C_RESTART_Msk              0x10000u
#define SCB_INTR_S_I2C_HS_ENTER_Pos             24u
#define SCB_INTR_S_I2C_HS_ENTER_Msk             0x1000000u
#define SCB_INTR_S_I2C_HS_EXIT_Pos              25u
#define SCB_INTR_S_I2C_HS_EXIT_Msk              0x2000000u
/* SCB.INTR_S_SET */
#define SCB_INTR_S_SET_I2C_ARB_LOST_Pos         0u
#define SCB_INTR_S_SET_I2C_ARB_LOST_Msk         0x1u
#define SCB_INTR_S_SET_I2C_NACK_Pos             1u
#define SCB_INTR_S_SET_I2C_NACK_Msk             0x2u
#define SCB_INTR_S_SET_I2C_ACK_Pos              2u
#define SCB_INTR_S_SET_I2C_ACK_Msk              0x4u
#define SCB_INTR_S_SET_I2C_WRITE_STOP_Pos       3u
#define SCB_INTR_S_SET_I2C_WRITE_STOP_Msk       0x8u
#define SCB_INTR_S_SET_I2C_STOP_Pos             4u
#define SCB_INTR_S_SET_I2C_STOP_Msk             0x10u
#define SCB_INTR_S_SET_I2C_START_Pos            5u
#define SCB_INTR_S_SET_I2C_START_Msk            0x20u
#define SCB_INTR_S_SET_I2C_ADDR_MATCH_Pos       6u
#define SCB_INTR_S_SET_I2C_ADDR_MATCH_Msk       0x40u
#define SCB_INTR_S_SET_I2C_GENERAL_Pos          7u
#define SCB_INTR_S_SET_I2C_GENERAL_Msk          0x80u
#define SCB_INTR_S_SET_I2C_BUS_ERROR_Pos        8u
#define SCB_INTR_S_SET_I2C_BUS_ERROR_Msk        0x100u
#define SCB_INTR_S_SET_SPI_EZ_WRITE_STOP_Pos    9u
#define SCB_INTR_S_SET_SPI_EZ_WRITE_STOP_Msk    0x200u
#define SCB_INTR_S_SET_SPI_EZ_STOP_Pos          10u
#define SCB_INTR_S_SET_SPI_EZ_STOP_Msk          0x400u
#define SCB_INTR_S_SET_SPI_BUS_ERROR_Pos        11u
#define SCB_INTR_S_SET_SPI_BUS_ERROR_Msk        0x800u
#define SCB_INTR_S_SET_I2C_RESTART_Pos          16u
#define SCB_INTR_S_SET_I2C_RESTART_Msk          0x10000u
#define SCB_INTR_S_SET_I2C_HS_ENTER_Pos         24u
#define SCB_INTR_S_SET_I2C_HS_ENTER_Msk         0x1000000u
#define SCB_INTR_S_SET_I2C_HS_EXIT_Pos          25u
#define SCB_INTR_S_SET_I2C_HS_EXIT_Msk          0x2000000u
/* SCB.INTR_S_MASK */
#define SCB_INTR_S_MASK_I2C_ARB_LOST_Pos        0u
#define SCB_INTR_S_MASK_I2C_ARB_LOST_Msk        0x1u
#define SCB_INTR_S_MASK_I2C_NACK_Pos            1u
#define SCB_INTR_S_MASK_I2C_NACK_Msk            0x2u
#define SCB_INTR_S_MASK_I2C_ACK_Pos             2u
#define SCB_INTR_S_MASK_I2C_ACK_Msk             0x4u
#define SCB_INTR_S_MASK_I2C_WRITE_STOP_Pos      3u
#define SCB_INTR_S_MASK_I2C_WRITE_STOP_Msk      0x8u
#define SCB_INTR_S_MASK_I2C_STOP_Pos            4u
#define SCB_INTR_S_MASK_I2C_STOP_Msk            0x10u
#define SCB_INTR_S_MASK_I2C_START_Pos           5u
#define SCB_INTR_S_MASK_I2C_START_Msk           0x20u
#define SCB_INTR_S_MASK_I2C_ADDR_MATCH_Pos      6u
#define SCB_INTR_S_MASK_I2C_ADDR_MATCH_Msk      0x40u
#define SCB_INTR_S_MASK_I2C_GENERAL_Pos         7u
#define SCB_INTR_S_MASK_I2C_GENERAL_Msk         0x80u
#define SCB_INTR_S_MASK_I2C_BUS_ERROR_Pos       8u
#define SCB_INTR_S_MASK_I2C_BUS_ERROR_Msk       0x100u
#define SCB_INTR_S_MASK_SPI_EZ_WRITE_STOP_Pos   9u
#define SCB_INTR_S_MASK_SPI_EZ_WRITE_STOP_Msk   0x200u
#define SCB_INTR_S_MASK_SPI_EZ_STOP_Pos         10u
#define SCB_INTR_S_MASK_SPI_EZ_STOP_Msk         0x400u
#define SCB_INTR_S_MASK_SPI_BUS_ERROR_Pos       11u
#define SCB_INTR_S_MASK_SPI_BUS_ERROR_Msk       0x800u
#define SCB_INTR_S_MASK_I2C_RESTART_Pos         16u
#define SCB_INTR_S_MASK_I2C_RESTART_Msk         0x10000u
#define SCB_INTR_S_MASK_I2C_HS_ENTER_Pos        24u
#define SCB_INTR_S_MASK_I2C_HS_ENTER_Msk        0x1000000u
#define SCB_INTR_S_MASK_I2C_HS_EXIT_Pos         25u
#define SCB_INTR_S_MASK_I2C_HS_EXIT_Msk         0x2000000u
/* SCB.INTR_S_MASKED */
#define SCB_INTR_S_MASKED_I2C_ARB_LOST_Pos      0u
#define SCB_INTR_S_MASKED_I2C_ARB_LOST_Msk      0x1u
#define SCB_INTR_S_MASKED_I2C_NACK_Pos          1u
#define SCB_INTR_S_MASKED_I2C_NACK_Msk          0x2u
#define SCB_INTR_S_MASKED_I2C_ACK_Pos           2u
#define SCB_INTR_S_MASKED_I2C_ACK_Msk           0x4u
#define SCB_INTR_S_MASKED_I2C_WRITE_STOP_Pos    3u
#define SCB_INTR_S_MASKED_I2C_WRITE_STOP_Msk    0x8u
#define SCB_INTR_S_MASKED_I2C_STOP_Pos          4u
#define SCB_INTR_S_MASKED_I2C_STOP_Msk          0x10u
#define SCB_INTR_S_MASKED_I2C_START_Pos         5u
#define SCB_INTR_S_MASKED_I2C_START_Msk         0x20u
#define SCB_INTR_S_MASKED_I2C_ADDR_MATCH_Pos    6u
#define SCB_INTR_S_MASKED_I2C_ADDR_MATCH_Msk    0x40u
#define SCB_INTR_S_MASKED_I2C_GENERAL_Pos       7u
#define SCB_INTR_S_MASKED_I2C_GENERAL_Msk       0x80u
#define SCB_INTR_S_MASKED_I2C_BUS_ERROR_Pos     8u
#define SCB_INTR_S_MASKED_I2C_BUS_ERROR_Msk     0x100u
#define SCB_INTR_S_MASKED_SPI_EZ_WRITE_STOP_Pos 9u
#define SCB_INTR_S_MASKED_SPI_EZ_WRITE_STOP_Msk 0x200u
#define SCB_INTR_S_MASKED_SPI_EZ_STOP_Pos       10u
#define SCB_INTR_S_MASKED_SPI_EZ_STOP_Msk       0x400u
#define SCB_INTR_S_MASKED_SPI_BUS_ERROR_Pos     11u
#define SCB_INTR_S_MASKED_SPI_BUS_ERROR_Msk     0x800u
#define SCB_INTR_S_MASKED_I2C_RESTART_Pos       16u
#define SCB_INTR_S_MASKED_I2C_RESTART_Msk       0x10000u
#define SCB_INTR_S_MASKED_I2C_HS_ENTER_Pos      24u
#define SCB_INTR_S_MASKED_I2C_HS_ENTER_Msk      0x1000000u
#define SCB_INTR_S_MASKED_I2C_HS_EXIT_Pos       25u
#define SCB_INTR_S_MASKED_I2C_HS_EXIT_Msk       0x2000000u
/* SCB.INTR_TX */
#define SCB_INTR_TX_TRIGGER_Pos                 0u
#define SCB_INTR_TX_TRIGGER_Msk                 0x1u
#define SCB_INTR_TX_NOT_FULL_Pos                1u
#define SCB_INTR_TX_NOT_FULL_Msk                0x2u
#define SCB_INTR_TX_EMPTY_Pos                   4u
#define SCB_INTR_TX_EMPTY_Msk                   0x10u
#define SCB_INTR_TX_OVERFLOW_Pos                5u
#define SCB_INTR_TX_OVERFLOW_Msk                0x20u
#define SCB_INTR_TX_UNDERFLOW_Pos               6u
#define SCB_INTR_TX_UNDERFLOW_Msk               0x40u
#define SCB_INTR_TX_BLOCKED_Pos                 7u
#define SCB_INTR_TX_BLOCKED_Msk                 0x80u
#define SCB_INTR_TX_UART_NACK_Pos               8u
#define SCB_INTR_TX_UART_NACK_Msk               0x100u
#define SCB_INTR_TX_UART_DONE_Pos               9u
#define SCB_INTR_TX_UART_DONE_Msk               0x200u
#define SCB_INTR_TX_UART_ARB_LOST_Pos           10u
#define SCB_INTR_TX_UART_ARB_LOST_Msk           0x400u
/* SCB.INTR_TX_SET */
#define SCB_INTR_TX_SET_TRIGGER_Pos             0u
#define SCB_INTR_TX_SET_TRIGGER_Msk             0x1u
#define SCB_INTR_TX_SET_NOT_FULL_Pos            1u
#define SCB_INTR_TX_SET_NOT_FULL_Msk            0x2u
#define SCB_INTR_TX_SET_EMPTY_Pos               4u
#define SCB_INTR_TX_SET_EMPTY_Msk               0x10u
#define SCB_INTR_TX_SET_OVERFLOW_Pos            5u
#define SCB_INTR_TX_SET_OVERFLOW_Msk            0x20u
#define SCB_INTR_TX_SET_UNDERFLOW_Pos           6u
#define SCB_INTR_TX_SET_UNDERFLOW_Msk           0x40u
#define SCB_INTR_TX_SET_BLOCKED_Pos             7u
#define SCB_INTR_TX_SET_BLOCKED_Msk             0x80u
#define SCB_INTR_TX_SET_UART_NACK_Pos           8u
#define SCB_INTR_TX_SET_UART_NACK_Msk           0x100u
#define SCB_INTR_TX_SET_UART_DONE_Pos           9u
#define SCB_INTR_TX_SET_UART_DONE_Msk           0x200u
#define SCB_INTR_TX_SET_UART_ARB_LOST_Pos       10u
#define SCB_INTR_TX_SET_UART_ARB_LOST_Msk       0x400u
/* SCB.INTR_TX_MASK */
#define SCB_INTR_TX_MASK_TRIGGER_Pos            0u
#define SCB_INTR_TX_MASK_TRIGGER_Msk            0x1u
#define SCB_INTR_TX_MASK_NOT_FULL_Pos           1u
#define SCB_INTR_TX_MASK_NOT_FULL_Msk           0x2u
#define SCB_INTR_TX_MASK_EMPTY_Pos              4u
#define SCB_INTR_TX_MASK_EMPTY_Msk              0x10u
#define SCB_INTR_TX_MASK_OVERFLOW_Pos           5u
#define SCB_INTR_TX_MASK_OVERFLOW_Msk           0x20u
#define SCB_INTR_TX_MASK_UNDERFLOW_Pos          6u
#define SCB_INTR_TX_MASK_UNDERFLOW_Msk          0x40u
#define SCB_INTR_TX_MASK_BLOCKED_Pos            7u
#define SCB_INTR_TX_MASK_BLOCKED_Msk            0x80u
#define SCB_INTR_TX_MASK_UART_NACK_Pos          8u
#define SCB_INTR_TX_MASK_UART_NACK_Msk          0x100u
#define SCB_INTR_TX_MASK_UART_DONE_Pos          9u
#define SCB_INTR_TX_MASK_UART_DONE_Msk          0x200u
#define SCB_INTR_TX_MASK_UART_ARB_LOST_Pos      10u
#define SCB_INTR_TX_MASK_UART_ARB_LOST_Msk      0x400u
/* SCB.INTR_TX_MASKED */
#define SCB_INTR_TX_MASKED_TRIGGER_Pos          0u
#define SCB_INTR_TX_MASKED_TRIGGER_Msk          0x1u
#define SCB_INTR_TX_MASKED_NOT_FULL_Pos         1u
#define SCB_INTR_TX_MASKED_NOT_FULL_Msk         0x2u
#define SCB_INTR_TX_MASKED_EMPTY_Pos            4u
#define SCB_INTR_TX_MASKED_EMPTY_Msk            0x10u
#define SCB_INTR_TX_MASKED_OVERFLOW_Pos         5u
#define SCB_INTR_TX_MASKED_OVERFLOW_Msk         0x20u
#define SCB_INTR_TX_MASKED_UNDERFLOW_Pos        6u
#define SCB_INTR_TX_MASKED_UNDERFLOW_Msk        0x40u
#define SCB_INTR_TX_MASKED_BLOCKED_Pos          7u
#define SCB_INTR_TX_MASKED_BLOCKED_Msk          0x80u
#define SCB_INTR_TX_MASKED_UART_NACK_Pos        8u
#define SCB_INTR_TX_MASKED_UART_NACK_Msk        0x100u
#define SCB_INTR_TX_MASKED_UART_DONE_Pos        9u
#define SCB_INTR_TX_MASKED_UART_DONE_Msk        0x200u
#define SCB_INTR_TX_MASKED_UART_ARB_LOST_Pos    10u
#define SCB_INTR_TX_MASKED_UART_ARB_LOST_Msk    0x400u
/* SCB.INTR_RX */
#define SCB_INTR_RX_TRIGGER_Pos                 0u
#define SCB_INTR_RX_TRIGGER_Msk                 0x1u
#define SCB_INTR_RX_NOT_EMPTY_Pos               2u
#define SCB_INTR_RX_NOT_EMPTY_Msk               0x4u
#define SCB_INTR_RX_FULL_Pos                    3u
#define SCB_INTR_RX_FULL_Msk                    0x8u
#define SCB_INTR_RX_OVERFLOW_Pos                5u
#define SCB_INTR_RX_OVERFLOW_Msk                0x20u
#define SCB_INTR_RX_UNDERFLOW_Pos               6u
#define SCB_INTR_RX_UNDERFLOW_Msk               0x40u
#define SCB_INTR_RX_BLOCKED_Pos                 7u
#define SCB_INTR_RX_BLOCKED_Msk                 0x80u
#define SCB_INTR_RX_FRAME_ERROR_Pos             8u
#define SCB_INTR_RX_FRAME_ERROR_Msk             0x100u
#define SCB_INTR_RX_PARITY_ERROR_Pos            9u
#define SCB_INTR_RX_PARITY_ERROR_Msk            0x200u
#define SCB_INTR_RX_BAUD_DETECT_Pos             10u
#define SCB_INTR_RX_BAUD_DETECT_Msk             0x400u
#define SCB_INTR_RX_BREAK_DETECT_Pos            11u
#define SCB_INTR_RX_BREAK_DETECT_Msk            0x800u
/* SCB.INTR_RX_SET */
#define SCB_INTR_RX_SET_TRIGGER_Pos             0u
#define SCB_INTR_RX_SET_TRIGGER_Msk             0x1u
#define SCB_INTR_RX_SET_NOT_EMPTY_Pos           2u
#define SCB_INTR_RX_SET_NOT_EMPTY_Msk           0x4u
#define SCB_INTR_RX_SET_FULL_Pos                3u
#define SCB_INTR_RX_SET_FULL_Msk                0x8u
#define SCB_INTR_RX_SET_OVERFLOW_Pos            5u
#define SCB_INTR_RX_SET_OVERFLOW_Msk            0x20u
#define SCB_INTR_RX_SET_UNDERFLOW_Pos           6u
#define SCB_INTR_RX_SET_UNDERFLOW_Msk           0x40u
#define SCB_INTR_RX_SET_BLOCKED_Pos             7u
#define SCB_INTR_RX_SET_BLOCKED_Msk             0x80u
#define SCB_INTR_RX_SET_FRAME_ERROR_Pos         8u
#define SCB_INTR_RX_SET_FRAME_ERROR_Msk         0x100u
#define SCB_INTR_RX_SET_PARITY_ERROR_Pos        9u
#define SCB_INTR_RX_SET_PARITY_ERROR_Msk        0x200u
#define SCB_INTR_RX_SET_BAUD_DETECT_Pos         10u
#define SCB_INTR_RX_SET_BAUD_DETECT_Msk         0x400u
#define SCB_INTR_RX_SET_BREAK_DETECT_Pos        11u
#define SCB_INTR_RX_SET_BREAK_DETECT_Msk        0x800u
/* SCB.INTR_RX_MASK */
#define SCB_INTR_RX_MASK_TRIGGER_Pos            0u
#define SCB_INTR_RX_MASK_TRIGGER_Msk            0x1u
#define SCB_INTR_RX_MASK_NOT_EMPTY_Pos          2u
#define SCB_INTR_RX_MASK_NOT_EMPTY_Msk          0x4u
#define SCB_INTR_RX_MASK_FULL_Pos               3u
#define SCB_INTR_RX_MASK_FULL_Msk               0x8u
#define SCB_INTR_RX_MASK_OVERFLOW_Pos           5u
#define SCB_INTR_RX_MASK_OVERFLOW_Msk           0x20u
#define SCB_INTR_RX_MASK_UNDERFLOW_Pos          6u
#define SCB_INTR_RX_MASK_UNDERFLOW_Msk          0x40u
#define SCB_INTR_RX_MASK_BLOCKED_Pos            7u
#define SCB_INTR_RX_MASK_BLOCKED_Msk            0x80u
#define SCB_INTR_RX_MASK_FRAME_ERROR_Pos        8u
#define SCB_INTR_RX_MASK_FRAME_ERROR_Msk        0x100u
#define SCB_INTR_RX_MASK_PARITY_ERROR_Pos       9u
#define SCB_INTR_RX_MASK_PARITY_ERROR_Msk       0x200u
#define SCB_INTR_RX_MASK_BAUD_DETECT_Pos        10u
#define SCB_INTR_RX_MASK_BAUD_DETECT_Msk        0x400u
#define SCB_INTR_RX_MASK_BREAK_DETECT_Pos       11u
#define SCB_INTR_RX_MASK_BREAK_DETECT_Msk       0x800u
/* SCB.INTR_RX_MASKED */
#define SCB_INTR_RX_MASKED_TRIGGER_Pos          0u
#define SCB_INTR_RX_MASKED_TRIGGER_Msk          0x1u
#define SCB_INTR_RX_MASKED_NOT_EMPTY_Pos        2u
#define SCB_INTR_RX_MASKED_NOT_EMPTY_Msk        0x4u
#define SCB_INTR_RX_MASKED_FULL_Pos             3u
#define SCB_INTR_RX_MASKED_FULL_Msk             0x8u
#define SCB_INTR_RX_MASKED_OVERFLOW_Pos         5u
#define SCB_INTR_RX_MASKED_OVERFLOW_Msk         0x20u
#define SCB_INTR_RX_MASKED_UNDERFLOW_Pos        6u
#define SCB_INTR_RX_MASKED_UNDERFLOW_Msk        0x40u
#define SCB_INTR_RX_MASKED_BLOCKED_Pos          7u
#define SCB_INTR_RX_MASKED_BLOCKED_Msk          0x80u
#define SCB_INTR_RX_MASKED_FRAME_ERROR_Pos      8u
#define SCB_INTR_RX_MASKED_FRAME_ERROR_Msk      0x100u
#define SCB_INTR_RX_MASKED_PARITY_ERROR_Pos     9u
#define SCB_INTR_RX_MASKED_PARITY_ERROR_Msk     0x200u
#define SCB_INTR_RX_MASKED_BAUD_DETECT_Pos      10u
#define SCB_INTR_RX_MASKED_BAUD_DETECT_Msk      0x400u
#define SCB_INTR_RX_MASKED_BREAK_DETECT_Pos     11u
#define SCB_INTR_RX_MASKED_BREAK_DETECT_Msk     0x800u


#endif /* _CYIP_SCB_V3_H_ */


/* [] END OF FILE */