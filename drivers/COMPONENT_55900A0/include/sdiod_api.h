//==================================================================================================
//                        THIS INFORMATION IS PROPRIETARY TO INFINEON
//--------------------------------------------------------------------------------------------------
//                               Copyright (c) 2022 Infineon Technologies.
//                                      ALL RIGHTS RESERVED
//==================================================================================================
//! \file
//!
//! SDIO CTSS Device Driver API
//
//==================================================================================================

#ifndef _SDIOD_API_H_
#define _SDIOD_API_H_

#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#else
#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "cy_pdl_wrapper.h"
#include "sdiod_common.h"
#endif


//==================================================================================================
// Types and constants
//==================================================================================================

#define SDIOD_FRAME_LENGTH_MAX                  (2048)

#define SDIOD_RX_FRAME_HDR_LENGTH               (sizeof(sdiod_f2_rx_frame_hdr_t))
#define SDIOD_RX_FRAME_PAYLOAD_LENGTH_MAX       (SDIOD_FRAME_LENGTH_MAX - sizeof(sdiod_f2_frame_hdr_t))
#define SDIOD_RX_GET_FRAME_PAYLOAD_LENGTH(x)    (*(UINT16*)(((BYTE*)x)+SDIOD_DMA_RX_HDR_LEN) - sizeof(sdiod_f2_frame_hdr_t))

#define SDIOD_TX_FRAME_PAYLOAD_LENGTH_MAX       (SDIOD_FRAME_LENGTH_MAX - sizeof(sdiod_f2_frame_hdr_t))

//==================================================================================================
// Public Types
//==================================================================================================

// Host enabled info
typedef struct
{
    BOOL8 io_enabled;
    BOOL8 mail_received;
} sdiod_event_data_host_info_t;

// Rx info
typedef struct
{
    sdiod_status_t status;
    UINT32 sdiod_status;
    BOOL8 more_data;
} sdiod_event_data_rx_info_t;

// Tx info
typedef struct
{
    sdiod_status_t status;
    UINT32 sdiod_status;
} sdiod_event_data_tx_info_t;

// Hardware bus info
typedef struct
{
    sdiod_status_t status;
    UINT32 sdiod_status;
} sdiod_event_data_hw_info_t;

typedef union
{
    sdiod_event_data_host_info_t      host_info;
    sdiod_event_data_rx_info_t        rx_info;
    sdiod_event_data_tx_info_t        tx_info;
    sdiod_event_data_hw_info_t        hw_info;
} sdiod_event_data_t;

//==================================================================================================
// Public Functions
//==================================================================================================

sdiod_status_t sdiod_Init(sdiod_dma_descs_buf_t* dma_descs_buf);
void sdiod_Deinit(void);
sdiod_status_t sdiod_RegisterCallback(sdiod_event_cb_t sdiod_event_cb);
sdiod_status_t sdiod_EnableInterrupt(void);
sdiod_status_t sdiod_DisableInterrupt(void);
sdiod_status_t sdiod_IsHostIOEnabled(void);
sdiod_status_t sdiod_SetIOReady(void);

sdiod_status_t sdiod_Receive_Async(BYTE* receive_buf, UINT32 receive_byte_count);
sdiod_status_t sdiod_Receive_Abort(void);
sdiod_status_t sdiod_Transmit_Async(BYTE* transmit_buf, UINT32 transmit_byte_count);
sdiod_status_t sdiod_Transmit_Abort(void);
sdiod_status_t sdiod_get_RxStatus(void);
sdiod_status_t sdiod_get_TxStatus(void);

sdiod_status_t sdiod_send_ToHostMailboxSignal(UINT32 signal);
sdiod_status_t sdiod_set_ToHostMailboxData(UINT32 data);
sdiod_status_t sdiod_read_FromHostMailboxData(UINT32* data);

sdiod_status_t sdiod_sleepModeInit(void);
sdiod_status_t sdiod_IsSleepAllowed(void);
sdiod_status_t sdiod_preSleep(void);
sdiod_status_t sdiod_postSleep(void);

#endif // _SDIOD_API_H_
