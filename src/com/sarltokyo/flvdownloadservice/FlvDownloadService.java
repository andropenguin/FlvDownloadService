package com.sarltokyo.flvdownloadservice;

import java.io.File;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

/**
 * FlvDownlaodService.java
 *
 * Copyright (C) 2011
 * @author OSABE Satoshi, e-mail address: andropenguin@gmail.com
 * @version 1.0
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version with the exception of the file
 *  FlvDownloadServiceInterface.aidl. The license of the
 *  FlvDownloadServiceInterface.aidl is Public domain. About the
 *  exclamation of this license, see http://en.wikipedia.org/wiki/Public_domain.
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with FlvDownlaodService.java; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 *  FlvDownlaodService is the ported version of flvstreamer to Android
 *  platform. The function of its is limited.
 *  The authors of flvstreamer are Howard Chu and
 *  Andrej Stepanchuk. The license of flvstreamer is GNU General Public
 *  License (GPL).
*/

public class FlvDownloadService extends Service {

	private final static String TAG = "FlvDownloadService";

	private FlvDownloadService mFlvDownloadService;

	private native int flvstreamerw(String url, String outfile);

	@Override
	public void onCreate() {
		super.onCreate();
		mFlvDownloadService = null;
		Log.i(TAG, "onCreate");
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		mFlvDownloadService = null;
		Log.i(TAG, "onDestroy");
	}

	@Override
	public IBinder onBind(Intent intent) {
		Log.i(TAG, "onBind");
		return mInterfaceImpl;
	}

	private int flvdonwload(String urlbase, String title, String where) {
		String url = urlbase + title;
		String outfile = where + title + ".flv";

		Log.i(TAG, "url = " + url);
		Log.i(TAG, "outfile = " + outfile);

		Log.i(TAG, "flvstreamerw");
		int rtn = flvstreamerw(url, outfile);
		Log.i(TAG, "return value of flvstreamerw = " + rtn);

		return rtn;
	}

	private int removeflv(String title, String where) {
		File flvfile = new File(where + title + ".flv");
		if (flvfile.exists()) {
			if (flvfile.delete()) {
				Log.i(TAG, "remove flv file");
				return 0; // remove success
			} else {
				Log.i(TAG, "cannot remove flv file");
				return 1; // remove fail
			}
		} else {
			Log.i(TAG, "flv file not exist");
			return 2;
		}
	}

	private FlvDownloadServiceInterface.Stub mInterfaceImpl =
		new FlvDownloadServiceInterface.Stub() {

		@Override
		public int flvdownload(String urlbase, String title, String where)
				throws RemoteException {
			int rtn = FlvDownloadService.this.flvdonwload(urlbase, title, where);
			return rtn;
		}

		@Override
			public int removeflv(String title, String where) throws RemoteException {
				int rtn = FlvDownloadService.this.removeflv(title, where);
				return rtn;
			}
		};

		static {
			System.loadLibrary("flvstreamer");
		}
}

