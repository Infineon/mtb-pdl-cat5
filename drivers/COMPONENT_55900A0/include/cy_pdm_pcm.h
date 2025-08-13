/***************************************************************************//**
* \file cy_pdm_pcm.h
*
* Provides API declarations of the PDM PCM driver.
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

#ifndef _CY_PDM_PCM_H_
#define _CY_PDM_PCM_H_

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

/**
* \addtogroup group_pdm_pcm_enums
* \{
*/

/** The PDM-PCM status codes*/
typedef enum
{
    CY_PDM_PCM_SUCCESS,
    CY_PDM_PCM_BAD_PARAM,
    CY_PDM_PCM_CLOCK_REQ_FAIL,
    CY_PDM_PCM_ERROR
} cy_en_pdm_pcm_status_t;

/** PDM CLK Selection*/
typedef enum
{
    CY_PDM_PCM_DMIC,    /**< Digital MIC */
    CY_PDM_PCM_AMIC        /**< Analog MIC */
} cy_en_pdm_pcm_mic_source_t;

/** PDM PCM SAMPLE RATE */
typedef enum
{

    CY_PDM_PCM_2M_16K,      /**< 2M PDM, 16K PCM sampling */
    CY_PDM_PCM_2M_8K,       /**< 2M PDM, 8K PCM sampling */
    CY_PDM_PCM_1M_16K,      /**< 1M PDM, 16K PCM sampling */
    CY_PDM_PCM_1M_8K,       /**< 1M PDM, 8K PCM sampling */
    /* Below values applicable only for Digital MIC use cases. */
    CY_PDM_PCM_512K_16K,    /**< 512K PDM, 16K PCM sampling */
    CY_PDM_PCM_512K_8K      /**< 512K PDM, 8K PCM sampling */
} cy_en_pdm_pcm_sample_rate_t;

/** \} group_pdm_pcm_enums */

/**
* \addtogroup group_pdm_pcm_data_structures
* \{
*/
/** PDM-PCM Interface structure */
typedef struct
{
    BOOL8                               pos_neg_sel; /**< latch data on positive or negative phase */
    uint8_t                             latch_phase; /**< Latch PDM data at certain phase of positive or negative edge clock. Valid range 0 to 15 */
    BOOL8                               clock_inv_sel; /**< 1: no inv   0: inv the clk_root or ADC_clk */
}cy_stc_pdm_pcm_inf_ctrl_sel_t;


/**

PDM-PCM bq filter coeff_data structure

A digital filter is characterized by its transfer function, or equivalently,
its difference equation. Mathematical analysis of the transfer function can 
describe how it will respond to any input. As such, designing a filter 
consists of developing specifications appropriate to the
problem (for example, a second-order low pass filter with a specific cut-off frequency),
and then producing a transfer function which meets the specifications.

The transfer function for a linear, time-invariant, digital filter can be expressed
as a transfer function in the Z-domain; if it is causal, then it has the form
        b1 + b2z^-1 + b3z^-2+.....
  H(Z)=------------------------------
        1 + a2z^-1 + a3z^-2+......
a1 is fixed = 1
*/
typedef struct
{
    int16_t         bq1_a2;            /**<  bq1 filter a2 coefficient */
    int16_t         bq2_a2;            /**<  bq2 filter a2 coefficient */

    int16_t         bq1_a3;            /**<  bq1 filter a3 coefficient */
    int16_t         bq2_a3;            /**<  bq2 filter a2 coefficient */

    int16_t         bq1_b1;            /**<  bq1 filter b1 coefficient */
    int16_t         bq2_b1;            /**<  bq2 filter b1 coefficient */

    int16_t         bq1_b2;            /**<  bq1 filter b2 coefficient */
    int16_t         bq2_b2;            /**<  bq2 filter b2 coefficient */

    int16_t         bq1_b3;            /**<  bq1 filter b3 coefficient */
    int16_t         bq2_b3;            /**<  bq2 filter b3 coefficient */
}cy_stc_pdm_pcm_bq_fir_coeff_t;


/** PDM-PCM control structure */
typedef struct
{
    cy_en_pdm_pcm_mic_source_t          mic_source;           /**< 0: Digital MIC, 1: Analog MIC */
    cy_en_pdm_pcm_sample_rate_t         pdm_pcm_sample_rate;    /**< PDM PCM sample rate */
    cy_stc_pdm_pcm_inf_ctrl_sel_t       *pdm_pcm_inf;        /**< NULL: Use default values. TBD: requirements/need to configure these values. */
    cy_stc_pdm_pcm_bq_fir_coeff_t       *bq_fir_coeffs;        /**< NULL: uses default bq filter coefficients */
}cy_stc_pdm_pcm_config_t;
/** \} group_pdm_pcm_data_structures */

/**
* \addtogroup group_pdm_pcm_functions
* \{
*/
/*******************************************************************************
* Function Name: Cy_PDM_PCM_Init
****************************************************************************//**
*
* Configures PDM PCM block as per PDM and PCM sampling rate.
* Programms filter coeffients, if NULL default values programmed.
* controls latching of PDM data based on interface selection. if NULL, default 
* configuration used. 
*
* \param base
* The pointer to the hardware PDMPCM IP block.
*
* \param pCfg
* The pointer to the configuration structure \ref cy_stc_pdm_pcm_config_t.
*
* \return
* The status \ref cy_en_pdm_pcm_status_t.
*
*******************************************************************************/
cy_en_pdm_pcm_status_t   Cy_PDM_PCM_Init(CyPdmPcm_Type * base, cy_stc_pdm_pcm_config_t const * config);

/*******************************************************************************
* Function Name: Cy_PDM_PCM_Enable
****************************************************************************//**
*
* Enables the PDM-PCM data conversion.
*
* \param base
* The pointer to the hardware PDMPCM IP block.
*
* \return
* The status \ref cy_en_pdm_pcm_status_t.
*
*******************************************************************************/
cy_en_pdm_pcm_status_t   Cy_PDM_PCM_Enable(CyPdmPcm_Type * base);

/*******************************************************************************
* Function Name: Cy_PDM_PCM_Disable
****************************************************************************//**
*
* Disables the PDM-PCM data conversion.
*
* \param base
* The pointer to the hardware PDMPCM IP block.
*
* \return
* The status \ref cy_en_pdm_pcm_status_t.
*
*******************************************************************************/
cy_en_pdm_pcm_status_t   Cy_PDM_PCM_Disable(CyPdmPcm_Type * base);

/*******************************************************************************
* Function Name: Cy_PDM_PCM_SetFifoLevel
****************************************************************************//**
*
* Sets FIFO water mark level.Registered callback get called once FIFO reached
* to water mark level. Max wmLevel = 127
*
* \return
* The status \ref cy_en_pdm_pcm_status_t.
*
*******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_SetFifoLevel(uint8_t wmLevel);

/*******************************************************************************
* Function Name: Cy_PDM_PCM_GetFifoLevel
****************************************************************************//**
*
* Returns depth of FIFO.
*
* \return
* Depth of FIFO. Max value = 127
*
*******************************************************************************/
uint8_t Cy_PDM_PCM_GetFifoLevel ( void );

/******************************************************************************
* Function Name: Cy_PDM_PCM_FreezeFifo
***************************************************************************//**
*
* Freezes the RX FIFO
*
* Note:- Cy_PDM_PCM_Disable must be called before invoke this API.
*
******************************************************************************/
void Cy_PDM_PCM_FreezeFifo( void );

/******************************************************************************
* Function Name: Cy_PDM_PCM_UnfreezeFifo
***************************************************************************//**
*
* Unfreezes the RX FIFO
*
******************************************************************************/
void Cy_PDM_PCM_UnfreezeFifo( void );

/******************************************************************************
* Function Name: Cy_PDM_PCM_ClearFifo
***************************************************************************//**
*
* Resets the output data FIFO, removing all data words from the FIFO.
*
* Note:- Cy_PDM_PCM_FreezeFifo must be called before invoke this API.
*
******************************************************************************/
void Cy_PDM_PCM_ClearFifo( void );

/*******************************************************************************
* Function Name: Cy_PDM_PCM_ReadFifoAll
****************************************************************************//**
*
* Reads whole the FIFO payload into the data array.
*
* \param pData
* The pointer to the 32 bit array for the FIFO payload.
*
* \param pDatalen
* number of 32 bit data entries. Max value allowed is 128.
*
* \param pFifoCntx
* FIFO context. This is the value returned in registered callback's argument
*
* \return
* The status \ref cy_en_pdm_pcm_status_t.
*
*******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_ReadFifoAll(uint32_t *pData, uint8_t *pDatalen, uint8_t *pFifoCntx);

/*******************************************************************************
* Function Name: Cy_PDM_PCM_DeInit
****************************************************************************//**
*
* De initializes PDMPCM block.
*
* \param base
* The pointer to the hardware PDMPCM IP block.
*
*
*******************************************************************************/
void Cy_PDM_PCM_DeInit ( CyPdmPcm_Type * base );

/** \brief PDMPCM - FIFO Interrupt Callback from IRQ Thread */
typedef void(*CY_PDM_PCM_IRQ_THREAD_CB_t)(uint8_t *pFifoCntx);
cy_en_pdm_pcm_status_t Cy_PDM_PCM_RegisterCallback ( CY_PDM_PCM_IRQ_THREAD_CB_t pCb );
/** \} group_pdm_pcm_functions */

#if defined(__cplusplus)
}
#endif

#endif //_CY_PDM_PCM_H_

/* [] END OF FILE */

