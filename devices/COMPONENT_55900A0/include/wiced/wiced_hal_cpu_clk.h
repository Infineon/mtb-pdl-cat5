/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to access the
* CPU Clock.
*
*/

#ifndef __WICED_CPU_CLK_H__
#define __WICED_CPU_CLK_H__


/**  \addtogroup CPU Clock
* \ingroup HardwareDrivers
*/
/*! @{ */
/**
* Defines a driver to facilitate interfacing with the CPU clock.
*
* Use this to update the CPU clock frequency.
* Care should be taken by an App that it doesn't disable a frequency not set by it.
*
*/

/******************************************************************************
*** Parameters.
***
*** The following parameters are used to configure the driver or define
*** return status. They are not modifiable.
******************************************************************************/
/** Clock Frequency*/
typedef enum
{
    WICED_CPU_CLK_24MHZ,    /**< 24Mhz clock frequency */
    WICED_CPU_CLK_32MHZ,    /**< 32Mhz clock frequency */
    WICED_CPU_CLK_48MHZ,    /**< 48Mhz clock frequency */
    WICED_CPU_CLK_96MHZ,    /**< 96Mhz clock frequency */
} wiced_cpu_clk_freq_t;

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

/**
 * Function         wiced_update_cpu_clock
 *
 * Enables/Disables the given cpu clock frequency.
 * the actual clock frequency is selected appropriately within the driver.
 *
 * @param[in]    enable           :enable or disable clock frequency.
 * @param[in]    freq           :clock frequency to enable/disable.
 *
 *  Usage:The application should call the API with argument enable set to WICED_TRUE to request the FW to set the clock speed to the desired value.
 *        When the application is done with its work at this clock speed and wants to return to the previous speed,
 *        it shall call the API with the argument enable set to WICED_FALSE and set the argument freq to the same frequency that it earlier requested to be set.
 *
 * @return     : wiced_bool_t
 */
wiced_bool_t wiced_update_cpu_clock( wiced_bool_t enable, wiced_cpu_clk_freq_t freq);

#endif // __WICED_CPU_CLK_H__
