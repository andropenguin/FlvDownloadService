#include "flvstreamer.h"
#include "com_sarltokyo_flvdownloadservice_FlvDownloadService.h"
#include <stdlib.h>
#include <string.h>

JNIEXPORT jint JNICALL Java_com_sarltokyo_flvdownloadservice_FlvDownloadService_flvstreamerw
  (JNIEnv *env, jobject me, jstring urlj, jstring outfilej) {

  const char *url;
  const char *outfile;

  int argc = 5;
  char *argv[5];
  int rtn;

  url = (*env)->GetStringUTFChars(env, urlj, NULL);
  if (url == NULL) return -1;

  outfile = (*env)->GetStringUTFChars(env, outfilej, NULL);
  if (outfile == NULL) return -1;

  argv[0] = malloc(sizeof(char) * (strlen("flvstreamer") + 1));
  strcpy(argv[0], "flvstreamer");

  argv[1] = malloc(sizeof(char) * (strlen("-r") + 1));
  strcpy(argv[1], "-r");

  argv[2] = malloc(sizeof(char) * (strlen(url) + 1));
  strcpy(argv[2], url);
  
  argv[3] = malloc(sizeof(char) * (strlen("-o") + 1));
  strcpy(argv[3], "-o");
  
  argv[4] = malloc(sizeof(char) * (strlen(outfile) + 1));
  strcpy(argv[4], outfile);

  rtn = flvstreamer(argc, argv);

  free(argv[0]);
  free(argv[1]);
  free(argv[2]);
  free(argv[3]);
  free(argv[4]);

  (*env)->ReleaseStringUTFChars(env, urlj, url);
  (*env)->ReleaseStringUTFChars(env, outfilej, outfile);

  return rtn;
}

