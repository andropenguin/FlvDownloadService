LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := flvstreamer
LOCAL_SRC_FILES := log.c rtmp.c amf.c flvstreamer.c parseurl.c com_sarltokyo_flvdownloadservice_FlvDownloadService.c
LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
