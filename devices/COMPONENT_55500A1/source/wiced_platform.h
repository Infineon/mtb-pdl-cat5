/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#ifndef __WICED_PLATFORM_H__
#define __WICED_PLATFORM_H__

#include "wiced.h"
#include "wiced_hal_gpio.h"

/*! configuration settings for button, x can be GPIO_EN_INT_RISING_EDGE or GPIO_EN_INT_FALLING_EDGE or GPIO_EN_INT_BOTH_EDGE */
#define WICED_GPIO_BUTTON_SETTINGS(x) (GPIO_INPUT_ENABLE | GPIO_PULL_UP | (x))

//! Possible interrupt configuration for platform buttons
typedef enum
{
    WICED_PLATFORM_BUTTON_BOTH_EDGE = WICED_GPIO_EN_INT_BOTH_EDGE,   //!< indicates that app. should receive interrupt on both edges
    WICED_PLATFORM_BUTTON_RISING_EDGE = WICED_GPIO_EN_INT_RISING_EDGE, //!< indicates that app. should receive interrupt only for rising edge
    WICED_PLATFORM_BUTTON_FALLING_EDGE = WICED_GPIO_EN_INT_FALLING_EDGE,//!< indicates that app. should receive interrupt only for falling edge
} wiced_platform_button_interrupt_edge_t;

/**
 * configuration for the platform GPIOs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t gpio_pin; /**< WICED GPIO pin */
    wiced_bt_gpio_function_t functionality; /**< chosen functionality for the pin */
}
wiced_platform_gpio_t;

/**
 * Configuration for platform LEDs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
}
wiced_platform_led_config_t;

/**
 * Configuration for platform Buttons
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., interrupt is configured through wiced_platform_register_button_callback(...) */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
    uint32_t button_pressed_value; /**< Button pressed value */
}
wiced_platform_button_config_t;

/**
 * Configuration for platform GPIOs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., interrupt is configured through wiced_platform_register_button_callback(...) */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
}
wiced_platform_gpio_config_t;


/*! pin for buttons */
#define WICED_BUTTON1 (WICED_GPIO_10)
#define WICED_BUTTON2 (WICED_GPIO_08)
#define WICED_BUTTON3 (WICED_GPIO_07)

//! Number of LEDs available on the platform.
typedef enum
{
    WICED_PLATFORM_LED_1,
    WICED_PLATFORM_LED_2,
    WICED_PLATFORM_LED_MAX,
} wiced_platform_led_number_t;

//! Number of Buttons available on the platform.
typedef enum
{
    WICED_PLATFORM_BUTTON_1,
    WICED_PLATFORM_BUTTON_2,
    WICED_PLATFORM_BUTTON_3,
    WICED_PLATFORM_BUTTON_MAX,
} wiced_platform_button_number_t;

#define WICED_PLATFORM_BUTTON_MAX_DEF WICED_PLATFORM_BUTTON_MAX // define for preprocessor

//! Number of GPIO available on the platform.
// Configurable via SuperMux
typedef enum
{
    WICED_PLATFORM_GPIO_1,  //!< LHL_GPIO3
    WICED_PLATFORM_GPIO_2,  //!< BT_GPIO 2
    WICED_PLATFORM_GPIO_3,  //!< BT_GPIO 3
    WICED_PLATFORM_GPIO_4,  //!< BT_GPIO 4
    WICED_PLATFORM_GPIO_5,  //!< BT_GPIO 5
    WICED_PLATFORM_GPIO_6,  //!< BT_GPIO 6
    WICED_PLATFORM_GPIO_7,  //!< BT_GPIO 7
    WICED_PLATFORM_GPIO_8,  //!< BT_GPIO 8
    WICED_PLATFORM_GPIO_9,  //!< BT_GPIO 9
    WICED_PLATFORM_GPIO_10,  //!< BT_GPIO 10
    WICED_PLATFORM_GPIO_11,  //!< BT_GPIO 11
    WICED_PLATFORM_GPIO_12,  //!< BT_GPIO 12
    WICED_PLATFORM_GPIO_13,  //!< BT_GPIO 13
    WICED_PLATFORM_GPIO_14,  //!< BT_GPIO 14
    WICED_PLATFORM_GPIO_15,  //!< BT_GPIO 15
    WICED_PLATFORM_GPIO_16,  //!< BT_GPIO 16
    WICED_PLATFORM_GPIO_17,  //!< BT_GPIO 17
    WICED_PLATFORM_GPIO_18,  //!< BT_GPIO 18
    WICED_PLATFORM_GPIO_19,  //!< BT_GPIO 19
    WICED_PLATFORM_GPIO_20,  //!< BT_GPIO 20
    WICED_PLATFORM_GPIO_MAX //!< Max GPIO for error check
} wiced_platform_gpio_number_t;

//! List of pins available on the platform
enum wiced_platform_pins
{
    PLATFORM_GPIO_0,
    PLATFORM_GPIO_1,
    PLATFORM_GPIO_2,
    PLATFORM_GPIO_3,
    PLATFORM_GPIO_4,
    PLATFORM_GPIO_5,
    PLATFORM_GPIO_6,
    PLATFORM_GPIO_7,
    PLATFORM_GPIO_8,
    PLATFORM_GPIO_9,
    PLATFORM_GPIO_10,
    PLATFORM_GPIO_11,
    PLATFORM_GPIO_12,
    PLATFORM_GPIO_13,
    PLATFORM_GPIO_14,
    PLATFORM_GPIO_15,
    PLATFORM_GPIO_16,
    PLATFORM_GPIO_17,
    PLATFORM_GPIO_18,
    PLATFORM_GPIO_19,
    PLATFORM_GPIO_20,
    PLATFORM_GPIO_MAX_PINS
};

typedef enum platform_button
{
    PLATFORM_BUTTON_1 = WICED_PLATFORM_BUTTON_1,
    PLATFORM_BUTTON_2 = WICED_PLATFORM_BUTTON_2,
    PLATFORM_BUTTON_3 = WICED_PLATFORM_BUTTON_3,
    PLATFORM_BUTTON_MAX = WICED_PLATFORM_BUTTON_MAX,
} platform_button_t;

/**
 * wiced_platform_transport_rx_data_handler
 *
 * Callback registered by the application to receive the incoming HCI UART data.
 *
 * @param[in] op_code   : operation code for the incoming HCI data (refer to hci_control_api.h)
 * @param[in] p_data    : Pointer to the received data for the op_code
 * @param[in] data_len  : length of the data pointed to by p_data in bytes
 */
typedef void (wiced_platform_transport_rx_data_handler)(uint16_t op_code, uint8_t *p_data, uint32_t data_len);

void wiced_platform_init(void);
uint32_t wiced_platform_get_button_pressed_value(wiced_platform_button_number_t button);
void wiced_platform_target_puart_init(void);
wiced_bool_t wiced_platform_transport_init(wiced_platform_transport_rx_data_handler *p_rx_data_handler);

/**
 *  \brief Provide utility function for application to register for cb upon button interrupt
 *
 *  \param [in] button select a button from wiced_platform_button_number_t
 *  \param [in] userfn Provide the call back function
 *  \param [in] userdata Data to be provided with the call back
 *  \param [in] trigger_edge To configure interrupt on rising/falling/dual edge
 *
 *  \return none
 *
 */
void wiced_platform_register_button_callback(wiced_platform_button_number_t button, void (*userfn)(void*, uint8_t), void* userdata,
                wiced_platform_button_interrupt_edge_t trigger_edge);



#endif
