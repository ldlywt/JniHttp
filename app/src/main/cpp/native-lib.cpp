#include <jni.h>
#include <string>
#include <reader.h>
#include "JniUtils.h"
#include "web_task.h"


using namespace std;

//http://www.weather.com.cn/data/sk/101110101.html
//{"weatherinfo":{"city":"深圳","cityid":"101280601","temp":"21","WD":"南风","WS":"1级","SD":"31%","WSE":"1","time":"17:05","isRadar":"1","Radar":"JC_RADAR_AZ9755_JB","njd":"暂无实况","qy":"1014","rain":"0"}}

extern "C"
jstring
Java_com_ldlywt_jnihttp_MainActivity_httpFromJNI(JNIEnv *env, jobject /* this */) {

/*    //POST请求,举例来说
    string url = "http://www.weather.com.cn/user/add";
    WebTask task;
    task.SetUrl(url.c_str());
    task.SetConnectTimeout(5);
    task.AddPostString("username", username);
    task.AddPostString("password", password);
    task.AddPostString("email", email);*/

    //GET请求
    string url = "http://www.weather.com.cn/data/sk/101280601.html";
    WebTask task;
    task.SetUrl(url.c_str());
    task.SetConnectTimeout(5);
    task.DoGetString();
    if (task.WaitTaskDone() == 0) {
        //请求服务器成功
        string jsonResult = task.GetResultString();
        LOGI("返回的json数据是：%s\n", jsonResult.c_str());
        Json::Reader reader;
        Json::Value root;

//从字符串中读取数据
if (reader.parse(jsonResult, root)) {
    /*//根节点
    Json::Value weatherinfo = root["weatherinfo"];
    string js1 = weatherinfo["city"].asString();
    LOGI("根节点解析: %s\n", js1.c_str());*/
    //读取子节点信息
    string city = root["weatherinfo"]["city"].asString();
    string temp = root["weatherinfo"]["temp"].asString();
    string WD = root["weatherinfo"]["WD"].asString();
    string WS = root["weatherinfo"]["WS"].asString();
    string time = root["weatherinfo"]["time"].asString();
    string result = "城市：" + city + "\n温度："+ temp+ "\n风向：" + WD + "\n风力："+ WS + "\n时间：" + time;
            return Str2Jstring(env, result.c_str());
        }
    } else {
        LOGI("网络连接失败\n");
        return env->NewStringUTF("网络连接失败！");
    }
}
