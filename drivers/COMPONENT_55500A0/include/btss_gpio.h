/***************************************************************************//**
* \file btss_gpio.h
*
* Provides API declarations of the BTSS GPIO driver.
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

#ifndef __BTSS_GPIO_H__
#define __BTSS_GPIO_H__

#include "cy_pdl_wrapper.h"


#if defined(__cplusplus)
extern "C" {
#endif

/** \brief GPIO interrupt trigger */
 typedef enum
{
    BTSS_GPIO_TRIGGER_EDGE_RISING,
    BTSS_GPIO_TRIGGER_EDGE_FALLING,
    BTSS_GPIO_TRIGGER_EDGES_BOTH,
    BTSS_GPIO_TRIGGER_LEVEL_LOW,
    BTSS_GPIO_TRIGGER_LEVEL_HIGH
} BTSS_GPIO_INT_TRIGGER_TYPE_t;

/** \brief GPIO interrupt callback */
typedef void BTSS_GPIO_ISR_CALLBACK_t ( UINT8 pin );

/** \brief List of GPIOs */
typedef enum
{
    BTSS_GPIO_0    = 0u,
    BTSS_GPIO_1    = 1u,
    BTSS_GPIO_2    = 2u,
    BTSS_GPIO_3    = 3u,
    BTSS_GPIO_4    = 4u,
    BTSS_GPIO_5    = 5u,
    BTSS_GPIO_6    = 6u,
    BTSS_GPIO_7    = 7u,
    BTSS_A_GPIO_0  = 8u,
    BTSS_A_GPIO_1  = 9u,
    BTSS_A_GPIO_2  = 10u,
    BTSS_A_GPIO_3  = 11u,
    BTSS_A_GPIO_4  = 12u,
    BTSS_A_GPIO_5  = 13u,
    BTSS_A_GPIO_6  = 14u,
    BTSS_A_GPIO_7  = 15u,
    BTSS_B_GPIO_0  = 16u,
    BTSS_B_GPIO_1  = 17u,
    BTSS_B_GPIO_2  = 18u,
    BTSS_B_GPIO_3  = 19u,
    BTSS_B_GPIO_4  = 20u,
    BTSS_B_GPIO_5  = 21u,
    BTSS_B_GPIO_6  = 22u,
    BTSS_B_GPIO_7  = 23u,
    BTSS_GPIO_LAST = BTSS_B_GPIO_7,
} BTSS_GPIO_t;

/** \brief List of GPIO Ports */
typedef enum
{
    BTSS_GPIO_PORT_0 = 0u, /* BTSS_GPIO_0 to BTSS_GPIO_7 IOs */
    BTSS_GPIO_PORT_1 = 1u, /* BTSS_A_GPIO_0 to BTSS_A_GPIO_0 IOs */
    BTSS_GPIO_PORT_2 = 2u, /* BTSS_B_GPIO_0 to BTSS_B_GPIO_0 IOs */
    BTSS_GPIO_PORT_LAST = BTSS_GPIO_PORT_2,
} BTSS_GPIO_PORT_t;

/**
 * Function btss_gpio_getNumGPIOs
 *
 *  Get Total Number of inputs and outputs
 *
 * \param                      : none
 *
 * \return       Number of GPIO pins present in chip
 */
UINT32 btss_gpio_getNumGPIOs( void );

/**
 * Function btss_gpio_setDirection
 *
 * Set the direction for the GPIO.
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    dir           : Direction Output (1) or Input (o)
 *
 * \return       none
 */
void btss_gpio_setDirection ( BTSS_GPIO_t gpio, BOOL8 output );

/**
 * Function btss_gpio_write
 *
 * Sets the state of the gpio when used as an output under firmware control
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    value         : Value high (1) or low (o)
 *
 * \return       none
 */
void btss_gpio_write( BTSS_GPIO_t gpio, BOOL32 value );

/**
 * Function btss_gpio_toggle
 *
 * Toggle the state of the gpio when used as an output under firmware control
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    value         : Value high (1) or low (o)
 *
 * \return       none
 */
void btss_gpio_toggle( BTSS_GPIO_t gpio );


/**
 * Function btss_gpio_read
 *
 *  Reads the state of one GPIO and returns that state in bit 0 of the return value
 *
 * \param[in]    gpioNum       : gpio number
 *
 * \return       Pin status - 1 High, 0 Low
 */
UINT32 btss_gpio_read( BTSS_GPIO_t gpio );

/**
 * Function btss_gpio_readPort
 *
 * Reads the state of all GPIOs in the entire gpio block/port
 *
 * \param[in]    gpioBlockNum  : port number
 *
 * \return       none
 */
UINT8 btss_gpio_readPort( BTSS_GPIO_PORT_t port );

/**
 * Function btss_gpio_enableInterrupt
 *
 * Enables/Disables the interrupt for a GPIO
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    enable        : TRUE - Enable or FALSE- Disable
 *
 * \return       none
 */
void btss_gpio_enableInterrupt ( BTSS_GPIO_t gpio, BOOL32 enable );

/**
 * Function btss_gpio_configInterrupt
 *
 * Configure interrupt mode for GPIO pin
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    trigger       : interrupt source
 *
 * \return       none
 */
void btss_gpio_configInterrupt( BTSS_GPIO_t gpio, BTSS_GPIO_INT_TRIGGER_TYPE_t trigger );

/**
 * Function btss_gpio_registerInterruptCallback
 *
 * Register/Unregister GPIO interrupt callback
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    callback      : callback called on interrupt from driver thread
 *
 * \return       none
 */
void btss_gpio_registerInterruptCallback( BTSS_GPIO_t gpio, BTSS_GPIO_ISR_CALLBACK_t* callback );

#if defined(__cplusplus)
}
#endif

#endif //__BTSS_GPIO_H__

/* [] END OF FILE */
