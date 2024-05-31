/********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Infineon Technologies AG
*-------------------------------------------------------------------
*
*           Copyright (c) 2022 Infineon Technologies AG
*                      ALL RIGHTS RESERVED
*
********************************************************************
*
********************************************************************************
*
* File Name: whd_hw_internal.h
*
* Abstract: Defines for WHD HW Driver
*
*******************************************************************************/

#ifndef _WHD_HW_INTERNAL_H_
#define _WHD_HW_INTERNAL_H_

#include "cy_pdl_wrapper.h"

typedef BOOL32 (*wl2bt_cb_t)(void * ctx, UINT32 db_status_mask, UINT32 *db_values, UINT8 len);

typedef struct
{
    wl2bt_cb_t cb;
    void *ctx;
} wl2bt_interrupt_callback_t;


#ifdef TZ_ACTIVE
#define whd_hw_generate_bt2wl_db_interrupt(A,B)     secure_call_whd_hw_generate_bt2wl_db_interrupt(A,B)
#define whd_hw_wl2bt_db_enable_interrupts_aux(A)    secure_call_whd_hw_wl2bt_db_enable_interrupts_aux(A)
#define whd_hw_read_db_values(A,B,C)                secure_call_whd_hw_read_db_values(A,B,C)
#define whd_hw_writeBTSwScratchpad2(A)              secure_call_whd_hw_writeBTSwScratchpad2(A)
#define whd_hw_readBTSwScratchpad2(A)               secure_call_whd_hw_readBTSwScratchpad2(A)
#define whd_hw_readWLSwScratchpad1(A)               secure_call_whd_hw_readWLSwScratchpad1(A)
#define whd_hw_readWLSwScratchpad2(A)               secure_call_whd_hw_readWLSwScratchpad2(A)
#define whd_hw_readGciChipIdRegister(A)             secure_call_whd_hw_readGciChipIdRegister(A)
#define whd_hw_wlanResetControlOverride(A)          secure_call_whd_hw_wlanResetControlOverride(A)
#define whd_hw_wlanDeassertReset                    secure_call_whd_hw_wlanDeassertReset
#define whd_hw_wlanAssertReset                      secure_call_whd_hw_wlanAssertReset
#define whd_hw_bt2wl_writeClockRequestAndStatus(A,B)    secure_call_whd_hw_bt2wl_writeClockRequestAndStatus(A,B)
#define whd_hw_bt2wl_readClockRequestAndStatus      secure_call_whd_hw_bt2wl_readClockRequestAndStatus
#endif // TZ_ACTIVE

UINT32 whd_hw_generate_bt2wl_db_interrupt(UINT32 db_index, UINT32 value);
void whd_hw_wl2bt_db_enable_interrupts_aux(UINT32 value);
UINT32 whd_hw_read_db_values(BOOL32 isCb, UINT32 *pdb_status_mask, UINT32 *pdb_values);
void whd_hw_writeBTSwScratchpad2(UINT32 value);
UINT32 whd_hw_readBTSwScratchpad2(void);
UINT32 whd_hw_readWLSwScratchpad1(void);
UINT32 whd_hw_readWLSwScratchpad2(void);
UINT32 whd_hw_readGciChipIdRegister(void);
void whd_hw_event_handler(void);
void whd_hw_interrupt_handler(void);
void whd_hw_wlanResetControlOverride(UINT32 enable);
void whd_hw_wlanDeassertReset(void);
void whd_hw_wlanAssertReset(void);
UINT32 whd_hw_bt2wl_readClockRequestAndStatus(void);
UINT32 whd_hw_bt2wl_writeClockRequestAndStatus(UINT32 bitmask, UINT32 bset);
#endif // _WHD_HW_INTERNAL_H_