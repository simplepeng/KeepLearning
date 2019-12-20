## 什么是FFmpeg

github地址：[https://github.com/FFmpeg/FFmpeg](https://github.com/FFmpeg/FFmpeg)

FFmpeg官网：[https://ffmpeg.org/](https://ffmpeg.org/)

`FFmpeg`是一套可以用来做音视频`采集`，`裁剪`,`转换`，`推流`等操作的`开源计算机程序`。采用LGPL或GPL许可证，它提供了录制、转换以及流化音视频的完整解决方案。

国内耳熟能详的`暴风影音`、`QQ影音`，以及国外著名的`KMPlayer`、`PotPlayer`，都采用了FFmpeg的代码但却不按规矩开源，被放入了FFmpeg的耻辱名单当中。

## FFmpeg主要组成组件

* `ffmpeg`：一个命令行工具，用来对视频，音频文件执行`剪辑`，`转换格式`，`旋转`，`添加滤镜`等操作的指令集
* `ffserver`：一个HTTP多媒体即时广播流服务器，支持回溯
* `ffplay`：一个简单的播放器，基于SDL与FFmpeg库
* `libavcodec`：包含全部FFmpeg音频/视频编解码库
* `libavformat`：包含demuxers和muxer封装格式库
* `libavutil`：ffmpeg一个工具库
* `libavfilter`：加filter的库(这里翻译成滤镜不太严谨)
* `libswscale`：对图像做转换比例(缩放)的库
* `libavresample`：做重采样的库
* `libavdevice`：使用这个库可以读取电脑（或者其他设备上）的多媒体设备的数据，或者输出数据到指定的多媒体设备上

## FFmpeg命令集的常用参数

FFmpeg可使用众多参数，参数内容会根据ffmpeg版本而有差异，使用前建议先参考参数及编解码器的叙述。

也可以使用`ffmpeng -h`命令查看

### 常用参数

* `-i`：设置输入源，可以是文件，也可以是网络流文件
* `-f`：设置输出格式
* `-y`：若输出文件已经存在就覆盖
* `-fs`：超过指定的文件的持续时间就结束
* `-ss`：从指定时间开始，一般格式为`00:00:00`，也可以是`多少秒`
* `-t`：指令的持续时间
* `-title`：设置媒体文件的标题
* `-c`：指定输出文件的编码
* `-metadata`：更改输出文件的`元数据`

### 影像参数

- `-b:v`——设置影像流量，默认为200Kbit/秒。
- `-r`——设置帧率值，默认为25。
- `-s`——设置画面的宽与高。
- `-aspect`——设置画面的比例。
- `-vn`——不处理影像，于仅针对声音做处理时使用。
- `-vcodec( -c:v )`——设置影像影像编解码器，未设置时则使用与输入文件相同之编解码器。

### 声音参数

- `-b:a`——设置每个`Channel`的流量（chanel可以理解为声道数，左声道，右声道这种）
- `-ar`——设置采样率。
- `-ac`——设置声音的`Channel`数。
- `-acodec ( -c:a )` ——设置声音编解码器，未设置时与影像相同，使用与输入文件相同之编解码器。
- `-an`——不处理声音，于仅针对影像做处理时使用。
- `-vol`——设置音量大小，256为标准音量。（要设置成两倍音量时则输入512，依此类推。）

## 常用命令

### 查看媒体信息

```shell
ffprobe xxx.xx
ffmpeg -i xxx.xx
```

### 播放媒体文件

```shell
ffplay xxxx.文件格式

ffplay xxx.mp4
```

### 下载网络媒体到本地

```shell
ffmpeg -i http://file.52lishi.com/file/yinxiao/ly-17-12-16-06.mp3 laosiji.aac
```

### 转换媒体格式

```shell
ffmpeg -i 源媒体 输出媒体
```

```shell
ffmpeg -i chailao.mp4 chailao.ts
```

`.ts`：TS是 transport Stream的缩写通常称为码流文件, TS文件是最原始的音频视频容器,没有经过其他算法的压缩所以一般会很大,这跟当时播放的源文件的情况,比如比特率什么的.

### 裁剪媒体文件

```shell
ffmpeg -i 源媒体 -ss 00:00:20 -t 10 -c copy 输出媒体
```

```shell
ffmpeg -i chailao.mp4 -ss 00:02:08 -t 7 -c copy chailao_split.mp4
```

`-c`：也就是`codec`(编码)，`copy`指定和源媒体使用同样的配置(元数据)

### 视频转gif

```shell
ffmpeg -i 源媒体 xxx.gif
```

```shell
ffmpeg -i chailao_split.mp4 chailao.gif
```

这个跟上面的转换媒体格式其实是一个。

### 从视频文件截取一帧转为图片

```shell
ffmpeg -i 源媒体 -ss 开始时间 -s 宽x高 -vframes 帧数 -f image2 输出文件
```

```shell
ffmpeg -i chailao.mp4 -ss 00:02:08 -s 300x300 -vframes 1 -f image2 frame.png
```

### 将一系列图片合成gif

```shell
ffmpeg -i xxx_%d.png -r 帧数 xxx.gif
```

```shell
ffmpeg -i frame%d.png -r 25 frame.gif
```

`-f`：设置帧数

### 分离视频音频流

```shell
ffmpeg -i input_file -vcodec copy -an output_file_video    //分离出视频流
ffmpeg -i input_file -acodec copy -vn output_file_audio    //分离出音频流
```

`-an`：不要音频流

`-vn`：不要视频流

```shell
ffmpeg -i chailao.mp4 -vcodec copy -an chailao_without_audio.mp4
ffmpeg -i chailao.mp4 -acodec copy -vn chailao_without_video.mp4
```

### 将视频和音频合并

```shell
ffmpeg -i video_file -i audio_file -vcodec copy -acodec copy output_file
```

`-vcodec`：视频编码器

`-acodec`：音频编码器

```shell
ffmpeg -i chailao_without_audio.mp4 -i chailao_without_video.mp4 -vcodec copy -acodec copy chailao_merge.mp4
```

### 音视频倒放

```shell
//视频倒放
ffmpeg -i input-file.mp4 -vf reverse output.mp4
```

```shell
//音视频都倒放
ffmpeg -i input-file.mp4 -vf reverse -af areverse output.mp4
```

```shell
ffmpeg -i chailao.mp4 -vf reverse reverse_video.mp4
//
ffmpeg -i chailao.mp4 -vf reverse -af areverse reverse_video_audio.mp4
```

