/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#ifndef __WICED_HAL_WLAN_H__
#define __WICED_HAL_WLAN_H__

#include "wiced_data_types.h"

/********************* GLOBAL DECLARATIONS **********************************/

/**
 *  \brief Assert WLAN power up signal. This API does not have any impact if WL_REG_ON pin is set high. 
 *  
 *  \param [in] power_on_flag TRUE - Power On or FALSE - Power off WLAN
 *  \return none
 */
void wiced_hal_wlan_override_wlregOn( wiced_bool_t power_on_flag );

/**
 *  \brief Remove SDIO line isolation after WLAN power-up using wiced_hal_wlan_override_wlregOn.
 *         This API does not have any impact if WL_REG_ON pin is set high. 
 *  
 *  \param none
 *  \return none
 */
void wiced_hal_wlan_remove_sdio_isolation( void );

#endif

