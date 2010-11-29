package com.sarltokyo.flvdownloadservice;

interface FlvDownloadServiceInterface {
	// download Flv file
	int flvdownload(in String urlbase, in String title, in String where);

	// remove flv file
	int removeflv(in String title, in String where);
}
