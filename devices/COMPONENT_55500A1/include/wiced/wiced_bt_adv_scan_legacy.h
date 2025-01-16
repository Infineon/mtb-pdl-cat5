/*
 * $ Copyright 2024-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * AIROC Bluetooth Low Energy (LE) Functions for legacy advertisement and scanning
 *
 */
#ifndef __WICED_BT_ADV_SCAN_LEGACY_H__
#define __WICED_BT_ADV_SCAN_LEGACY_H__

#include "wiced_bt_cfg.h"
#include "wiced_bt_dev.h"

/**
 * This section contains the legacy mode advertisement and scanning defines, structures and functions.
 * @note Applications should invoke functions in this section if and only if the application wishes to use
 * only legacy mode for advertisement and scanning
 *
 * @addtogroup  wicedbt_Legacy   LE Legacy Mode Advertising and Scanning
 *
 * @ingroup     wicedbt
 *
 * @{
 */

#define BTM_BLE_LEGACY_AD_DATA_LEN 31                 /**< Max legacy advertisement data len*/
#define BTM_AFH_CHNL_MAP_SIZE HCI_AFH_CHANNEL_MAP_LEN /**< AFH channel map size */
#define BLE_CHANNEL_MAP_LEN 5                         /**< AFH Channel Map len */
/** LE Channel Map */
typedef uint8_t wiced_bt_ble_chnl_map_t[BLE_CHANNEL_MAP_LEN];

/** Scanner filter policy */
enum wiced_bt_ble_scanner_filter_policy_e
{
    BTM_BLE_SCAN_POLICY_ACCEPT_ADV_RSP, /**< accept adv packet from all, directed adv pkt not directed to local device is ignored */
    BTM_BLE_SCAN_POLICY_FILTER_ADV_RSP, /**< accept adv packet from device in filter Accept List, directed adv packet not directed to local device is ignored */
    BTM_BLE_SCAN_POLICY_ACCEPT_RPA_DIR_ADV_RSP, /**< accept adv packet from all, directed adv pkt not directed to local device is ignored except direct adv with RPA */
    BTM_BLE_SCAN_POLICY_FILTER_RPA_DIR_ADV_RSP, /**< accept adv packet from device in filter Accept List, directed adv pkt not directed to me is ignored except direct adv with RPA */
    BTM_BLE_SCAN_POLICY_MAX                     /**< Max Scan filter policy value */
};
/** LE Scanner filter policy (see #wiced_bt_ble_scanner_filter_policy_e) */
typedef uint8_t wiced_bt_ble_scanner_filter_policy_t;

/** default advertising channel map */
#ifndef BTM_BLE_DEFAULT_ADVERT_CHNL_MAP
#define BTM_BLE_DEFAULT_ADVERT_CHNL_MAP (BTM_BLE_ADVERT_CHNL_37 | BTM_BLE_ADVERT_CHNL_38 | BTM_BLE_ADVERT_CHNL_39)
#endif

/** Advertising filter policy */
enum wiced_bt_ble_advert_filter_policy_e
{
    /**< Process scan and connection requests from all devices (i.e., the Filter Accept List is not in use) (default) */
    BTM_BLE_ADV_POLICY_ACCEPT_CONN_AND_SCAN = 0x00,
    /**< Process connection requests from all devices and only scan requests from devices that are in the Filter Accept List. */
    BTM_BLE_ADV_POLICY_ACCEPT_CONN_FILTER_SCAN = 0x01,
    /**< Process scan requests from all devices and only connection requests from devices that are in the Filter Accept List */
    BTM_BLE_ADV_POLICY_FILTER_CONN_ACCEPT_SCAN = 0x02,
    /**< Process scan and connection requests only from devices in the Filter Accept List. */
    BTM_BLE_ADV_POLICY_FILTER_CONN_FILTER_SCAN = 0x03,
    /**< Max Adv filter value */
    BTM_BLE_ADV_POLICY_MAX
};
/** Advertising filter policy (see wiced_bt_ble_advert_filter_policy_e) */
typedef uint8_t wiced_bt_ble_advert_filter_policy_t;

/** default advertising filter policy */
#define BTM_BLE_ADVERT_FILTER_DEFAULT BTM_BLE_ADV_POLICY_ACCEPT_CONN_AND_SCAN

#define BTM_BLE_ADVERT_INTERVAL_MIN 0x0020 /**< adv parameter Min value */
#define BTM_BLE_ADVERT_INTERVAL_MAX 0x4000 /**< adv parameter Max value */

#define BTM_BLE_SCAN_INTERVAL_MIN 0x0004 /**< Scan interval minimum value */
#define BTM_BLE_SCAN_INTERVAL_MAX 0x4000 /**< Scan interval miximum value */
#define BTM_BLE_SCAN_WINDOW_MIN 0x0004   /**< Scan window minimum value */
#define BTM_BLE_SCAN_WINDOW_MAX 0x4000   /**< Scan window maximum value */
#define BTM_BLE_CONN_INTERVAL_MIN 0x0006 /**< Connection interval minimum value */
#define BTM_BLE_CONN_INTERVAL_MAX 0x0C80 /**< Connection interval maximum value */
#define BTM_BLE_CONN_LATENCY_MAX 500     /**< Maximum Connection Latency */
#define BTM_BLE_CONN_SUP_TOUT_MIN 0x000A /**< Minimum Supervision Timeout */
#define BTM_BLE_CONN_SUP_TOUT_MAX 0x0C80 /**< Maximum Supervision Timeout */
#define BTM_BLE_CONN_PARAM_UNDEF 0xffff  /**< use this value when a specific value not to be overwritten */
#define BTM_BLE_CONN_SUP_TOUT_DEF 700    /**< Default Supervision Timeout */

/* default connection parameters if not configured, use GAP recommend value for auto connection */
/** default scan interval
 *  30 ~ 60 ms (use 60)  = 96 *0.625
 */
#define BTM_BLE_SCAN_FAST_INTERVAL 96

/** default scan window (in .625ms slots) for background auto connections
 * 30 ms = 48 *0.625
 */
#define BTM_BLE_SCAN_FAST_WINDOW 48

/** default scan interval used in reduced power cycle (background scanning)
 *  1.28 s   = 2048 *0.625
 */
#define BTM_BLE_SCAN_SLOW_INTERVAL_1 2048

/** default scan window used in reduced power cycle (background scanning)
 *   11.25 ms = 18 *0.625
 */
#define BTM_BLE_SCAN_SLOW_WINDOW_1 18

/** default scan interval used in reduced power cycle (background scanning)
 *  2.56 s   = 4096 *0.625
 */
#define BTM_BLE_SCAN_SLOW_INTERVAL_2 4096

/** default scan window used in reduced power cycle (background scanning)
 *  22.5 ms = 36 *0.625
 */
#define BTM_BLE_SCAN_SLOW_WINDOW_2 36

/** default connection interval min
 *  recommended min: 30ms  = 24 * 1.25
 */
#define BTM_BLE_CONN_INTERVAL_MIN_DEF 24

/** default connection interval max
 * recommended max: 50 ms = 56 * 1.25
 */
#define BTM_BLE_CONN_INTERVAL_MAX_DEF 40

/** default Peripheral latency */
#define BTM_BLE_CONN_PERIPHERAL_LATENCY_DEF 0

/** default supervision timeout */
#define BTM_BLE_CONN_TIMEOUT_DEF 2000

/** LE Signature
 *  LE data signature length 8 Bytes + 4 bytes counter
 */
#define BTM_BLE_AUTH_SIGNATURE_SIZE 12
/** Device address (see #BTM_BLE_AUTH_SIGNATURE_SIZE) */
typedef uint8_t wiced_dev_ble_signature_t[BTM_BLE_AUTH_SIGNATURE_SIZE];

#define BTM_BLE_POLICY_REJECT_ALL 0x00 /**< relevant to both */
#define BTM_BLE_POLICY_ALLOW_SCAN 0x01 /**< relevant to advertiser */
#define BTM_BLE_POLICY_ALLOW_CONN 0x02 /**< relevant to advertiser */
#define BTM_BLE_POLICY_ALLOW_ALL 0x03  /**< relevant to both */

/* ADV data flag bit definition used for BTM_BLE_ADVERT_TYPE_FLAG */
#define BTM_BLE_LIMITED_DISCOVERABLE_FLAG (0x01 << 0) /**< Limited Discoverable */
#define BTM_BLE_GENERAL_DISCOVERABLE_FLAG (0x01 << 1) /**< General Discoverable */
#define BTM_BLE_BREDR_NOT_SUPPORTED (0x01 << 2)       /**< BR/EDR Not Supported */
/* 4.1 spec adv flag for simultaneous BR/EDR+LE connection support (see) */
#define BTM_BLE_SIMULTANEOUS_DUAL_MODE_TO_SAME_DEVICE_CONTROLLER_SUPPORTED                                             \
    (0x01 << 3) /**< Simultaneous LE and BR/EDR to Same Device Capable (Controller). */
#define BTM_BLE_SIMULTANEOUS_DUAL_MODE_TO_SAME_DEVICE_HOST_SUPPORTED                                                   \
    (0x01 << 4)                                      /**< Simultaneous LE and BR/EDR to Same Device Capable (Host). */
#define BTM_BLE_NON_LIMITED_DISCOVERABLE_FLAG (0x00) /**< Non Discoverable */
#define BTM_BLE_ADVERT_FLAG_MASK                                                                                       \
    (BTM_BLE_LIMITED_DISCOVERABLE_FLAG | BTM_BLE_BREDR_NOT_SUPPORTED |                                                 \
     BTM_BLE_GENERAL_DISCOVERABLE_FLAG)                                       /**< LE adverisement mask */
#define BTM_BLE_LIMITED_DISCOVERABLE_MASK (BTM_BLE_LIMITED_DISCOVERABLE_FLAG) /**< LE Limited discovery mask*/



/** Scan result event type */
enum wiced_bt_dev_ble_evt_type_e
{
    BTM_BLE_EVT_CONNECTABLE_ADVERTISEMENT = 0x00,          /**< Connectable advertisement */
    BTM_BLE_EVT_CONNECTABLE_DIRECTED_ADVERTISEMENT = 0x01, /**< Connectable Directed advertisement */
    BTM_BLE_EVT_SCANNABLE_ADVERTISEMENT = 0x02,            /**< Scannable advertisement */
    BTM_BLE_EVT_NON_CONNECTABLE_ADVERTISEMENT = 0x03,      /**< Non connectable advertisement */
    BTM_BLE_EVT_SCAN_RSP = 0x04                            /**< Scan response */
};
/** Scan result event value (see #wiced_bt_dev_ble_evt_type_e) */
typedef uint8_t wiced_bt_dev_ble_evt_type_t;


/** LE inquiry result type */
typedef struct
{
    uint8_t ble_addr_type;                    /**< LE Address type */
    wiced_bt_device_address_t remote_bd_addr; /**< Device address */
    int8_t rssi;                              /**< Set to #BTM_INQ_RES_IGNORE_RSSI, if not valid */
    wiced_bt_dev_ble_evt_type_t ble_evt_type; /**< Scan result event type*/
    uint8_t flag;                             /**< Adverisement Flag value */
} wiced_bt_ble_scan_results_t;

/* The power table for multi ADV Tx Power levels
    Min   : -12 dBm     #define BTM_BLE_ADV_TX_POWER_MIN        0
    Low   :  -8 dBm     #define BTM_BLE_ADV_TX_POWER_LOW        1
    Mid   :  -4 dBm     #define BTM_BLE_ADV_TX_POWER_MID        2
    Upper :   0 dBm     #define BTM_BLE_ADV_TX_POWER_UPPER      3
    Max   :   4 dBm     #define BTM_BLE_ADV_TX_POWER_MAX        4
*/
#define MULTI_ADV_TX_POWER_MIN_INDEX 0 /**< Multi adv tx min power index */
#define MULTI_ADV_TX_POWER_MAX_INDEX 4 /**< Multi adv tx max power index */

/** Transmit Power in dBm ( #MULTI_ADV_TX_POWER_MIN_INDEX to #MULTI_ADV_TX_POWER_MAX_INDEX ) */
typedef int8_t wiced_bt_ble_adv_tx_power_t;

/** Multi-advertisement start/stop */
enum wiced_bt_ble_multi_advert_start_e
{
    MULTI_ADVERT_STOP = 0x00, /**< Stop Multi-adverstisment */
    MULTI_ADVERT_START = 0x01 /**< Start Multi-adverstisment */
};

/** Multi-advertisement type */
enum wiced_bt_ble_multi_advert_type_e
{
    MULTI_ADVERT_CONNECTABLE_UNDIRECT_EVENT = 0x00, /**< Multi adv Connectable undirected event */
    MULTI_ADVERT_CONNECTABLE_DIRECT_EVENT = 0x01,   /**< Multi adv Connectable directed event */
    MULTI_ADVERT_DISCOVERABLE_EVENT = 0x02,         /**< Multi adv Discoverable event */
    MULTI_ADVERT_NONCONNECTABLE_EVENT = 0x03,       /**< Multi adv NonConnectable event */
    MULTI_ADVERT_LOW_DUTY_CYCLE_DIRECT_EVENT = 0x04 /**< Multi adv Low Cycle directed event */
};
typedef uint8_t wiced_bt_ble_multi_advert_type_t; /**< LE advertisement type (see #wiced_bt_ble_multi_advert_type_e) */

/** LE Multi advertising parameter */
typedef struct
{
    /**< BTM_BLE_ADVERT_INTERVAL_MIN to BTM_BLE_ADVERT_INTERVAL_MAX ( As per spec ) */
    uint16_t adv_int_min; /**< Minimum adv interval */
    /**< BTM_BLE_ADVERT_INTERVAL_MIN to BTM_BLE_ADVERT_INTERVAL_MAX ( As per spec ) */
    uint16_t adv_int_max;                                  /**< Maximum adv interval */
    wiced_bt_ble_multi_advert_type_t adv_type;             /**< Adv event type */
    wiced_bt_ble_advert_chnl_map_t channel_map;            /**< Adv channel map */
    wiced_bt_ble_advert_filter_policy_t adv_filter_policy; /**< Advertising filter policy */
    wiced_bt_ble_adv_tx_power_t adv_tx_power;              /**< Adv tx power */
    wiced_bt_device_address_t peer_bd_addr;                /**< Peer Device address */
    wiced_bt_ble_address_type_t peer_addr_type;            /**< Peer LE Address type */
    wiced_bt_device_address_t own_bd_addr;                 /**< Own LE address */
    wiced_bt_ble_address_type_t own_addr_type;             /**< Own LE Address type */
} wiced_bt_ble_multi_adv_params_t;


/** Multi-advertisement Filtering policy  */
enum wiced_bt_ble_multi_advert_filtering_policy_e
{
    MULTI_ADVERT_FILTER_POLICY_NOT_USED = 0x00, /**< Multi adv filter filter Accept List not used */
    MULTI_ADVERT_FILTER_POLICY_ADV_ALLOW_UNKNOWN_CONNECTION =
        0x01, /**< Multi adv filter filter Accept List for scan request */
    MULTI_ADVERT_FILTER_POLICY_ADV_ALLOW_UNKNOWN_SCANNING =
        0x02,                                     /**< Multi adv filter filter Accept List for connection request */
    MULTI_ADVERT_FILTER_POLICY_USE_FOR_ALL = 0x03 /**< Multi adv filter filter Accept List for all */
};
/** LE advertisement filtering policy (see #wiced_bt_ble_multi_advert_filtering_policy_e) */
typedef uint8_t wiced_bt_ble_multi_advert_filtering_policy_t;


/**
 * Callback to receive legacy scan results
 *
 * Scan result callback (from calling #wiced_bt_ble_scan)
 *
 * @param p_scan_result             : scan result data (NULL indicates end of scanning)
 * @param p_adv_data                : Advertisement data (parse using #wiced_bt_ble_check_advertising_data)
 *
 * @return Nothing
 */
typedef void(wiced_bt_ble_scan_result_cback_t)(wiced_bt_ble_scan_results_t *p_scan_result, uint8_t *p_adv_data);


#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup  btm_ble_adv_scan_functions        Advertisement & Scan
 * @ingroup     btm_ble_api_functions
 *
 * This section provides functions for LE advertisement and LE scan operations.
 *
 * @{
 */
    /**
 * Start advertising.
 *
 * Use #wiced_bt_ble_set_raw_advertisement_data to configure advertising data
 * prior to starting avertisements. The advertisements are stopped upon successful LE connection establishment.
 *
 * @note 1. Steps for undirected ADVs viz., BTM_BLE_ADVERT_UNDIRECTED_HIGH, BTM_BLE_ADVERT_UNDIRECTED_LOW,
 * and non connectable advs viz., BTM_BLE_ADVERT_NONCONN_HIGH, BTM_BLE_ADVERT_NONCONN_LOW
 *   a) Set ADV data
 *   b) Set Scan Response data if adv type is scannable
 * @note 2. if adv type is set to Directed then the stack resets any advertisement data which was set for an earlier advertisement.
 * To attempt an UNDIRECTED_ADV after a DIRECTED_ADV, refer to instructions in note 1.
 *
 * The <b>advert_mode</b> parameter determines what advertising parameters and durations
 * to use (as specified by the application configuration).
 *
 * @param[in]       advert_mode                         : advertisement mode
 * @param[in]       directed_advertisement_bdaddr_type  : BLE_ADDR_PUBLIC or BLE_ADDR_RANDOM (if using directed advertisement mode)
 * @param[in]       directed_advertisement_bdaddr_ptr   : Directed advertisement address (NULL if not using directed advertisement)
 *
 * @return      status
 *
 */
    wiced_result_t wiced_bt_start_advertisements(wiced_bt_ble_advert_mode_t advert_mode,
                                                 wiced_bt_ble_address_type_t directed_advertisement_bdaddr_type,
                                                 wiced_bt_device_address_ptr_t directed_advertisement_bdaddr_ptr);

    /**
 *
 * Get current advertising mode
 *
 * @return          Current advertising mode (refer #wiced_bt_ble_advert_mode_e)
 *
 */
    wiced_bt_ble_advert_mode_t wiced_bt_ble_get_current_advert_mode(void);

    /**
 * Set advertisement raw data to the controller. Application can invoke #wiced_bt_start_advertisements
 * after setting the adv data. Max length of the advertising data to be set is 31 bytes.
 * API returns an error if the length of data being set exceeds 31 bytes
 *
 * @param[in] num_elem :   number of ADV data element
 * @param[in] p_data :      advertisement raw data
 *
 * @return          wiced_result_t
 *
 */
    wiced_result_t wiced_bt_ble_set_raw_advertisement_data(uint8_t num_elem, wiced_bt_ble_advert_elem_t *p_data);

/**
 *
 * Update the filter policy of advertiser.
 *
 *  @param[in]      advertising_policy: advertising filter policy
 *
 *  @return         TRUE if successful
 */
    wiced_bool_t wiced_btm_ble_update_advertisement_filter_policy(
        wiced_bt_ble_advert_filter_policy_t advertising_policy);

    /**
*  Command to set LE Advertisement tx power
*
* @param[in]       power          :  power value in db
* @param[in]       p_cb           :  Result callback (wiced_bt_set_adv_tx_power_result_t will be passed to the callback)
*
* @return          wiced_result_t
*                  WICED_BT_PENDING if callback is not NULL.
*                  WICED_BT_SUCCESS if callback is NULL
*
*
**/
    wiced_result_t wiced_bt_ble_set_adv_tx_power(int8_t power,
                                                 wiced_bt_dev_vendor_specific_command_complete_cback_t *p_cb);

    /**
* Read LE Advertisement transmit power
* @note: This API can be used to get Tx power for Legacy advertisements.
*        It will return an error if the application is using Extended Advertisements.
*        See Bluetool Core spec 5.2, Vol 4, Part E, section 3.1.1 Legacy and extended advertising
*
* @param[in]       p_cback         : Result callback (wiced_bt_tx_power_result_t will be passed to the callback)
*
* @return
*
*                  WICED_BT_PENDING if command issued to controller.
*                  WICED_BT_NO_RESOURCES if couldn't allocate memory to issue command
*                  WICED_BT_BUSY if command is already in progress
*                  WICED_BT_ILLEGAL_VALUE if the callback is NULL
*/
    wiced_result_t wiced_bt_ble_read_adv_tx_power(wiced_bt_dev_cmpl_cback_t *p_cback);

/**
 *
 * Set scan response raw data
 *
 * @param[in] num_elem :   number of scan response data elements
 * @param[in] p_data :     scan response raw data
 *
 * @return          status of the operation
 *
 */
    wiced_bt_dev_status_t wiced_bt_ble_set_raw_scan_response_data(uint8_t num_elem, wiced_bt_ble_advert_elem_t *p_data);

    /**
 *
 * This function makes the device start or stop operating in the observer role.
 * The observer role device receives advertising events from a broadcast device.
 *
 * @note This API uses following parameters from the configuration settings \ref wiced_bt_cfg_ble_t.p_ble_scan_cfg, \n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.low_duty_scan_interval,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.low_duty_scan_window, \n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.scan_mode, \n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.scan_mode
 *
 *
 *
 * @param[in] start :               TRUE to start the observer role
 * @param[in] duration :            the duration for the observer role
 * @param[in] p_scan_result_cback : scan result callback
 *
 * @return          status of the operation
 *
 */
    wiced_bt_dev_status_t wiced_bt_ble_observe(wiced_bool_t start,
                                               uint8_t duration,
                                               wiced_bt_ble_scan_result_cback_t *p_scan_result_cback);

    /**
 * Start LE scanning
 *
 * The <b>scan_type</b> parameter determines what scanning parameters and durations
 *                  to use (as specified by the application configuration).
 *
 *                  Scan results are notified using \p p_scan_result_cback
 *
 * @note This API uses following parameters from the configuration settings of \ref wiced_bt_cfg_ble_t.p_ble_scan_cfg,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.high_duty_scan_interval,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.high_duty_scan_window,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.high_duty_scan_duration,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.low_duty_scan_interval,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.low_duty_scan_window,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.low_duty_scan_duration,\n
 *       \ref wiced_bt_cfg_ble_scan_settings_t.scan_mode \n
 *
 *
 * @param[in]       scan_type : BTM_BLE_SCAN_TYPE_NONE, BTM_BLE_SCAN_TYPE_HIGH_DUTY,  BTM_BLE_SCAN_TYPE_LOW_DUTY
 * @param[in]       duplicate_filter_enable : TRUE or FALSE to enable or disable  duplicate filtering
 *
 * @param[in]       p_scan_result_cback : scan result callback
 *
 * @return          wiced_result_t \n
 *
 * <b> WICED_BT_PENDING </b>        : if successfully initiated \n
 * <b> WICED_BT_BUSY </b>           : if already in progress \n
 * <b> WICED_BT_ILLEGAL_VALUE </b>  : if parameter(s) are out of range \n
 * <b> WICED_BT_NO_RESOURCES </b>   : if could not allocate resources to start the command \n
 * <b> WICED_BT_WRONG_MODE </b>     : if the device is not up.
 */
    wiced_result_t wiced_bt_ble_scan(wiced_bt_ble_scan_type_t scan_type,
                                     wiced_bool_t duplicate_filter_enable,
                                     wiced_bt_ble_scan_result_cback_t *p_scan_result_cback);

    /**
 *
 * Get current scan state
 *
 * @return          wiced_bt_ble_scan_type_t \n
 *
 * <b> BTM_BLE_SCAN_TYPE_NONE </b>         Not scanning \n
 * <b> BTM_BLE_SCAN_TYPE_HIGH_DUTY </b>    High duty cycle scan \n
 * <b> BTM_BLE_SCAN_TYPE_LOW_DUTY </b>     Low duty cycle scan
 */
    wiced_bt_ble_scan_type_t wiced_bt_ble_get_current_scan_state(void);

    /**
 *
 * Update the filter policy of scanning.
 *
 *  @param[in]      scanner_policy: scanning filter policy
 *
 *  @return         void
 */
    void wiced_bt_ble_update_scanner_filter_policy(wiced_bt_ble_scanner_filter_policy_t scanner_policy);

/**
 * Parse advertising data (returned from scan results callback #wiced_bt_ble_scan_result_cback_t).
 * @note This function cannot be used for scan results received from #wiced_ble_ext_scan_result_cback_t
 * Look for specified advertisement data type.
 *
 * @param[in]       p_adv       : pointer to advertisement data
 * @param[in]       type        : advertisement data type to look for
 * @param[out]      p_length    : length of advertisement data (if found)
 *
 * @return          pointer to start of requested advertisement data (if found). NULL if requested data type not found.
 *
 */
    uint8_t *wiced_bt_ble_check_advertising_data(uint8_t *p_adv, wiced_bt_ble_advert_type_t type, uint8_t *p_length);
/**@} btm_ble_adv_scan_functions */



/**
 * @addtogroup  btm_ble_multi_adv_functions        MultiAdv
 * @ingroup     btm_ble_api_functions
 *
 * This section describes Multiple Advertisement API, using this interface application can enable more than one advertisement train.
 * @note Controller should have support for this feature.
 *
 * @{
 */

    /**
 * Start/Stop Mulit advertisements.
 * wiced_start_multi_advertisements gives option to start multiple adverstisment instances
 * Each of the instances can set different #wiced_set_multi_advertisement_params and #wiced_set_multi_advertisement_data.
 * Hence this feature allows the device to advertise to multiple Centrals at the same time like a multiple peripheral device,
 * with different advertising data, Random private addresses, tx_power etc.
 *
 * @param[in]       advertising_enable : MULTI_ADVERT_START  - Advertising is enabled
 *                                       MULTI_ADVERT_STOP   - Advertising is disabled
 *
 * @param[in]       adv_instance       : 1 to MULTI_ADV_MAX_NUM_INSTANCES
 *
 * @return          wiced_bt_dev_status_t
 *
 *                  TRUE if command succeeded
 */
    wiced_bt_dev_status_t wiced_start_multi_advertisements(uint8_t advertising_enable, uint8_t adv_instance);

    /**
 * Set multi advertisement data for each adv_instance
 *
 *
 * @param[in]       p_data        : Advertising Data ( Max length 31 bytess)
 * @param[in]       data_len      : Advertising Data len ( Max 31 bytes )
 * @param[in]       adv_instance  : 1 to MULTI_ADV_MAX_NUM_INSTANCES
 *
 * @return          wiced_bt_dev_status_t \n
 *                  WICED_BT_SUCCESS if command succeeded
 */
    wiced_bt_dev_status_t wiced_set_multi_advertisement_data(uint8_t *p_data, uint8_t data_len, uint8_t adv_instance);

    /**
 * Set multi advertisement params for each adv_instance
 *
 *
 * @param[in]       adv_instance  : 1 to MULTI_ADV_MAX_NUM_INSTANCES
 * @param[in]       params        : Advertising params refer #wiced_bt_ble_multi_adv_params_t
 *
 * @return          wiced_bt_dev_status_t \n
 *                  WICED_BT_SUCCESS if command succeeded
 */

    wiced_bt_dev_status_t wiced_set_multi_advertisement_params(uint8_t adv_instance,
                                                               wiced_bt_ble_multi_adv_params_t *params);

    /**
 * Set multi advertisement data for scan response
 *
 * @param[in]       p_data        : Advertising Data ( Max length 31 bytess)
 * @param[in]       data_len      : Advertising Data len ( Max 31 bytes )
 * @param[in]       adv_instance  : 1 to MULTI_ADV_MAX_NUM_INSTANCES
 *
 * @return          wiced_bt_dev_status_t \n
 *                  WICED_BT_SUCCESS if command succeeded
 */
    wiced_bt_dev_status_t wiced_set_multi_advertisement_scan_response_data(uint8_t *p_data,
                                                                           uint8_t data_len,
                                                                           uint8_t adv_instance);

    /**
 * Set multi advertisement random address for an instance
 *
 *
 * @param[in]       randomAddr    : own random address
 * @param[in]       adv_instance  : 1 to MULTI_ADV_MAX_NUM_INSTANCES
 *
 * @return          wiced_bt_dev_status_t \n
 *                  WICED_BT_SUCCESS if command succeeded
 */
    wiced_bt_dev_status_t wiced_set_multi_advertisements_random_address(wiced_bt_device_address_t randomAddr,
                                                                        uint8_t adv_instance);

    /**
 * Allows the application to register a callback that will be invoked
 * just before an ADV packet is about to be sent out and immediately after.
 *
 * @param[in]       adv_instance                : 1 to MULTI_ADV_MAX_NUM_INSTANCES
 * @param[in]       clientCallback              : Pointer to a function that will be invoked in application thread context
 *                  with WICED_BT_ADV_NOTIFICATION_READY for before ADV and WICED_BT_ADV_NOTIFICATION_DONE after ADV packet is complete.
 * @param[in]       advanceNoticeInMicroSeconds : Number of microseconds before the ADV the notification is to be sent. Will be rounded down to
 *                  the nearest 1.25mS. Has to be an even multiple of 625uS.
 *
 * @return          wiced_bool_t \n
 *                  WICED_TRUE if command succeeded
 */
    wiced_bool_t wiced_bt_notify_multi_advertisement_packet_transmissions(uint8_t adv_instance,
                                                                          void (*clientCallback)(uint32_t),
                                                                          uint32_t advanceNoticeInMicroSeconds);

    /**@} btm_ble_multi_adv_functions */

/**
 * Sends HCI command to write the legacy adv data
 * @note This API allows sending data formatted with \ref wiced_ble_adv_data_build
 *
 * @param[in]       data_len - length of the adv data to use, max size 31 bytes
 * @param[in]       p_data   - pointer to the adv data to use
 *
 * @return          wiced_bt_dev_status_t
 * <b> WICED_BT_SUCCESS </b>       : If all extended adv data set successfully\n
 * <b> WICED_BT_ILLEGAL_VALUE </b> : If paramer is wrong \n
 * <b> WICED_BT_UNSUPPORTED </b>   : If command not supported \n
 * <b> WICED_BT_NO_RESOURCES </b>  : If no memory to issue the command \n
 * <b> WICED_BT_PENDING </b>       : If command queued to send down \n
 *
 */
    wiced_bt_dev_status_t wiced_bt_ble_set_legacy_adv_data(uint16_t data_len, uint8_t *p_data);


#ifdef __cplusplus
} // extern "C"
#endif

/**@} wicedbt */

#endif // __WICED_BT_ADV_SCAN_LEGACY_H__
