//==================================================================================================
//                        THIS INFORMATION IS PROPRIETARY TO INFINEON
//--------------------------------------------------------------------------------------------------
//                               Copyright (c) 2024 Infineon Technologies.
//                                      ALL RIGHTS RESERVED
//==================================================================================================
//! \file
//!
//! HCI UART Driver API
//
//==================================================================================================

#ifndef _CY_HCI_UART_H_
#define _CY_HCI_UART_H_

#ifdef CY_USING_HAL
#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "cy_pdl_wrapper.h"
#include "cy_hci_uart_common.h"
#else
#include "cy_pdl_wrapper.h"
#endif

//==================================================================================================
// Types and constants
//==================================================================================================

//==================================================================================================
// Public Types
//==================================================================================================


//==================================================================================================
// Public Functions
//==================================================================================================
cy_en_hci_uart_status_t Cy_HCI_UART_Init(uint32_t baudrate);
void Cy_HCI_UART_DeInit(void);
uint32_t Cy_HCI_UART_Put(uint8_t c);
uint32_t Cy_HCI_UART_PutArray(uint8_t *buffer, uint32_t size);
uint32_t Cy_HCI_UART_Get(void);
uint32_t Cy_HCI_UART_GetArray(uint8_t *buffer, uint32_t size);
BOOL8 Cy_HCI_UART_IsTxComplete();
cy_en_hci_uart_status_t Cy_HCI_UART_SetBaud(uint32_t baudrate);

#endif // _CY_HCI_UART_H_
