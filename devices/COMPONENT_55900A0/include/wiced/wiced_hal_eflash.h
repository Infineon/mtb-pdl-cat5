/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
* List of parameters and defined functions needed to access the
* Embedded Flash interface driver.
*
*/

#ifndef _WICED_HAL_EFLASH_H_
#define _WICED_HAL_EFLASH_H_

/**  \addtogroup EmbeddedFlashInterfaceDriver Embedded Flash Interface
* \ingroup HardwareDrivers
* Defines a driver for the Serial Flash interface.
* @{
*/

/**
 * Function         wiced_hal_eflash_init
 *
 * Intializes the embedded flash
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_init( void );

/**
 * Function         wiced_hal_eflash_read
 *
 * Reads the data from eflash
 *
 * @param[in]    offset           :start offset of eflash from which data to be read, offset should be word aligned
 * @param[in]    p_buffer        :Pointer to the buffer to which data is to be read, buffer should be word aligned
 * @param[in]    length           :length of data in byte's to be read.
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_read( uint32_t offset, uint8_t* p_buffer, uint32_t length );

/**
 * Function         wiced_hal_eflash_write
 *
 * Writes the data to eflash.Interrupts will be locked for the duration of the write. And only writes to an already
 * erased location is valid.
 *
 * @param[in]    offset           :start offset of eflash to be written, offset should be word aligned
 * @param[in]    p_buffer        :Pointer to the buffer from which data will be written, buffer should be byte, half-word, or word aligned.
 * @param[in]    length           :length of data in byte's to be written, length should be word aligned
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_write( uint32_t offset, uint8_t* p_buffer, uint32_t length );

/**
 * Function         wiced_hal_eflash_erase
 *
 * Erase the eflash. Erase is performed page-wise. eflash page size is 0x1000 bytes.
 * eflash page count is 0x100.
 *
 * @param[in]    offset           :start offset of eflash page to be erased.
 * @param[in]    length           :length of data in byte's to be erased, erase performed page-wise.
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_erase( uint32_t offset, uint32_t length );

/**
 * Function         wiced_hal_eflash_erase_whole
 *
 * Erase the whole eflash
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_erase_whole( void );

/**
 * Function         wiced_hal_eflash_get_size
 *
 * Gets the sizeof the eflash
 *
 * @return     : eflash size
 */
uint32_t wiced_hal_eflash_get_size( void );

/* @} */

#endif // _WICED_HAL_EFLASH_H_
