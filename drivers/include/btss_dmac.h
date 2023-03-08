/***************************************************************************//**
* \file btss_dmac.h
*
* Provides API declarations of the BTSS DMAC driver.
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

#ifndef _BTSS_DMAC_H_
#define _BTSS_DMAC_H_

#include "cy_pdl_wrapper.h"


#if defined(__cplusplus)
extern "C" {
#endif

/** Callback func is called when a DMA transfer has completed. */
typedef void (*BTSS_DMAC_CALLBACK_t)(void* arg);

/** DMAC Control register configuration */
typedef union
{
    struct {
        UINT32 length      : 12;
        UINT32 srcBurstSize: 3;
        UINT32 dstBurstSize: 3;
        UINT32 srcDataWidth: 3;
        UINT32 dstDataWidth: 3;
        UINT32 reserved_1  : 2;
        UINT32 srcIncrement: 1;
        UINT32 dstIncrement: 1;
        UINT32 reserved    : 3;
        UINT32 intEnable   : 1;
    } bitfields;
    UINT32 u32;
} BTSS_DMAC_CONTROL_REG_t;

/** DMAC Control register - Transfer data width configuration */
typedef enum
{
    BTSS_DMAC_CONTROL_REG_DATAWIDTH_1BYTE     = 0,
    BTSS_DMAC_CONTROL_REG_DATAWIDTH_HALF_WORD = 1,
    BTSS_DMAC_CONTROL_REG_DATAWIDTH_WORD      = 2,
} BTSS_DMAC_CONTROL_REG_DATAWIDTH_t;

/** DMAC Control register - Transfer burst size configuration */
typedef enum
{
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_1   = 0,
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_4   = 1,
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_8   = 2,
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_16  = 3,
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_32  = 4,
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_64  = 5,
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_128 = 6,
    BTSS_DMAC_CONTROL_REG_BURST_SIZE_256 = 7
} BTSS_DMAC_CONTROL_REG_BURST_SIZE_t;

/** DMAC Control register - DMAC Flow Control Lines configuration */
typedef enum
{
    //! None
    BTSS_DMAC_CONTROL_LINE_NONE  = 0,
BTSS_DMAC_CONTROL_LINE_SRC_HCI_UART  = 0,
BTSS_DMAC_CONTROL_LINE_DST_HCI_UART  = 0,

    //! mxtdm0 Tx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_DST_MXTDM0    = 4,
    //! mxtdm0 Rx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_SRC_MXTDM0    = 5,
    //! mxtdm1 Tx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_DST_MXTDM1    = 6,
    //! mxtdm1 Rx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_SRC_MXTDM1    = 7,
    //! scb1 Rx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_SRC_SCB1      = 9,
    //! scb0 Rx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_SRC_SCB0      = 10,
    //! scb0 Tx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_DST_SCB0      = 11,
    //! scb Tx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_DST_SCB1      = 13,
    //! scb2 Rx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_SRC_SCB2      = 14,
    //! scb2 Tx DMA flow control line
    BTSS_DMAC_CONTROL_LINE_DST_SCB2      = 15,
} BTSS_DMAC_CONTROL_LINE_t;

/** DMAC Config register configuration */
typedef union
{
    struct {
        UINT32 channelEn   : 1;
        UINT32 srcDmaLine  : 4;
        UINT32 reserved_1  : 1;
        UINT32 dstDmaLine  : 4;
        UINT32 reserved_2  : 1;
        UINT32 flowcontrol : 3;
        UINT32 tcIntMask   : 1;
        UINT32 errIntMask  : 1;
        UINT32 reserved_3  : 16;
    } bitfields;
    UINT32 u32;
} BTSS_DMAC_CONFIG_REG_t;

/** DMAC Config register - Flow control type configuration */
typedef enum
{
    //! memory-to-memory transfer.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_MEMORY_TO_MEMORY                 =  0,

    //! memory-to-peripheral transfer without flow control.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_MEMORY_TO_PERIPH_NO_FLOW         =  1,

    //! peripheral-to-memory transfer without flow control.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_PERIPH_TO_MEMORY_NO_FLOW         = 2,

    //! peripheral-to-peripheral transfer without flow control.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_PERIPH_TO_PERIPH_NO_FLOW         = 3,

    //! peripheral-to-peripheral transfer with the destination peripheral providing flow control.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_PERIPH_TO_PERIPH_DEST_FLOW       = 4,

    //! memory-to-peripheral transfer with the destination peripheral providing flow control.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_MEMORY_TO_PERIPH_DEST_FLOW       = 5,

    //! peripheral-to-memory transfer with the source peripheral providing flow control.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_PERIPH_TO_MEMORY_SRC_FLOW        = 6,

    //! peripheral-to-peripheral transfer with the source peripheral providing flow control.
    BTSS_DMAC_CONFIG_REG_FLOWCNTRL_PERIPH_TO_PERIPH_SRC_FLOW        = 7
} BTSS_DMAC_CONFIG_REG_FLOWCONTROL_t;

/** DMAC Next Linked List Descriptor */
typedef struct BTSS_DMAC_LLI_DESC
{
    //! The source address from which the data transferred by the DMA controller will be read.  The
    //! pointer can be incremented with each 8, 16, or 32 bits, depending on the SWidth and SI
    //! fields in DMACCxControl.
    const void*                                                     DMACCxSrcAddr;

    //! The destination address to which the data transferred by the DMA controller will be written.
    //! The pointer can be incremented with each 8, 16, or 32 bits, depending on the SWidth and SI
    //! fields in DMACCxControl.
    void*                                                           DMACCxDestAddr;

    //! Pointer to the next linked list item, to be processed by the DMA controller.  It contains
    //! the next set of channel control register values for as an additional segment to be
    //! transferred when this segment is done.
    struct BTSS_DMAC_LLI_DESC*                                      DMACCxLLI;

    //! Please refer to the ARM PL081 DMA controller documentation.  That documentation is more
    //! comprehensive than what can be presented here.  As for this documentation, please refer to
    //! the defines for flags and masks with names beginning in DMACCXCONTROL_.
    UINT32                                                          DMACCxControl;
} BTSS_DMAC_LLI_DESC_t;

/** DMAC messaging for internal queue */
typedef struct BTSS_DMAC_MSG
{
    //! Pointer to next msg
    struct BTSS_DMAC_MSG* next;

    //! msg code
    UINT32 code;
} BTSS_DMAC_MSG_t;

/** DMA transfer request control block, to be used with a call to dma_RequestTransfer. */
typedef struct BTSS_DMAC_APP_REQUEST
{
    //! Pointer to a pending transfer request on a shared channel.  The list is maintained by the
    //! DMA driver, and deferred requests will be initiated in first-in-first-out order whenever a
    //! previous transfer request has completed.
    struct BTSS_DMAC_APP_REQUEST*                                    next;

    //! DMA channel number on which the transfer is to be executed.  Which channel should be used
    //! is determined by a chip-specific DMA channel map, with constants named DMA_CHANNEL_*.
    UINT8                                                           channel;

    //! Function pointer specifying a function to be called when the DMA transfer has completed.  As
    //! the name indicates, this function is always called from the DMA complete interrupt.  The
    //! function pointer can be NULL if there is some other mechanism for completing the transfer,
    //! though using callback is the safest way to assure that the DMA driver's state
    //! remains consistent with the state of the firmware that is using it.
    BTSS_DMAC_CALLBACK_t                                            callback;

    //! Arbitrary argument to be passed to callback_arg.  It can be used by that function to
    //! identify what transfer was completed, using whatever information seems appropriate to the
    //! designer.  The argument could be a pointer to this very DMA_TRANSFER_REQUEST_t, but
    //! typically it is more useful to pass a pointer to the "larger" relevant state information
    //! block that described whatever the transfer was serving.
    void*                                                           callback_arg;

    //! The register values that should be set in the DMA controller for the target channel.  These
    //! values will be written to the DMA controller's channel register bank when this transfer
    //! starts.  DMA_LLI_t contains all those registers, although linked list items won't actually
    //! be used unless DMACCx_first_segment_regs.DMACCxLLI points to an actual linked list item.
    BTSS_DMAC_LLI_DESC_t                                            DMACCx_first_segment_regs;

    //! Please refer to the ARM PL081 DMA controller documentation.  That documentation is more
    //! comprehensive than what can be presented here.  As for this documentation, please refer to
    //! the defines for flags and masks with names beginning in DMACCXCONFIG_.
    UINT32                                                          DMACCxConfiguration;

    //! Reserved
    UINT8                                                           reserved : 7;

    //! DMA error status bit. To be cleared by SW after processing the callback.
    UINT8                                                           errStatus : 1;

    //! Message queue pointer to follow up App callbacks from driver thread
    BTSS_DMAC_MSG_t                                                 msg;
} BTSS_DMAC_APP_REQUEST_t;

/* DMA Request Status */
typedef enum
{
    BTSS_DMA_REQ_STATUS_NO_PENDING        = 0, /* No DMA transfers are pending */
    BTSS_DMA_REQ_STATUS_IN_PROGRESS       = 1, /* DMA request is currently in progress */
    BTSS_DMA_REQ_STATUS_WAITING_IN_QUEUE  = 2, /* DMA request is pending in queue */
    BTSS_DMA_REQ_STATUS_NOT_IN_QUEUE      = 3, /* DMA request is not in queue - could be completed. */
} BTSS_DMAC_REQ_STATUS_t;


/**
 * Function btss_dmac_init
 *
 * Initialize BTSS DMAC
 *
 * \param        none
 *
 * \return       First free DMA channel
 */
UINT8 btss_dmac_init(void);

/**
 * Function btss_dmac_getAppFirstChannel
 *
 * Get App usable DMA channel's starting number
 *
 * \param        none
 *
 * \return       First free DMA channel
 */
UINT8 btss_dmac_getAppFirstChannel(void);

/**
 * Function btss_dmac_setPeripheralDMACSync
 *
 * Enables or disables synchronization logic for the DMA request
 * Use synchronization logic when the peripheral generating the DMA request
 * runs on a different clock to the DMAC/CPU. For peripherals running on the
 * same clock as DMAC, disabling the synchronization logic improves the DMA
 * response time.
 *
 * \param[in]    signal           : DMA request signal
 * \param[in]    sync_not_required: FALSE - Enables sync, TRUE - Disables sync
 *
 * \return       none
 */
void btss_dmac_setPeripheralDMACSync( UINT8 signal, BOOL32 sync_not_required );

/**
 * Function btss_dmac_requestTransfer
 *
 * Posts DMA request to the DMAC HW.
 *
 * \param[in]    dmaReq        : DMA request input
 *
 * \return       1 - Success, 0 - Failure
 */
BOOL32 btss_dmac_requestTransfer(BTSS_DMAC_APP_REQUEST_t* dmaReq);

/**
 * Function btss_dmac_killTransfer
 *
 * Kill the requested DMA transfer
 *
 * \param[in]    dmaReq        : DMA request input
 *
 * \return       none
 */
void btss_dmac_killTransfer(BTSS_DMAC_APP_REQUEST_t * dmaReq);

/**
 * Function btss_dmac_dmaReqSetSrc
 *
 * Sets the source address parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    src           : Source address - Aligned to src transfer size parameter
 *
 * \return       none
 */
void btss_dmac_dmaReqSetSrc(BTSS_DMAC_APP_REQUEST_t* dmaReq, UINT32 src);

/**
 * Function btss_dmac_dmaReqSetDst
 *
 * Sets the destination address parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    dst           : Destination address
 *
 * \return       none
 */
void btss_dmac_dmaReqSetDst(BTSS_DMAC_APP_REQUEST_t* dmaReq, UINT32 dst);

/**
 * Function btss_dmac_dmaReqSetChannel
 *
 * Sets the channel parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    channel       : DMA channel
 *
 * \return       none
 */
void btss_dmac_dmaReqSetChannel(BTSS_DMAC_APP_REQUEST_t* dmaReq, UINT8 channel);

/**
 * Function btss_dmac_dmaReqSetLLI
 *
 * Sets the next linked DMA descriptor parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    next_lli      : Next DMA descriptor
 *
 * \return       none
 */
void btss_dmac_dmaReqSetLLI(BTSS_DMAC_APP_REQUEST_t* dmaReq, BTSS_DMAC_LLI_DESC_t* next_lli);

/**
 * Function btss_dmac_dmaReqSetControl
 *
 * Sets the control register parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    control       : DMA control register configuration
 *
 * \return       none
 */
void btss_dmac_dmaReqSetControl(BTSS_DMAC_APP_REQUEST_t* dmaReq, BTSS_DMAC_CONTROL_REG_t control);

/**
 * Function btss_dmac_dmaReqSetConfig
 *
 * Sets the config register parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    config        : DMA config register configuration
 *
 * \return       none
 */
void btss_dmac_dmaReqSetConfig(BTSS_DMAC_APP_REQUEST_t* dmaReq, BTSS_DMAC_CONFIG_REG_t config);

/**
 * Function btss_dmac_dmaReqSetLength
 *
 * Sets the length parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    length        : DMA transfer length
 *
 * \return       none
 */
void btss_dmac_dmaReqSetLength(BTSS_DMAC_APP_REQUEST_t* dmaReq, UINT16 length);

/**
 * Function btss_dmac_dmaReqSetCallback
 *
 * Sets the callback and arg parameter in dmaReq
 *
 * \param[in]    dmaReq        : DMA request input
 * \param[in]    callback      : Callback on completing DMA transfer
 * \param[in]    arg           : Argument to be passed back with callback
 *
 * \return       none
 */
void btss_dmac_dmaReqSetCallback(BTSS_DMAC_APP_REQUEST_t* dmaReq, BTSS_DMAC_CALLBACK_t callback, void *arg);

/**
 * Function btss_dmac_dmaReqGetStatus
 *
 * Gets the status of DMAC transfer
 *
 * \param[in]    dmaReq        : DMA request input
 *
 * \return       none
 */
BTSS_DMAC_REQ_STATUS_t btss_dmac_dmaReqGetStatus(BTSS_DMAC_APP_REQUEST_t* dmaReq);

#if defined(__cplusplus)
}
#endif

#endif //_BTSS_DMAC_H_

/* [] END OF FILE */
