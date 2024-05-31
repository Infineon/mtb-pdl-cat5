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
#include "ptu.h"
#include "cy_device.h"

//! Enable peripheral device.
static inline void thread_ap_enablePeripheral(CLOCK_TPORT_PERIPHERAL_t peri, UINT8 clock_div, BOOL8 hw_reset)
{
    (void)peri;
    (void)clock_div;
    (void)hw_reset;
}

//! Disables interrupt according ot prived mask for drivers only.
//! Does not allows for manipulaiotn of other interrupts.
int thread_ap_DisableDriverInts(UINT64 mask);

//! Enables interrupt according ot prived mask for drivers only.
//! Does not allows for manipulaiotn of other interrupts.
int thread_ap_EnableDriverInts(UINT64 mask);

int thread_ap_ClearPendingDriverInts(UINT64 mask);

//! This fucntion calls all SVCs.
//! There isn o other entry point allowed for SVCs  (with exception of one ThreadX SVC.)
int thread_ap_CallSVC(void);

//! Sets baud rate for HCI UART.
void thread_ap_setUartbaudRate(UINT32 baud_rate);

//! Save desired baudrate when app tries to configure baudrate before uart transport is up.
void thread_ap_saveDesiredBaudRate(UINT32 baud_rate);

//! Sends message from MPAF to transport.
void thread_ap_transPutMsg(void *msg);

//! Set wake up source (limited to LHL GPIOs, Quadrature and Keyscan)
int thread_ap_SetMPAFwakeUpSource(UINT32 mask);

void thread_ap_watchdog_HardResetHelper(void);

#ifdef SMIF_CY
BOOL8 thread_ap_cy_smif_flash_ReadMemory (UINT32 address, UINT8 *rxBuffer, UINT32 rxSize);
BOOL8 thread_ap_cy_smif_flash_WriteMemory(UINT32 address, UINT8 *txBuffer, UINT32 txSize);
BOOL8 thread_ap_cy_smif_flash_EraseMemory(UINT32 address, UINT32 length);
#endif

UINT32 thread_ap_rbg_rand(void);

#ifdef TCPWM
void thread_ap_TcpwmInterruptControl (PTU_TCPWM_INTR_CONTROL_t control, PTU_TCPWM_INTR_EN_MASK_t mask);
#endif

//! To support LPO clock source changes from MPAF
void thread_ap_selectEnhancedLPOSource(PMU_LPO_CLK_SOURCE lpoSource, UINT16 driftRate);
//! To support clock change requests from MPAF
UINT32 thread_ap_clockRequest(CLOCK_REQ req, CLOCK_FREQ freq);

#endif // _CY_TX_THREAD_H_
