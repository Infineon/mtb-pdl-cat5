/* source: https://github.com/ARM-software/psa-api/blob/main/headers/status-code/1.0/psa/error.h */

// SPDX-FileCopyrightText: Copyright 2017-2022 Arm Limited and/or its affiliates <open-source-office@arm.com>
// SPDX-License-Identifier: Apache-2.0

// This file is a reference template for implementation of the PSA Certified Status code API

#ifndef PSA_ERROR_H
#define PSA_ERROR_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BTFW return code mismatch. Needs remap to PSA  */
typedef enum fw_psa_status
{
    /** Action was performed successfully */
    FW_PSA_SUCCESS = 0,
    /** Boot status data is unavailable or malformed */
    FW_PSA_ERROR_SERVICE_FAILURE,
    /** Token buffer is too small to store the created token there */
    FW_PSA_ERROR_BUFFER_TOO_SMALL,
    /** One of the following invalid input conditions occured:
     * - the challenge size is not supported
     * - the challenge object is not writable
     * - the token buffer is not writable
    **/
    FW_PSA_ERROR_INVALID_ARGUMENT,
    /** Unexpected error happened during operation */
    FW_PSA_ERROR_GENERIC_ERROR,
    /** Following entry is only to ensure the error code of integer size */
    FW_PSA_ATTEST_ERR_FORCE_INT_SIZE = 0xFFFFF
}fw_psa_status_t;


/* Prevent multiple definitions of psa_status_t, if PSA_SUCCESS is already
   defined in an external header
 */
#ifndef PSA_SUCCESS

/**
 * @brief A status code type used for all PSA Certified APIs.
 */
typedef int32_t psa_status_t;
#endif

/**
 * @brief A status code to indicate general success.
 */
#define PSA_SUCCESS ((psa_status_t)0)

/**
 * @brief A status code that indicates a PROGRAMMER ERROR in the client.
 */
#define PSA_ERROR_PROGRAMMER_ERROR ((psa_status_t)-129)

/**
 * @brief A status code that indicates that the caller is not permitted to
 *        connect to a Service.
 */
#define PSA_ERROR_CONNECTION_REFUSED ((psa_status_t)-130)

/**
 * @brief A status code that indicates that the caller cannot connect to a
 *        service.
 */
#define PSA_ERROR_CONNECTION_BUSY ((psa_status_t)-131)

/**
 * @brief A status code that indicates an error that does not correspond to any
 *        defined failure cause.
 */
#define PSA_ERROR_GENERIC_ERROR ((psa_status_t)-132)

/**
 * @brief A status code that indicates that the requested action is denied by a
 *        policy.
 */
#define PSA_ERROR_NOT_PERMITTED ((psa_status_t)-133)

/**
 * @brief A status code that indicates that the requested operation or a
 *        parameter is not supported.
 */
#define PSA_ERROR_NOT_SUPPORTED ((psa_status_t)-134)

/**
 * @brief A status code that indicates that the parameters passed to the
 *        function are invalid.
 */
#define PSA_ERROR_INVALID_ARGUMENT ((psa_status_t)-135)

/**
 * @brief A status code that indicates that a handle parameter is not valid.
 */
#define PSA_ERROR_INVALID_HANDLE ((psa_status_t)-136)

/**
 * @brief A status code that indicates that the requested action cannot be
 *        performed in the current state.
 */
#define PSA_ERROR_BAD_STATE ((psa_status_t)-137)

/**
 * @brief A status code that indicates that an output buffer parameter is too
 *        small.
 */
#define PSA_ERROR_BUFFER_TOO_SMALL ((psa_status_t)-138)

/**
 * @brief A status code that indicates that an identifier or index is already in
 *        use.
 */
#define PSA_ERROR_ALREADY_EXISTS ((psa_status_t)-139)

/**
 * @brief A status code that indicates that an identified resource does not
 *        exist.
 */
#define PSA_ERROR_DOES_NOT_EXIST ((psa_status_t)-140)

/**
 * @brief A status code that indicates that there is not enough runtime memory.
 */
#define PSA_ERROR_INSUFFICIENT_MEMORY ((psa_status_t)-141)

/**
 * @brief A status code that indicates that there is not enough persistent
 *        storage.
 */
#define PSA_ERROR_INSUFFICIENT_STORAGE ((psa_status_t)-142)

/**
 * @brief A status code that indicates that a data source has insufficient
 *        capacity left.
 */
#define PSA_ERROR_INSUFFICIENT_DATA ((psa_status_t)-143)

/**
 * @brief A status code that indicates an error within the service.
 */
#define PSA_ERROR_SERVICE_FAILURE ((psa_status_t)-144)

/**
 * @brief A status code that indicates a communication failure between the
 *        function and another service or component.
 */
#define PSA_ERROR_COMMUNICATION_FAILURE ((psa_status_t)-145)

/**
 * @brief A status code that indicates a storage failure that may have led to
 *        data loss.
 */
#define PSA_ERROR_STORAGE_FAILURE ((psa_status_t)-146)

/**
 * @brief A status code that indicates that a hardware failure was detected.
 */
#define PSA_ERROR_HARDWARE_FAILURE ((psa_status_t)-147)

/**
 * @brief A status code that indicates that a signature, MAC or hash is
 *        incorrect.
 */
#define PSA_ERROR_INVALID_SIGNATURE ((psa_status_t)-149)

/**
 * @brief A status code that indicates that internal data has been tampered
 *        with.
 */
#define PSA_ERROR_CORRUPTION_DETECTED ((psa_status_t)-151)

/**
 * @brief A status code that indicates that stored data has been corrupted.
 */
#define PSA_ERROR_DATA_CORRUPT ((psa_status_t)-152)

/**
 * @brief A status code that indicates that data read from storage is not valid
 *        for the implementation.
 */
#define PSA_ERROR_DATA_INVALID ((psa_status_t)-153)

/**
 * @brief A status code that indicates that the requested operation is
 *        interruptible, and still has work to do.
 */
#define PSA_OPERATION_INCOMPLETE ((psa_status_t)-248)

#ifdef __cplusplus
}
#endif

#endif // PSA_ERROR_H