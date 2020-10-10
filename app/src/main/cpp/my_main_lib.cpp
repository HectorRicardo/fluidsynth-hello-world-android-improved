#include <jni.h>
#include <string>
#include <fluidsynth.h>
#include <unistd.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myappinc_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */,
        jstring jSoundfontPath) {
    fluid_settings_t *settings = new_fluid_settings();
    fluid_synth_t *synth = new_fluid_synth(settings);
    fluid_audio_driver_t *adriver = new_fluid_audio_driver(settings, synth);

    const char *soundfontPath = env->GetStringUTFChars(jSoundfontPath, nullptr);
    int sfont_id = fluid_synth_sfload(synth, soundfontPath, 1);
    if (sfont_id == FLUID_FAILED)
    {
        delete_fluid_audio_driver(adriver);
        delete_fluid_synth(synth);
        delete_fluid_settings(settings);
        std::string hello = "Error";
        return env->NewStringUTF(hello.c_str());
    }

    fluid_synth_noteon(synth, 0, 60, 127);
    fluid_synth_noteon(synth, 0, 64, 127);
    fluid_synth_noteon(synth, 0, 67, 127);
    sleep(1);
    fluid_synth_noteoff(synth, 0, 60);
    fluid_synth_noteoff(synth, 0, 127);
    fluid_synth_noteoff(synth, 0, 67);

    fluid_synth_noteon(synth, 0, 62, 127);
    fluid_synth_noteon(synth, 0, 65, 127);
    fluid_synth_noteon(synth, 0, 69, 127);
    sleep(1);
    fluid_synth_noteoff(synth, 0, 62);
    fluid_synth_noteoff(synth, 0, 65);
    fluid_synth_noteoff(synth, 0, 69);

    fluid_synth_noteon(synth, 0, 64, 127);
    fluid_synth_noteon(synth, 0, 67, 127);
    fluid_synth_noteon(synth, 0, 71, 127);
    sleep(1);
    fluid_synth_noteoff(synth, 0, 127);
    fluid_synth_noteoff(synth, 0, 67);
    fluid_synth_noteoff(synth, 0, 71);

    delete_fluid_audio_driver(adriver);
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);

    std::string hello = "Hello World! Brought by C++";
    return env->NewStringUTF(hello.c_str());
}
