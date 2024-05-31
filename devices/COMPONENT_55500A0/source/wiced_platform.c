/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#include <wiced.h>
#include "wiced_platform.h"
#include "platform_mem.h"
#include "bt_types.h"

extern void wiced_app_hal_init(void );

void wiced_platform_init(void)
{
    wiced_app_hal_init();

    // this UART to GPIO configuration is not for PSVP
    // wiced_platform_target_puart_init();

    /* Platform memory for Bluetooth key info */
    platform_mem_init();
}
