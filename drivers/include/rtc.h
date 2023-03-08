/***************************************************************************//**
* \file rtc.h
*
* Provides API declarations of the RTC driver.
*
********************************************************************************
* \copyright
* Copyright 2022 Infineon Technologies
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

#ifndef __RTC_H__
#define __RTC_H__

#ifdef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/** RTC HW Raw Counter - 48-bit Counter */
typedef union
{
    UINT64          rtc64;

    struct
    {
        UINT16      rtc16[4];
    } reg16map;

    struct
    {
        UINT32      rtc32[2];
    } reg32map;

} RTC_RAW_COUNTER_t;

/** RTC time management - Calendar representation of time */
typedef struct
{
    /// seconds (0 - 59), not support leap seconds
    UINT16  second;

    /// minutes (0 - 59),
    UINT16  minute;

    /// hours (0 - 23)
    UINT16  hour;

    /// day of the month (1 - 31)
    UINT16  day;

    /// month (0 - 11, 0=January)
    UINT16  month;

    /// year
    /// should larger then 2010
    UINT16  year;

} RTC_TIME_t;

/**
 * Function rtc_init
 *
 * Initialize the RTC driver.
 *
 * \param        none
 *
 * \return       none
 */
void rtc_init(void);

/**
 * Function rtc_getRawClock
 *
 * This function call read 48 bits real-time-clock value from RTC HW
 *
 * \param[in]    rtcClock      : buffer to for the read data
 *
 * \return       none
 */
void rtc_getRawClock(RTC_RAW_COUNTER_t *rtcClock);

/**
 * Function rtc_getRTCTime
 *
 * Get current time in Calendar format
 *
 * \param[in]    rtcTime       : Timer object pointer to be stored for the return value
 *
 * \return       none
 */
void rtc_getRTCTime(RTC_TIME_t *timebuf);

/**
 * Function rtc_setReferenceTime
 *
 * Set the reference time to the given reference. Useful when the app sets one time
 * and then enters deep sleep, and then wakes up and then wants the ref time to
 * still be the one that was set the reference to the original rtc_setRTCTime call.
 *
 * \param[in]    ref_time      : The original reference time that was set using rtc_setRTCTime.
 *
 * \return       none
 */
void rtc_setReferenceTime(RTC_TIME_t* ref_time);

/**
 * Function rtc_setRTCTime
 *
 * Set the current time
 * This function call will asume the current time is later then
 * BASE_LINE_REF time
 *
 * \param[in]    newTime       : timer object pointer for current time
 *
 * \return       0 - FAILED, 1 - SUCCESS
 */
BOOL32 rtc_setRTCTime(RTC_TIME_t  *newTime);

/**
 * Function rtc_ctime
 *
 * This function call will convert the RtcTime object pointed by rtctime to
 * c string containing a human-readable verion of the correspoing
 * local time and data. Caller should make sure *outbuf size
 * larger then 22 bytes.
 *
 * The returned string has the folloing format
 *
 * Mmm dd hh:mm:ss yyyy
 * where
 *      Mmm - the month in letters
 *      dd  - the day of the month
 *      hh:mm:ss -  time
 *      yyyy - year
 *
 * \param[in]    timer         : timer object pointer to be converted
 * \param[out]   outbuf        : buffer for the converted string
 *
 * \return NULL if convert fail, or will be start of the valid string
 */
char *rtc_ctime(RTC_TIME_t *timer, char *outbuf);

/**
 * Function rtc_sec2RtcTime
 *
 * Convert from UINT32 seconds to RTC_time timer object
 *
 * \param[in]    second        : 32-bits seconds to be converted
 * \param[out]   rtctime       : converted timer object pointer
 *
 * \return       none
 */
void rtc_sec2RtcTime(UINT32 second, RTC_TIME_t *rtctime);

/**
 * Function rtc_RtcTime2Sec
 *
 * Convert RTC_time format to 32-bits seocnds format
 *
 * \param[in]    rtctime       : timer object pointer to be converted
 * \param[out]   second        : converted UINT32 seconds
 *
 * \return       none
 */
void rtc_RtcTime2Sec(RTC_TIME_t *rtctime, UINT32 *second);

#if defined(__cplusplus)
}
#endif

#endif //__RTC_H__

/* [] END OF FILE */
