package com.example.myappinc;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.widget.TextView;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("my_main_lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        String path;
        try {
            String fileName = "my_temp_file.sf2";
            writeFileToPrivateStorage(getAssets().open("example.sf2"), fileName);
            path = getApplicationContext().getFilesDir().toString() + "/" + fileName;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        String myFinalString = stringFromJNI(path) + " " + path;
        tv.setText(myFinalString);
    }

    public void writeFileToPrivateStorage(InputStream is, String toFile) throws IOException {
        int bytes_read;
        byte[] buffer = new byte[4096];
        FileOutputStream fos = openFileOutput(toFile, Context.MODE_PRIVATE);
        while ((bytes_read = is.read(buffer)) != -1)
            fos.write(buffer, 0, bytes_read); // write

        fos.close();
        is.close();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI(String path);
}
