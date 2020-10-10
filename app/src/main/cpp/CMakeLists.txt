# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../distribution)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library(lib_gperf SHARED IMPORTED)

add_library(libc++_shared SHARED IMPORTED)
set_target_properties(libc++_shared PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libc++_shared.so)

add_library(libcharset SHARED IMPORTED)
set_target_properties(libcharset PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libcharset.so)

add_library(libffi SHARED IMPORTED)
set_target_properties(libffi PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libffi.so)

add_library(libFLAC SHARED IMPORTED)
set_target_properties(libFLAC PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libFLAC.so)

add_library(libfluidsynth SHARED IMPORTED)
set_target_properties(libfluidsynth PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libfluidsynth.so)

add_library(libfluidsynth-assetloader SHARED IMPORTED)
set_target_properties(libfluidsynth-assetloader PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libfluidsynth-assetloader.so)

add_library(libgio-2.0 SHARED IMPORTED)
set_target_properties(libgio-2.0 PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libgio-2.0.so)

add_library(libglib-2.0 SHARED IMPORTED)
set_target_properties(libglib-2.0 PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libglib-2.0.so)

add_library(libgmodule-2.0 SHARED IMPORTED)
set_target_properties(libgmodule-2.0 PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libgmodule-2.0.so)

add_library(libgobject-2.0 SHARED IMPORTED)
set_target_properties(libgobject-2.0 PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libgobject-2.0.so)

add_library(libgthread-2.0 SHARED IMPORTED)
set_target_properties(libgthread-2.0 PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libgthread-2.0.so)

add_library(libiconv SHARED IMPORTED)
set_target_properties(libiconv PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libiconv.so)

add_library(libintl SHARED IMPORTED)
set_target_properties(libintl PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libintl.so)

add_library(liboboe SHARED IMPORTED)
set_target_properties(liboboe PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/liboboe.so)

add_library(libogg SHARED IMPORTED)
set_target_properties(libogg PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libogg.so)

add_library(libsndfile SHARED IMPORTED)
set_target_properties(libsndfile PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libsndfile.so)

add_library(libvorbis SHARED IMPORTED)
set_target_properties(libvorbis PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libvorbis.so)

add_library(libvorbisenc SHARED IMPORTED)
set_target_properties(libvorbisenc PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libvorbisenc.so)

add_library(libvorbisfile SHARED IMPORTED)
set_target_properties(libvorbisfile PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libvorbisfile.so)

add_library(libz SHARED IMPORTED)
set_target_properties(libz PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/libz.so)

add_library(preloadable_libiconv SHARED IMPORTED)
set_target_properties(preloadable_libiconv PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/fluidsynth/lib/${ANDROID_ABI}/preloadable_libiconv.so)

add_library(my_main_lib SHARED my_main_lib.cpp)

# Unknown

set_target_properties(lib_gperf PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/gperf/lib/${ANDROID_ABI}/libgperf.so)
target_include_directories(my_main_lib PRIVATE ${distribution_DIR}/gperf/include ${distribution_DIR}/fluidsynth/include)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries(
        my_main_lib
        lib_gperf


        libc++_shared
        libcharset
        libffi
        libFLAC
        libfluidsynth
        libfluidsynth-assetloader
        libgio-2.0
        libglib-2.0
        libgmodule-2.0
        libgobject-2.0
        libgthread-2.0
        libiconv
        libintl
        liboboe
        libogg
        libsndfile
        libvorbis
        libvorbisenc
        libvorbisfile
        libz
        preloadable_libiconv
)
