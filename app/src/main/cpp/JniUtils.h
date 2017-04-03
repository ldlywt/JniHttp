/*
 * 说明：Android JNI Log打印宏定义文件
 */
#ifndef _JNI_UTILS_
#define _JNI_UTILS_

#include <android/log.h>

#define IS_DEBUG
#ifdef IS_DEBUG
#define LOG_TAG ("fromNDK")
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO   , LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR  , LOG_TAG, __VA_ARGS__))
#else
#define LOGI(LOG_TAG, ...) NULL
#define LOGE(LOG_TAG, ...) NULL
#endif

std::string Jstring2string(JNIEnv *env, jstring jstr);
jstring Str2Jstring(JNIEnv *env, const char *pStr);
#endif