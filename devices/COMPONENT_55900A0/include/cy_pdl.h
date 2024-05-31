/***************************************************************************//**
* \file cy_pdl.h
*
* Include this file in all of your source files that access PDL.
*
********************************************************************************
* \copyright
* Copyright 2018-2019 Cypress Semiconductor Corporation
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

#ifndef CY_PDL_H
#define CY_PDL_H

#include "cy_device.h"

#include "cy_tx_thread.h"
#include "btss_dmac.h"
#include "btss_gpio.h"
#include "btss_pinmux.h"
#include "btss_system.h"
#include "rtc.h"
#include "vs_kvstore.h"

#include "cy_adccomp.h"
#include "cy_pdm_pcm.h"
#include "cy_scb.h"
#include "cy_scb_ezi2c.h"
#include "cy_scb_i2c.h"
#include "cy_scb_spi.h"
#include "cy_scb_uart.h"
#include "cy_smif.h"
#include "cy_smif_memslot.h"
#include "cy_tcpwm.h"
#include "cy_tcpwm_counter.h"
#include "cy_tcpwm_pwm.h"
#include "cy_tcpwm_quaddec.h"
#include "cy_tcpwm_shiftreg.h"
#include "t2_arm_timer.h"
#include "cy_tdm.h"
#include "cy_tdm_common.h"
#include "cy_rtc.h"

/** Driver Library major version */
#define CY_PDL_VERSION_MAJOR        1

/** Driver Library minor version */
#define CY_PDL_VERSION_MINOR        6

/** Driver Library version */
#define CY_PDL_VERSION              106

#endif /* CY_PDL_H */
