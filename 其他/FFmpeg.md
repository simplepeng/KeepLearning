## 将视频分解成图片序列

> ffmpeg -i video.mpg image%d.jpg

* -i->input
* -r->帧率

## 将图片序列合成视频

> ffmpeg -f image2 -i image%d.jpg video.mpg
>
> ffmpeg -loop 1 -f image2 -i in-1.png -t 3 out.mpg

* -f->fmt
* image2->默认格式

## 格式转换

> ffmpeg -i input.avi output.mp4

## 常用参数

* -loop_1循环读输入 0读完就不读了
* -vcodec_编码格式(libx24,hx264...)
* -b_指定码率
* -t_指定时长
* -vf_添加滤镜

## 合并多条视频

> ffmpeg -i "concat:out1.mpg|out2.mpg|out3.mpg" -c copy concat.mpg

## 合并音视频

> ffmpeg -i a.mp4 -i b.mp3 out.mp4