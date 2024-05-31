/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
*Defines the interfaces for Buffer , Timer and Event Management Services
*/
#ifndef _WICED_GKI_H_
#define _WICED_GKI_H_

#include "wiced_bt_dev.h"
#include "wiced_bt_stack_platform.h"

/*****************************************************************************
**                                                 Function Declarations
*****************************************************************************/

/**
 * Function         wiced_bt_did_stack_overflow
 *
 * Checks if the application thread stack overflowed at some point
 *
 * @return    TRUE : on stack overflow;
 *            FALSE : if no stack overflow
 *
 */
uint8_t wiced_bt_did_stack_overflow(void);

/**
 * Function         wiced_bt_stack_check_init
 *
 * Prepares the stack to allow the app to check for stack overflow.
 *
 */
void wiced_bt_stack_check_init(void);

/**
 * Function         wiced_bt_ble_get_available_tx_buffers
 *
 * Used to get the available number of LE tx buffers
 *
 * Return           the available number of LE tx buffers
 */
uint32_t wiced_bt_ble_get_available_tx_buffers( void );

void wdog_generate_hw_reset(void);//TODO: #define wdog_generate_hw_reset wiced_hal_wdog_reset_system
uint32_t wiced_get_free_memory(void);//TODO: #define wiced_get_free_memory wiced_memory_get_free_bytes

void wiced_set_exception_callback(pf_wiced_exception pf_handler);


#endif //_WICED_GKI_H_
