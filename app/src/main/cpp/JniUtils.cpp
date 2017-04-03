//
// Created by lexwu on 2017/3/30.
//
#include <jni.h>
#include <string>
#include "JniUtils.h"


/**
 * 把java的string转化成c的字符串
 */
std::string Jstring2string(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");  //String
    jstring strencode = env->NewStringUTF("GB2312"); //"gb2312"
    jmethodID mid = env->GetMethodID(clsstring, "getBytes",
                                     "(Ljava/lang/String;)[B"); //getBytes(Str);
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid,
                                                         strencode); // String .getByte("GB2312");
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);         //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);  //释放内存空间
    return rtn;
}

/**
 * C字符串转java字符串
 */
jstring Str2Jstring(JNIEnv *env, const char *pStr) {
    int strLen = strlen(pStr);
    jclass jstrObj = env->FindClass("java/lang/String");
    jmethodID methodId = env ->GetMethodID(jstrObj, "<init>", "([BLjava/lang/String;)V");
    jbyteArray byteArray = env ->NewByteArray(strLen);
    jstring encode = env ->NewStringUTF("utf-8");
    env ->SetByteArrayRegion(byteArray, 0, strLen, (jbyte *) pStr);
    return (jstring) env ->NewObject(jstrObj, methodId, byteArray, encode);
}
