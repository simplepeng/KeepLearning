# JNI学习笔记

## 类型对照表

### 基础类型

| Java类型 | JNI类型  | C/C++类型     | 大小             |
| :------- | :------- | ------------- | ---------------- |
| Boolean  | jboolean | unsigned char | 无符号8位        |
| Byte     | jbyte    | char          | 有符号8位        |
| Char     | jchar    | unsigned char | 无符号16位       |
| Short    | jshort   | short         | 有符号16位       |
| Integer  | jint     | int           | 有符号32位       |
| Long     | jlong    | long long     | 有符号64位       |
| Float    | jfloat   | float         | 32位浮点值       |
| Double   | jdouble  | double        | 64位双精度浮点值 |

### 引用类型

| Java类型            | C/C++类型     |
| ------------------- | ------------- |
| java.lang.Class     | jclass        |
| java.lang.Throwable | jthrowable    |
| java.lang.String    | jstring       |
| java.lang.Object    | jobject       |
| java.util.Objects   | jobjects      |
| java.lang.Object[]  | jobjectArray  |
| Boolean[]           | jbooleanArray |
| Byte[]              | jbyteArray    |
| Char[]              | jcharArray    |
| Short[]             | jshortArray   |
| int[]               | jintArray     |
| long[]              | jlongArray    |
| float[]             | jfloatArray   |
| double[]            | jdoubleArray  |
| 通用数组 []         | jarray        |

在c里面，所以引用类型都是jobject

## 签名对照表

JNI获取Java类的方法ID和字段ID都需要一个重要的参数，那就是Java类的方法和字段的签名。

```c
jfieldID j_fid = env->GetFieldID(j_class, "noStaticField", "I");
jmethodID id = env->GetMethodID(clazz, "paramMethod", "(I)V");
```

如果Java方法有返回值就要加上括号`()`包住参数，括号后跟上返回值得签名类型。

多个参数不需要用符号隔开，直接顺序写签名类型

```java
  public me.simple.example_ndk_cmake.Test(int, java.lang.String);
    descriptor: (ILjava/lang/String;)V
```

### 基础类型

| Java类型 | 签名描述 |
| :------- | :------- |
| boolean  | Z        |
| byte     | B        |
| char     | C        |
| short    | S        |
| int      | I        |
| long     | J        |
| float    | F        |
| double   | D        |
| void     | V        |

### 引用类型

以大写`L`开头，`;`结尾，中间的是引用类型的完整路径，包名的`.`用`/`代替。

```java
String ： Ljava/lang/String;
Object ： Ljava/lang/Object;
自定义类型 ：L包名/类型名
构造方法：<init>
```

### 数组

在类型前面加一个左方括号`[`，几维数组就加几个`[`

```java
int [] ：[I
Long[][]  ： [[J
Object[][][] ： [[[Ljava/lang/Object
```

### 命令查看签名

```java
javap -s -p xxx.class
```

```java
public class me.simple.example_ndk_cmake.MainActivity extends androidx.appcompat.app.AppCompatActivity {
  public static final java.lang.String TAG;
    descriptor: Ljava/lang/String;
  public java.lang.String filedA;
    descriptor: Ljava/lang/String;
  public static int filedStaticB;
    descriptor: I
  public me.simple.example_ndk_cmake.MainActivity();
    descriptor: ()V

  protected void onCreate(android.os.Bundle);
    descriptor: (Landroid/os/Bundle;)V

  public void callJniMethod(android.view.View);
    descriptor: (Landroid/view/View;)V

  public void toast(java.lang.String);
    descriptor: (Ljava/lang/String;)V

  public static native void jniCallJavaMethod();
    descriptor: ()V
}
```

## 常见用法

### Java调用JNI方法

```java
static {
        System.loadLibrary("hello_jni");
}

public static native String callJniMethod();
```

```c
JNIEXPORT jstring JNICALL Java_me_simple_example_1ndk_1cmake_MainActivity_callJniMethod(
        JNIEnv *env, jclass clazz
) {
    const char *message = "string from jni c";
    return (*env)->NewStringUTF(env, message);
}
```

### JNI访问Java类的变量

`private`的变量一样可以访问

```c
JNIEXPORT void JNICALL
Java_me_simple_example_1ndk_1cmake_MainActivity_native_1callJavaFiled(
        JNIEnv *env, jclass clazz, jobject testObj) {
    //根据类路径找到类对象
//    jclass jclazz = (*env)->FindClass(env, class_name);
    jclass jclazz = (*env)->GetObjectClass(env, testObj);
    //获取变量字段的id
    const char *filed = "a";
    const char *sign = "I";
    jfieldID jfieldId = (*env)->GetFieldID(env, jclazz, filed, sign);
    //获取字段的值
    jint jint1 = (*env)->GetIntField(env, testObj, jfieldId);
    log_d("get filed == %d", jint1);
    //更改字段的值
    (*env)->SetIntField(env, testObj, jfieldId, 3);
    jint1 = (*env)->GetIntField(env, testObj, jfieldId);
    log_d("set filed == %d", jint1);
}
```

### JNI访问Java类的静态变量

```c
		//根据类路径找到类对象
    jclass jclass1 = (*env)->FindClass(env, class_name);
    //获取static变量字段的id
    const char *filed = "b";
    const char *sign = "Ljava/lang/String;";
    jfieldID jfieldId = (*env)->GetStaticFieldID(env, jclass1, filed, sign);
    //获取staic字段的值
    jstring jstring1 = (jstring) (*env)->GetStaticObjectField(env, jclass1, jfieldId);
    //jstring转换为字符指针
    const char *filed_string = (*env)->GetStringUTFChars(env, jstring1, 0);
    log_d("get string filed == %s", filed_string)
```

### JNI调用Java类的方法

```c
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
```

### JNI调用Java类的静态方法

```c
jclass jclazz = (*env)->FindClass(env, class_name);

const char *method = "staticLog";
const char *sign = "(Ljava/lang/String;)V";
jmethodID jmethodId = (*env)->GetStaticMethodID(env, jclazz, method, sign);

const char *message = "message from c";
jstring jmessage = (*env)->NewStringUTF(env, message);
(*env)->CallStaticVoidMethod(env, jclazz, jmethodId, jmessage);
```

### JNI调用Java类的构造方法

* 调用无参构造方法

```c
//获取类的空参构造方法
const char *construct_method = "<init>";
jmethodID construct = (*env)->GetMethodID(env, jclazz, construct_method, "()V");
//创建该类的实例
jobject jobject1 = (*env)->NewObject(env, jclazz, construct);
```

* 调用有参构造方法

```c
//根据类路径找到类对象
jclass jclazz = (*env)->FindClass(env, class_name);
//获取类的有参构造方法
const char *construct_method = "<init>";
const char *sign = "(ILjava/lang/String;)V";
jmethodID construct = (*env)->GetMethodID(env, jclazz, construct_method, sign);
//创建该类的实例
jint arg_a = 10;
jstring arg_b = (*env)->NewStringUTF(env, "hello world");
jobject jobject1 = (*env)->NewObject(env, jclazz, construct, arg_a, arg_b);
```

* 如何是内部类，包名之前还是用`/`，内部类连接用`$`，比如`android/graphics/Bitmap$Config`。

### JNI异常处理

* 抛出异常

```c
jclass e_class = (*env)->FindClass(env, "java/lang/Exception");
(*env)->ThrowNew(env, e_class, "throw exception from c");
```

* 检测异常

使用`ExceptionOccurred`进行异常的检测。注意，这里只能检测java异常。

使用`ExceptionClear`进行异常的清除。

```c
jclass jclass1 = (*env)->FindClass(env, "java/lang/Exception");

const char *method = "a";
const char *sign = "b";
jfieldID  jfieldId = (*env)->GetFieldID(env,jclass1,method,sign);

//检测异常是否发生
jthrowable e =  (*env)->ExceptionOccurred(env);
if (e != NULL){
        log_d("异常发生")
        //清除异常，需要和ExceptionOccurred成对出现
        (*env)->ExceptionClear(env);
 }
```

### JNI创建Java枚举对象

使用`java -p 枚举类`可以查看对应签名，枚举类的变量字段都会生成为`static final`的，并且会生成一个`valueOf`的静态方法。

```c++
jobject createBitmap(JNIEnv *env,
                     int width, int height) {

    jclass bitmapCls = env->FindClass("android/graphics/Bitmap");
    jmethodID createBitmapFunction = env->GetStaticMethodID(bitmapCls,
                                                            "createBitmap",
                                                            "(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;");
    jstring configName = env->NewStringUTF("ARGB_8888");
    jclass bitmapConfigClass = env->FindClass("android/graphics/Bitmap$Config");
    jmethodID valueOfBitmapConfigFunction = env->GetStaticMethodID(bitmapConfigClass,
                                                                   "valueOf",
                                                                   "(Ljava/lang/String;)Landroid/graphics/Bitmap$Config;");

    jobject bitmapConfig = env->CallStaticObjectMethod(bitmapConfigClass,
                                                       valueOfBitmapConfigFunction,
                                                       configName);

    jobject newBitmap = env->CallStaticObjectMethod(bitmapCls,
                                                    createBitmapFunction,
                                                    width, height,
                                                    bitmapConfig);

    return newBitmap;
}
```

## 静态注册

```c

Java_me_simple_example_1ndk_1cmake_MainActivity_native_1callJavaFiled(JNIEnv *env, 
                                                                      jclass clazz){
 
}
```

包名+类名+方法名，用`_`分开。

## 动态注册

```java
public class MainActivity extends AppCompatActivity {

    // 加载so
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(getString());
    }

    /**
     * 定义native方法
     */
    public native String getString();
}
```

```c
#include <jni.h>
#include <string>
/**
 * extern "C" ：主要作用就是为了能够正确实现C++代码调用其他C语言代码
 * JNIEXPORT，JNICALL ：告诉虚拟机，这是jni函数
 */
extern "C"
JNIEXPORT jstring JNICALL
native_getString(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
/**
 * 对应java类的全路径名，.用/代替
 */
const char *classPathName = "com/chenpeng/registernativemethoddemo/MainActivity";

/**
 * JNINativeMethod 结构体的数组
 * 结构体参数1：对应java类总的native方法
 * 结构体参数2：对应java类总的native方法的描述信息，用javap -s xxxx.class 查看
 * 结构体参数3：c/c++ 种对应的方法名
 */
JNINativeMethod method[] = {{"getString", "()Ljava/lang/String;", (void *) native_getString}};

/**
 * 该函数定义在jni.h头文件中，System.loadLibrary()时会调用JNI_OnLoad()函数
 */
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    //定义 JNIEnv 指针
    JNIEnv *env = NULL;
    //获取 JNIEnv
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    //获取对应的java类
    jclass clazz = env->FindClass(classPathName);
    //注册native方法
    env->RegisterNatives(clazz, method, 1);
    //返回Jni 的版本
    return JNI_VERSION_1_6;
}
```

## log输出

```c
#include <android/log.h>

#define TAG "example_ndk"
#define log_v(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define log_d(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define log_i(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define log_w(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define log_e(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
```



