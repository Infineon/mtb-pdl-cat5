/***************************************************************************//**
* \file cy_tcpwm.h
*
* Provides API declarations of the TCPWM driver related to BTSS integration.
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

#ifndef __CY_TCPWM_H__
#define __CY_TCPWM_H__

#include "cy_pdl_device.h"

#if defined (CY_IP_MXTCPWM)

#include "cy_tcpwm_common.h"
#include "cy_tcpwm_pwm.h"
#include "cy_tcpwm_quaddec.h"
#include "cy_tcpwm_shiftreg.h"

#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#define TCPWM_IP_SYS_CLK_MAX_FREQUENCY 96000000u
#define TCPWM_LOGIC_WGPO_MUX_IN_SEL_EVEN_Pos(x)      (0 + (x << 1))
#define TCPWM_LOGIC_WGPO_MUX_IN_SEL_EVEN_Msk(x)      (0x03 << TCPWM_LOGIC_WGPO_MUX_IN_SEL_EVEN_Pos(x))
#define TCPWM_LOGIC_WGPO_MUX_IN_SEL_EVEN_Val(x, y)   ((x & 0x03) << TCPWM_LOGIC_WGPO_MUX_IN_SEL_EVEN_Pos(y))
#define TCPWM_LOGIC_WGPO_MUX_IN_SEL_ODD_Pos(x)       (8 + (x << 1))
#define TCPWM_LOGIC_WGPO_MUX_IN_SEL_ODD_Msk(x)       (0x03 << TCPWM_LOGIC_WGPO_MUX_IN_SEL_ODD_Pos(x))
#define TCPWM_LOGIC_WGPO_MUX_IN_SEL_ODD_Val(x, y)    ((x & 0x03) << TCPWM_LOGIC_WGPO_MUX_IN_SEL_ODD_Pos(y))

#define TCPWM_LOGIC_LGPO_MUX_IN_SEL_EVEN_Pos(x)      (16 + (x << 1))
#define TCPWM_LOGIC_LGPO_MUX_IN_SEL_EVEN_Msk(x)      (0x03 << TCPWM_LOGIC_LGPO_MUX_IN_SEL_EVEN_Pos(x))
#define TCPWM_LOGIC_LGPO_MUX_IN_SEL_EVEN_Val(x, y)   ((x & 0x03) << TCPWM_LOGIC_LGPO_MUX_IN_SEL_EVEN_Pos(y))
#define TCPWM_LOGIC_LGPO_MUX_IN_SEL_ODD_Pos(x)       (24 + (x << 1))
#define TCPWM_LOGIC_LGPO_MUX_IN_SEL_ODD_Msk(x)       (0x03 << TCPWM_LOGIC_LGPO_MUX_IN_SEL_ODD_Pos(x))
#define TCPWM_LOGIC_LGPO_MUX_IN_SEL_ODD_Val(x, y)    ((x & 0x03) << TCPWM_LOGIC_LGPO_MUX_IN_SEL_ODD_Pos(y))

#define TCPWM_TR_ONE_FROM_TR_OUT_SEL_Pos(x)          (x * 3)
#define TCPWM_TR_ONE_FROM_TR_OUT_SEL_Msk(x)          (0x07u << TCPWM_TR_ONE_FROM_TR_OUT_SEL_Pos(x))
#define TCPWM_TR_ONE_FROM_TR_OUT_SEL_Val(x,y)        ((x & 0x07u) << TCPWM_TR_ONE_FROM_TR_OUT_SEL_Pos(y))

#define TCPWM_TR_ONE_FROM_ADC_CH_SEL_Pos(x)          (24 + x)
#define TCPWM_TR_ONE_FROM_ADC_CH_SEL_Msk(x)          (1u << TCPWM_TR_ONE_FROM_ADC_CH_SEL_Pos(x))
#define TCPWM_TR_ONE_FROM_ADC_CH_SEL_Val(x,y)        ((x & 1u) << TCPWM_TR_ONE_FROM_ADC_CH_SEL_Pos(y))

#define TCPWM_LOGIC_OUTPUT_LGPO_Msk                  0x10u
#define TCPWM_LOGIC_OUTPUT_CONFIG_Msk                0x07u
#define TCPWM_LOGIC_OUTPUT_CONFIG_Size               3

#define TCPWM_LOGIC_OUTPUT_CONFIG_Pos(x)             (x * TCPWM_LOGIC_OUTPUT_CONFIG_Size)
#define TCPWM_LOGIC_OUTPUT_CONFIG_WGPO_Pos(x)        (3  + TCPWM_LOGIC_OUTPUT_CONFIG_Pos(x))
#define TCPWM_LOGIC_OUTPUT_CONFIG_LGPO_Pos(x)        (15 + TCPWM_LOGIC_OUTPUT_CONFIG_Pos(x))
#define TCPWM_LOGIC_OUTPUT_CONFIG_LGPO_Val(x)        (x << + TCPWM_LOGIC_OUTPUT_CONFIG_Pos(x))

#define TCPWM_WGPO_SEL_Pos                           27u
#define TCPWM_WGPO_SEL_Msk(x)                        (0x03u << TCPWM_WGPO_SEL_Pos)
#define TCPWM_WGPO_SEL_Val(x)                        ((x << TCPWM_WGPO_SEL_Pos) & TCPWM_WGPO_SEL_Msk(x))

#define TCPWM_GRP_LINEOUT_EN_MODE_AND_Msk            (1u << 29)

#define TCPWM_ADC_UPPER_THRES_pos                    0u
#define TCPWM_ADC_UPPER_THRES_Msk                    (0xFFFFu << TCPWM_ADC_UPPER_THRES_pos)
#define TCPWM_ADC_LOWER_THRES_pos                    8u
#define TCPWM_ADC_LOWER_THRES_Msk                    (0xFFFFu << TCPWM_ADC_LOWER_THRES_pos)

#define TCPWM_TRIGMUX_1To1_ADC_CH_MUX_Msk            0x80

typedef enum
{
    TCPWM_INTR_MASK_NONE      = 0u,

    TCPWM_INTR_MASK_GRP0_CNT0 = (1u << 0),

    TCPWM_INTR_MASK_GRP0_CNT1 = (1u << 1),

#if TCPWM_IP_GRP > 1

#if TCPWM_IP_GRP1_CNT > 0
    TCPWM_INTR_MASK_GRP1_CNT0 = (1u << 2),
#else
    TCPWM_INTR_MASK_GRP1_CNT0 = 0u,
#endif
#if TCPWM_IP_GRP1_CNT > 1
    TCPWM_INTR_MASK_GRP1_CNT1 = (1u << 3),
#else
    TCPWM_INTR_MASK_GRP1_CNT1 = 0u,
#endif
#if TCPWM_IP_GRP1_CNT > 2
    TCPWM_INTR_MASK_GRP1_CNT2 = (1u << 4),
#else
    TCPWM_INTR_MASK_GRP1_CNT2 = 0u,
#endif
#if TCPWM_IP_GRP1_CNT > 3
    TCPWM_INTR_MASK_GRP1_CNT3 = (1u << 5),
#else
    TCPWM_INTR_MASK_GRP1_CNT3 = 0u,
#endif
#if TCPWM_IP_GRP1_CNT > 4
    TCPWM_INTR_MASK_GRP1_CNT4 = (1u << 6),
#else
    TCPWM_INTR_MASK_GRP1_CNT4 = 0u,
#endif
#if TCPWM_IP_GRP1_CNT > 5
    TCPWM_INTR_MASK_GRP1_CNT5 = (1u << 7),
#else
    TCPWM_INTR_MASK_GRP1_CNT5 = 0u,
#endif
#if TCPWM_IP_GRP1_CNT > 6
    TCPWM_INTR_MASK_GRP1_CNT6 = (1u << 8),
#else
    TCPWM_INTR_MASK_GRP1_CNT6 = 0u,
#endif

#endif //TCPWM_IP_GRP
} TCPWM_INTR_MASK_t;

/** \brief TCPWM - Interrupt Callback from IRQ Thread
   The tcpwm clock will be divided down from the rpu 96mhz clock, so that the tcpwm can do different protocol clock frequency. The divided value:
   */
typedef enum
{
   TCPWM_TPORT_CLK_DIV_1  = 1,
   TCPWM_TPORT_CLK_DIV_2  = 2,
   TCPWM_TPORT_CLK_DIV_4  = 3,
   TCPWM_TPORT_CLK_DIV_6  = 4,
   TCPWM_TPORT_CLK_DIV_8  = 5,
   TCPWM_TPORT_CLK_DIV_10 = 6,
   TCPWM_TPORT_CLK_DIV_12 = 7,
   TCPWM_TPORT_CLK_DIV_16 = 8,
   TCPWM_TPORT_CLK_DIV_32 = 9,
} TCPWM_TPORT_CLK_DIV_SEL_t;

/** \brief TCPWM - Logic block output selector */
typedef enum
{
    TCPWM_LOGIC_OUTPUT_WGPO_0 = 0x00,
    TCPWM_LOGIC_OUTPUT_WGPO_1 = 0x01,
    TCPWM_LOGIC_OUTPUT_WGPO_2 = 0x02,
    TCPWM_LOGIC_OUTPUT_WGPO_3 = 0x03,
    TCPWM_LOGIC_OUTPUT_LGPO_0 = 0x10,
    TCPWM_LOGIC_OUTPUT_LGPO_1 = 0x11,
    TCPWM_LOGIC_OUTPUT_LGPO_2 = 0x12,
    TCPWM_LOGIC_OUTPUT_LGPO_3 = 0x13,
} TCPWM_LOGIC_OUTPUT_t;

/** \brief TCPWM - Trigmux output mode selector */
typedef enum
{
    TCPWM_TRIGMUX_OUTPUT_LINE_OUT = 0x00, /* 8 WGPO Outputs = {4 Line Out, 4 Line Compl} */
    TCPWM_TRIGMUX_OUTPUT_WGPO     = 0x01, /* 8 WGPO Outputs = {4'b0, 4 WGPO} */
    TCPWM_TRIGMUX_OUTPUT_LGPO     = 0x02, /* 8 WGPO Outputs = {4'b0, 4 LGPO} */
    TCPWM_TRIGMUX_OUTPUT_DISABLE  = 0x03, /* 8 WGPO Outputs disabled */
} TCPWM_TRIGMUX_OUTPUT_SEL_t;

/** \brief TCPWM - Logic block operations */
typedef enum
{
    TCPWM_LOGIC_AND  = 0,
    TCPWM_LOGIC_NAND = 1,
    TCPWM_LOGIC_OR   = 2,
    TCPWM_LOGIC_NOR  = 3,
    TCPWM_LOGIC_XOR  = 4,
    TCPWM_LOGIC_XNOR = 5,
} TCPWM_LOGIC_FUNC_t;

/** \brief TCPWM - PAD output configuration */
typedef enum
{
    TCPWM_GRP_LINEOUT_EN_MODE_OR  = 0u, /* pad_out_en = in_1_en | in_2_en */
    TCPWM_GRP_LINEOUT_EN_MODE_AND = 1u, /* pad_out_en = in_1_en & in_2_en */
} TCPWM_GRP_LINEOUT_EN_MODE_t;

/** \brief TCPWM - Trigmux input options */
typedef enum
{
    TCPWM_LOGIC_TRIGMUX_WGPO_INPUT_LINE_OUT_0 = 0x00,
    TCPWM_LOGIC_TRIGMUX_WGPO_INPUT_LINE_OUT_1 = 0x01,
    TCPWM_LOGIC_TRIGMUX_WGPO_INPUT_LINE_OUT_2 = 0x02,
    TCPWM_LOGIC_TRIGMUX_WGPO_INPUT_LINE_OUT_3 = 0x03,
    TCPWM_LOGIC_TRIGMUX_LGPO_INPUT_GPIO_0     = 0x00,
    TCPWM_LOGIC_TRIGMUX_LGPO_INPUT_GPIO_1     = 0x01,
    TCPWM_LOGIC_TRIGMUX_LGPO_INPUT_GPIO_2     = 0x02,
    TCPWM_LOGIC_TRIGMUX_LGPO_INPUT_GPIO_3     = 0x03,
} TCPWM_LOGIC_TRIGMUX_INPUT_t;

/** \brief TCPWM - Trigmux tr_all options */
typedef enum
{
    TCPWM_LOGIC_TRIGMUX_LINEOUT = 0u,
    TCPWM_LOGIC_TRIGMUX_WGPO   = 1u,
    TCPWM_LOGIC_TRIGMUX_LGPO = 1u
} TCPWM_LOGIC_TRIGMUX_t;

/** \brief TCPWM - Trigmux tr_one options */
typedef enum
{
    TCPWM_TR_ONE_1     = 0x00,
    TCPWM_TR_ONE_2     = 0x01,
    TCPWM_TR_ONE_4     = 0x02,
    TCPWM_TR_ONE_5     = 0x03,
    TCPWM_TR_ONE_7     = 0x04,
    TCPWM_TR_ONE_8     = 0x05,
    TCPWM_TR_ONE_10    = 0x06,
    TCPWM_TR_ONE_11    = 0x07,
} TCPWM_TR_ONE_TR_OUT_LIST_t;

/** \brief TCPWM - Adc tr_one mux index list */
typedef enum
{
    TCPWM_TR_ONE_0     = 0x00,
    TCPWM_TR_ONE_3     = 0x01,
    TCPWM_TR_ONE_6     = 0x02,
    TCPWM_TR_ONE_9     = 0x03,
} TCPWM_TR_ONE_ADC_CH_LIST_t;

/** \brief TCPWM - Trigmux tr_out list */
typedef enum
{
    TCPWM_TR_OUT_0     = 0x00,
    TCPWM_TR_OUT_1     = 0x01,
    TCPWM_TR_OUT_2     = 0x02,
    TCPWM_TR_OUT_3     = 0x03,
    TCPWM_TR_OUT_4     = 0x04,
    TCPWM_TR_OUT_5     = 0x05,
    TCPWM_TR_OUT_6     = 0x06,
    TCPWM_TR_OUT_7     = 0x07, 
} TCPWM_TR_OUT_LIST_t;

/** \brief TCPWM - Trigmux - Input adc channel list */
typedef enum
{
    TCPWM_ADC_CH_0     = 0x00,
    TCPWM_ADC_CH_1     = 0x01,
    TCPWM_ADC_CH_2     = 0x02,
    TCPWM_ADC_CH_3     = 0x03,
} TCPWM_ADC_CH_LIST_t;

/** \brief TCPWM - Trigmux tr_one mux list */
typedef enum
{
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_1     = 0x00,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_2     = 0x01,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_4     = 0x02,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_5     = 0x03,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_7     = 0x04,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_8     = 0x05,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_10    = 0x06,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_11    = 0x07,
    TCPWM_TRIGMUX_1To1_TR_OUT_MUX_LAST  = 0x07,

    TCPWM_TRIGMUX_1To1_ADC_CH0_MUX_0    = 0x80,
    TCPWM_TRIGMUX_1To1_ADC_CH1_MUX_3    = 0x81,
    TCPWM_TRIGMUX_1To1_ADC_CH2_MUX_6    = 0x82,
    TCPWM_TRIGMUX_1To1_ADC_CH3_MUX_9    = 0x83,
    TCPWM_TRIGMUX_1To1_ADC_CH_MUX_LAST  = 0x83
} TCPWM_TRIGMUX_1To1_t;

/** \brief TCPWM - Trigmux tr_all config */
typedef struct
{
    TCPWM_LOGIC_TRIGMUX_t       mux_type;
    UINT8                       mux_idx;
    TCPWM_LOGIC_TRIGMUX_INPUT_t input0;
    TCPWM_LOGIC_TRIGMUX_INPUT_t input1;
    TCPWM_LOGIC_FUNC_t          logic;
} TCPWM_TRIGMUX_t;

/** \brief TCPWM - Trigmux tr_one config */
typedef struct
{
    TCPWM_TRIGMUX_1To1_t       mux_idx;
    BOOL8                      adc_threshold_config;
    UINT16                     adc_upper_threshold;
    UINT16                     adc_lower_threshold;
} TCPWM_TRIGMUX_ONETOONE_t;

/** \brief TCPWM - Interrupt Callback from IRQ Thread */
typedef void(*TCPWM_IRQ_THREAD_CB_t)(UINT8 group_id, UINT8 counter_id);

/**
 * Function Cy_TCPWM_EnableClock
 *
 * Configure TCPWM IP clock frequency
 *
 * \param[in]    div_sel       : Clock Divider calculated based on Sysclk
 * \param[in]    hw_reset      : Full IP reset - all registers & HW back to
 *                               initial state
 *
 * \return       Result - Divided IP clock
 */
uint32_t Cy_TCPWM_EnableClock(TCPWM_TPORT_CLK_DIV_SEL_t div_sel, BOOL8 hw_reset);

/**
 * Function Cy_TCPWM_RegisterInterruptCallback
 *
 * Register interrupt callback for all TCPWM interrupts
 *
 * \param[in]    irqCb         : Callback function
 *
 * \return       Result - Pass or Fail
 */
BOOL32 Cy_TCPWM_RegisterInterruptCallback(TCPWM_IRQ_THREAD_CB_t irqCb);

/**
 * Function Cy_TCPWM_EnableInterrupt
 *
 * Enable TCPWM interrupt in groups - Refer TCPWM_INTR_MASK_t
 *
 * \param[in]    mask          : TCPWM Interrupt Mask
 *
 * \return       none
 */
void Cy_TCPWM_EnableInterrupt (TCPWM_INTR_MASK_t mask);

/**
 * Function Cy_TCPWM_DisableInterrupt
 *
 * Disable TCPWM interrupt in groups - Refer TCPWM_INTR_MASK_t
 *
 * \param[in]    mask          : TCPWM Interrupt Mask
 *
 * \return       none
 */
void Cy_TCPWM_DisableInterrupt(TCPWM_INTR_MASK_t mask);

/**
 * Function Cy_TCPWM_DisableAllInterrupt
 *
 * Disable all TCPWM counter interrupt in all groups
 *
 * \return      none
 */
void Cy_TCPWM_DisableAllInterrupt(void);

/**
 * Function Cy_TCPWM_ConfigureLogicOutputFunction
 *
 * Configures the logic operation on inputs signals for a LGPO output.
 *
 * \param[in]    sel           : Trigmux output selector from TCPWM_LOGIC_OUTPUT_t
 * \param[in]    logic         : Glue logic from TCPWM_LOGIC_FUNC_t list to be applied on signals before output
 *
 * \return       none
 */
void Cy_TCPWM_ConfigureLogicOutputFunction(TCPWM_LOGIC_OUTPUT_t output, TCPWM_LOGIC_FUNC_t logic);

/**
 * Function Cy_TCPWM_SelectTrigmuxOutput
 *
 * Configures the output signals in WGPO.
 *
 * \param[in]    sel           : Trigmux Output Selector
 *
 * \return       none
 */
void Cy_TCPWM_SelectTrigmuxOutput(TCPWM_TRIGMUX_OUTPUT_SEL_t sel);

/**
 * Function Cy_TCPWM_SelectInputSignalForLGPOMux
 *
 * Configures the input signal for a LGPO mux.
 *
 * \param[in]    mux_index     : Trigmux input index for LGPO
 * \param[in]    mux_input     : LGPO/WGPO Input signal selection for mix_in from TCPWM_LOGIC_TRIGMUX_INPUT_t
 *
 * \return       none
 */
void Cy_TCPWM_SelectInputSignalForLGPOMux (UINT8 mux_index, TCPWM_LOGIC_TRIGMUX_INPUT_t mux_input);

/**
 * Function Cy_TCPWM_SelectInputSignalForWGPOMux
 *
 * Configures the input signal for a WGPO mux.
 *
 * \param[in]    mux_index     : Trigmux input index for WGPO
 * \param[in]    mux_input     : Input signal selection for mix_in from TCPWM_LOGIC_TRIGMUX_INPUT_t
 *
 * \return       none
 */
void Cy_TCPWM_SelectInputSignalForWGPOMux (UINT8 mux_index, TCPWM_LOGIC_TRIGMUX_INPUT_t mux_input);

/**
 * Function Cy_TCPWM_SetGroupLineOutPadOutputEnable
 *
 * Configures the pad_en (OR, AND) logic for a WGPO.
 *
 * \param[in]    pad_en_mode   : Controls whether pad_out_en = in_1_en | in_2_en or pad_out_en = in_1_en & in_2_en
 *                               Refer TCPWM_GRP_LINEOUT_EN_MODE_t
 *
 * \return       none
 */
void Cy_TCPWM_SetGroupLineOutPadOutputEnable(TCPWM_GRP_LINEOUT_EN_MODE_t pad_en_mode);

/**
 * Function Cy_TCPWM_SelectTrOneFromTrOut
 *
 * Configures the tr_out input for tr_one mux
 *
 * \param[in]    tr_one        : Select tr_one mux from TCPWM_TR_ONE_TR_OUT_LIST_t
 * \param[in]    tr_out        : Select tr_out input signal from TCPWM_TR_OUT_LIST_t
 *
 * \return       none
 */
void Cy_TCPWM_SelectTrOneFromTrOut(TCPWM_TR_ONE_TR_OUT_LIST_t tr_one, TCPWM_TR_OUT_LIST_t tr_out);

/**
 * Function Cy_TCPWM_ConfigureAdcLowerThreshold
 *
 * Configures the lower threshold for ADC output comparator
 *
 * \param[in]    threshold     : Lower threshold value
 *
 * \return       none
 */
void Cy_TCPWM_ConfigureAdcLowerThreshold(uint16_t threshold);

/**
 * Function Cy_TCPWM_ConfigureAdcUpperThreshold
 *
 * Configures the upper threshold for ADC output comparator
 *
 * \param[in]    threshold     : Upper threshold value
 *
 * \return       none
 */
void Cy_TCPWM_ConfigureAdcUpperThreshold(uint16_t threshold);

/**
 * Function Cy_TCPWM_SelectTrOneFromAdcCh
 *
 * Configures the adc input for tr_one mux
 *
 * \param[in]    tr_one        : Adc has its own list of supported tr_one signals from TCPWM_TR_ONE_ADC_CH_LIST_t
 * \param[in]    tr_out        : Adc Input selected for the tr_one mux from TCPWM_ADC_CH_LIST_t
 *
 * \return       none
 */
void Cy_TCPWM_SelectTrOneFromAdcCh(TCPWM_TR_ONE_ADC_CH_LIST_t tr_one, TCPWM_ADC_CH_LIST_t tr_out);

/**
 * Function Cy_TCPWM_ConnectTrigmux
 *
 * Configures the tr_all 0 Trigger All mux.
 *
 * \param[in]    config        : Refer to TCPWM_TRIGMUX_t
 *
 * \return       Result - Pass or Fail
 */
BOOL8 Cy_TCPWM_ConnectTrigmux (TCPWM_TRIGMUX_t *config);

/**
 * Function Cy_TCPWM_ConnectTrigOneToOnemux
 *
 *  Configures the one2one trigger mux.
 *
 * \param[in]    config        : Refer to TCPWM_TRIGMUX_ONETOONE_t
 *
 * \return       Result - Pass or Fail
 */
BOOL8 Cy_TCPWM_ConnectTrigOneToOnemux (TCPWM_TRIGMUX_ONETOONE_t *config);

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXTCPWM */

#endif /* __CY_TCPWM_H__ */

/* [] END OF FILE */
