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

// This is a stub. Too many dependencies to be brought in as is. Expand as necessary.

#ifndef _CY_TX_THREAD_H_
#define _CY_TX_THREAD_H_


#include "cy_pdl_wrapper.h"
#include "cy_device.h"
#include "btss_system.h"


//! Disables interrupt according ot prived mask for drivers only.
//! Does not allows for manipulaiotn of other interrupts.
int thread_ap_DisableDriverInts(UINT64 mask);

//! Enables interrupt according ot prived mask for drivers only.
//! Does not allows for manipulaiotn of other interrupts.
int thread_ap_EnableDriverInts(UINT64 mask);

int thread_ap_ClearPendingDriverInts(UINT64 mask);

//! Sets baud rate for HCI UART.
void thread_ap_setUartbaudRate(UINT32 baud_rate);

//! Save desired baudrate when app tries to configure baudrate before uart transport is up.
void thread_ap_saveDesiredBaudRate(UINT32 baud_rate);

//! Sends message from MPAF to transport.
void thread_ap_transPutMsg(void *msg);

//! Set wake up source (limited to LHL GPIOs, Quadrature and Keyscan)
int thread_ap_SetMPAFwakeUpSource(UINT32 mask);


#if NVRAM_SUPPORTED
UINT32 thread_ap_config_VS_Read (UINT16 vsID, UINT32 itemLength, UINT8 *payload);
UINT32 thread_ap_config_VS_Write (UINT16 vsID, UINT32 itemLength, UINT8 *payload);
BOOL32 thread_ap_config_VS_Delete (UINT16 vsId);
#endif

void thread_ap_watchdog_HardResetHelper(void);

UINT32 thread_ap_rbg_rand(void);

#if defined(SMIF_CY) && defined(TZ_ACTIVE) && defined(BCM55500)
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_Initialize(BTSS_SYSTEM_NVRAM_OTA_HEADER_t *hdr, UINT32 size);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_EraseAltImageMemory(UINT32 address, UINT32 size);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_WriteAltImageMemory(UINT32 address, UINT8 * txBuffer, UINT32 txSize);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_SwitchToAltImage(void);
#endif

#endif // _CY_TX_THREAD_H_
