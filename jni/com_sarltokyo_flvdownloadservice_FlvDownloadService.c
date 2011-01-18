/*  JNI files in FlvDownloadService.
 *  Copyright (C) 2011
 *  @author OSABE Satoshi, e-mail address: andropenguin@gmail.com
 *  @version 1.0
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version with the exception of the file
 *  FlvDownloadServiceInterface.aidl. The license of the
 *  FlvDownloadServiceInterface.aidl is Public domain. About the exclamation
 *  of this license, see http://en.wikipedia.org/wiki/Public_domain.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with FlvDownlaodService; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 *  FlvDownlaodService is the ported version of flvstreamer to Android
 *  platform. The function of its is limited.
 *  The authors of flvstreamer are Howard Chu and Andrej Stepanchuk.
 *  The license of flvstreamer is GNU General Public License (GPL).
*/


#include "flvstreamer.h"
#include "com_sarltokyo_flvdownloadservice_FlvDownloadService.h"
#include <stdlib.h>
#include <string.h>
#include "log.h"

JNIEXPORT jint JNICALL Java_com_sarltokyo_flvdownloadservice_FlvDownloadService_flvstreamerw
  (JNIEnv *env, jobject me, jstring urlj, jstring outfilej) {

  const char *url;
  const char *outfile;

  int argc = 6;
  char *argv[6];
  int rtn;

  url = (*env)->GetStringUTFChars(env, urlj, NULL);
  if (url == NULL) return -1;

  outfile = (*env)->GetStringUTFChars(env, outfilej, NULL);
  if (outfile == NULL) return -1;

  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, url = %s", url);
  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, outfile = %s", outfile);

  argv[0] = (char *)malloc(sizeof(char) * (strlen("flvstreamer") + 1));
  if (argv[0] == NULL) {
    LogPrintf("memory allocation of argv[0] failed");
    return -1;
  }
  memset(argv[0], 0, strlen("flvstreamer") + 1);
  strcpy(argv[0], "flvstreamer");
  
  argv[1] = (char *)malloc(sizeof(char) * (strlen("-r") + 1));
  if (argv[1] == NULL) {
    LogPrintf("memory allocation of argv[1] failed");
    return -1;
  }
  memset(argv[1], 0, strlen("-r") +1);
  strcpy(argv[1], "-r");

  argv[2] = (char *)malloc(sizeof(char) * (strlen(url) + 1));
  if (argv[2] == NULL) {
    LogPrintf("memory allocation of argv[2] failed");
    free(argv[1]);
    return -1;
  }
  memset(argv[2], 0, strlen(url) + 1);
  strcpy(argv[2], url);
  
  argv[3] = (char *)malloc(sizeof(char) * (strlen("-o") + 1));
  if (argv[3] == NULL) {
    LogPrintf("memory allocation of argv[3] failed");
    free(argv[0]);
    free(argv[1]);
    free(argv[2]);
    return -1;
  }
  memset(argv[3], 0, strlen("-o") + 1);
  strcpy(argv[3], "-o");
  
  argv[4] = (char *)malloc(sizeof(char) * (strlen(outfile) + 1));
  if (argv[4] == NULL) {
    LogPrintf("memory allocation of argv[4] failed");
    free(argv[0]);
    free(argv[1]);
    free(argv[2]);
    free(argv[3]);
    return -1;
  }
  memset(argv[4], 0, strlen(outfile) + 1);
  strcpy(argv[4], outfile);

  argv[5] = (char *)malloc(sizeof(char) * (strlen("-e") + 1));
  if (argv[5] == NULL) {
    LogPrintf("memory allocation of argv[5] failed");
    free(argv[0]);
    free(argv[1]);
    free(argv[2]);
    free(argv[3]);
    free(argv[4]);
    return -1;
  }
  memset(argv[5], 0, strlen("-e") + 1);
  strcpy(argv[5], "-e");

  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, argv[0] = %s", argv[0]);
  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, argv[1] = %s", argv[1]);
  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, argv[2] = %s", argv[2]);
  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, argv[3] = %s", argv[3]);
  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, argv[4] = %s", argv[4]);
  LogPrintf("in com_sarltokyo_flvdownloadservice_FlvDownloadService, argv[5] = %s", argv[5]);

  rtn = flvstreamer(argc, argv);

  free(argv[0]);
  free(argv[1]);
  free(argv[2]);
  free(argv[3]);
  free(argv[4]);
  free(argv[5]);

  (*env)->ReleaseStringUTFChars(env, urlj, url);
  (*env)->ReleaseStringUTFChars(env, outfilej, outfile);

  return rtn;
}

