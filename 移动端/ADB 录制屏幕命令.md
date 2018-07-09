---
title:  ADB 录制屏幕命令
---

- 对于Android4.4的上的手机，系统自带了一个命令screenrecord，我们可以很方便的使用。

- 录制命令
  
		adb shell screenrecord /sdcard/test.mp4

	视频保存目录可以自己指定，如上面的/sdcard/test.mp4，命令执行后会一直录制180s，按下ctrl+c可以提前结束录制
	输入 --time-limit N，限制视频录制时间为N秒

- 设定视频分辨率

	对于高分辨率的手机，录制的视频很大，我们分享又不需要这么大的
	我们可以设置录制的视频分辨率

		adb shell screenrecord --size 848*480 /sdcard/test.mp4

- 设定视频比特率

	默认比特率是4M/s，为了分享方便，我们可以调低比特率为2M
		
		adb shell screenrecord --bit-rate 2000000 /sdcard/test.mp4

- 获取视频文件

	使用adb pull 即可把手机SD卡中视频获取到本地

		adb pull /sdcard/test.mp4 .