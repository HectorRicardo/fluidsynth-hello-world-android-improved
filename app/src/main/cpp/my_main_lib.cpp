#include <jni.h>
#include <string>
#include <fluidsynth.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myappinc_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello World! Brought by C++";
    return env->NewStringUTF(hello.c_str());
}
