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
* File Name: crypto_secfw.h
*
* Abstract: This file contains CC-312 crypto APIs definitions towards (supported) cloud-id/others
*
*******************************************************************************/

#if !defined(_CRYPTO_SEC_FW_H_)
#define _CRYPTO_SEC_FW_H_

#include "brcm_fw_types.h"

typedef struct tag_t_secure_sockets_params
{
    uint8_t *signature; /* output (non-secure) buffer to hold ECC signature */
    uint32_t signature_length; /* size of the output buffer */
    uint32_t *actual_signature_length; /* actual length of the ECC signature */
    BOOL32 verify; /* ECC verification is requested? */
}T_SECFW_SECURESOCKET_PARAMS;

typedef enum tag_e_netxsecure_algos
{
/* ECC key types */
    ECC_CURVE_NIST_P_256 = 0, /* supported */
    ECC_CURVE_NIST_P_384, /* supported */
    ECC_CURVE_NIST_P_521,
    ECC_CURVE_BRAIN_POOL_P_256R1,
    ECC_CURVE_BRAIN_POOL_P_384R1,
    ECC_CURVE_BRAIN_POOL_P_512R1,
/* RSA key types */
    RSA_KEY_1024_BIT_EXPONENTIAL,
    RSA_KEY_2048_BIT_EXPONENTIAL,
    RSA_KEY_4096_BIT_EXPONENTIAL,
} E_NETXSECURE_ALGOS;

#define CRYPTOUTIL_ERR_BASE          0x00E00000UL

/* error: <input> NULL instead of valid */
#define CRYPTOUTIL_ERR_NULL_PARAM ( CRYPTOUTIL_ERR_BASE + 1 )
/* error: <input> unsupported parameter */
#define CRYPTOUTIL_ERR_UNSUPPORTED_PARAM ( CRYPTOUTIL_ERR_BASE + 2 )
/* error: <input> invalid parameter */
#define CRYPTOUTIL_ERR_INVALID_PARAM ( CRYPTOUTIL_ERR_BASE + 3 )
/* error: <input> invalid parameter size */
#define CRYPTOUTIL_ERR_INVALID_SIZE_PARAM ( CRYPTOUTIL_ERR_BASE + 4 )
/* error: dynamic memory allocation failed */
#define CRYPTOUTIL_ERR_MEMORY_ALLOC_FAILURE ( CRYPTOUTIL_ERR_BASE + 5 )
/* error: dynamic memory access bound check failed */
#define CRYPTOUTIL_ERR_MEMORY_ACCESS_BOUNDS ( CRYPTOUTIL_ERR_BASE + 6 )
/* error: input(i.e. hash) length has to match ECC Key-size */
#define CRYPTOUTIL_ERR_INVALID_HASH_SIZE ( CRYPTOUTIL_ERR_BASE + 7 )
/* error: mutex get/set failed (check calling context) */
#define CRYPTOUTIL_ERR_LOCK ( CRYPTOUTIL_ERR_BASE + 8 )
/* NOTE : Additional error codes starting from CC_ERROR_BASE (i.e. 0x00F00000UL) are from CC-312 */


uint32_t secfw_get_key_type(uint16_t uid);

uint32_t secfw_get_indexed_pubkey( uint16_t uid, uint8_t *p_buff_pubkey, uint32_t len_buff_pub_key, uint32_t *p_len_pub_key );

uint32_t secfw_cid_generate_signature( uint16_t uid,
                                       const uint8_t *input, uint32_t length_input,
                                       T_SECFW_SECURESOCKET_PARAMS *params );

#endif /* _CRYPTO_SEC_FW_H_ */
