# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../distribution)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library(lib_gperf SHARED IMPORTED)
add_library(my_main_lib SHARED my_main_lib.cpp)

# Unknown

set_target_properties(lib_gperf PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/gperf/lib/${ANDROID_ABI}/libgperf.so)
target_include_directories(my_main_lib PRIVATE ${distribution_DIR}/gperf/include)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries(my_main_lib lib_gperf)
