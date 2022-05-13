# 编译Android下可执行命令的FFmpeg

上一篇讲到了`使用FFmpeg生成视频封面图`，其实也可以直接使用`FFmpeg相关命令`截取一帧的图像数据保存到本地，然后加载到ImageView上，有时候使用命令确实比写代码更加简单和使人轻松一点，所以这一篇是讲解如何导入`FFmpeg相关源码` 然后如何执行命令行工具的博客，但是其实这只是个Demo而已，因为有很多细节需要处理，推荐直接使用开源库。

## 导入源码

从FFmpeg源码中导入`cmdutils.c`、`cmdutils.h`、`config.h`、`ffmpeg.c`、`ffmpeg.h`、

`ffmpeg_filter.c`、`ffmpeg_hw.c`、`ffmpeg_opt.c`这几个源码，一般存放在`fftools`目录下。`config.h`如果编译生成目录下没有，就可以直接使用ffmpeg根目录下的`config.h`。

## 编写CmakeList

```cmake
# 设置构建本机库文件所需的 CMake的最小版本
cmake_minimum_required(VERSION 3.4.1)

#添加头文件的搜索路径
include_directories(src/main/cpp/include)

#设置查找动态库位置
set(LINK_DIR ${CMAKE_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI})
link_directories(${LINK_DIR})
#找到所有的so库，存放在全局变量SO_DIR中
file(GLOB SO_DIR ${LINK_DIR}/*.so)

#找到所有的源文件，存放在全局变量中
#file(GLOB FFMPEG_DIR src/main/cpp/ffmpeg/*.c)
#message("FFMPEG_DIR == ${FFMPEG_DIR}")

file(GLOB CPP_DIR src/main/cpp/*.cpp)
file(GLOB FFMPEG_DIR src/main/cpp/include/*.c)

# 添加自己写的 C/C++源文件
add_library(utils #so名称
        SHARED #动态库
        ${CPP_DIR}
        ${FFMPEG_DIR}
        )

#  依赖 NDK中自带的log库
find_library(log-lib log)

#  链接库
target_link_libraries(
        utils
        ${SO_DIR}
        jnigraphics
        ${log-lib})
```

我是将ffmpeg的源码和之前生成的ffmpeg头文件都放在了`cpp/include`目录下，这样在CmakeList中使用`include_directories`就可以直接找到所有的头文件，然后将ffmpeg的源码和自己写的工具类源码关联起来就行了。

## 修改FFmpeg的源码

修改`ffmpeg.c`的`main`方法名称为`exe_cmd`，并在`ffmpeg.h`头文件加上同样名称的方法声明。

```c
//ffmpeg.c
int exe_cmd(int argc, char **argv) {
  ...
}
//ffmpeg.h
int exe_cmd(int argc, char **argv);
```

原生命令行工具在执行完FFmpeg命令后都会退出程序，但是在Android里面可不能这样，所以我们要修改FFmpeg结束程序的函数。

修改`cmdutils.c`和`cmdutils.h`，注释掉退出程序的代码，并且增加一个int的返回值。

```c
//cmdutils.c
int exit_program(int ret)
{
//    if (program_exit)
//        program_exit(ret);

//    exit(ret);
    return ret;
}

//cmdutils.h
int exit_program(int ret);
```

并且在Android里面我们肯定是执行完一条命令，接着还会继续执行其他命令，所以我们需要重新初始化一些关键变量的值。

找到`ffmpeg.c`中的`ffmpeg_cleanup`函数，在末尾将一些关键变量重新初始化。

```c
//ffmpeg.c
static void ffmpeg_cleanup(int ret) {
  ...
    nb_filtergraphs = 0;
    nb_output_files = 0;
    nb_output_streams = 0;
    nb_input_files = 0;
    nb_input_streams = 0;
}
```

最后在`main`函数末尾调用`ffmpeg_cleanup`函数

```c
int exe_cmd(int argc, char **argv) {
  ...
    //    exit_program(received_nb_signals ? 255 : main_return_code);
    ffmpeg_cleanup(0);
}
```

## 增加FFmpeg日志输出

在`ffmpeg.c`中找到`log_callback_null`的函数，添加如下代码，原代码块是空实现。

```c
#include "android/log.h"
#define logDebug(...) __android_log_print(ANDROID_LOG_DEBUG,"MainActivity",__VA_ARGS__)

static void log_callback_null(void *ptr, int level, const char *fmt, va_list vl) {
    static int print_prefix = 1;
    static int count;
    static char prev[1024];
    char line[1024];
    static int is_atty;
    av_log_format_line(ptr, level, fmt, vl, line, sizeof(line), &print_prefix);
    strcpy(prev, line);

    logDebug("ffmpeg log ----- %s", line);
}
```

在`main`函数中调用`log_callback_null`函数

```c
int exe_cmd(int argc, char **argv) {
    av_log_set_callback(log_callback_null);
  	 int i, ret;
  ...
}
```

## 编写工具类方法

在`MainActivity`中增加`exeCmd(String[] cmd)`方法

```java
public static native int exeCmd(String[] cmd);
```

在`ffmpeg_utils.cpp`增加jni方法

```c++
JNIEXPORT jint JNICALL
Java_demo_simple_example_1ffmpeg_MainActivity_exeCmd(JNIEnv *env, jclass clazz, jobjectArray cmd) {
    int argc = env->GetArrayLength(cmd);
    logDebug("argc == %d", argc);
    char *argv[argc];

    for (int i = 0; i < argc; ++i) {
        jstring str = (jstring) env->GetObjectArrayElement(cmd, i);
        argv[i] = (char *) env->GetStringUTFChars(str, JNI_FALSE);
        logDebug("%s ", argv[i]);
    }

    return exe_cmd(argc, argv);
//    return 1;
}
```

执行命令

```java
private void exeCmd() {
        String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator
                + "get_cover1.mp4";
        String outPath = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separator
                + "video.flv";
        File outFile = new File(outPath);
        if (outFile.exists()) {
            outFile.delete();
        }
        //裁剪个1s视频
        String cmd = "ffmpeg -ss 00:00:00 -t 00:00:10 -i " + path + " -vcodec copy -acodec copy " + outPath;
        String[] cmdArr = cmd.split(" ");
        int result = exeCmd(cmdArr);
        Log.d(TAG, "exe cmd result == " + result);
    }
```

查看日志输出

```shell
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- 
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log -----   Total: 331 packets (1993540 bytes) demuxed
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- Output file #0 (/storage/emulated/0/video.flv):
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log -----   Output stream #0:0 (video): 
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- 129 packets muxed (1822580 bytes); 
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- 
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log -----   Output stream #0:1 (audio): 
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- 202 packets muxed (170960 bytes); 
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- 
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log -----   Total: 331 packets (1993540 bytes) muxed
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- 0 frames successfully decoded, 0 decoding errors
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- [AVIOContext @ 0xda2ea480] Statistics: 2 seeks, 10 writeouts
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- [AVIOContext @ 0xda2ea3c0] Statistics: 2161643 bytes read, 1 seeks
demo.simple.example_ffmpeg D/MainActivity: ffmpeg log ----- 
demo.simple.example_ffmpeg D/MainActivity: exe cmd result == 0
```

执行命令的返回值`==0`，并且也看到确实文件已经生成出来了，我们`adb pull`把文件导出到桌面用`ffprobe`或`ffplay`看看。

```shell
ffprobe video.flv
```

```shell
ffprobe version 4.0.4 Copyright (c) 2007-2019 the FFmpeg developers
built with Apple LLVM version 10.0.0 (clang-1000.10.44.4)
configuration:
libavutil      56. 14.100 / 56. 14.100
libavcodec     58. 18.100 / 58. 18.100
libavformat    58. 12.100 / 58. 12.100
libavdevice    58.  3.100 / 58.  3.100
libavfilter     7. 16.100 /  7. 16.100
libswscale      5.  1.100 /  5.  1.100
libswresample   3.  1.100 /  3.  1.100
Input #0, flv, from 'video.flv':
Metadata:
 major_brand     : mp42
 minor_version   : 0
 compatible_brands: mp42mp41
 encoder         : Lavf58.45.100
Duration: 00:00:01.07, start: 0.033000, bitrate: 3130 kb/s
 Stream #0:0: Video: h264 (Main), yuv420p(tv, bt709, progressive), 1080x1920, 3390 kb/s, 30 fps, 30 tbr, 1k tbn, 60 tbc
 Stream #0:1: Audio: aac (LC), 48000 Hz, stereo, fltp, 317 kb/s
```

可以看到确实裁剪生成了一个1秒的视频，虽然后缀名我们用的`.flv`，但是其实我们是拷贝的视频编码，所以还是`mp4`的封装格式。

[源码](https://github.com/simplepeng/AndroidExamples/tree/master/example_ffmpeg)

## 使用已有的轮子

上面的例子并不是一个完善的工具类，比如缺少Native层的线程支持，出现错误就会直接闪退，缺少进度回调等，所以还是直接使用现成的轮子比较靠谱，只是我们需要知道轮子大概是怎么造出来的就行了。

这里我推荐使用[mobile-ffmpeg](https://github.com/tanersener/mobile-ffmpeg)这个开源库，1.8k的star足以证明其品质还行，直接导入编译好的`aar`就可以执行命令行工具链，而且可以自行编译链接很多有用的第三方library，比如`x264`、`libwebp`	等。

动手能力强或有特殊需求的可以使用`android.sh`自行编译出FFmpeg头文件和动态库，以及Android工具链的aar。

比如说我现在只需要一个支持`arm64-v8a`和`api16`及以上的动态库，那么我就自己新建了一个shell脚本文件：

```shell
#!/bin/bash

export ANDROID_HOME="/Users/chenpeng/Library/Android/sdk/"
export ANDROID_NDK_ROOT="/Users/chenpeng/Desktop/work_space/ndk/android-ndk-r21b/"

build() {
    ./android.sh \
        --lts \
        --disable-arm-v7a \
        --disable-arm-v7a-neon \
        --disable-x86 \
        --disable-x86-64
}

build
```

执行完这个shell后，就会在`prebuilt`目录下生产对应的头文件，动态库，以及aar文件，直接拿来用就可以了。