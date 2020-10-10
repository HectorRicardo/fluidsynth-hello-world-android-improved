package com.example.myappinc;

import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private final Synthesizer synthesizer = new Synthesizer(this);
    private boolean playing = false;

    private final Runnable melodyRunnable = new Runnable() {
        @Override
        public void run() {
            try {
                synthesizer.noteOn(Notes.C4);
                synthesizer.noteOn(Notes.E4);
                synthesizer.noteOn(Notes.G4);
                Thread.sleep(500);
                synthesizer.noteOff(Notes.C4);
                synthesizer.noteOff(Notes.E4);
                synthesizer.noteOff(Notes.G4);

                synthesizer.noteOn(Notes.D4);
                synthesizer.noteOn(Notes.F4);
                synthesizer.noteOn(Notes.A4);
                Thread.sleep(500);
                synthesizer.noteOff(Notes.D4);
                synthesizer.noteOff(Notes.F4);
                synthesizer.noteOff(Notes.A4);

                synthesizer.noteOn(Notes.E4);
                synthesizer.noteOn(Notes.G4);
                synthesizer.noteOn(Notes.B4);
                Thread.sleep(500);
                synthesizer.noteOff(Notes.E4);
                synthesizer.noteOff(Notes.G4);
                synthesizer.noteOff(Notes.B4);

            } catch (InterruptedException ignored) {
            } finally {
                playing = false;
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        synthesizer.open("example.sf2");

        synthesizer.programChange(5);

        synthesizer.controlChange(65, 127);
        synthesizer.controlChange(5, 1);
    }

    public void play(View view) {
        if (playing) return;
        playing = true;
        new Thread(melodyRunnable).start();
    }

    @Override
    protected void onDestroy() {
        synthesizer.close();
        super.onDestroy();
    }
}
