#  Makefile of the JNI files in FlvDownloadService.
#
#  Copyright (C) 2011
#  @author OSABE Satoshi, e-mail address: andropenguin@gmail.com
#  @version 1.0
#
#  This Program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2, or (at your option)
#  any later version with the exception of the file
#  FlvDownloadServiceInterface.aidl. The license of the
#  FlvDownloadServiceInterface.aidl is Public domain. About the exclamation
#  of this license, see http://en.wikipedia.org/wiki/Public_domain.
#
#  This Program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with FlvDownlaodService; see the file COPYING.  If not, write to
#  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
#  http://www.gnu.org/copyleft/gpl.html
#
#  FlvDownlaodService is the ported version of flvstreamer to Android
#  platform. The function of its is limited.
#  The authors of flvstreamer are Howard Chu and Andrej Stepanchuk.
#  The license of flvstreamer is GNU General Public License (GPL).
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := flvstreamer
LOCAL_SRC_FILES := log.c rtmp.c amf.c flvstreamer.c parseurl.c com_sarltokyo_flvdownloadservice_FlvDownloadService.c
LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
