# JniHttp_Sample      
NDK开发中在C层请求网络并解析Json                 
blog地址：http://www.jianshu.com/p/99912b40c4c2   
## 具体功能如下    
- 在JNI中实现Http请求网络      
- 在JNI中解析JSON数据并传递给Java层             
## 这样做的好处                  
- 避免将网络协议和URL暴露出来                         
- 将服务器放回的JSON数据阉割部分私密字段再抛给java层
