# Kernel
TARGET_KERNEL_SOURCE := kernel/samsung/universal8890
TARGET_KERNEL_CONFIG := exynos8890-hero2lte_defconfig

# Assert
TARGET_OTA_ASSERT_DEVICE := hero2lteskt,hero2ltektt,hero2ltelgt,hero2ltekor,hero2ltebmc,hero2ltexx,hero2lte

# Init
TARGET_INIT_VENDOR_LIB := libinit_hero2lte
TARGET_RECOVERY_DEVICE_MODULES := libinit_hero2lte

# Inherit common board flags
include device/samsung/hero-common/BoardConfigCommon.mk
