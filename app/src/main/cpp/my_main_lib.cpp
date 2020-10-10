#include <jni.h>
#include <string>
#include <gperf.h>
#include <fluidsynth.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myappinc_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    auto ticks = GetTicks();
    std::string hello = "Hello World! Brought by C++ " + std::to_string(ticks);
    return env->NewStringUTF(hello.c_str());
}
