package com.sarltokyo.flvdownloadservice;

/**
  *  FlvDownloadServiceInterface.aidl
  *
  *  The license of this file is Public domain. About the exclamation
  *  of this license, see http://en.wikipedia.org/wiki/Public_domain.
*/

interface FlvDownloadServiceInterface {
	// download Flv file
	int flvdownload(in String urlbase, in String title, in String where);

	// remove flv file
	int removeflv(in String title, in String where);
}
