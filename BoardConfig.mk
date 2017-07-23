#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# WARNING: This line must come *before* including the proprietary
# variant, so that it gets overwritten by the parent (which goes
# against the traditional rules of inheritance).

# Inherit from common b2wlj-common
-include device/htc/b2wlj-common/BoardConfigCommon.mk

# Model Ids
# 0PAG10000 - KDDI
# 0PAG20000 - International
# 0P6B10000 - International
# 0P6B12000 - AT&T/Dev Edition
# 0P6B13000 - T-Mobile
# 0P6B16000 - Telus/Rogers (Canada)
# 0P6B20000 - Verizon
# 0P6B70000 - Sprint

# Assert
TARGET_OTA_ASSERT_DEVICE := htc_b2wlj,htc_b2ul,htc_m8,m8,b2wlj,b2ul

# Kernel
TARGET_KERNEL_CONFIG := lineageos_b2wlj_defconfig

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/htc/b2wlj/bluetooth

# RIL
BOARD_RIL_CLASS := ../../../device/htc/b2wlj/ril

# Partitions
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1073741824
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13153337344

# Vendor Init
TARGET_INIT_VENDOR_LIB := libinit_b2wlj
TARGET_RECOVERY_DEVICE_MODULES := libinit_b2wlj
TARGET_UNIFIED_DEVICE := true

# Inherit from the proprietary version
-include vendor/htc/b2wlj/BoardConfigVendor.mk

