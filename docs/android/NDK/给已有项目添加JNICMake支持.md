# 给已有项目添加JNI/CMake支持

## 添加`CMakeLists.txt`文件

在项目根目录添加`CMakeLists.txt`(其他路径也可)

```cmake
# 设置构建本机库文件所需的 CMake的最小版本
cmake_minimum_required(VERSION 3.4.1)

#添加头文件的搜索路径
include_directories(src/main/jni/)

# 添加自己写的 C/C++源文件
add_library(hello_jni #so名称
        SHARED #动态库
        src/main/jni/android_log.h
        src/main/jni/hello_jni.c
        )

#  依赖 NDK中的库
find_library(log-lib
        log)

#  将目标库与 NDK中的库进行连接
target_link_libraries(
        hello_jni
        ${log-lib})
```

## 添加`native`原生代码

在`src/main/`目录下添加`c/cpp`原生代码的目录，名称随意，一般可以为`jni/cpp`

```c++
JNIEXPORT void JNICALL
Java_me_simple_example_1ndk_1cmake_MainActivity_jniCallJavaMethod(
        JNIEnv *env, jclass this) {

    const char *class_name = "me/simple/example_ndk_cmake/Test";
    //根据类路径找到类对象
    jclass jclazz = (*env)->FindClass(env, class_name);
    //jclass jclazz = (*env)->GetObjectClass(env, this);
    //获取类的空参构造方法
    const char *construct_method = "<init>";
    jmethodID construct = (*env)->GetMethodID(env, jclazz, construct_method, "()V");
    //创建该类的实例
    jobject jobject1 = (*env)->NewObject(env, jclazz, construct);
    //找到要调用的方法id
    const char *method = "log";
    const char *sign = "(Ljava/lang/String;)V";
    jmethodID jmethodId = (*env)->GetMethodID(env, jclazz, method, sign);
    //调用改类的方法
    const char *message = "method called by c";
    jstring jstring1 = (*env)->NewStringUTF(env, message);
    (*env)->CallVoidMethod(env, jobject1, jmethodId, jstring1);
    //释放引用
    (*env)->DeleteLocalRef(env, jclazz);
    (*env)->DeleteLocalRef(env, jobject1);
    (*env)->DeleteLocalRef(env, jstring1);
}
```

## 在该模块下的`build.grald`添加相应配置

```groovy
android {
    compileSdkVersion 28
    buildToolsVersion "29.0.1"

    defaultConfig {
				...
      
        //ndk so架构的选择
        ndk {
            abiFilters 'armeabi-v7a', 'arm64-v8a'
        }
    }

  	...

    //cmake文件的查找路径
    externalNativeBuild {
        cmake {
            path file('CMakeLists.txt')
        }
    }

}
```

