cmake_minimum_required(VERSION 3.4.1)

add_library(native-lib
             SHARED
             src/main/cpp/native-lib.cpp
             src/main/cpp/JniUtils.cpp
             src/main/cpp/web_task.cpp )

 include_directories( src/main/cpp/include/jsoncpp
                      src/main/cpp/include/curl
                     )

add_library(curl STATIC IMPORTED)
set_target_properties(curl
  PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libcurl.a)

add_library(jsoncpp STATIC IMPORTED)
set_target_properties(jsoncpp
  PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libjsoncpp.a)

# 不能向下面格式写，会出现 Error:error: '../../../../src/main/libs/libjsoncpp.a', needed by '../obj/armeabi/libnative-lib.so', missing and no known rule to make it

# add_library(curl STATIC IMPORTED)
# set_target_properties(curl
#   PROPERTIES IMPORTED_LOCATION
#   ${CMAKE_SOURCE_DIR}/src/main/libs/libcurl.a)

# add_library(jsoncpp STATIC IMPORTED)
# set_target_properties(jsoncpp
#   PROPERTIES IMPORTED_LOCATION
#   ${CMAKE_SOURCE_DIR}/src/main/libs/libjsoncpp.a)

find_library( # Sets the name of the path variable.
              log-lib
              log )

target_link_libraries( # Specifies the target library.
                       native-lib

                       jsoncpp
                       curl
                       ${log-lib} )
