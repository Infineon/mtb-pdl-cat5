/*
 * $ Copyright 2021-YEAR Cypress Semiconductor $
 */

#include "wiced_bt_types.h"
#include "wiced_result.h"
#include "hcidefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * Verify if the given bd_addr matches with the local bd_addr
 *
 * @param[in]      bd_addr    :  remote bd address
 *
 * @return         TRUE if bd_addr is same as local_bd_addr,FALSE otherwise
 *
 */
wiced_bool_t wiced_bt_dev_bdaddr_is_local(wiced_bt_device_address_t bd_addr);

/**
*
* Compare two BD address
*
* @param[in]      bd_addr_1    :  bd address
* @param[in]      bd_addr_2    :  bd address to be compared with bd_addr_1
*
* Returns         TRUE if both bd_addr are same,
*                 FALSE if different
*
*/
wiced_bool_t wiced_bt_dev_bdaddr_is_same(wiced_bt_device_address_t bd_addr_1, wiced_bt_device_address_t bd_addr_2);

/**
* Is controller address resolution enabled
*
*
* Returns         TRUE if enabled
*
*/
wiced_bool_t wiced_bt_dev_is_address_resolution_enabled(void);

/**
* Is device privacy supported
*
*
* Returns         TRUE if supported
*
*/
wiced_bool_t wiced_bt_dev_is_privacy_supported(void);

/**
*  This function turns OFF/ON SMP over BR/EDR (i.e. link keys crosspairing SC BR/EDR->SC LE) for the remote device.
*  If mode is set to TRUE then the crosspairing will not happen.
*
* @param[in]  mode :  Set to TRUE to disable support for smp on br.
*
* Returns void
*
*/
void wiced_bt_dev_set_no_smp_on_br(wiced_bool_t mode);
