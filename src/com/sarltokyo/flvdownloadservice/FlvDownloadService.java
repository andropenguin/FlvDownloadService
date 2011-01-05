package com.sarltokyo.flvdownloadservice;

import java.io.File;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

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
