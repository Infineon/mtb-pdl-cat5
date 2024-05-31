/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to utilize the
* watchdog.
*
*/

#ifndef __WICED_WDOG_RESET_H__
#define __WICED_WDOG_RESET_H__

#include "wiced.h"
#include "wiced_hal_gpio.h"

/**  \addtogroup WatchdogInterface Watchdog Interface
* \ingroup HardwareDrivers
* Defines a driver for the watchdog interface. This driver manages the
* hardware watchdog countdown timer. When enabled, the watchdog timer will generate
* an interrupt when the timer counts down to zero, then will reload the counter.
* If the counter counts down to zero again, the hardware performs a device reset.
* The lowest priority "idle" thread restarts the watchdog counter preiodically,
* and other operations that may keep the system busy call wiced_hal_wdog_restart to
* extend the watchdog countdown.
*/
/*! @{ */

/******************************************************************************
*** Function prototypes.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Execute a soft reset of the system.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_reset_system(void);

#ifdef ARLO_SUPPORT
#ifndef TZ_ACTIVE
///////////////////////////////////////////////////////////////////////////////
/// \brief Function to check whether reset happened due to Watchdog timer expiry
///
/// \return TRUE - if reset is due to Watchdog, FALSE otherwise
///////////////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_watchdog_get_reset_reason(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Function to configure gpio and its active level to be set on WDT expiry
///
/// \param [in] gpio Bluetooth GPIO to be asserted before watchdog reset(only WICED_GPIO_00 - WICED_GPIO_15 are valid).
/// \param [in] active_level WICED_GPIO_ACTIVE_LOW/WICED_GPIO_ACTIVE_HIGH
/// \return WICED_SUCCESS - if GPIO is configured sucessfully, else WICED_BADARG.
///////////////////////////////////////////////////////////////////////////////
wiced_result_t wiced_watchdog_configure_reset_gpio(wiced_bt_gpio_numbers_t gpio, wiced_bool_t active_level);

///////////////////////////////////////////////////////////////////////////////
/// \brief Function to add application required delay on WDT expiry after asserting HOST_WAKE/configured GPIO
/// and before triggering core-dump transfer
///
/// \param [in] delay_ms delay in ms (default delay is 0ms).
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_watchdog_configure_reset_delay(uint32_t delay_ms);
#endif  //#ifndef TZ_ACTIVE
#endif  //#ifdef ARLO_SUPPORT
#endif // __WICED_WDOG_RESET_H__
