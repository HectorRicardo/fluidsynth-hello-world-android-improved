#include <jni.h>
#include <fluidsynth.h>
#include <unistd.h>

fluid_settings_t* settings;
fluid_synth_t* synth;
fluid_audio_driver_t* adriver;
fluid_sfont_t* sfont;

JNIEXPORT jboolean JNICALL Java_com_example_myappinc_Synthesizer_openFluidSynth(JNIEnv* env, jobject thisObj, jstring soundfont) {
    settings = new_fluid_settings();
    synth = new_fluid_synth(settings);
    adriver = new_fluid_audio_driver(settings, synth);

    const char* soundfontPath = (*env)->GetStringUTFChars(env, soundfont, NULL);
    int sfont_id = fluid_synth_sfload(synth, soundfontPath, 1);
    if (sfont_id == FLUID_FAILED) {
        delete_fluid_audio_driver(adriver);
        delete_fluid_synth(synth);
        delete_fluid_settings(settings);
        return 0;
    }

    sfont = fluid_synth_get_sfont_by_id(synth, sfont_id);
    return 1;
}

JNIEXPORT void JNICALL Java_com_example_myappinc_Synthesizer_noteOn(JNIEnv* env, jobject thisObj, jint midiNumber) {
    fluid_synth_noteon(synth, 0, midiNumber, 127);
}

JNIEXPORT void JNICALL Java_com_example_myappinc_Synthesizer_noteOff(JNIEnv* env, jobject thisObj, jint midiNumber) {
    fluid_synth_noteoff(synth, 0, midiNumber);
}

JNIEXPORT void JNICALL Java_com_example_myappinc_Synthesizer_controlChange(JNIEnv* env, jobject thisObj, jint controller, jint value) {
    fluid_synth_cc(synth, 0, controller, value);
}

JNIEXPORT void JNICALL Java_com_example_myappinc_Synthesizer_programChange(JNIEnv* env, jobject thisObj, jint program) {
    fluid_synth_program_change(synth, 0, program);
}

JNIEXPORT void JNICALL Java_com_example_myappinc_Synthesizer_close(JNIEnv* env, jobject thisObj) {
    delete_fluid_audio_driver(adriver);
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);
}
