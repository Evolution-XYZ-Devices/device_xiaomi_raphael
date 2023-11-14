LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := RemovePackages
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_OVERRIDES_PACKAGES := CalendarGooglePrebuilt DevicePolicyPrebuilt GoogleTTS Photos PixelLiveWallpaperPrebuilt
LOCAL_OVERRIDES_PACKAGES += PixelWallpapers2020 PixelWallpapers2021 PixelWallpapers2022 PixelWallpapers2022a PixelWallpapers2023Tablet
LOCAL_OVERRIDES_PACKAGES += PixelWallpapers2023 RecorderPrebuilt SoundAmplifierPrebuilt Videos
LOCAL_UNINSTALLABLE_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
LOCAL_SRC_FILES := /dev/null
include $(BUILD_PREBUILT)
