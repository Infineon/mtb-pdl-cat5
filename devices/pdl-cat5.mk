################################################################################
# \file pdl-cat5.mk
#
# \brief
# Add pdl file paths to build environment.
#
################################################################################
# \copyright
# Copyright 2021-2022 Cypress Semiconductor Corporation (an Infineon company) or
# an affiliate of Cypress Semiconductor Corporation
#
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
################################################################################

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif

#
# Patch variables
#
CY_PDL_ROOT=$(SEARCH_mtb-pdl-cat5)

CY_CORE_PATCH_DIR=$(CY_PDL_ROOT)/devices/patches/wlbga_iPA_dLNA_ANT0/$(LIFE_CYCLE_STATE)

CY_CORE_PATCH=$(CY_CORE_PATCH_DIR)/patch.elf
CY_CORE_PATCH_CERT=$(CY_CORE_PATCH_DIR)/patch_cert.hex
CY_CORE_PATCH_SEC_XIP_MDH=$(CY_CORE_PATCH_DIR)/patch_sec_xip.mdh
CY_CORE_PATCH_SEC=$(CY_CORE_PATCH_DIR)/patch_sec.bin
CY_CORE_PATCH_SEC_HEX=$(CY_CORE_PATCH_DIR)/patch_sec.hex
CY_CORE_PATCH_FW=$(CY_CORE_PATCH_DIR)/patch_fw.bin
CY_CORE_PATCH_DEFS=$(CY_PDL_ROOT)/devices/source/platforms/$(CY_TARGET_DEVICE).cflag
CY_CORE_PATCH_LIB_PATH=$(CY_PDL_ROOT)/libraries/prebuilt

#
# Variables for pre-build and post-build processing
#
CY_CORE_PLATFORM_PATH=$(CY_PDL_ROOT)/devices/source/platforms
CY_CORE_HDF=$(CY_CORE_PLATFORM_PATH)/configdef$(CY_TARGET_DEVICE).hdf
CY_CORE_HCI_ID=$(CY_CORE_PLATFORM_PATH)/IDFILE.txt
CY_CORE_CGSLIST+=$(CY_CORE_PLATFORM_PATH)/platform.cgs
CY_CORE_BTP=$(CY_CORE_PLATFORM_PATH)/ram.btp
ifneq ($(LIFE_CYCLE_STATE),DM)
  CY_CORE_MINIDRIVER=$(CY_CORE_PATCH_DIR)/minidriver.hex
else
  CY_CORE_MINIDRIVER=$(CY_CORE_PATCH_DIR)/secure_loader_dm.hcd
endif

CY_CORE_LD_DEFS+=NUM_PATCH_ENTRIES=0

define extract_btp_file_value
$(patsubst $1=%,%,$(filter $1%,$2))
endef

# these make targets do not need this data and don't work if importing an app
# that has not yet run make getlibs, so skip it
ifeq ($(filter import_deps getlibs get_app_info,$(MAKECMDGOALS)),)

# split up btp file into "x=y" text
CY_BT_FILE_TEXT:=$(shell cat -e $(CY_CORE_BTP))
CY_BT_FILE_TEXT:=$(subst $(MTB__SPACE),,$(CY_BT_FILE_TEXT))
CY_BT_FILE_TEXT:=$(subst ^M,,$(CY_BT_FILE_TEXT))
CY_BT_FILE_TEXT:=$(patsubst %$(MTB__NEWLINE),% ,$(CY_BT_FILE_TEXT))
CY_BT_FILE_TEXT:=$(subst $$,$(MTB__SPACE),$(CY_BT_FILE_TEXT))

ifeq ($(CY_BT_FILE_TEXT),)
$(error Failed to parse BTP variables from file: $(CY_CORE_BTP))
endif

SS_LOCATION = $(call extract_btp_file_value,DLConfigSSLocation,$(CY_BT_FILE_TEXT))
VS_LOCATION = $(call extract_btp_file_value,DLConfigVSLocation,$(CY_BT_FILE_TEXT))
VS_LENGTH = $(call extract_btp_file_value,DLConfigVSLength,$(CY_BT_FILE_TEXT))
DS_LOCATION = $(call extract_btp_file_value,ConfigDSLocation,$(CY_BT_FILE_TEXT))

PLATFORM_DIRECT_LOAD_BASE_ADDR = $(SS_LOCATION)

endif # end filter import_deps getlibs get_app_info
