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
#include "cy_smif_memslot.h"

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

#if defined(XIP_BUILD)
// this structure is used to restore the smif parameters that were configured when it went through SFDP when
// chip came up as BCM55500A0 before jumping to BCM55900 XIP mode.  The configuration was saved during
// BCM55900 XIP boot by the secure code and stored at the beginning of patch RAM.  The non-secure code
//  must restore the configuration before this patch RAM area is used for other purposes.

typedef struct
{
    uint32_t numOfAddrBytes;                              /**< This specifies the number of address bytes used by the
                                                          * memory slave device, valid values 1-4 */
    uint32_t memSize;                                     /**< The memory size: For densities of 2 gigabits or less - the size in bytes;
                                                          * For densities 4 gigabits and above - bit-31 is set to 1b to define that
                                                          * this memory is 4 gigabits and above; and other 30:0 bits define N where
                                                          * the density is computed as 2^N bytes.
                                                          * For example, 0x80000021 corresponds to 2^30 = 1 gigabyte.
                                                          */
    cy_stc_smif_mem_cmd_t readCmd;                       /**< This specifies the Read command */
    cy_stc_smif_mem_cmd_t writeEnCmd;                    /**< This specifies the Write Enable command */
    cy_stc_smif_mem_cmd_t writeDisCmd;                   /**< This specifies the Write Disable command */
    cy_stc_smif_mem_cmd_t eraseCmd;                      /**< This specifies the Erase command */
    uint32_t eraseSize;                                   /**< This specifies the sector size of each Erase */
    cy_stc_smif_mem_cmd_t chipEraseCmd;                  /**< This specifies the Chip Erase command */
    cy_stc_smif_mem_cmd_t programCmd;                    /**< This specifies the Program command */
    uint32_t programSize;                                 /**< This specifies the page size for programming */
    cy_stc_smif_mem_cmd_t readStsRegWipCmd;              /**< This specifies the command to read the WIP-containing status register  */
    cy_stc_smif_mem_cmd_t readStsRegQeCmd;               /**< This specifies the command to read the QE-containing status register */
    cy_stc_smif_mem_cmd_t writeStsRegQeCmd;              /**< This specifies the command to write into the QE-containing status register */
    cy_stc_smif_mem_cmd_t readSfdpCmd;                   /**< This specifies the read SFDP command */
#if (0) //include for ROM code backport
    cy_stc_smif_mem_cmd_t  deepPowerDownCmd;             /**< This specifies the deep power down command */
    cy_stc_smif_mem_cmd_t  releasePowerDownCmd;          /**< This specifies the release power down command */
#endif
    uint32_t stsRegBusyMask;                              /**< The Busy mask for the status registers */
    uint32_t stsRegQuadEnableMask;                        /**< The QE mask for the status registers */
    uint32_t eraseTime;                                   /**< Max time for erase type 1 cycle time in ms */
    uint32_t chipEraseTime;                               /**< Max time for chip erase cycle time in ms */
    uint32_t programTime;                                 /**< Max time for page program cycle time in us */
    uint32_t hybridRegionCount;                           /**< This specifies the number of regions for memory with hybrid sectors */
#if 0 // NULL pointer
    cy_stc_smif_hybrid_region_info_t** hybridRegionInfo;  /**< This specifies data for memory with hybrid sectors */
    cy_stc_smif_mem_cmd_t readLatencyCmd;                   /**< This specifies the command to read variable latency cycles configuration register */
    cy_stc_smif_mem_cmd_t writeLatencyCmd;               /**< This specifies the command to write variable latency cycles configuration register */
#endif
    uint32_t latencyCyclesRegAddr;                        /**< This specifies the address for variable latency cycle address */
    uint32_t latencyCyclesMask;                           /**< This specifies variable latency cycles Mask */
#if(CY_IP_MXSMIF_VERSION>=2)
#if 0 // NULL pointer
    cy_stc_smif_octal_ddr_en_seq_t octalDDREnableSeq;    /**< This specifies data for memory with hybrid sectors */
    cy_stc_smif_mem_cmd_t readStsRegOeCmd;               /**< This specifies the command to read the OE-containing status register */
    cy_stc_smif_mem_cmd_t writeStsRegOeCmd;              /**< This specifies the command to write into the OE-containing status register */
#endif
    uint32_t stsRegOctalEnableMask;                       /**< The QE mask for the status registers */
    uint32_t octalEnableRegAddr;                          /**< Octal enable register address */
    cy_en_smif_interface_freq_t freq_of_operation;        /**< Frequency of operation used in Octal mode */
#endif
} cy_stc_copy_smif_mem_device_cfg_t;

typedef struct
{
    /** Determines the slave select where the memory device is placed */
    cy_en_smif_slave_select_t slaveSelect;
    /** Determines if the device is memory-mapped, enables the Autodetect
     * using the SFDP, enables the write capability, or enables the crypto
     * support for this memory slave */
    uint32_t flags;
    /** The data-line selection options for a slave device */
    cy_en_smif_data_select_t dataSelect;
    /** The base address the memory slave is mapped to in the PSoC memory map.
     * This address must be a multiple of the SMIF XIP memory size/capacity. The
     * SMIF XIP memory region should NOT overlap with other memory regions
     * (with exception to dual quad mode). Valid when the memory-mapped mode is
     * enabled.
     */
    uint32_t baseAddress;
    /** The size/capacity allocated in the PSoC memory map for the memory slave
     * device. The capacity is allocated from the base address. The capacity
     * must be a power of 2 and greater or equal than 64 KB. Valid when
     * memory-mapped mode is enabled
     */
    uint32_t memMappedSize;
    /** Defines if this memory device is one of the devices in the dual quad SPI
     * configuration. Equals the sum of the slave-slot numbers.  */
    uint32_t dualQuadSlots;
    cy_stc_copy_smif_mem_device_cfg_t deviceCfg;   /**< The configuration of the device */
#if(CY_IP_MXSMIF_VERSION>=2)
    /** Continous transfer merge timeout.
     * After this period the memory device is deselected. A later transfer, even from a
     * continuous address, starts with the overhead phases (command, address, mode, dummy cycles).
     * This configuration parameter is available for CAT1B, CAT1C and CAT1D devices. */
    cy_en_smif_merge_timeout_t mergeTimeout;
#endif /* CY_IP_MXSMIF_VERSION */

} cy_stc_copy_smif_mem_config_t;


typedef struct
{
    UINT32 smif_device_jedec_id;
    void * smif_base;
    cy_stc_copy_smif_mem_config_t smif_mem_config;
}   cy_stc_copy_smif_settings_t;
#endif // defined(XIP_BUILD)
typedef enum
{
    cy_smif_flash_powerdown_disallow = 0, /* Disallow deep power down command to flash */
    cy_smif_flash_powerdown_allow_app_control = 1, /* Allow deep power down command to flash by application */
    cy_smif_flash_powerdown_allow_bt_control = 2, /* Allow deep power down command to flash by BT */
} cy_smif_flash_power_down_method_t;

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
#define Cy_SMIF_SaveHwRegs(A) secure_call_Cy_SMIF_SaveHwRegs(A)
void Cy_SMIF_SaveHwRegs(cy_stc_smif_clk_t *clkConfig);
#else
#define cy_smif_flash_isRangeValid(A,B) TRUE
#endif
BOOL32 cy_smif_flash_read( int offset, UINT8* buffer, int length);
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

cy_smif_flash_power_down_method_t smif_flash_isPowerDownCmdAllowed(void);
cy_smif_flash_power_down_method_t smif_flash_allowPowerDownCmd(cy_smif_flash_power_down_method_t allowed);
BOOL32 smif_flash_deepPowerDown(BOOL32 fromApp, UINT32 devId);
BOOL32 smif_flash_releasePowerDown(BOOL32 fromApp, UINT32 devId);

#endif //SMIF_NON_SECURE_DRIVER
#if defined(__cplusplus)
}
#endif

#endif /* (CY_SMIF_FLASH_H) */


/* [] END OF FILE */
