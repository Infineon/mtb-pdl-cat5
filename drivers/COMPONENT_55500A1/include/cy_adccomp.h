/***************************************************************************//**
* \file cy_adccomp.h
*
* Provides API declarations of the ADCCOMP driver.
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
#ifndef _CY_ADCCOMP_H_
#define _CY_ADCCOMP_H_

#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif
#include "cy_pdl_device.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define CY_ADCCOMP_MV  (1000L)      /**< 1 Volt in millivolts */
#define CY_ADCCOMP_UV  (1000000L)   /**< 1 Volt in microvolts */

typedef enum
{
    CY_ADCCOMP_LPCOMP_1 = 1,
    CY_ADCCOMP_LPCOMP_2 = 2
}cy_en_adccomp_lpcomp_id_t;

typedef enum
{
    CY_ADCCOMP_LPCOMP_DC,   /**< DC mode: comparator  assert when the V(+) - V(-) > 0.5*hysterisis limit */
    CY_ADCCOMP_LPCOMP_NTD   /**< NTD mode: comparator to detect when the peak-peak mic input level is larger than
                                 the selected hysterisis limit */
}cy_en_adccomp_lpcomp_mode_t;

typedef enum
{
    /**< ADC input channel for DC conversion */
    CY_ADCCOMP_ADC_IN_GPIO0,        /**< GPIO 0  */
    CY_ADCCOMP_ADC_IN_GPIO1,        /**< GPIO 1  */
    CY_ADCCOMP_ADC_IN_GPIO2,        /**< GPIO 2  */
    CY_ADCCOMP_ADC_IN_GPIO3,        /**< GPIO 3  */
    CY_ADCCOMP_ADC_IN_GPIO4,        /**< GPIO 4  */
    CY_ADCCOMP_ADC_IN_GPIO5,        /**< GPIO 5  */
    CY_ADCCOMP_ADC_IN_GPIO6,        /**< GPIO 6  */
    CY_ADCCOMP_ADC_IN_GPIO7,        /**< GPIO 7  */
    CY_ADCCOMP_ADC_IN_OPEN = 16     /**< input to ADC is open */
}cy_en_adccomp_adc_dc_channel_t;

typedef enum
{
    /**< ADC input channel for audio capture */
    CY_ADCCOMP_ADC_IN_MIC = 8
}cy_en_adccomp_adc_mic_channel_t;

typedef enum
{
    /**< Comparator -ve terminal input MUX */
    CY_ADCCOMP_LPCOMP_IN_N_GPIO04,  /**< GPIO0 to LPCOMP2 -ve terminal or GPIO4 to LPCOMP1 -ve terminal*/
    CY_ADCCOMP_LPCOMP_IN_N_GPIO15,  /**< GPIO1 to LPCOMP2 -ve terminal or GPIO5 to LPCOMP1 -ve terminal*/
    CY_ADCCOMP_LPCOMP_IN_N_OPEN     /**< comparator negative terminal input to open */
} cy_en_adccomp_lpcomp_negative_channel_t;

typedef enum
{
    /**< Comparator +ve terminal input MUX */
    CY_ADCCOMP_LPCOMP_IN_P_GPIO26,  /**< GPIO2 to LPCOMP2 +ve terminal or GPIO6 to LPCOMP1 +ve terminal*/
    CY_ADCCOMP_LPCOMP_IN_P_GPIO37,  /**< GPIO3 to LPCOMP2 +ve terminal or GPIO7 to LPCOMP1 +ve terminal*/
    CY_ADCCOMP_LPCOMP_IN_P_MIC,     /**< MIC input to positive terminal of comparator. Applicable only in NTD mode */
    CY_ADCCOMP_LPCOMP_IN_P_OPEN = 4     /**< comparator positive terminal input to open */
} cy_en_adccomp_lpcomp_positive_channel_t;

/**< Hysterisis for lpcomp1. The output of the comparator is asserted
    when the peak-peak mic input level is larger than the selected limit below.
    In DC mode the output is asserted and latched when the V(+) - V(-) > 0.5*limit.
    HYST                   Limit             Sound Pressure Level (SPL in db)
    0000                    0                         -
    0001                    4                         78
    0010                    8                         84
    0011                    12                       87.5
    0100                    16                       90
    0101                    20                       92
    0110                    24                       93.5
    0111                    28                       95
    1000                    32                       96
    1001                    36                       97
    1010                    40                       98
    1011                    44                       99
    1100                    48                       99.6
    1101                    52                       100.3
    1110                    56                       101
    1111                    60                       101.5
*/
typedef enum
{
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_0MV_NONE,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_4MV_78DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_8MV_84DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_12MV_87_5DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_16MV_90DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_20MV_92DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_24MV_93_5DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_28MV_95DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_32MV_96DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_36MV_97DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_40MV_98DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_44MV_99DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_48MV_99_6DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_52MV_100_3DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_56MV_101DB,
    CY_ADCCOMP_LPCOMP_HYST_LIMIT_60MV_101_5DB
}cy_en_adccomp_lpcomp_hyst_t;


// Hachet 1 default ADC input clock is 4 MHz.
typedef enum
{
    CY_ADCCOMP_ADC_CLK_IN_1MHZ_PDM_OUT_1MHZ,    /**< Input to adc is 1 MHz and o/p PDM data required is 1 MHz */
    CY_ADCCOMP_ADC_CLK_IN_2MHZ_PDM_OUT_1MHZ,    /**< Input to adc is 2 MHz and o/p PDM data required is 1 MHz */
    CY_ADCCOMP_ADC_CLK_IN_2MHZ_PDM_OUT_2MHZ,    /**< Input to adc is 2 MHz and o/p PDM data required is 2 MHz */
    CY_ADCCOMP_ADC_CLK_IN_4MHZ_PDM_OUT_2MHZ     /**< Input to adc is 4 MHz and o/p PDM data required is 1 MHz */
}cy_en_adccomp_adc_clk_in_pdm_out_t;

/** adc and low power comparator error codes. */
typedef enum
{
    CY_ADCCOMP_SUCCESS = 0x00u,
    CY_ADCCOMP_BAD_PARAM,
    CY_ADCCOMP_CLOCK_REQ_FAIL,
    CY_ADCCOMP_NOT_SUPPORTED
} cy_en_adccomp_status_t;

/**
* \addtogroup group_adccomp_macros_interrupt
* \{
*/
/** Bit 0: comparator1 fires,
    NTD mode:- when the peak-peak mic input level is larger than the selected hysterisis limit.
    DC sense:- V(+) - V(-) > 0.5* hysterisis limit */
#define CY_ADCCOMP_INTR_LPCOMP1         (ADCCOMP_INTR_MASK_INTR_LPCOMP1_Msk)
/** Bit 1: comparator2 fires,
    NTD mode:- when the peak-peak mic input level is larger than the selected hysterisis limit.
    DC sense:- V(+) - V(-) > 0.5* hysterisis limit */
#define CY_ADCCOMP_INTR_LPCOMP2         (ADCCOMP_INTR_MASK_INTR_LPCOMP2_Msk)
/** Bit 2: When CIC block completes DC conversion */
#define CY_ADCCOMP_INTR_CIC             (ADCCOMP_INTR_MASK_INTR_CIC_Msk)
/** Bit 3: Interrupt generates when ADC LDO is stable (or) ADC timer expires(applicable only in case of DC calibration) */
#define CY_ADCCOMP_INTR_ADC_READY       (ADCCOMP_INTR_MASK_INTR_TIMER_Msk)
#define CY_ADCCOMP_INTR                 (ADCCOMP_INTR_MASK_INTR_LPCOMP1_Msk | \
                                         ADCCOMP_INTR_MASK_INTR_LPCOMP2_Msk | \
                                         ADCCOMP_INTR_MASK_INTR_CIC_Msk | \
                                         ADCCOMP_INTR_MASK_INTR_TIMER_Msk)
/** \} group_adccomp_macros_interrupt */

typedef enum
{
    CY_ADCCOMP_STATUS_LPCOMP1_LATCHED_HIGH    = (1 << 4),    /**< Comparator 1 o/p latched high */
    CY_ADCCOMP_STATUS_LPCOMP2_LATCHED_HIGH    = (1 << 5),    /**< Comparator 2 o/p latched high */
    CY_ADCCOMP_STATUS_ADC_PDM_DATA_READY    = (1 << 7),    /**< Reflects when ADC enabled and PDM data is ready */
    CY_ADCCOMP_STATUS_ADC_GM_LDO_OK         = (1 << 8),  /**< i.e. After ADC internal LDO’s power-up sequence is completed. */
    CY_ADCCOMP_STATUS_ADC_TIMER_SET         = (1 << 9),  /**< i.e. When the ADC 100us timer is set. */
    CY_ADCCOMP_STATUS_ADC_CLK_READY         = (1 << 11), /**< Indicates ADC input clock is a valid clock. */
}cy_adccomp_status_register_mask_t;

typedef enum
{
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_0,     /**< Gain 8/8, Max i/p(Vpp) = 1 */
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_1,     /**< Gain 8/7, Max i/p(Vpp) = 875 m */
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_2,     /**< Gain 8/6, Max i/p(Vpp) = 750 m */
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_3,     /**< Gain 8/5, Max i/p(Vpp) = 625 m */
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_4,     /**< Gain 8/4, Max i/p(Vpp) = 500 m */
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_5,     /**< Gain 8/3, Max i/p(Vpp) = 375 m */
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_6,     /**< Gain 8/2, Max i/p(Vpp) = 250 m */
    CY_ADCCOMP_ADC_PGA_GAIN_CTRL_7      /**< Gain 8/1, Max i/p(Vpp) = 125 m */
}cy_en_adccomp_adc_pga_gain_ctrl_t;

typedef struct
{
    cy_en_adccomp_lpcomp_hyst_t             lpcompHyst;
    BOOL8                                   lpcompHyst2x;   /**< hysterisis value get doubled */
    cy_en_adccomp_lpcomp_negative_channel_t inN;
    cy_en_adccomp_lpcomp_positive_channel_t inP;
}cy_stc_adccomp_lpcomp_dc_config_t;

typedef struct
{
    cy_en_adccomp_lpcomp_hyst_t             lpcompHyst;
    BOOL8                                   lpcompHyst2x;   /**< 1: hysterisis value get doubled */
}cy_stc_adccomp_lpcomp_ntd_config_t;

typedef struct
{
    cy_stc_adccomp_lpcomp_dc_config_t   * dcConfig;
    cy_stc_adccomp_lpcomp_ntd_config_t  * ntdConfig;
}cy_stc_adccomp_lpcomp_config_t;

typedef enum
{
    CY_ADCCOMP_ADC_DC,   /**< DC voltage measurement */
    CY_ADCCOMP_ADC_MIC /**< Analog MIC with PGA */
}cy_en_adccomp_adc_mode_t;

/** The ADC driver context structure - it stores the offset values for DC voltage measurement. */
typedef struct
{
    int16_t offset; /**< The storage for the offset calibration value */
    int16_t gain;   /**< The storage for the gain calibration value */
} cy_stc_adccomp_adc_context_t;

typedef struct
{
    cy_en_adccomp_adc_dc_channel_t  channel;        /**< Applicable only for DC measurement. Not applicable for DC calibration */
    cy_stc_adccomp_adc_context_t    * context;      /**< The pointer to the context structure.
                                                     *   If neither \ref Cy_ADCCOMP_CountsTo_uVolts,
                                                     *              nor \ref Cy_ADCCOMP_CountsTo_mVolts,
                                                     *   functions is used, this pointer can be NULL.
                                                     */
}cy_stc_adccomp_adc_dc_config_t;

typedef struct
{
    cy_en_adccomp_adc_pga_gain_ctrl_t   adcMicPgaGain;  /**< MIC Programmable gain */
}cy_stc_adccomp_adc_mic_config_t;

typedef struct
{
    cy_en_adccomp_adc_clk_in_pdm_out_t  adcClkInPdmOut; /**< ADC clock input and PDM output selection */
    cy_stc_adccomp_adc_dc_config_t      * dcConfig;     /**< The pointer to the DC measurement path configuration structure */
    cy_stc_adccomp_adc_mic_config_t     * micConfig;    /**< The pointer to the audio MIC configuration structure */
}cy_stc_adccomp_adc_config_t;


/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_Init
****************************************************************************//**
*
* Configures Low power comparator for DC mode or noise threshold detect(NTD) mode
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
* \param lpcompMode
* Low power comparator mode of operation \ref cy_en_adccomp_lpcomp_mode_t.
*
* \param pCfg
* The pointer to the configuration structure \ref cy_stc_adccomp_lpcomp_config_t.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_LPCOMP_Init ( CyADCCOMP_Type *base,
                                                             cy_en_adccomp_lpcomp_id_t lpcompId,
                                                             cy_en_adccomp_lpcomp_mode_t lpcompMode,
                                                             cy_stc_adccomp_lpcomp_config_t *pCfg);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_Enable
****************************************************************************//**
*
* Enable comparator for either DC threshold detection or NTD(Noise Threshold mode).
* when comparator i/p(i.e. +ve terminal i/p) is above threshold(i.e. -ve terminal value),
* comparator interrupt \ref group_adccomp_macros_interrupt get generated.
* In interrupt callback, ADC status register \ref cy_adccomp_status_register_mask_t
* can be read to check for comparator o/p latched high.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
* \note if comparator configured for NTD mode and enabling, application must wait
* for comparator to settle and configure as wake source using /ref Cy_ADCCOMP_LPCOMP_EnableWakeConfig
* what is comparator settling? When comparator configured for NTD mode first time after power up,
* it take a while for comparator to settle down depending on DC blocking capacitor and MIC output common-mode (DC output),
* both are application configurable. During this time comparator may latch if the voltage difference between comparator
* +ve and -ve terminal exceed configured hysterisis limit. Application needs to poll for every 10 ms
* for comparator latched status using /ref Cy_ADCCOMP_GetStatusRegisterVal and clear latch 
* using /ref Cy_ADCCOMP_GetStatusRegisterVal. Once application does not see comparator latch, few 10 ms intervals
* continuously then application configure comparator as wake source using /ref Cy_ADCCOMP_LPCOMP_EnableWakeConfig
* and then only allow device to enter to low power mode.
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_LPCOMP_Enable (CyADCCOMP_Type *base, cy_en_adccomp_lpcomp_id_t lpcompId);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_Disable
****************************************************************************//**
*
* Disables comparator
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_LPCOMP_Disable (CyADCCOMP_Type *base, cy_en_adccomp_lpcomp_id_t lpcompId);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_DeInit
****************************************************************************//**
*
* Disable comparator and resets configuration to default values, i.e.
* input to comparator is open, Resets comparator o/p, Clears NTD mode and 
* Set Hysterisis to CY_LPCOMP_HYST_LIMIT_0MV_NONE
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_LPCOMP_DeInit (CyADCCOMP_Type *base, cy_en_adccomp_lpcomp_id_t lpcompId);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_EnableWakeConfig
****************************************************************************//**
*
* Configures comparator as wake source. Applicable to use in NTD mode only.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
* \note This function must be called after comparator settled down after
* comparator configured for NTD mode. /ref Cy_ADCCOMP_LPCOMP_Enable description
*
*******************************************************************************/
void Cy_ADCCOMP_LPCOMP_EnableWakeConfig(cy_en_adccomp_lpcomp_id_t lpcompId);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_DisableWakeConfig
****************************************************************************//**
*
* Disables comparator wake source configuration. Applicable to use in NTD mode only.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
*******************************************************************************/
void Cy_ADCCOMP_LPCOMP_DisableWakeConfig(cy_en_adccomp_lpcomp_id_t lpcompId);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_isWakeSource
****************************************************************************//**
*
* Return TRUE/FALSE depending on comparator is the reason for device wake from low power mode or not.
* Applicable to use in NTD mode only.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
* \return
* TRUE :- device wake from low power mode because of comparator latch
* FALSE:- device wake from low power mode is not because of comparator latch
*
*******************************************************************************/
BOOL32 Cy_ADCCOMP_LPCOMP_isWakeSource(cy_en_adccomp_lpcomp_id_t lpcompId);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_LPCOMP_ClearLatch
****************************************************************************//**
*
* Clears the comparator latched status
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param lpcompId
* Low power comparator Id \ref cy_en_adccomp_lpcomp_id_t.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_LPCOMP_ClearLatch (CyADCCOMP_Type *base,
                                                                   cy_en_adccomp_lpcomp_id_t lpcompId);


/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_Init
****************************************************************************//**
*
* Configures ADC block for DC conversion or analog MIC mode for audio acquistion
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param adcMode
* ADC mode of operation \ref cy_en_adccomp_adc_mode_t.
*
* \param pCfg
* The pointer to the configuration structure \ref cy_stc_adccomp_adc_config_t.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_ADC_Init ( CyADCCOMP_Type *base,
                                                       cy_en_adccomp_adc_mode_t adcMode,
                                                       cy_stc_adccomp_adc_config_t *pCfg);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_SelectDcChannel
****************************************************************************//**
*
* Sets the specified DC measurement channel.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param channel
* The DC measurement channel \ref cy_en_adccomp_adc_dc_channel_t.
*
* \note This function is useful for DC measurement only.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_ADC_SelectDcChannel(CyADCCOMP_Type * base,
                                                                     cy_en_adccomp_adc_dc_channel_t channel);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_SetPgaGain
****************************************************************************//**
*
* Configures the PGA gain (gain factor 1 to 8) for MIC.
* In DC mode, gain not applicable, i.e gain = 1.
* This API must be called before ADC enabled
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param gain
* The gain value \ref cy_en_adccomp_adc_pga_gain_ctrl_t.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_SetPgaGain(CyADCCOMP_Type *  base, cy_en_adccomp_adc_pga_gain_ctrl_t gain);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_Enable
****************************************************************************//**
*
* Enable ADC for DC operation or MIC audio capture.
* CY_ADCCOMP_INTR_ADC_READY \ref group_adccomp_macros_interrupt interrupt get generated,
* on ADC LDO stable(i.e. ADC ready for operation). From interrupt callback, call
* below APIs for corresponding operation.
* DC mode:
*   DC conversion: Call Cy_ADCCOMP_ADC_Start for DC conversion
*   DC calibration: Call Cy_ADCCOMP_ADC_InitiateDcCalibration
*   MIC audio capture: call pdmpcm APIs \ref cy_pdm_pcm.h to capture PCM audio samples
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_ADC_Enable ( CyADCCOMP_Type *base );


/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_Start
****************************************************************************//**
*
* Triggers CIC operation for DC conversion.
* CY_ADCCOMP_INTR_CIC \ref group_adccomp_macros_interrupt interrupt get generated
* on CIC operation completion. From interrupt callback, call corresponding APIs to get DC result.
* For DC calibration value, call Cy_ADCCOMP_GetDcOffset to get signed DCc alibration result. User has
* to save this value in memory \ref cy_stc_adccomp_adc_context_t and use it in subsequent DC measures.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_ADC_Start ( CyADCCOMP_Type *base );

/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_Stop
****************************************************************************//**
*
* Disables PDM data sync and CIC filter.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_ADC_Stop ( CyADCCOMP_Type *base );

/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_InitiateDcCalibration
****************************************************************************//**
*
* Configures ADC for DC calibration.
* CY_ADCCOMP_INTR_ADC_READY \ref group_adccomp_macros_interrupt interrupt get generated
* From interrupt callback, call Cy_ADCCOMP_ADC_Start to start CIC operation.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_ADC_InitiateDcCalibration ( CyADCCOMP_Type *base );

/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_EndDcCalibration
****************************************************************************//**
*
* Program register to power down the ADC DC calibration mode.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
*******************************************************************************/
void Cy_ADCCOMP_ADC_EndDcCalibration ( CyADCCOMP_Type *base );

/*******************************************************************************
* Function Name: Cy_ADCCOMP_ADC_Disable
****************************************************************************//**
*
* Program register to power down the ADC block.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The status \ref cy_en_adccomp_status_t.
*
*******************************************************************************/
cy_en_adccomp_status_t Cy_ADCCOMP_ADC_Disable ( CyADCCOMP_Type *base );

/*******************************************************************************
* Function Name: Cy_ADCCOMP_EnableTimer
****************************************************************************//**
*
* Enables the timer. \ref Cy_ADCCOMP_SetTimerPeriod for timer requirement.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
*******************************************************************************/
__STATIC_INLINE void Cy_ADCCOMP_EnableTimer(CyADCCOMP_Type * base)
{
    base->TIMER_CTRL |= ADCCOMP_TIMER_CTRL_TIMER_EN_Msk;
    (void)base->TIMER_CTRL; /* Dummy read to ensure write is done before return */
}


/*******************************************************************************
* Function Name: Cy_ADCCOMP_DisableTimer
****************************************************************************//**
*
* Disables the timer.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
*******************************************************************************/
__STATIC_INLINE void Cy_ADCCOMP_DisableTimer(CyADCCOMP_Type * base)
{
    base->TIMER_CTRL &= ~ADCCOMP_TIMER_CTRL_TIMER_EN_Msk;
    (void)base->TIMER_CTRL; /* Dummy read to ensure write is done before return */
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_SetTimerPeriod
****************************************************************************//**
*
* Sets the timer period.
* Timer control APIs allows the user to give extra time to ADC LDO to become stable.
* By default driver bypass the timer and relay on ADC's GMLDO OK signal to generate 
* CY_ADCCOMP_INTR_ADC_READY \ref group_adccomp_macros_interrupt.
* For examle, at 2.048Mhz default value(= 0xCD) count will be programmed to generate
* CY_ADCCOMP_INTR_ADC_READY interrupt based on ADC GM LDO OK signal to indicate
* that 100us has lapsed and the ADC's LDO is stable. User can adjust this count
* through external timer using these APIs.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param period
* The 16-bit timer period.
*
*******************************************************************************/
__STATIC_INLINE void Cy_ADCCOMP_SetTimerPeriod(CyADCCOMP_Type * base, uint16_t period)
{
    CY_REG32_CLR_SET(base->TIMER_CTRL, ADCCOMP_TIMER_CTRL_TIMER_LIMIT, period);
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_GetDcResult
****************************************************************************//**
*
* Returns the DC conversion result from the CIC status register.
* Note:- Driver programs HW to get calibrated DC conversion result, so user
* must program valid calibration offset value using #Cy_ADCCOMP_SetDcOffset
* before start DC measurement operation.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The signed DC conversion result.
*
*******************************************************************************/
__STATIC_INLINE int16_t Cy_ADCCOMP_GetDcResult ( CyADCCOMP_Type const *base )
{
    //CIC count range: 0x0000 - 0x7FFF.
    //Clip >0x8000 to 0x8000

    uint16_t val = ((uint16_t)_FLD2VAL(ADCCOMP_CIC_STATUS_CIC, base->CIC_STATUS));
    return ((int16_t)(val > 0x7FFF ? 0x7FFF : val));

}
/*******************************************************************************
* Function Name: Cy_ADCCOMP_SetDcOffset
****************************************************************************//**
*
* Sets the offset value for DC measurement calibration.
* HW CIC updated with offset value
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param offset
* The offset value.
*
* \param context
* The pointer to the context structure \ref cy_stc_adccomp_adc_context_t.
*
*******************************************************************************/
void Cy_ADCCOMP_SetDcOffset( CyADCCOMP_Type *base, int16_t offset,
                                        cy_stc_adccomp_adc_context_t * context);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_GetCalibrationResult
****************************************************************************//**
*
* Get the DC calibration offset
* API must be called after successful completion of DC calibration procedure
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The signed DC calibration result.
*
*******************************************************************************/
__STATIC_INLINE int16_t Cy_ADCCOMP_GetCalibrationResult( CyADCCOMP_Type const *base )
{
    //DC common mode compensation(i.e. DC calibration offset) signed value: CIC_STATUS[31:16]
    return ((int16_t)((uint16_t)_FLD2VAL(ADCCOMP_CIC_STATUS_DC_OFFSET, base->CIC_STATUS)));
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_SetDcGain
****************************************************************************//**
*
* Sets the gain value for DC measurement calibration.
* For H1 ADCCOMP IP, this is 2 ^ 15 = 0x8000,
* essentially it is an amount of raw counts per 1 volt of input voltage.
*
* \param gain
* The gain value.
*
* \param context
* The pointer to the context structure \ref cy_stc_adccomp_adc_context_t.
*
*******************************************************************************/
void Cy_ADCCOMP_SetDcGain(int16_t gain, cy_stc_adccomp_adc_context_t * context);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_CountsTo_mVolts
****************************************************************************//**
*
* Convert the ADC output to millivolts as an int16. For example, if the ADC
* measured 0.534 volts, the return value would be 534.
* The calculation of voltage depends on the DC range.
* The equation used is:
*
*     mV = (RawCounts) * 1000 / Gain
*
* where,
* - RawCounts: Raw counts returned by the \ref Cy_ADCCOMP_GetDcResult.
* - Driver programs the hardware to adjust Raw counts by the \ref Cy_ADCCOMP_SetDcOffset,
*   essentially it is a raw count value of ADC internal ground voltage measurement.
* - 1000 *  - amount of millivolts in 1 volt
* - Gain: the gain value, can be adjusted by the \ref Cy_ADCCOMP_SetDcGain, depends on DC range,
*   essentially it is an amount of raw counts per 1 volt of input voltage.
*
* \note
* This function is for DC measurement only.
*
* \param adcCounts
* Conversion result from \ref Cy_ADCCOMP_GetDcResult
*
* \param context
* The pointer to the context structure \ref cy_stc_adccomp_adc_context_t.
*
* \return
* Result in millivolts.
*
*
*******************************************************************************/

__STATIC_INLINE int16_t Cy_ADCCOMP_CountsTo_mVolts(int16_t adcCounts, cy_stc_adccomp_adc_context_t const * context)
{
    uint32_t count = (uint16_t)adcCounts;
    uint32_t gain = (uint16_t)context->gain;
    int16_t result = ((count* CY_ADCCOMP_MV) / gain);

    return result;
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_CountsTo_uVolts
****************************************************************************//**
*
* Convert the ADC output to microvolts as an int32. For example, if the ADC
* measured 0.534 volts, the return value would be 534000.
* The calculation of voltage depends on the DC range.
* The equation used is:
*
*     uV = (RawCounts) * 1000000 / Gain
*
* where,
* - RawCounts: Raw counts returned by the \ref Cy_ADCCOMP_GetDcResult.
* - Driver programs the hardware to adjust Raw counts by the \ref Cy_ADCCOMP_SetDcOffset,
*   essentially it is a raw count value of ADC internal ground voltage measurement.
* - 1000000 - amount of microvolts in 1 volt
* - Gain: the gain value, can be adjusted by the \ref Cy_ADCCOMP_SetDcGain, depends on DC range,
*   essentially it is an amount of raw counts per 1 volt of input voltage.
*
* \note
* This function is for DC measurement only.
*
* \param adcCounts
* Conversion result from \ref Cy_ADCCOMP_GetDcResult
*
* \param context
* The pointer to the context structure \ref cy_stc_adccomp_adc_context_t.
*
* \return
* Result in microvolts.
*
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_ADCCOMP_CountsTo_uVolts(int16_t adcCounts, cy_stc_adccomp_adc_context_t const * context)
{
    uint64_t count = (uint16_t)adcCounts;
    uint64_t gain = (uint16_t)context->gain;
    int32_t result = ((count* CY_ADCCOMP_UV) / gain);

    return result;
}


/*******************************************************************************
* Function Name: Cy_ADCCOMP_GetStatusRegisterVal
****************************************************************************//**
*
* Reads the ADCCOMP status register.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* ADC Status register value \ref cy_adccomp_status_register_mask_t.
*
*******************************************************************************/
__STATIC_INLINE UINT32 Cy_ADCCOMP_GetStatusRegisterVal ( CyADCCOMP_Type const *base )
{
    return (base->ADC_STATUS);
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_EnableInterrupt
****************************************************************************//**
*
* Sets the specified interrupt bit in the interrupt mask register.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param intrMask
* The mask of interrupts.
* Select one or more values from \ref group_adccomp_macros_interrupt and "OR" them together.
* - \ref CY_ADCCOMP_INTR_LPCOMP1
* - \ref CY_ADCCOMP_INTR_LPCOMP2
* - \ref CY_ADCCOMP_INTR_CIC
* - \ref CY_ADCCOMP_INTR_ADC_READY
*
*
*******************************************************************************/
void Cy_ADCCOMP_EnableInterrupt(CyADCCOMP_Type * base, uint32_t intrMask);


/*******************************************************************************
* Function Name: Cy_ADCCOMP_DisableInterrupt
****************************************************************************//**
*
* Clears the specified interrupt bit in the interrupt mask register.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param intrMask
* The mask of interrupts.
* Select one or more values from \ref group_adccomp_macros_interrupt and "OR" them together.
* - \ref CY_ADCCOMP_INTR_LPCOMP1
* - \ref CY_ADCCOMP_INTR_LPCOMP2
* - \ref CY_ADCCOMP_INTR_CIC
* - \ref CY_ADCCOMP_INTR_ADC_READY
*
*
*******************************************************************************/
void Cy_ADCCOMP_DisableInterrupt(CyADCCOMP_Type * base, uint32_t intrMask);

/*******************************************************************************
* Function Name: Cy_ADCCOMP_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt status.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The interrupt status.
*
*******************************************************************************/
__STATIC_INLINE UINT32 Cy_ADCCOMP_GetInterruptStatus(CyADCCOMP_Type const * base)
{
    return (base->INTR & CY_ADCCOMP_INTR);
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_ClearInterrupt
****************************************************************************//**
*
* Clears the specified interrupts status.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param intrMask
* The mask of interrupts to clear. Typically this will be the value returned
* from \ref Cy_ADCCOMP_GetInterruptStatus.
* Alternately, select one or more values from \ref group_adccomp_macros_interrupt and "OR" them together.
* - \ref CY_ADCCOMP_INTR_LPCOMP1
* - \ref CY_ADCCOMP_INTR_LPCOMP2
* - \ref CY_ADCCOMP_INTR_CIC
* - \ref CY_ADCCOMP_INTR_ADC_READY
*
*******************************************************************************/
__STATIC_INLINE void Cy_ADCCOMP_ClearInterrupt(CyADCCOMP_Type * base, UINT32 intrMask)
{
    base->INTR = intrMask & CY_ADCCOMP_INTR;
    /* This dummy reading is necessary here. It provides a guarantee that interrupt is cleared at returning from this function. */
    (void) base->INTR;
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask value.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The interrupt mask value.
*
*******************************************************************************/
__STATIC_INLINE UINT32 Cy_ADCCOMP_GetInterruptMask(CyADCCOMP_Type const * base)
{
    return (base->INTR_MASK);
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_SetInterrupt
****************************************************************************//**
*
* sets the interrupt.
* Intended mostly for debugging.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param intrMask
* The mask of interrupts.
* Select one or more values from \ref group_adccomp_macros_interrupt and "OR" them together.
* - \ref CY_ADCCOMP_INTR_LPCOMP1
* - \ref CY_ADCCOMP_INTR_LPCOMP2
* - \ref CY_ADCCOMP_INTR_CIC
* - \ref CY_ADCCOMP_INTR_ADC_READY
*
*******************************************************************************/
__STATIC_INLINE void Cy_ADCCOMP_SetInterrupt(CyADCCOMP_Type * base, uint32_t intrMask)
{
    base->INTR_SET = intrMask & CY_ADCCOMP_INTR;
}

/*******************************************************************************
* Function Name: Cy_ADCCOMP_SetInterruptMask
****************************************************************************//**
*
* Write interrupt mask value into interrupt mask register.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \param intrMask
* The mask of interrupts.
* Select one or more values from \ref group_adccomp_macros_interrupt and "OR" them together.
* - \ref CY_ADCCOMP_INTR_LPCOMP1
* - \ref CY_ADCCOMP_INTR_LPCOMP2
* - \ref CY_ADCCOMP_INTR_CIC
* - \ref CY_ADCCOMP_INTR_ADC_READY
*
*******************************************************************************/
__STATIC_INLINE void Cy_ADCCOMP_SetInterruptMask(CyADCCOMP_Type * base, uint32_t intrMask)
{
    base->INTR_MASK = intrMask;
}

/*******************************************************************************
* Function Name: Cy_ADC_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the logical AND of the corresponding INTR and INTR_MASK fields
* in a single-load operation.
*
* \param base
* The pointer to the hardware ADCCOMP block.
*
* \return
* The masked interrupt status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_ADCCOMP_GetInterruptStatusMasked(CyADCCOMP_Type const * base)
{
    return (base->INTR_MASKED);
}


/** \brief ADCCOMP - Interrupt Callback from IRQ Thread */
typedef void(*CY_ADCCOMP_IRQ_THREAD_CB_t)(void);
cy_en_adccomp_status_t Cy_ADCCOMP_RegisterIntrCallback ( CY_ADCCOMP_IRQ_THREAD_CB_t pCb);

#if defined(__cplusplus)
}
#endif


#endif // _CY_ADCCOMP_H_

/* [] END OF FILE */

