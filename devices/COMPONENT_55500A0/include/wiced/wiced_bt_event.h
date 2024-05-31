/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
 /** @file
 *
 *  This implements the application-thread level event handling for AIROC Apps
 */
#ifndef __WICED_BT_EVENT_H__
#define __WICED_BT_EVENT_H__
#include "wiced.h"

/*
 * Size of historical failure code size
 *
 * @note This definition value is not permitted to change.
 */
#define WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_HISTORY_SIZE 5

typedef enum
{
     WICED_SERIALIZATION_EVENT = 1,
}wiced_bt_internal_events_t;

/*
 * AIROC APP Event Serialization Failure Code
 *
 * @note This failure code is used to check the failure status if the return value
 *       of wiced_app_event_serialize() utility is FALSE.
 */
typedef enum wiced_app_event_serialization_failure_code
{
    /*
     * 0x00: Invalid failure code. This is the default value and shall be ignored while debugging.
     */
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_INVALID                  = 0x00,

    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_NOT_INITIALIZED          = 0x10,

    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_NO_MEMORY                = 0x20,
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_QUEUE_FULL               = 0x21,

    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_MUTEX_CREATE_FAIL        = 0x30,
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_MUTEX_GET_FAIL           = 0x31,
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_MUTEX_PUT_FAIL           = 0x32,

    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_EVENT_SET_FAIL           = 0x40,
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_EVENT_INVALID_VALUE      = 0x41,

    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_EVENT_QUEUE_ADD_FAIL     = 0x50,

    /* Failure code for handling event. */
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_HANDLER_MUTEX_GET_FAIL   = 0x60,
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_HANDLER_MUTEX_PUT_FAIL   = 0x61,
    WICED_APP_EVENT_SERIALIZATION_FAILURE_CODE_HANDLER_EVENT_SET_FAIL   = 0x62,

} wiced_app_event_serialization_failure_code_t;

 /* The serialization queue will have these callbacks */
typedef struct
{
    // The function to invoke in application thread context
    int (*fn)(void*);

    // Any arbitrary data to be given to the callback. wiced_app_event_serialize Caller has to allocate and free once serialized event handled
    void* data;
} wiced_app_event_srzn_cb_t;


/*
 *This function lets you serialize a call onto the application thread.
 *
 *@param[in]    fn          : serialized call back on serialization
 *
 *@param[in]    data        : data to be handled in serialized call

 * @return      wiced_bool_t

 * Note: It is application's responsibility freeing data pointer
 */
wiced_bool_t wiced_app_event_serialize( int (*fn)(void*), void* data);

/*
 * AIROC Application Serialization Event handling debug callback.
 *
 * @param[in]   error code: Refer to the error codes defined in the section,
 *              "Failure code for handling the event", in enum,
 *              wiced_app_event_serialization_failure_code_t.
 *
 * @note        This is used for debugging the serialization event handler in application layer
 */
typedef void (wiced_app_event_debug_callback_t)(wiced_app_event_serialization_failure_code_t error_code);

/*
 * AIROC Application Event Serialization Handler DeBug Callback Register
 *
 * @param[in]   callback
 *
 * @note        While an error in occurred in the serialization event handler, the registered
 *              callback will be called to indicate current situation with error code defined
 *              in wiced_app_event_serialization_failure_code_t.
 */
void wiced_app_event_serialization_debug_callback_register( wiced_app_event_debug_callback_t *callback );

#endif //__WICED_BT_EVENT_H__
