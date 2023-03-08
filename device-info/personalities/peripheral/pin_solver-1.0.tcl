# \copyright
# Copyright (c) (2023), Cypress Semiconductor Corporation (an Infineon company) or
# an affiliate of Cypress Semiconductor Corporation.
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# From https://wiki.tcl-lang.org/page/constants
proc const {name value} {
    uplevel 1 [list set $name $value]
    uplevel 1 [list trace var $name w {error constant} ]
}

const ARG_IDX 0
const BTSS_VALUE  "btssValuePersonality"

const FUNC_A_GPIO_0 1
const FUNC_A_GPIO_7 8
const BTSS_A_GPIO_0 8

const FUNC_B_GPIO_0 9
const FUNC_B_GPIO_7 16
const BTSS_B_GPIO_0 16

const FUNC_GPIO_0 19
const FUNC_GPIO_7 26
const BTSS_GPIO_0 0

const ERROR_ARG_COUNT 1
const SUCCESS 0

set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

proc solve_pin {} {
    if {$::argc != $::ARG_IDX + 1} {
        error "Requires one argument"
        return $::ERROR_ARG_COUNT
    }
    set func [lindex $::argv $::ARG_IDX]

    return [getValue $func]
}

proc output_results {btssValue} {
    puts $::channelName "param:$::BTSS_VALUE=$btssValue"
}

proc getValue {functionlity} {
    set value 0
    if {($functionlity >= $::FUNC_A_GPIO_0) && ($functionlity <= $::FUNC_A_GPIO_7)} {
        set value [expr {($functionlity - $::FUNC_A_GPIO_0) + $::BTSS_A_GPIO_0}]
    } elseif {($functionlity >= $::FUNC_B_GPIO_0) && ($functionlity <= $::FUNC_B_GPIO_7)} {
        set value [expr {($functionlity - $::FUNC_B_GPIO_0) + $::BTSS_B_GPIO_0}]
    } else {
        set value [expr {($functionlity - $::FUNC_GPIO_0) + $::BTSS_GPIO_0}]
    }
    output_results $value
    return $::SUCCESS
}

solve_pin
