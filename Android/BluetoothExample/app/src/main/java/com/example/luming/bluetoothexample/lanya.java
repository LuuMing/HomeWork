package com.example.luming.bluetoothexample;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.IOException;
import java.io.OutputStream;
import java.util.UUID;

/**
 * Created by LuMing on 2017/12/30.
 */

public class lanya extends Activity {
    private static final String TAG = "THINBTCLIENT";
    private static final boolean D = true;
    private static final UUID MY_UUID = UUID.fromString("00011101-0000-1000-8019-00805F9B34FB");//蓝牙标准串行
    //private static String address = "78:0c:b8:a7:4e:7c";
    private static String address = "00:11:03:21:00:42";
    Button mButtonF;
    Button mButtonB;
    Button mButtonL;
    Button mButtonR;
    Button mButtonS;
    private BluetoothAdapter mBluetoothAdapter = null;
    private BluetoothSocket btSocket = null;
    private OutputStream outStream = null;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mButtonF = (Button) findViewById(R.id.btnF);
        mButtonB = (Button) findViewById(R.id.btnB);
        mButtonL = (Button) findViewById(R.id.btnL);
        mButtonR = (Button) findViewById(R.id.btnR);
        mButtonS = (Button) findViewById(R.id.btnS);
        mButtonF.setOnTouchListener(createlistener("1", "0"));
        mButtonB.setOnTouchListener(createlistener("3", "0"));
        mButtonL.setOnTouchListener(createlistener("2", "0"));
        mButtonR.setOnTouchListener(createlistener("4", "0"));
        mButtonF.setOnTouchListener(new Button.OnTouchListener() {
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                    try {
                        outStream = btSocket.getOutputStream();
                    } catch (IOException e) {
                        Log.e(TAG, "ON RESUME Output stream creation failed.", e);
                    }
                String message = "0";
                byte[] msgBuffer = message.getBytes();
                try {
                    outStream.write(msgBuffer);
                } catch (IOException e) {
                    Log.e(TAG, "ON RESUME:Exception during write.", e);
                }
                return false;
            }
        });

        //设定五个按键的listener
        if (D)
            Log.e(TAG, "+++ON CREATE +++");
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        if (mBluetoothAdapter == null) {
            Toast.makeText(this, "蓝牙设备不可用，请打开蓝牙!", Toast.LENGTH_LONG).show();
            finish();
            return;
        }
        if (!mBluetoothAdapter.isEnabled()) {
            Toast.makeText(this, "请打开蓝牙并重新云行程序!", Toast.LENGTH_LONG).show();
            finish();
            return;
        }
        if (D)
            Log.e(TAG, "+++ DONE IN ON CREATE, GOT LOCAL BT ADAPTER +++");
    }

    public void onStart() {
        super.onStart();
        if (D)
            Log.e(TAG, "ON START ++");
    }

    public void onResume() {
        super.onResume();
        if (D) {
            Log.e(TAG, "+ ON RESUME +");
            Log.e(TAG, "+ ABOUT TO ATTEMPT CLIENT CONNECT +");
        }
        Toast.makeText(this, "正在尝试连接小车,请稍后....", Toast.LENGTH_LONG).show();
        BluetoothDevice device = mBluetoothAdapter.getRemoteDevice(address);
        try {
            btSocket = device.createRfcommSocketToServiceRecord(MY_UUID);
        } catch (IOException e) {
            Toast.makeText(this, "套接字创建失败", Toast.LENGTH_LONG).show();
        }
        Toast.makeText(this, "成功连接，可以开始操控", Toast.LENGTH_LONG).show();
        mBluetoothAdapter.cancelDiscovery();
        try {
            btSocket.connect();
            Toast.makeText(this, "连接成功，数据连接打开", Toast.LENGTH_LONG).show();
        } catch (IOException e) {
            try {
                btSocket.close();
            } catch (IOException e2) {
                DisplayToast("连接没有成功,无法关闭套接字");
            }
        }
        if (D) {
            Log.e(TAG, "+ ABOUT TO SAY SOMETHING TO SERVER +");
        }

    }

    public void onPause() {
        super.onPause();
        if (D) {
            Log.e(TAG, "- ON PAUSE -");
            if (outStream != null) {
                try {
                    outStream.flush();
                } catch (IOException e) {
                    Log.e(TAG, "ON PAUSE:Couldn't flush output stream.", e);
                }
            }
            try {
                btSocket.close();
            } catch (IOException e) {
                DisplayToast("套接字关闭失败");
            }
        }
    }

    public void onStop() {
        super.onStop();
        if (D)
            Log.e(TAG, "-- ON STOP --");
    }

    public void onDestroy() {
        super.onDestroy();
        if (D)
            Log.e(TAG, "-- ON DESTROY ---");
    }

    public void DisplayToast(String str) {
        Toast toast = Toast.makeText(this, str, Toast.LENGTH_LONG);
        toast.setGravity(Gravity.TOP, 0, 220);
        toast.show();
    }

    private Button.OnTouchListener createlistener(final String a, final String b) {
        return new Button.OnTouchListener() {
            @Override
            public boolean onTouch(View V, MotionEvent event) {
                String message;
                byte[] msgBuffer;
                int action = event.getAction();
                switch (action) {
                    case MotionEvent.ACTION_DOWN:
                        try {
                            outStream = btSocket.getOutputStream();
                        } catch (IOException e) {
                            Log.e(TAG, "ON RESUME:Output steam creation failed.", e);
                        }
                        message = a;
                        msgBuffer = message.getBytes();
                        try {
                            outStream.write(msgBuffer);
                        } catch (IOException e) {
                            Log.e(TAG, "ON RESUME:Exception during write.", e);
                        }
                        break;
                    case MotionEvent.ACTION_UP:
                        try {
                            outStream = btSocket.getOutputStream();
                        } catch (IOException e) {
                            Log.e(TAG, "ON RESUME:Output steam creation failed.", e);
                        }
                        message = b;
                        msgBuffer = message.getBytes();
                        try {
                            outStream.write(msgBuffer);
                        } catch (IOException e) {
                            Log.e(TAG, "Exception during write.", e);
                        }

                }
                return false;
            }

        };
    }

}
