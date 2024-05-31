/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 *  \addtogroup nvram NVRAM
 *  \ingroup HardwareDrivers
 *
 *  @{
 *
 *  Defines the interface for reading and writing any data to the NVRAM
 *
 */
#ifndef _WICED_HAL_NVRAM_H_
#define _WICED_HAL_NVRAM_H_

/*****************************************************************************
**                               Constants
*****************************************************************************/
/**
 * @brief Defines the first usable NVRAM Volatile Section Identifier.
 * Application can use the VS ids starting from WICED_NVRAM_VSID_START.to
 * WICED_NVRAM_VSID_END
 * Note: Values less than 0x200 reserved for AIROC internal purpose and not advisable to use by applications
 **/
    /* AIROC applications */
#define WICED_NVRAM_VSID_START              0x200
#define WICED_NVRAM_VSID_END                0x3FFF

/*****************************************************************************
**                          Function Declarations
*****************************************************************************/

/**
 * Writes the data to NVRAM,
 * Application can write up to 255 bytes in one VS  id section
 *
 * @param[in] vs_id        : Volatile Section Identifier. Application can use
 *                           the VS ids from WICED_NVRAM_VSID_START to
 *                           WICED_NVRAM_VSID_END
 *
 * @param[in] data_length  : Length of the data to be written to the NVRAM,
 *
 * @param[in] p_data       : Pointer to the data to be written to the NVRAM
 *
 * @param[out] p_status    : Pointer to location where status of the call
 *                           is returned
 *
 *
 * @return  number of bytes written, 0 on error
 */
uint16_t wiced_hal_write_nvram( uint16_t vs_id,
            uint16_t         data_length,
            uint8_t        * p_data,
            wiced_result_t * p_status);

/** Reads the data from NVRAM
 *
 * @param[in]  vs_id       : Volatile Section Identifier. Application can use
 *                           the VS ids from WICED_NVRAM_VSID_START to
 *                           WICED_NVRAM_VSID_END
 *
 * @param[in]  data_length : Length of the data to be read from NVRAM
 *
 * @param[out] p_data      : Pointer to the buffer to which data will be copied
 *
 * @param[out] p_status    : Pointer to location where status of the call
 *                           is returned
 *
 * @return  the number of bytes read, 0 on failure
 */
uint16_t wiced_hal_read_nvram( uint16_t vs_id,
            uint16_t         data_length,
            uint8_t        * p_data,
            wiced_result_t * p_status);

/** deletes data from NVRAM at specified VS id
 *
 * @param[in]  vs_id       : Volatile Section Identifier. Application can use
 *                           the VS ids from WICED_NVRAM_VSID_START to
 *                           WICED_NVRAM_VSID_END
 *
 *
 * @param[out] p_status    : Pointer to location where status of the call
 *                           is returned
 *
 * @return  void
 */
void wiced_hal_delete_nvram( uint16_t vs_id, wiced_result_t * p_status);

/** @} */

#endif //_WICED_HAL_NVRAM_H_
