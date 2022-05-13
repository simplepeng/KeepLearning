# Canvas构造方法解析

* Canvas() 
* Canvas(@NonNull Bitmap bitmap)

空参构造方法没有承载体

有`bitmap`的构造方法的canvas会把对canvas所有操作承载到`bitmap`上

## 获取canvas的几种方法

1. 直接调用构造方法

2. 回调`view`的`onDraw`方法

   ```java
   @Override
       protected void onDraw(Canvas canvas) {
           super.onDraw(canvas);
           
       }
   ```

3. 调用`surfaceHolder`的`lockCanvas()`

	```java
SurfaceView surfaceView = new SurfaceView(this);
	SurfaceHolder surfaceHolder = surfaceView.getHolder();
	//获取
	Canvas c = surfaceHolder.lockCanvas();
	//释放
	surfaceHolder.unlockCanvasAndPost(c);
	```

