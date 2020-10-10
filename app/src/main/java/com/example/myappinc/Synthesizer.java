package com.example.myappinc;

import android.content.Context;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class Synthesizer {

    private final Context context;

    public Synthesizer(Context context) {
        this.context = context;
    }

    public void open(String soundfont) {
        try {
            writeFileToPrivateStorage(context.getAssets().open(soundfont), soundfont);
            final String path = context.getApplicationContext().getFilesDir().toString() + "/" + soundfont;
            if (!openFluidSynth(path)) {
                throw new RuntimeException("fluidsynth_wrapper: Unable to loud soundfont " + soundfont + " at " + path + ".");
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private native boolean openFluidSynth(String soundfontFile);

    public native void noteOn(int midiNumber);
    public native void noteOff(int midiNumber);
    public native void controlChange(int controller, int value);
    public native void programChange(int program);
    public native void close();

    private void writeFileToPrivateStorage(InputStream is, String toFile) throws IOException {
        int bytes_read;
        final byte[] buffer = new byte[4096];
        final FileOutputStream fos = context.openFileOutput(toFile, Context.MODE_PRIVATE);
        while ((bytes_read = is.read(buffer)) != -1) {
            fos.write(buffer, 0, bytes_read); // write
        }
        fos.close();
        is.close();
    }

    static {
        System.loadLibrary("fluidsynth_wrapper");
    }
}