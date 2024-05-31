/***************************************************************************//**
* \file whd_hw.h
*
* Provides API declarations of the WHD HW driver.
*
********************************************************************************
* \copyright
* Copyright 2023 Infineon Technologies
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

#ifndef _WHD_HW_H_
#define _WHD_HW_H_

#include "whd_hw_internal.h"



#define NUM_WL2BT_DB_REGISTERS 8
#define WHD_MAX_DOORBELL_INDEX  7

//GCI Registers
// gci_gciintmask_adr    When the 31st bit of this Reg is set, Doorbell Interrupts to the IP(BT/WLAN) are enabled
#define GCI_DB_INT_STS_BIT  ( 1U << 31 )    /* 31st bit of gci_gciintmask_adr */

typedef enum
{
    WHD_HW_SUCCESS,
    WHD_HW_OUT_OF_RANGE,
    WHD_HW_FAILURE,
} whd_hw_return_codes_t;

typedef enum
{
  WHD_HW_DEVICE_NONE,
  WHD_HW_DEVICE_SDIO,
  WHD_HW_DEVICE_WLAN,
  WHD_HW_DEVICE_SDIO_AND_WLAN,
} WHD_HW_DEVICE_t;



/*****************************************************************
* Function: whd_hw_initApi
*
* Abstract: Initialization that is performed at startup and any other
*           time lose register settings such as when come out of deep sleep.
*
* Input/Output:
*       none
*
* Return:
*       none
*
*****************************************************************/
void whd_hw_initApi(void);


/*****************************************************************
* Function: whd_hw_generateBt2WlDbInterruptApi
*
* Abstract: Write to BT2WL register, which will generate an interrupt
*           to WL
*
* Input/Output:
*       db_index: ranges from 0-7
*       value: value to write to register
*
* Return:
*       "WHD_SUCCESS" on successfully writing the value to the register
*       "WHD_OUT_OF_RANGE" if the db_index is greater than 7
*       "WHD_FAILURE" - if don't read back the value wrote
*
*****************************************************************/
UINT32 whd_hw_generateBt2WlDbInterruptApi(UINT32 db_index, UINT32 value);


/*****************************************************************
* Function: whd_hw_registerWl2BtInterruptCallbackApi
*
* Abstract: Register callback function to be called when get WL2BT doorbell interrupt,
*           and value to pass into callback function
*
* Input/Output:
*       cb: callback to be invoked when the BT receives doorbell interrupts from the WL
*       ctx: to be passed back when the callback is invoked
*
* Return:
*       none
*
*****************************************************************/
void whd_hw_registerWl2BtInterruptCallbackApi(wl2bt_cb_t cb, void* ctx);


/*****************************************************************
* Function: whd_hw_wl2BtDbEnableInterruptsApi
*
* Abstract: Specify which WL2BT doorbells will cause interrupts when
*           WL writes to them.  Save the value since it is necessary
*           to disable and then reenable the desired WLinterruptting2BT interrupts
*           at various times.
*
* Input/Output:
*       value: bits representing the WL2BT interrupts that need to be enabled/disabled
*
* Return:
*       none
*
*****************************************************************/
void whd_hw_wl2BtDbEnableInterruptsApi(UINT32 value);


/*****************************************************************
* Function: whd_hw_readDbValuesApi
*
* Abstract: Read WL2BT doorbell registers that are interrupting. If
*           the higher layer has registered a callback function, fill
*           passed in array pointer with the values from interrupting
*           doorbell registers.
*
*
* Input/Output:
*       isCb: indicates if there is a callback function registered
*       pdb_status_mask: pointer to location that will be filled in
*                        with bitmask indicating interrupting
*                        doorbell registers
*       pdb_values:  pointer to array that will be filled in
*                    with the values read from the interrupting
*                    WL2BT doorbell registers
*
* Return:
*       The number of interrupting WL2BT doorbells, which will
*       also be equal to the number of valid pdb_values[] entries
*
*****************************************************************/
UINT32 whd_hw_readDbValuesApi(BOOL32 isCb, UINT32 *pdb_status_mask, UINT32 *pdb_values);


/*****************************************************************
* Function: whd_hw_writeBTSwScratchpad2Api
*
* Abstract: Write to GCI BTSwScratchpad2 register.  This register is
*           used for handshaking between WHD and Bootloader on CR4
*           before doing WLAN FW download.
*
*
* Input/Output:
*       value: value to write to register
*
* Return:
*       none
*
*****************************************************************/
void whd_hw_writeBTSwScratchpad2Api(UINT32 value);


/*****************************************************************
* Function: whd_hw_readBTSwScratchpad2
*
* Abstract: Read from GCI BTSwScratchpad2 register.  This register is
*           used for handshaking between WHD and Bootloader on CR4
*           before doing WLAN FW download.
*
*
* Input/Output:
*       none
*
* Return:
*       value read from register
*
*****************************************************************/
UINT32 whd_hw_readBTSwScratchpad2Api(void);


/*****************************************************************
* Function: whd_hw_readWLSwScratchpad1Api
*
* Abstract: Read from GCI WLSwScratchpad1 register.
*           Written by WLAN only. Read by BT and WLAN both.
*           Reset with WLAN reset. Reset value 0.
*
*
* Input/Output:
*       none
*
* Return:
*       value read from register
*
*****************************************************************/
UINT32 whd_hw_readWLSwScratchpad1Api(void);


/*****************************************************************
* Function: whd_hw_readWLSwScratchpad2Api
*
* Abstract: Read from GCI WLSwScratchpad2 register.  This register is
*           used for handshaking between WHD and Bootloader on CR4
*           before doing WLAN FW download.
*
*
* Input/Output:
*       none
*
* Return:
*       value read from register
*
*****************************************************************/
UINT32 whd_hw_readWLSwScratchpad2Api(void);


/*****************************************************************
* Function: whd_hw_readGciChipIdRegisterApi
*
* Abstract: Read from GCI ChipID register.
*
*
* Input/Output:
*       none
*
* Return:
*       value read from register
*
*****************************************************************/
UINT32 whd_hw_readGciChipIdRegisterApi(void);


/*******************************************************************************
* Function Name: whd_hw_openDeviceAccessApi
********************************************************************************
*
* Allow devices to access a memory range in non-secure SRAM
*
* \param device
* enum specifying which devices to allow access
*
* \param address
* The starting address in memory range
*
* \param length
* The number of bytes starting from address to allow access to.
*
* \param index
* The region to map.  Allowable values are 0 and 1.

* \return Status of the operation. TRUE if opened access, otherwise FALSE
*
*******************************************************************************/
BOOL32 whd_hw_openDeviceAccessApi(WHD_HW_DEVICE_t device, UINT8 *address, UINT32 length, UINT32 index);


// number of bytes to allocate, returns NULL If fails
void* whd_hw_allocatePermanentApi(UINT32 size_bytes);


/*****************************************************************
* Function: whd_hw_wlanResetControlOverrideApi
*
* Abstract: Allow BT to to override raw WL_REG_ON signal.
*
* Input/Output:
*       enable: 1 to enable override, 0 to disable override
*
* Return:
*      none
*
*****************************************************************/
void whd_hw_wlanResetControlOverrideApi(UINT32 enable);


/*****************************************************************
* Function: whd_hw_wlanDeassertResetApi
*
* Abstract: Deassert wlan reset.
*
* Input/Output:
*       none
*
* Return:
*      none
*
*****************************************************************/
void whd_hw_wlanDeassertResetApi(void);


/*****************************************************************
* Function: whd_hw_wlanAssertResetApi
*
* Abstract: Assert wlan reset.
*
* Input/Output:
*       none
*
* Return:
*      none
*
*****************************************************************/
void whd_hw_wlanAssertResetApi(void);


/*****************************************************************
* Function: whd_hw_bt2wl_readClockRequestAndStatusApi
*
* Abstract: Read from BT2WL Clock Request and Status Register
*
* Input/Output:
*       none
*
* Return:
*       value read from register
*
*****************************************************************/
UINT32 whd_hw_bt2wl_readClockRequestAndStatusApi(void);


/*****************************************************************
* Function: whd_hw_bt2wl_writeClockRequestAndStatusApi
*
* Abstract: Write to BT2WL Clock Request and Status Register
*
* Input/Output:
*       bset: if nonzero set bits, otherwise clear bits
*       bitmask: bitmask to set or clear
*
* Return:
*       the new value of the register
*
*****************************************************************/
UINT32 whd_hw_bt2wl_writeClockRequestAndStatusApi(UINT32 bitmask, UINT32 bset);

#endif // _WHD_HW_H_