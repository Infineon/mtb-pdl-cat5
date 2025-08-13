/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to utilize the
*
*
*/

#pragma once

#include "wiced.h"

/**  \addtogroup RandomNumberGenerator Random Number Generator (RNG)
* \ingroup HardwareDrivers
* @{
*
* Defines a driver for the Random Number Generator (RNG). The TRNG uses a
* special hardware module to generate either a single 32-bit random number or
* fill a given array with 32-bit random numbers. These are useful for
* applications such as authentication.
*
*/

/******************************************************************************
*** Function prototypes.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Generates and returns a pseudo random 32-bit integer.
/// "soft" random number.
///
/// \param none
///
/// \return A randomly generated 32-bit integer.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_pseudo_rand_gen_num(void);

///////////////////////////////////////////////////////////////////////////////
/// Generates and returns a random 32-bit integer. Internal functions check
/// that the generating hardware is warmed up and ready before returning
/// the random value. If the hardware is too "cold" at the time of use,
/// the function will instead use the Bluetooth clock as a "seed" and generate a
/// "soft" random number.
///
/// \param none
///
/// \return A randomly generated 32-bit integer.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_rand_gen_num(void);


///////////////////////////////////////////////////////////////////////////////
/// Fills a given array with randomly generated 32-bit integers. Uses the
/// function wiced_hal_rand_gen_num().
///
/// \param randNumberArrayPtr - Pointer to an array to be populated with
///                             the random numbers.
/// \param length             - Length of the array pointed to by
///                             randNumberArrayPtr.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_rand_gen_num_array(uint32_t* randNumberArrayPtr, uint32_t length);

///////////////////////////////////////////////////////////////////////////////
/// This functin returns a pseudo random number
///
/// \param none
///
/// \return A randomly generated 32-bit integer.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_get_pseudo_rand_number(void);

/* @} */
