# Cmake学习笔记

## 简介

[官网](https://cmake.org/documentation/)

CMake 是一个跨平台的，开源的构建系统（BuildSystem）。CMake 可以通过 CMakeLists.txt 文件来产生特定平台的标准的构建文件，例如：为 Unix 平台生成makefiles文件（使用GCC编译），为 Windows MSVC 生成 projects/workspaces（使用VS IDE编译）或Makefile文件（使用nmake编译）

## 基本语法

### 注释

cmake中以`#`开头为注释

### cmake命令

命令不区分大小写（参数会区分大小写），命令由命令、参数列表组成，参数之间使用空格进行分隔。

使用一对双引号包括的字符串认为是一个参数。

命令可以是一个内置命令（例如：project，add_executable等），也可以是一个用户定义的宏（macro）或者函数（function）。

### 变量

CMake的基本数据类型是字符串，一组字符串在一起称为列表（list）

`set`命令设置一个变量，`${var}`取出变量的值。

变量名区分大小写

在字符串中也可以使用 `${VariableName}` 来访问变量的值

使用语法 `$ENV{VariableName}` 来访问环境变量的值`（ENV{VariableName}` 则表示环境变量本身）

### 条件控制

```cmake
if(expression)

    #...

elseif(expression2)

    #...

else()

    #...

endif()
```

表达式中可以包含操作符，操作符包括：

一元操作符，例如：EXISTS、COMMAND、DEFINED 等

二元操作符，例如：EQUAL、LESS、GREATER、STRLESS、STRGREATER 等

NOT（非操作符）

AND（与操作符）、OR（或操作符）

操作符优先级：一元操作符 > 二元操作符 > NOT > AND、OR

常用操作符介绍：

```cmake
# 为真的前提是 expression 为假
if(NOT expression)

# 为真的前提是存在 command-name 命令、宏或函数且能够被调用
if(COMMAND command-name)

# 为真的前提是存在 name 的文件或者目录（应该使用绝对路径）
if(EXISTS name)

# 为真的前提是 file1 比 file2 新或者 file1、file2 中有一个文件不存在（应该使用绝对路径）
if(file1 IS_NEWER_THAN file2)

# 为真的前提是 directory-name 表示的是一个目录（应该使用绝对路径）
if(IS_DIRECTORY directory-name)

# 为真的前提是变量值或者字符串匹配 regex 正则表达式
if(variable|string MATCHES regex)

# 为真的前提是变量值或者字符串为有效的数字且满足小于（大于、等于）的条件
if(variable|string LESS variable|string)
if(variable|string GREATER variable|string)
if(variable|string EQUAL variable|string)

# 为真的前提是变量值或者字符串以字典序满足小于（大于、等于）的条件
if(variable|string STRLESS variable|string)
if(variable|string STRGREATERvariable|string)
if(variable|string STREQUALvariable|string)

# 为真的前提是 variable 表示的变量被定义了。
if(DEFINED variable)
```

### 循环结构

```cmake
set(VAR a b c)

foreach(f ${VAR})

   message(${f})

endforeach()
```

```cmake
set(VAR 5)

while(${VAR} GREATER 0)

   message(${VAR})

   math(EXPR VAR "${VAR} - 1")

endwhile()
```

### 函数和宏定义

```cmake
# 定义一个宏 hello

macro(hello MESSAGE)

   message(${MESSAGE})

endmacro()

# 调用宏 hello

hello("hello world")
```

```cmake
# 定义一个函数 hello

function(hello MESSAGE)

   message(${MESSAGE})

endfunction()
```

函数和宏可以通过命令 return() 返回，但是函数和宏的返回值必须通过参数传递出去。

```cmake
cmake_minimum_required(VERSION 2.8)

function(get_func RESULT)
    #RESULT 的值为实参的值，因此需要使用 ${RESULT}
    #这里使用 PARENT_SCOPE 是因为函数会构建一个局部作用域
   set(${RESULT} "Hello Function" PARENT_SCOPE)
endfunction()

macro(get_macro RESULT)
   set(${RESULT} "Hello Macro")
endmacro()

get_func(V1)

# 输出 Hello Function
message(${V1})

get_macro(V2)
# 输出 Hello Macro
message(${V2})
```

### 字符串

字符串可跨行且支持转移字符

```cmake
set(VAR "hello

world")

# 输出结果为：

# ${VAR} = hello

# world

message("\${VAR} = ${VAR}")
```

## 常用命令

### project

```cmake
project(<projectname> [languageName1 languageName2 … ] )
```

命令简述：用于指定项目的名称

使用范例：project(Main)

### cmake_minimum_required

```cmake
cmake_minimum_required(VERSION major[.minor[.patch[.tweak]]][FATAL_ERROR])
```

命令简述：用于指定需要的 CMake 的最低版本

使用范例：cmake_minimum_required(VERSION 3.14)

### aux_source_directory

```cmake
aux_source_directory(<dir> <variable>)
```

命令简述：用于将 dir 目录下的所有源文件的名字保存在变量 variable 中

使用范例：aux_source_directory(. DIR_SRCS)

### add_executable

```cmake
add_executable(<name> [WIN32] [MACOSX_BUNDLE][EXCLUDE_FROM_ALL] source1 source2 … sourceN)
```

命令简述：用于指定从一组源文件 source1 source2 … sourceN 编译出一个可执行文件且命名为 name

使用范例：add_executable(Main ${DIR_SRCS})

### add_library

```cmake
add_library([STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 source2 … sourceN)
```

命令简述：用于指定从一组源文件 source1 source2 … sourceN 编译出一个库文件且命名为 name

使用范例：add_library(Lib ${DIR_SRCS}) add_library(native_lib shared hello.c world.c)

### add_dependencies

```cmake
add_dependencies(target-name depend-target1 depend-target2 …)
```

命令简述：用于指定某个目标（可执行文件或者库文件）依赖于其他的目标。这里的目标必须是 add_executable、add_library、add_custom_target 命令创建的目标

### add_subdirectory

```cmake
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
```

命令简述：用于添加一个需要进行构建的子目录

使用范例：add_subdirectory(Lib)

### target_link_libraries

```cmake
target_link_libraries(<target> [item1 [item2 […]]][[debug|optimized|general] ] …)
```

命令简述：用于指定 target 需要链接 item1 item2 …。这里 target 必须已经被创建，链接的 item 可以是已经存在的 target（依赖关系会自动添加）

使用范例：target_link_libraries(Main Lib)

### set

```cmake
set(<variable> <value> [[CACHE <type><docstring> [FORCE]] | PARENT_SCOPE])
```

命令简述：用于设定变量 variable 的值为 value。如果指定了 CACHE 变量将被放入 Cache（缓存）中。

使用范例：set(ProjectName Main)

### unset

```cmake
unset(<variable> [CACHE])
```

命令简述：用于移除变量 variable。如果指定了 CACHE 变量将被从 Cache 中移除。

使用范例：unset(VAR CACHE)

### message

命令语法：message([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERROR] “message todisplay”…)

命令简述：用于输出信息

### include_directories

```cmake
include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 …)
```

命令简述：用于设定目录，这些设定的目录将被编译器用来查找 include 的源文件

使用范例：include_directories(${PROJECT_SOURCE_DIR}/lib)

### find_path

```cmake
find_path(<VAR> name1 [path1 path2 …])
```

命令简述：用于查找包含文件 name1 的路径，如果找到则将路径保存在 VAR 中（此路径为一个绝对路径），如果没有找到则结果为 <VAR>-NOTFOUND。默认的情况下，VAR 会被保存在 Cache 中，这时候我们需要清除 VAR 才可以进行下一次查询（使用 unset 命令）。

使用范例：

```cmake
find_path(LUA_INCLUDE_PATH lua.h${LUA_INCLUDE_FIND_PATH})

if(NOT LUA_INCLUDE_PATH)

  message(SEND_ERROR "Header file lua.h not found")

endif()
```

### find_library

```cmake
find_library(<VAR> name1 [path1 path2 …])
```

命令简述：用于查找库文件 name1 的路径，如果找到则将路径保存在 VAR 中（此路径为一个绝对路径），如果没有找到则结果为 <VAR>-NOTFOUND。一个类似的命令 link_directories 已经不太建议使用了

### add_definitions

```cmake
add_definitions(-DFOO -DBAR …)
```

命令简述：用于添加编译器命令行标志（选项），通常的情况下我们使用其来添加预处理器定义

使用范例：add_definitions(-D_UNICODE -DUNICODE)

### execute_process

```cmake
execute_process(COMMAND <cmd1>[args1...]]

                  [COMMAND <cmd2>[args2...] [...]]

                  [WORKING_DIRECTORY<directory>]

                  [TIMEOUT <seconds>]

                  [RESULT_VARIABLE<variable>]

                  [OUTPUT_VARIABLE<variable>]

                  [ERROR_VARIABLE<variable>]

                  [INPUT_FILE <file>]

                  [OUTPUT_FILE <file>]

                  [ERROR_FILE <file>]

                  [OUTPUT_QUIET]

                  [ERROR_QUIET]

                 [OUTPUT_STRIP_TRAILING_WHITESPACE]

                 [ERROR_STRIP_TRAILING_WHITESPACE])
```

命令简述：用于执行一个或者多个外部命令。每一个命令的标准输出通过管道转为下一个命令的标准输入。WORKING_DIRECTORY 用于指定外部命令的工作目录，RESULT_VARIABLE 用于指定一个变量保存外部命令执行的结果，这个结果可能是最后一个执行的外部命令的退出码或者是一个描述错误条件的字符串，OUTPUT_VARIABLE 或者 ERROR_VARIABLE 用于指定一个变量保存标准输出或者标准错误，OUTPUT_QUIET 或者 ERROR_QUIET 用于忽略标准输出和标准错误。

使用范例：execute_process(COMMAND ls)

### file

命令简述：此命令提供了丰富的文件和目录的相关操作

使用范例：

* 目录的遍历

* GLOB 用于产生一个文件（目录）路径列表并保存在variable 中

* 文件路径列表中的每个文件的文件名都能匹配globbing expressions（非正则表达式，但是类似）

*  如果指定了 RELATIVE 路径，那么返回的文件路径列表中的路径为相对于 RELATIVE 的路径

*  file(GLOB variable [RELATIVE path][globbing expressions]...)

*  获取当前目录下的所有的文件（目录）的路径并保存到 ALL_FILE_PATH 变量中

file(GLOB ALL_FILE_PATH ./*)

*  获取当前目录下的 .h 文件的文件名并保存到ALL_H_FILE 变量中

*  这里的变量CMAKE_CURRENT_LIST_DIR 表示正在处理的 CMakeLists.txt 文件的所在的目录的绝对路径（2.8.3 以及以后版本才支持）

file(GLOB ALL_H_FILE RELATIVE${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*.h)

## Cmake配合AndroidStudio

**build.gradle**

```groovy
android {
    compileSdkVersion 28
    defaultConfig {
        externalNativeBuild {
            // 主要是配置了cmake的命令参数
            cmake {
                cppFlags ""
                // 设置编译c/c++ 源文件的cpu类型
                // 如果不设置，连接不同的设备，gralde会自动根据连接的设备，如armeabi-v7a架构的手机，则编译出armeabi-v7a，如模拟器，则编译出x86。
                // 由于考虑编译出来后包的大小，一般实际开发中，都只是编译兼容性最多的armeabi-v7a架构
                abiFilters 'armeabi-v7a'
            }
        }
    }
    externalNativeBuild {
        // 主要定义了CMake的构建脚本CMakeLists.txt的路径
        cmake {
            // 当前的CMakeLists.txt与build.gradle在同一个目录下
            // CMakeLists.txt也可以在其他路径下，比如可以在cpp目录下创建一个CMakeList.txt配置cpp目录下的源文件
            path "CMakeLists.txt"
        }
    }
}
```

**CMakeList.txt**

```cmake
# 设置cmake最低支持版本
cmake_minimum_required(VERSION 3.4.1)
# 编译library库
add_library( 
			 # 设置编译后的library名称
			 native-lib
			 # 设置library模式，STATIC为静态库，如果想编译为动态库，则修改为SHARED
             STATIC  
             # 设置编译使用到的源代码，如果添加了源代码，都需要修改此处添加源代码的路径
             src/main/cpp/native-lib.cpp )

# 查找library，因为NDK中已经有一部分预构建库，已经被配置为cmake搜索路径的一部分，所以，可以直接添加库的名称。
find_library(
			 # 此处为查找名称为log的库，将绝对路径赋值到变量log-lib
			 log-lib
             log )

# 链接library
target_link_libraries(
					   # 链接自己编写的native-lib库和上面查找到的lib库
					   # 位置不能更改，native-lib为目标的库，必须放在前面
					   native-lib
                       ${log-lib} )
                 
# 这样多的话，写进去就比较麻烦，导入只需要写源文件，.h可以不写
add_executable(Demo2 main.c hello.c)
# 查找当前目录所有源文件 并将名称保存到 DIR_SRCS 变量
# 注意这样不能查找子目录，也不会自动往子目录找
aux_source_directory(. DIR_SRCS)
# 或者也可以使用如果通配符的方式，引入所有.c文件，同样保存到 DIR_SRCS变量中
file(GLOB DIR_SRCS *.c)

# $() 为引用变量DIR_SRCS的值
add_executable(Demo2 ${DIR_SRCS})
                 
# 如果上面不预先使用find_library的话，也可以直接使用
target_link_libraries( native-lib 
					   log)
```

