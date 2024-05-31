/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * @defgroup Transport     AIROC real timer clock interface
 * @ingroup HardwareDrivers
 *
 */
#pragma once

#include "wiced_bt_dev.h"
#include "wiced_hal_pspi.h"
#include "wiced_transport_heap.h"


/*****************************************************************************
**                                                 Function Declarations
*****************************************************************************/

/**
 * Function         wiced_rtc_init
 *
 * Initialize the RTC block.
 *
 * * @param[in]  void
 *
 * @return     : None
 */
void wiced_rtc_init(void);


/**
 * Function         wiced_rtc_get_raw_clock
 *
 * Reads Real time clock value from hardware clock.
 *
 * * @param[in]  rtcClock : Real time clock
 *
 * @return     : None
 */
void wiced_rtc_get_raw_clock(tRTC_REAL_TIME_CLOCK *rtcClock);


/**
 * Function         wiced_rtc_get_time
 *
 *  get current time in RTC_time format
 *
 * * @param[in]  timebuf: current time in rtc format
 *
 * @return     : None
 */
void wiced_rtc_get_time(RtcTime *timebuf);


/**
 * Function         wiced_rtc_set_reference_time
 *
 *  set original reference time.
 *
 * * @param[in]  ref_time: rtc time
 *
 * @return     : None
 */
void wiced_rtc_set_reference_time(RtcTime* ref_time);


/**
 * Function         wiced_rtc_set_reference_time
 *
 *  set the current time
 *
 * * @param[in]  newTime : rtc time for setting.
 *
 * @return     : SUCCESS/FALSE
 */
BOOL32 wiced_set_rtc_time(RtcTime  *newTime);


/**
 * Function         wiced_rtc_ctime
 *

 * convert the tm object pointed by timer to
 * c string containing a human-readable verion of the correspoing local time and data
 *
 * the returned string has the folloing format
 *
 * Mmm dd hh:mm:ss yyyy
 * where
 *      Mmm - the month in letters
 *      dd  - the day of the month
 *      hh:mm:ss -  time
 *      yyyy - year
 * * @param[in]  timer:  rtc time
 * * @param[in]  outbuf: string output
 *
 * @return     : SUCCESS/FALSE
 */
BOOL32 wiced_rtc_ctime(RtcTime *timer, char *outbuf);

/**
 * Function         wiced_seconds_to_rtc_time
 *
 *  conver the 32 bit seconds to RTC_time broken down format
 *
 * * @param[in]  second:  seconds
 * * @param[in]  rtctime: rtc format output
 *
 * @return     : NONE
 */
void wiced_seconds_to_rtc_time(UINT32 second, RtcTime *rtctime);

/**
 * Function         wiced_rtc_time_to_seconds
 *
 *  convert RTC_time broken-down format to 32-bits seocnds
 *
 * * @param[in]  rtctime :  rtc time
 * * @param[in]  second  :  seconds
 *
 * @return     : NONE
 */
void wiced_rtc_time_to_seconds(RtcTime *rtctime, UINT32 *second);
