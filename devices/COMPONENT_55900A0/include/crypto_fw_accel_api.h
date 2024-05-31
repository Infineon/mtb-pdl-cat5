#if !defined(_CRYPTO_FW_ACCEL_API_H_)
#define _CRYPTO_FW_ACCEL_API_H_

/*******************************************************************************
* THIS INFORMATION IS PROPRIETARY TO INFINEON TECHNOLOGIES
*
* ------------------------------------------------------------------------------
*
* Copyright (c) 2023 Infineon Technologies.
*
*          ALL RIGHTS RESERVED
*
********************************************************************************
*
********************************************************************************
*
* File Name: crypto_fw_accel_api.h
*
* Abstract: This file contains (non-mbed-tls) wrappers for CC-312
*
*******************************************************************************/
/* APIs to be shared with APP/NetX, do not put internal ones here */


/* create random number (prototype as per MBED-TLS c/b)*/
int32_t crypto_gen_random( void *unused, uint8_t *output, size_t output_len );

#endif /* _CRYPTO_FW_ACCEL_API_H_ */
