/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * Definitions the interfaces  for the AIROC Host Controller Interface
 */
#ifndef _WICED_HCI_H_
#define _WICED_HCI_H_



/*****************************************************************************
**                                              Constants
*****************************************************************************/
/**
 * Defines the AIROC hci channel instance size
 */
#define WICED_HCI_CHANNEL_INSTANCE_SIZE     sizeof(MPAF_TRANS_CHANNEL)

/**
 * Defines the size of AIROC hci invalid channel
 */
#define WICED_HCI_INVALID_CHANNEL         0xFFFF

/**
 * AIROC trans header size = 4 bytes
            2 bytes - opcode,
            2 bytes - length
 */
#define WICED_TRANS_HEADER_SIZE             4


#define HCI_EVENT_WICED_TRACE   0x02        /* AIROC HCI trace */
#define HCI_EVENT_HCI_TRACE     0x03        /* Bluetooth protocol trace */


/*****************************************************************************
**                                               Enumerations
*****************************************************************************/

/*
 * AIROC HCI Port IDs
 */
typedef enum
{
    WICED_HCI_PORT_1 = 0,       /**< Reserved */
    WICED_HCI_PORT_2 = 1,       /**< Reserved */
    WICED_HCI_PORT_3 = 2,       /**< Reserved */
    WICED_HCI_PORT_4 = 3,       /**< Used for raw data transfers */
    WICED_HCI_PORT_5 = 4        /**< Verify if this port is usable. Max ports available is only 5 */
}wiced_hci_port_t;

/*
 * AIROC HCI Channel Data Direction
 */
typedef enum
{
    WICED_HCI_DIR_DEVICE_IN   = 0,
    WICED_HCI_DIR_DEVICE_OUT  = 1
}wiced_hci_dir_t;

/*
 * AIROC HCI Channel Endpoint Address
 */
typedef uint8_t wiced_hci_ep_t;

/*
 * AIROC HCI Channel Types, Control Channel/Data Channel
 */
typedef enum
{
    WICED_HCI_CTRL = 0,
    WICED_HCI_DATA = 1
}wiced_hci_channel_type_t;

typedef uint32_t * wiced_hci_channel_t;

/*****************************************************************************
**                                                Type Definitions
*****************************************************************************/

/*
 *Defines the AIROC hci channel
 */
/* Todo  This note shall be removed .Note: Defining the hci channel structure using a
               reserved parameter to hide the  internal structure parameters from the application.
               Size check shall be done in internal headers */

/*
 * Function prototype for Data Sink handler.
 */
typedef uint8_t (*wiced_hci_data_handler_t)( uint8_t * data_ptr, uint32_t data_len );

typedef void (*wiced_hci_data_sink_t)(uint8_t* buf, uint32_t len, uint32_t sink_ctx );


/*****************************************************************************
**                                                 Function Declarations
*****************************************************************************/

/**  Configures the hci channel
 *
 *@param[in]    p_channel              :Pointer to the hci channel
 *@param[in]      port                    :Port Id
 *@param[in]      type                    :Channel type
 *@param[in]      ep                      :HCI Channel EP Addess
 *@param[in]      dir                      :HCI Channel Direction
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_init_hci_channel( wiced_hci_channel_t* p_channel,
                                           wiced_hci_port_t port,
                                           wiced_hci_channel_type_t type,
                                           wiced_hci_ep_t ep,
                                           wiced_hci_dir_t  dir );

/** Opens a channel for data transfer
 *Channel should be initialized before opening the channel
 *@param[in]    p_channel           :Pointer to the hci channel
 *
 * @return   channel id on success,
 *               WICED_HCI_INVALID_CHANNEL, on failure
 */
uint32_t wiced_open_hci_channel( wiced_hci_channel_t* p_channel );


/** Closes the hci channel
 *
 *@param[in]    p_channel           :Pointer to the hci channel
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_close_hci_channel( wiced_hci_channel_t* p_channel );


/** Deletes the hci channel. instance
 *Deletes the memory associated with the hci channel
 *
 *@param[in]    p_channel           :Pointer to the hci channel
 *
 * @return   None
 */
wiced_result_t wiced_deinit_hci_channel( wiced_hci_channel_t* p_channel );


/** Attaches a sink to the hci channel
 *
 *@param[in]    p_channel           :Pointer to the hci channel
 *@param[in]    sink                    :Pointer to the sink handler
 *@param[in]    sink_ctx              :Any context info that the handler would need.
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_attach_sink_hci_channel( wiced_hci_channel_t* p_channel,
                                                          wiced_hci_data_sink_t sink,
                                                          uint32_t  sink_ctx );

/** Sends data through the channel
 *
 *@param[in]    p_channel           :Pointer to the hci channel
 *@param[in]    p_data                :Data buffer pointer
 *@param[in]    data_len              :Length of Data
 *
 * @return   wiced_result_t
 */

wiced_result_t wiced_send_hci_channel( wiced_hci_channel_t* p_channel,
                                                   uint8_t* p_data,
                                                   uint32_t data_len );

/** Flushes the data from the channel
 *
 *@param[in]    p_channel           :Pointer to the hci channel
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_flush_hci_channel( wiced_hci_channel_t* p_channel );

#endif // _WICED_HCI_H_
