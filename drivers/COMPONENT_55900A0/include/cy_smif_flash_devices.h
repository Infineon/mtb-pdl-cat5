/***************************************************************************//**
* \file cy_smif_flash_devices.h
* \version 1.10.1
*
* \brief
*  This file includes the supported flash devices.
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

#if !defined(CY_SMIF_FLASH_DEVICES_H)
#define CY_SMIF_FLASH_DEVICES_H

#include "cy_smif.h"
#include "cy_smif_memslot.h"
#include "brcm_fw_types.h"
#include "supported_flash/sfdp_flash.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************************************************
* Global Constants
***************************************************************************/

#define CY_SMIF_DOUBLE_BUFFER_MEMCPY_SIZE_BYTES  128u /* 16-byte aligned recommended */
#define CY_SMIF_DOUBLE_BUFFER_MEMCPY_SIZE_WORDS (CY_SMIF_DOUBLE_BUFFER_MEMCPY_SIZE_BYTES >> 2)

#ifdef CLOCK_TREE_PS_PLL_V2_SUPPORTED
#define CY_SMIF_CLOCK_SRC                        CLOCK_SMIF_CLK_SRC_PLL0
#else
#ifdef PS_PLL_ENABLED
#define CY_SMIF_PLL_770M_DIV_UNUSED              0xFFu
/* Default PLL config is for VCO = 770.048MHz. Divider 8 is used to get 96MHz */
#define CY_SMIF_PLL_770M_DIV_FOR_96M             0x08u
/* Default PLL config is for VCO = 770.048MHz. Divider 4 is used to get 192MHz */
#define CY_SMIF_PLL_770M_DIV_FOR_192M            0x04u

#define CY_SMIF_CLOCK_SRC                        CLOCK_SMIF_CLK_SRC_PLL
#define CY_SMIF_CLOCK_SRC_PLL_CFG                CLOCK_PSPLL_CFG_MAN_192MHz_CH0_96MHz
#define CY_SMIF_CLOCK_SRC_PLL_DIV                CY_SMIF_PLL_770M_DIV_UNUSED
#else
#define CY_SMIF_CLOCK_SRC                        CLOCK_SMIF_CLK_SRC_FLL
#endif //PS_PLL_ENABLED
#endif //CLOCK_TREE_PS_PLL_V2_SUPPORTED

/* Set it high enough for the sector erase operation to complete */
#define CY_SMIF_MEMORY_BUSY_CHECK_RETRIES       (750u)

/* Timeout used in polling of the transfer status of SMIF block */
#define CY_SMIF_TRANSFER_TIMEOUT                (1000u) /* microseconds */

#define CY_SMIF_DEVICE_NUM                      1

#define CY_SMIF_BOOT_SLAVE_SELECT                CY_SMIF_SLAVE_SELECT_0
#define CY_SMIF_BOOT_DATA_SELECT                 CY_SMIF_DATA_SEL0


#define CY_SMIF_JEDEC_ID_COMMAND   (0x9Fu)  /**< JEDEC Standard command to read manufacturer ID */
#define CY_SMIF_JEDEC_ID_SIZE      (3u)     /**< JEDEC Manufacturer ID is typically 3 bytes
                                             * followed by additional info
                                             */


#define CY_SMIF_JEDEC_ID_MASK                    0x0000FFFF      /* 1st Byte - Manufacturer ID
                                                                   2nd Byte - Device ID MSB - Memory Type
                                                                   3rd Byte - Device ID LSB - Memory Size
                                                                   4th Byte - Unused
                                                                 */




#define CY_SMIF_NO_DEVICE                        0xFFFFFFFF

#define CY_SMIF_TIMEOUT_1_MS                     (1000u) /* microseconds */

#define CY_SMIF_MERGE_CYCLES                     CY_SMIF_MERGE_TIMEOUT_256_CYCLES


#if MINIDRIVER
#define S25FS064S_OR_S25HS512T_CFG_REG3_SECTOR_UNIFORM_EN_MASK      0x08u
#define S25FS064S_OR_S25HS512T_CFG_REG3_ERASE_BLANK_CHECK_EN_MASK   0x20u
#define S25FS064S_OR_S25HS512T_CFG_REG3_NV_ADR                      0x00000004u

/* Non-volatile register write time */
#define S25HS512T_NV_REG_WRITE_TIME                                 (360u)
#define S25HS512T_JEDEC_ID                                          0x001A2B34u
#define S25HS512T_SECTOR_SIZE                                       (256 * 1024u) /* 256KB Sector Size */

/* Non-volatile register write time */
#define S25FS064S_NV_REG_WRITE_TIME                                 (725u)
#define S25FS064S_JEDEC_ID                                          0x00170201u
#define S25FS064S_SECTOR_SIZE                                       (64 * 1024u) /* 64KB Sector Size */
#endif


extern cy_stc_smif_mem_config_t* g_smif_memConfigs[CY_SMIF_DEVICE_NUM];


void cy_smif_flash_devices_Initialize(void);
void sfdp_flash_InitializeVariablesBeforeScatterload(void);

#if defined(__cplusplus)
}
#endif

#endif /* (CY_SMIF_FLASH_DEVICES_H) */


/* [] END OF FILE */
