/***************************************************************************//**
* \file cy_pdl_wrapper.h
*
* \brief
*  This file provides the wrapper for syslib APIs from CY PDL
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation.  All rights reserved.
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

#if !defined(CY_PDL_WRAPPER_H)
#define CY_PDL_WRAPPER_H

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "cy_utils.h"

#if defined(__cplusplus)
extern "C" {
#endif

// brcm_fw_types.h

//#define __STATIC_INLINE        ATTR_STATIC_INLINE
#define __STATIC_INLINE         static inline

//! Unsigned 8-bit integer.
typedef uint8_t                 UINT8;
typedef uint8_t                 uint8;
typedef uint8_t                 BYTE;
typedef char                    char_t;

//! Signed 8-bit integer.
typedef int8_t                  INT8;
typedef int8_t                  int8;

//! Unsigned 16-bit integer.
typedef uint16_t                UINT16;
typedef uint16_t                uint16;
typedef uint16_t                WORD;

//! Signed 16-bit integer.
typedef int16_t                 INT16;
typedef int16_t                 int16;

//! Unsigned 32-bit integer.
typedef uint32_t                UINT32;
typedef uint32_t                uint32;
typedef uint32_t                DWORD;

//! Signed 32-bit integer.
typedef int32_t                 INT32;
typedef int32_t                 int32;

//! Unsigned 64-bit integer.
typedef uint64_t                UINT64;

//! Signed 64-bit integer.
typedef int64_t                 INT64;

//! Boolean type in its most size-efficient form, for use in structures.
typedef uint8_t                 BOOL8;

//! typedef for 32-bit floating point
typedef float                   cy_float32_t;

//! Macro to divide numerator by denominator, rounding up.
#define DIV_ROUND_UP( n, d )                                    ( ( (n) + (d)-1 ) / (d) )

//! Macro to divide numerator by denominator, rounding to the nearest number.
#define DIV_ROUND_NEAREST( n, d )                               ( ( (n) + (d)/2 ) / (d) )

//! Macro to obtain the absolute value of an integer.
#ifndef ABS
#define ABS(v)                                                  ( ( (v) < 0 ) ? ( 0-(v) ) : (v) )
#endif

//! Macro to obtain the minimum (smaller) of two numbers.
#ifndef MIN
#define MIN( a, b )                                             ( ( (a) < (b) ) ? (a) : (b) )
#endif

//! Macro to obtain the maximum (larger) of two numbers.
#ifndef MAX
#define MAX( a, b )                                             ( ( (a) > (b) ) ? (a) : (b) )
#endif

//==================================================================================================
// Macro for access to hardware registers
//==================================================================================================

//! The REG32 macro is a convenient way to access a 32-bit hardware register.  It merely casts the
//! integer register address to a pointer to a volatile UINT32 and dereferences it.
#define REG32(address)  ( *(volatile UINT32*)(address) )
#define REG32_FLD_UPDATE(address, value, mask)    REG32(address) = ((REG32(address) & ~(mask)) | ((value) & (mask)))

//==================================================================================================
// Constants
//==================================================================================================
#if !(defined TRUE)
    //! Macro representing a boolean true condition.  Note that it is appropriate to return TRUE, but
    //! not appropriate to compare against it because any non-zero value can legitimately be used to
    //! represent truth, especially in optimized code.  Instead of if(condition == TRUE) one should
    //! simply use if(condition).
    #define TRUE    1
#endif

#if !(defined FALSE)
    //! Macro representing a boolean false condition.
    #define FALSE   0
#endif

#define ATTRIBUTE(x)            __attribute__(x)

// Linker uses .bss as a trigger to create the section as "Zero" type.
//   This allows us to override in scatter file with UNINIT
#define ATTR_ZI_INIT(x)         __attribute__((section(".bss." x)))

#define PLACE_IN_DROM1
#define PLACE_IN_DROM           ATTRIBUTE((section("const_drom_var")))

/******************************************************************************
* PDL cy_syslib to BTFW
******************************************************************************/

#include "wiced_rtos.h"
#include "btss_system.h"

#define Cy_SysLib_DelayUs(x)                    (void)wiced_rtos_delay_microseconds(x)
#define Cy_SysLib_Delay(x)                      (void)wiced_rtos_delay_milliseconds(x, ALLOW_THREAD_TO_SLEEP)
#define Cy_SysLib_EnterCriticalSection()        btss_system_enterCriticalSection()
#define Cy_SysLib_ExitCriticalSection(x)        btss_system_exitCriticalSection(x)

/******************************************************************************
* PDL Macros
*****************************************************************************/

#define CY_PDL_STATUS_CODE_Pos  (0U)        /**< The module status code position in the status code */
#define CY_PDL_STATUS_TYPE_Pos  (16U)       /**< The status type position in the status code */
#define CY_PDL_MODULE_ID_Pos    (18U)       /**< The software module ID position in the status code */
#define CY_PDL_STATUS_INFO      (0UL << CY_PDL_STATUS_TYPE_Pos)    /**< The information status type */
#define CY_PDL_STATUS_WARNING   (1UL << CY_PDL_STATUS_TYPE_Pos)    /**< The warning status type */
#define CY_PDL_STATUS_ERROR     (2UL << CY_PDL_STATUS_TYPE_Pos)    /**< The error status type */
#define CY_PDL_MODULE_ID_Msk    (0x3FFFU)   /**< The software module ID mask */

/** Get the software PDL module ID */
#define CY_PDL_DRV_ID(id)       ((uint32_t)((uint32_t)((id) & CY_PDL_MODULE_ID_Msk) << CY_PDL_MODULE_ID_Pos))

/******************************************************************************
* PDL Device Header Macros
*****************************************************************************/

/* These are CMSIS-CORE defines used for structure members definitions */
#ifndef     __IM
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#endif
#ifndef     __OM
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#endif
#ifndef     __IOM
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */
#endif


/*******************************************************************************
*  SysPM to BTFW
*******************************************************************************/

#define CY_SYSPM_ID                      (CY_PDL_DRV_ID(0x10U))

/** This enumeration specifies the associated callback mode. This enum defines the callback mode. */
typedef enum
{
    CY_SYSPM_CHECK_READY        = 0x01U,    /**< Callbacks with this mode are executed before entering into the
                                                 low power mode. The purpose of his callback function is to check
                                                 if the device is ready to enter the low power mode. */
    CY_SYSPM_CHECK_FAIL         = 0x02U,    /**< Callbacks with this mode are executed after the CY_SYSPM_CHECK_READY
                                                 callbacks execution returns CY_SYSPM_FAIL.
                                                 The callback with the CY_SYSPM_CHECK_FAIL mode should roll back the
                                                 actions performed in the previously executed callback with
                                                 CY_SYSPM_CHECK_READY */
    CY_SYSPM_BEFORE_TRANSITION  = 0x04U,    /**< Callbacks with this mode are executed after the CY_SYSPM_CHECK_READY
                                                 callbacks execution returns CY_SYSPM_SUCCESS.
                                                 Performs the actions to be done before entering into the
                                                 low power mode. */
    CY_SYSPM_AFTER_TRANSITION   = 0x08U     /**< Performs the actions to be done after exiting the low power mode
                                                 if entered. */
} cy_en_syspm_callback_mode_t;

/**
* This enumeration is used to initialize the functions wait action. The wait actions can be -
* an interrupt or an event. Refer to the CMSIS for WFE and WFI instruction explanations.
*/
typedef enum
{
    CY_SYSPM_WAIT_FOR_INTERRUPT,    /**< Wait for an interrupt. */
    CY_SYSPM_WAIT_FOR_EVENT         /**< Wait for an event. */
} cy_en_syspm_waitfor_t;

/** The SysPm function return value status definitions. */
typedef enum
{
    CY_SYSPM_SUCCESS         = 0x0U,                                         /**< Successful. */
    CY_SYSPM_BAD_PARAM       = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x01U,    /**< One or more invalid parameters. */
    CY_SYSPM_TIMEOUT         = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x02U,    /**< A time-out occurred. */
    CY_SYSPM_INVALID_STATE   = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x03U,    /**< The operation is not setup or is in an
                                                                                  improper state. */
    CY_SYSPM_CANCELED        = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x04U,    /**< Operation canceled. */
    CY_SYSPM_SYSCALL_PENDING = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x05U,    /**< Canceled due syscall operation pending. */
    CY_SYSPM_FAIL            = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0xFFU     /**< Unknown failure. */
} cy_en_syspm_status_t;


/** The structure contains syspm callback parameters */
typedef struct
{
    void *base;         /**< Base address of a HW instance, matches name of the driver in
                             the API for the base address. Can be undefined if not required. Base address is not
                             required for the SysPm driver as the device has only one set of power modes */
    void *context;      /**< Context for the handler function. This item can be
                             skipped if not required. Can be undefined if not required. */

} cy_stc_syspm_callback_params_t;

/** The type for syspm callbacks */
typedef cy_en_syspm_status_t (*Cy_SysPmCallback) (cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);

/** Device types for access to a memory range in non-secure SRAM */
typedef enum
{
  SEC_HW_DEVICE_NONE,
  SEC_HW_DEVICE_SDIO,
  SEC_HW_DEVICE_WLAN,
  SEC_HW_DEVICE_SDIO_AND_WLAN,
} SEC_HW_DEVICE_t;

/*******************************************************************************
*  Data manipulation defines
*******************************************************************************/
/** \cond INTERNAL */

/**
* Class 1 - The highest class, safety-critical functions which rely on parameters that could be
* changed between different PSoC devices
*/
#define CY_ASSERT_CLASS_1           (1U)

/** Class 2 - Functions that have fixed limits such as counter periods (16-bits/32-bits etc.) */
#define CY_ASSERT_CLASS_2           (2U)

/** Class 3 - Functions that accept enums as constant parameters */
#define CY_ASSERT_CLASS_3           (3U)

#ifndef CY_ASSERT_LEVEL
    /** The user-definable assert level from compiler command-line argument (similarly to DEBUG / NDEBUG) */
    #define CY_ASSERT_LEVEL         CY_ASSERT_CLASS_3
#endif /* CY_ASSERT_LEVEL */

#if (CY_ASSERT_LEVEL == CY_ASSERT_CLASS_1)
    #define CY_ASSERT_L1(x)         CY_ASSERT(x)     /**< Assert Level 1 */
    #define CY_ASSERT_L2(x)         do{} while(0)    /**< Assert Level 2 */
    #define CY_ASSERT_L3(x)         do{} while(0)    /**< Assert Level 3 */
#elif (CY_ASSERT_LEVEL == CY_ASSERT_CLASS_2)
    #define CY_ASSERT_L1(x)         CY_ASSERT(x)     /**< Assert Level 1 */
    #define CY_ASSERT_L2(x)         CY_ASSERT(x)     /**< Assert Level 2 */
    #define CY_ASSERT_L3(x)         do{} while(0)    /**< Assert Level 3 */
#else /* Default is Level 3 */
    #define CY_ASSERT_L1(x)         CY_ASSERT(x)     /**< Assert Level 1 */
    #define CY_ASSERT_L2(x)         CY_ASSERT(x)     /**< Assert Level 2 */
    #define CY_ASSERT_L3(x)         CY_ASSERT(x)     /**< Assert Level 3 */
#endif /* CY_ASSERT_LEVEL == CY_ASSERT_CLASS_1 */


/*******************************************************************************
* Macro Name: _BOOL82FLD
****************************************************************************//**
*
*  Returns a field mask if the value is not FALSE.
*  Returns 0, if the value is FALSE.
*
*******************************************************************************/
#define _BOOL82FLD(field, value) (((value) != FALSE) ? (field ## _Msk) : 0UL)


/*******************************************************************************
* Macro Name: _FLD2BOOL8
****************************************************************************//**
*
*  Returns TRUE, if the value includes the field mask.
*  Returns FALSE, if the value doesn't include the field mask.
*
*******************************************************************************/
#define _FLD2BOOL8(field, value) (((value) & (field ## _Msk)) != 0UL)


/**
  \brief   Mask and shift a bit field value for use in a register bit range.
  \param[in] field  Name of the register bit field.
  \param[in] value  Value of the bit field. This parameter is interpreted as an UINT32 type.
  \return           Masked and shifted value.
*/
#define _VAL2FLD(field, value)    (((UINT32)(value) << field ## _Pos) & field ## _Msk)

/**
  \brief     Mask and shift a register value to extract a bit filed value.
  \param[in] field  Name of the register bit field.
  \param[in] value  Value of register. This parameter is interpreted as an UINT32 type.
  \return           Masked and shifted bit field value.
*/
#define _FLD2VAL(field, value)    (((UINT32)(value) & field ## _Msk) >> field ## _Pos)


/*******************************************************************************
* Macro Name: CY_SYSLIB_DIV_ROUND
****************************************************************************//**
*
*  Calculates a / b with rounding to the nearest integer,
*  a and b must have the same sign.
*
* \note
* This macro is available for devices having M33SYSCPUSS IP.
*
*******************************************************************************/
#define CY_SYSLIB_DIV_ROUND(a, b) (((a) + ((b) / 2U)) / (b))


/*******************************************************************************
* Macro Name: CY_SYSLIB_DIV_ROUNDUP
****************************************************************************//**
*
*  Calculates a / b with rounding up if remainder != 0,
*  both a and b must be positive.
*
* \note
* This macro is available for devices having M33SYSCPUSS IP.
*
*******************************************************************************/
#define CY_SYSLIB_DIV_ROUNDUP(a, b) ((((a) - 1U) / (b)) + 1U)

/*******************************************************************************
* Macro Name: CY_UNUSED_PARAM
****************************************************************************//**
*
*  Suppresses the unused parameter warning
*
* \note
* This macro is available for devices having M33SYSCPUSS IP.
*
*******************************************************************************/
#define CY_UNUSED_PARAM(a) (void)(a)

/*******************************************************************************
* Macro Name: CY_ARRAY_SIZE(x)
****************************************************************************//**
*
* Returns the size of Array
*
* \param x  Array Name
*
* \note
* This macro is available for devices having M33SYSCPUSS IP.
*
*******************************************************************************/
#define CY_ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#if defined(__cplusplus)
}
#endif

#endif /* (CY_PDL_WRAPPER_H) */

/* [] END OF FILE */
