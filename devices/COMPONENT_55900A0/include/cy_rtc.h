/***************************************************************************//**
* \file cy_rtc.h
* \version 2.30
*
* This file specifies the structures used by the RTC.
*
********************************************************************************
* \copyright
* Copyright 2021-2022 Cypress Semiconductor Corporation
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

#ifndef CY_RTC_H_
#define CY_RTC_H_

/**
  * @brief Enum used to distinguish between fixed and relative DST start/end times
  */
typedef enum
{
    CY_RTC_DST_RELATIVE,       /**< Relative DST format. eg: Begins on the last Sunday of March
                                    and ends on the last Sunday of October. */
    CY_RTC_DST_FIXED           /**< Fixed DST format. eg: Begins on 21st March
                                    and ends on 21st September. */
} cy_rtc_dst_format_t;

/**
* @brief Day Light Savings Time (DST) structure for setting when to apply. It allows to
* set the DST time and date using a fixed or relative time format.
*/
typedef struct
{
    cy_rtc_dst_format_t                 format;       /**< DST format. See /ref cy_rtc_dst_format_t.
                                                           Based on this value other structure elements
                                                           should be filled or could be ignored */
    uint32_t                            hour;         /**< Hour in 24hour format, range[0-23] */
    union
    {
        uint32_t                        dayOfMonth;   /**< Day of Month, range[1-31]. */
        struct /* format = CY_RTC_DST_FIXED */
        {
            uint32_t                    dayOfWeek;    /**< Day of the week, starting on Sunday, range[0-6] */
            uint32_t                    weekOfMonth;  /**< Week of month, range[0-5]. Where 5 => Last week of month */
        };                                            /**< Anonymous struct specifying the week number plus day of week */
    };                                                /**< Anonymous union for the day as either a specific day (dayOfMonth)
                                                           or as a week number (weekOfMonth) plus day of week (dayOfWeek) */
    uint32_t                            month;        /**< Month value, range[0-11]. */
} cy_rtc_dst_t;

/**
 * @brief This is the DST structure to handle start DST and stop DST
 */
typedef struct
{
    cy_rtc_dst_t                 startDst;       /**< DST start time structure */
    cy_rtc_dst_t                 stopDst;        /**< DST stop time structure */
} cy_stc_rtc_dst_t;

#endif // CY_RTC_H_
