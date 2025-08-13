/*******************************************************************************
* THIS INFORMATION IS PROPRIETARY TO INFINEON TECHNOLOGIES
*
* ------------------------------------------------------------------------------
*
* Copyright (c) 2024 Infineon Technologies.
*
*          ALL RIGHTS RESERVED
*
********************************************************************************
*
********************************************************************************
*
* File Name: attest_csr.h
*
* Abstract: This file contains CSR (as supported on target) Interface(s)
*
*******************************************************************************/

#if !defined(_ATTEST_CSR_SEC_FW_H_)
#define _ATTEST_CSR_SEC_FW_H_

/* Key index to be used */
/* for attestation */
#define KEY_IDX_ATTEST_SECP256R1  2
/* for cloud-id */
#define KEY_IDX_CLOUDID_SECP256R1 0
#define KEY_IDX_CLOUDID_SECP384R1 1

/**
 * @brief Retrieve CSR specific to the requested Key-index
 * 
 * @param key_idx         Key-index for CSR.
 * @param p_token_buf     Output buffer where CSR is to be written.
 * @param p_token_size    Input/Output variable for the actual token size.
 */
psa_status_t attestation_get_csr(int32_t key_idx, uint8_t *p_token_buf, uint32_t *p_token_size);

/**
 * @brief Calculate the size of an Initial Attestation Token.
 *
 * @param key_idx         Key-index for CSR.
 * @param p_token_size    Output variable for the actual CSR size.
 *
 */
psa_status_t attestation_get_csr_size(int32_t key_idx, size_t *p_token_size);

#endif /* _ATTEST_CSR_SEC_FW_H_ */
