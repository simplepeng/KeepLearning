# 单例模式

[维基百科](https://zh.wikipedia.org/wiki/单例模式)

单例类只能有一个实例

单例类必须自己创建自己的唯一实例

单例类必须给所有其他对象提供这一实例

* 懒汉式-线程不安全
* 懒汉式-线程安全
* 饿汉式
* 双重校验锁（double checked locking）
* 静态内部类
* 枚举

## 懒汉式-线程不安全

没有`synchronized`，也就是没有加锁，严格来说不算单例模式，因为在多线程下还是会创建多个实例。

```java
public class Singleton {  
  
    private static Singleton instance; 
  
    private Singleton (){}  
  
    public static Singleton getInstance() {  
        if (instance == null) {  
            instance = new Singleton();  
        }  
        return instance;  
    }  
}
```

## 懒汉式-线程安全

这种方式虽然虽然加了锁，但是效率很低。

```java
public class Singleton {  
  
    private static Singleton instance;  
  
    private Singleton (){}  
  
    public static synchronized Singleton getInstance() {  
        if (instance == null) {  
            instance = new Singleton();  
        }  
        return instance;  
    }  
}
```

## 饿汉式

这种方式没有懒加载，容易浪费内存，比如该类有个其他静态方法被调用，一样也会创建该类的实例。

但是因为没有加锁，相对于来说效率也会高点。

```java
public class Singleton {  
  
    private static Singleton instance = new Singleton();  
  
    private Singleton (){}  
  
    public static Singleton getInstance() {  
    return instance;  
    }  
}
```

## 双重校验锁

这种方式采用双锁机制，安全且在多线程情况下能保持高性能。

```java
public class Singleton {  
  
    private volatile static Singleton singleton;  
  
    private Singleton (){}  
  
    public static Singleton getSingleton() {  
    if (singleton == null) {  
        synchronized (Singleton.class) {  
            if (singleton == null) {  
                singleton = new Singleton();  
            }  
        }  
    }  
    return singleton;  
    }  
}
```

## 静态内部类

这种方式能达到双检锁方式一样的功效，但实现更简单。

对静态域使用延迟初始化，应使用这种方式而不是双检锁方式。这种方式只适用于静态域的情况，双检锁方式可在实例域需要延迟初始化时使用。

这种方式同样利用了 classloader 机制来保证初始化 instance 时只有一个线程，它跟第 3 种方式不同的是：第 3 种方式只要 Singleton 类被装载了，那么 instance 就会被实例化（没有达到懒加载效果），而这种方式是 Singleton 类被装载了，instance 不一定被初始化。

```java
public class Singleton {  
  
    private static class SingletonHolder {  
      
    	private static final Singleton INSTANCE = new Singleton(); 
      
    }  
  
    private Singleton (){}  
  
    public static final Singleton getInstance() {  
        return SingletonHolder.INSTANCE;  
    }  
}
```

## 枚举

这种方式是 Effective Java 作者 Josh Bloch 提倡的方式，它不仅能避免多线程同步问题，而且还自动支持序列化机制，防止反序列化重新创建新的对象，绝对防止多次实例化。

不过，由于 JDK1.5 之后才加入 enum 特性，好像大多数人都不喜欢这么用。

```java
public enum Singleton {  
    INSTANCE;  
    public void whateverMethod() {  
    }  
}
```

## 题外话

Kotlin实现单例模式，直接用`object`关键字就行了，是真的香。

