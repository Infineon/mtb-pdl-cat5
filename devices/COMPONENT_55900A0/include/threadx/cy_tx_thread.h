//==================================================================================================
//                        THIS INFORMATION IS PROPRIETARY TO BROADCOM CORP
//--------------------------------------------------------------------------------------------------
//                               Copyright (c) 2011 Broadcom Corp.
//                               Copyright (c) 2018 Cypress Semi.
//                                      ALL RIGHTS RESERVED
//==================================================================================================
//! \file
//!
//! Thread creation and management interface for the ThreadX RTOS.
//
//==================================================================================================

#ifndef _CY_TX_THREAD_H_
#define _CY_TX_THREAD_H_

#include "cy_pdl_wrapper.h"
#include "cy_device.h"
#include "cy_smif_psram.h"

//! Disables interrupt according to prived mask for drivers only.
//! Does not allows for manipulation of other interrupts.
int thread_ap_DisableDriverInts(UINT64 mask);

//! Enables interrupt according to prived mask for drivers only.
//! Does not allows for manipulation of other interrupts.
int thread_ap_EnableDriverInts(UINT64 mask);

int thread_ap_ClearPendingDriverInts(UINT64 mask);

//! This function calls all SVCs.
//! There is no other entry point allowed for SVCs (with the exception of one ThreadX SVC.)
int thread_ap_CallSVC(void);

//! Sets baud rate for HCI UART.
void thread_ap_setUartbaudRate(UINT32 baud_rate);

//! Save desired baudrate when app tries to configure baudrate before uart transport is up.
void thread_ap_saveDesiredBaudRate(UINT32 baud_rate);

//! Sends message from MPAF to transport.
void thread_ap_transPutMsg(void *msg);

//! Set wake up source (limited to LHL GPIOs, Quadrature and Keyscan).
int thread_ap_SetMPAFwakeUpSource(UINT32 mask);

//! Allow devices to access a memory range in non-secure SRAM.
BOOL32 thread_ap_sec_hw_openDeviceAccess(SEC_HW_DEVICE_t device, UINT8 *address, UINT32 length, UINT32 index);

//! Allocates permanent memory.
void* thread_ap_memory_AllocatePermanent(UINT32 size_bytes);

#if NVRAM_SUPPORTED
UINT32 thread_ap_config_VS_Read (UINT16 vsID, UINT32 itemLength, UINT8 *payload);
UINT32 thread_ap_config_VS_Write (UINT16 vsID, UINT32 itemLength, UINT8 *payload);
BOOL32 thread_ap_config_VS_Delete (UINT16 vsId);
#endif

void thread_ap_watchdog_HardResetHelper(void);
BOOL8 thread_ap_watchdog_ConfigureTime(UINT8 time_s);

#ifdef SMIF_CY
BOOL8 thread_ap_cy_smif_flash_ReadMemory (UINT32 address, UINT8 *rxBuffer, UINT32 rxSize);
BOOL8 thread_ap_cy_smif_flash_WriteMemory(UINT32 address, UINT8 *txBuffer, UINT32 txSize);
BOOL8 thread_ap_cy_smif_flash_EraseMemory(UINT32 address, UINT32 length);
#endif

UINT32 thread_ap_rbg_rand(BOOL32 requires_high_quality_rng);

#if defined(SMIF_CY) && defined(TZ_ACTIVE) && defined(BCM55900)
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_Initialize(BTSS_SYSTEM_NVRAM_OTA_HEADER_t *hdr, UINT32 size);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_EraseAltImageMemory(UINT32 address, UINT32 size);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_WriteAltImageMemory(UINT32 address, UINT8 * txBuffer, UINT32 txSize);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_SwitchToAltImage(void);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_Deinitialize(void);
#endif

BOOL8 thread_ap_smif_psram_Init(cy_smif_psram_device_cfg_t * cfg);
BOOL8 thread_ap_smif_psram_DeInit();


#endif // _CY_TX_THREAD_H_
