/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

 /** @file
 *
 *  AIROC BLEHIDD COMMON APIs for Human Interface Device Profile (HID) Device over LE
 *
 * This file provides definitions of the interfaces for AIROC
 * BLEHIDD Application development.
 *
 */

#ifndef __WICED_HIDD_LIB_H__
#define __WICED_HIDD_LIB_H__

#include "bt_types.h"


extern UINT32 g_wiced_BtTransportSenseRetryMax;

////////////////////////////////////////////////////////////////////////////////
/// Check if transport (UART, USB etc.) detection polling is still on-going
///
/// \param none
///
/// \return WICED_TRUE/WICED_FALSE
////////////////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_hidd_is_transport_detection_polling_on(void);


/* @} */

#endif // __WICED_HIDD_LIB_H__
