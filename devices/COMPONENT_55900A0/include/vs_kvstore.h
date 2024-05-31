/*******************************************************************************
* \file vs_kvstore.h
*
* Provides API declarations of the updated VS interfaces for use with KVStore.
*
********************************************************************************
* \copyright
* Copyright 2023 Infineon Technologies
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _VS_KVSTORE_H_
#define _VS_KVSTORE_H_

#define VS_RET_OK     0
#define VS_RET_FAIL   1
#define VS_RET_FAIL_OVERWRITE              ((1u<<4)|VS_RET_FAIL)
#define VS_RET_FAIL_MEMACESS               ((2u<<4)|VS_RET_FAIL)
#define VS_RET_FAIL_INSUFFICIENT_STORAGE   ((3u<<4)|VS_RET_FAIL)
#define VS_RET_FAIL_RECORD_NOT_FOUND       ((4u<<4)|VS_RET_FAIL)

/**
 * Function VS_KVStore_SingleRecordSize
 *
 * \param[out]   record_size      : Maximum size of a single record in VS
 *
 * \return       Result - Pass(VS_RET_OK) or Fail(VS_RET_FAIL)
 */
UINT8 VS_KVStore_SingleRecordSize(UINT32* recordSize);

/**
 * Function VS_KVStore_Size
 *
 * \param[out]    size            : Size of the current/usable memory reserved for VS in non volatile storage
 *
 * \return       Result - Pass(VS_RET_OK) or Fail(VS_RET_FAIL)
 */
UINT8 VS_KVStore_Size(UINT32* size);

/**
 * Function VS_KVStore_Write
 *
 * \param[in]    key              : Key identifier req
 * \param[in]    data             : Pointer to the  buffer that holds the value to be written to the VS storage
 * \param[in]    size             : Length of the value to be written to the VS storage
 * \param[in]    overwrite        : Flag to indicate if the overwrite is allowed. 0 indicates overwrite not allowed, 1 indicates overwrite allowed
 *
 * \return       Result - Pass -> VS_RET_OK
 *                        Fail -> VS_RET_FAIL
 *                        Fail if record exists & overwrite is not allowed -> VS_RET_FAIL_OVERWRITE
 */
UINT8 VS_KVStore_Write(const UINT16 key, const UINT8 *data, UINT32 size, BOOL32 overwrite);

/**
 * Function VS_KVStore_ValueSize
 *
 * \param[in]    key              : Key identifier
 * \param[in]    size             : Size of the value that corresponds to the key
 *
 * \return       Result - Pass(VS_RET_OK) or Fail(VS_RET_FAIL)
 */
UINT8 VS_KVStore_ValueSize( const UINT16 key, UINT32 *size);

/**
 * Function VS_KVStore_Read
 *
 * \param[in]    key              : Key identifier
 * \param[out]   data             : Pointer to the buffer to copy the data read from the VS storage
 *
 * \return       Result - Pass(VS_RET_OK) or Fail(VS_RET_FAIL)
 */
UINT8 VS_KVStore_Read( const UINT16 key,  UINT8 *data, UINT32 *size );

/**
 * Function VS_KVStore_Delete
 *
 * \param[in]    key              : Identifier corresponds to the key to be deleted
 *
 * \return       Result - Pass(VS_RET_OK) or Fail(VS_RET_FAIL)
 */
UINT8 VS_KVStore_Delete( const UINT16 key );

/**
 * Function VS_KVStore_Erase
 *
 * This erases the whole storage
 *
 * \param                         : None
 *
 * \return       Result - Pass(VS_RET_OK) or Fail(VS_RET_FAIL)
 */
UINT8 VS_KVStore_Erase(void);

#if defined(COMPONENT_CAT5)

UINT8 thread_ap_VS_KVStore_SingleRecordSize( UINT32* recordSize );
UINT8 thread_ap_VS_KVStore_Size( UINT32* size );
UINT8 thread_ap_VS_KVStore_Write( const UINT16 key, const UINT8 *data, UINT32 size, BOOL32 overwrite );
UINT8 thread_ap_VS_KVStore_ValueSize( const UINT16 key, UINT32 *size );
UINT8 thread_ap_VS_KVStore_Read( const UINT16 key,  UINT8 *data, UINT32 *size );
UINT8 thread_ap_VS_KVStore_Delete( const UINT16 key );
UINT8 thread_ap_VS_KVStore_Erase( void );


/* for use in MTB build */
#define config_VS_single_record_size thread_ap_VS_KVStore_SingleRecordSize
#define config_VS_size               thread_ap_VS_KVStore_Size
#define config_VS_write              thread_ap_VS_KVStore_Write
#define config_VS_value_size         thread_ap_VS_KVStore_ValueSize
#define config_VS_read               thread_ap_VS_KVStore_Read
#define config_VS_delete             thread_ap_VS_KVStore_Delete
#define config_VS_erase              thread_ap_VS_KVStore_Erase

#endif /* COMPONENT_CAT5 */


#endif /* _VS_KVSTORE_H_ */
