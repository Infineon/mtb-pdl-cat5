//==================================================================================================
//                        THIS INFORMATION IS PROPRIETARY TO INFINEON
//--------------------------------------------------------------------------------------------------
//                               Copyright (c) 2024 Infineon Technologies.
//                                      ALL RIGHTS RESERVED
//==================================================================================================
//! \file
//!
//! HCI UART Driver
//
//==================================================================================================

#ifndef _CY_HCI_UART_COMMON_H_
#define _CY_HCI_UART_COMMON_H_

#ifdef CY_USING_HAL
#include <stdint.h>
#endif

//==================================================================================================
// Types and constants
//==================================================================================================
#define CY_HCI_UART_MAX_BAUDRATE       (1000000)

/** Data returned when an empty RX FIFO is read */
#define CY_HCI_UART_RX_NO_DATA         (0xFFFFFFFFu)


//==================================================================================================
// Public Types
//==================================================================================================

/** HCI UART status codes */
typedef enum
{
    /** Operation completed successfully */
    CY_HCI_UART_SUCCESS = 0,

    /* HCI UART already initialized */
    CY_HCI_UART_ALREADY_INIT = 1,

    /** One or more of input parameters are invalid */
    CY_HCI_UART_BAD_PARAM = 2,

    /* Out of memory error */
    CY_HCI_UART_OUT_OF_MEMORY = 3,

}cy_en_hci_uart_status_t;

#endif // _CY_HCI_UART_COMMON_H_
