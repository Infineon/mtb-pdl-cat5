/***************************************************************************//**
* \file cy_smif_flash.h
* \version 1.10.1
*
* \brief
*  This file includes the top level APIs to access a flash device.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2019, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SMIF_FLASH_H)
#define CY_SMIF_FLASH_H

#include "cyip_smif.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum
{
#ifdef CLOCK_TREE_PS_PLL_V2_SUPPORTED
    CLOCK_SMIF_CLK_SRC_PLL0 = 0, /**< ANA LP-PLL0. In FPGA - 12MHz fixed clock */
    CLOCK_SMIF_CLK_SRC_PLL1 = 1, /**< ANA LP-PLL1. In FPGA - 12MHz fixed clock */
#else
#ifdef PS_PLL_ENABLED
    CLOCK_SMIF_CLK_SRC_PLL = 0, /**< ANA PS-PLL Channel 0. In FPGA - 12MHz fixed clock */
#endif /* PS_PLL_ENABLED */
    CLOCK_SMIF_CLK_SRC_FLL = 1,  /**< FLL Channel 1 In FPGA - 4MHz fixed clock */
#endif /* CLOCK_TREE_PS_PLL_V2_SUPPORTED */
} clock_smif_clk_src_option_t;

/** The SMIF configuration structure. */
typedef struct
{
    clock_smif_clk_src_option_t      clkSource;      /**< SMIF IP Clock Source Selection \ref cy_en_smif_clk_src_option_t */
#ifdef PS_PLL_ENABLED
    clock_pspll_freq_cfg_t           pllConfig;      /**< PLL Output Frequency Selection \ref cy_en_smif_clk_src_pll_freq_t */
    BOOL8                            pllSmifChDivEn; /**< Enable PLL Manual config of divider */
    UINT8                            pllSmifChDiv;   /**< PLL Manual config of divider */
#endif
} cy_stc_smif_clk_t;

#ifndef SMIF_NON_SECURE_DRIVER
#define cy_smif_flash_DetectFlash(A) secure_call_cy_smif_flash_DetectFlash(A)
extern BOOL8 cy_smif_flash_DetectFlash(UINT32 smif_base_address);

#define cy_smif_flash_ReadMemory(A,B,C) secure_call_cy_smif_flash_ReadMemory(A,B,C)
extern BOOL8 cy_smif_flash_ReadMemory (UINT32 address, UINT8 *rxBuffer, UINT32 rxSize);

#define cy_smif_flash_WriteMemory(A,B,C) secure_call_cy_smif_flash_WriteMemory(A,B,C)
extern BOOL8 secure_call_cy_smif_flash_WriteMemory(UINT32 address, UINT8 *txBuffer, UINT32 txSize);

#define cy_smif_flash_EraseMemory(A,B) secure_call_cy_smif_flash_EraseMemory(A,B)
extern BOOL8 secure_call_cy_smif_flash_EraseMemory(UINT32 address, UINT32 length);

#define cy_smif_flash_CopyMemory(A,B,C) secure_call_cy_smif_flash_CopyMemory(A,B,C)
extern void secure_call_cy_smif_flash_CopyMemory(UINT32 dest, UINT32 src, UINT32 len);

#define cy_smif_flash_EnterFirmwareDownloadMode secure_call_cy_smif_flash_EnterFirmwareDownloadMode
extern void secure_call_cy_smif_flash_EnterFirmwareDownloadMode(void);
#else
#ifdef TZ_ACTIVE
#define cy_smif_flash_isRangeValid(A,B) secure_call_cy_smif_flash_isRangeValid(A,B)
BOOL32 cy_smif_flash_isRangeValid(UINT32 address, UINT32 length);
#else
#define cy_smif_flash_isRangeValid(A,B) TRUE
#endif
#ifdef FIX_CYW55500A0_112
BOOL32 cy_smif_flash_read( int offset, UINT8* buffer, int length);
#endif
BOOL8 cy_smif_flash_DetectFlash(UINT32 smif_base_address, BOOL32 callSaveHwRegs);
BOOL8 cy_smif_flash_ReadMemory (UINT32 address, UINT8 *rxBuffer, UINT32 rxSize);
BOOL8 cy_smif_flash_WriteMemory(UINT32 address, UINT8 *txBuffer, UINT32 txSize);
BOOL8 cy_smif_flash_EraseMemory(UINT32 address, UINT32 length);
void  cy_smif_flash_CopyMemory(UINT32 dest, UINT32 src, UINT32 len);
BOOL8 cy_smif_flash_EnableCrypto(UINT32 *cryptoKey);
BOOL8 cy_smif_flash_IsDetected(void);
void cy_smif_flash_EnterFirmwareDownloadMode(void);
void cy_smif_flash_ExitFirmwareDownloadMode(void);
void cy_smif_flash_InitializeVariablesBeforeScatterload(void);

#endif //SMIF_NON_SECURE_DRIVER
#if defined(__cplusplus)
}
#endif

#endif /* (CY_SMIF_FLASH_H) */


/* [] END OF FILE */
