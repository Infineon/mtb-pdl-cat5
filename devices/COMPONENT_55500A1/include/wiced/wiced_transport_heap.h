/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * API Defines the transport utilities using dynamic memory allocation for sending/receiving the data.
 */
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "wiced_data_types.h"
#include "wiced_result.h"

/*
*  Define structure to configure dynamic heap for transport
*/
typedef struct wiced_transport_heap_cfg_s
{
    /*Data heap size requirement of application, this heap will be used for data tx and Rx*/
    uint32_t      data_heap_size;

    /*Data heap size requirement of application, this heap will be used for logging hci trace*/
    uint32_t      hci_trace_heap_size;

    /*Data heap size requirement of application, this heap will be used for logging debug trace*/
    uint32_t      debug_trace_heap_size;
}wiced_transport_heap_cfg_t;

/**
* Function         wiced_trans_create_heap
*
*                  Creates dynamic memory area. Application reserves an area for dynamic
*                  variable memory allocations with this call. Application can now allocate
*                  variable sized buffers.
*
* @param[in]       Size of heap to be allocated and related configuration defined by config
*
* @return          wiced_result_t
*/
wiced_result_t wiced_trans_create_heap (wiced_transport_heap_cfg_t * heap_config);

/**
* Function         wiced_trans_malloc_data
*
*                  Allocates memory from the transport data heap
*
* @param[in]       Size of heap to be allocated and heap type
*
* @return          void
*/
void * wiced_trans_malloc_data(uint32_t length);

/**
* Function         wiced_trans_malloc_hci_trace
*
*                  Allocates memory from the transport hci trace heap
*
* @param[in]       Size of heap to be allocated and heap type
*
* @return          void
*/
void* wiced_trans_malloc_hci_trace(uint32_t length);

/**
* Function         wiced_trans_malloc_debug
*
*                  Allocates memory from the transport debug heap
*
* @param[in]       Size of heap to be allocated and heap type
*
* @return          void
*/
void* wiced_trans_malloc_debug(uint32_t length);


/**
* Function         wiced_trans_free
*
*                  Frees memory from the heap specified by type
*
* @param[in]       pointer to the heap memory.
*
* @return          void
*/
void wiced_trans_free (void *pBuf);
