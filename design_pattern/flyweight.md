# 享元模式

[维基百科](https://zh.wikipedia.org/wiki/享元模式)

享元模式主要用于减少创建对象的数量，以减少内存占用和提高性能。

这种类型的设计模式属于结构型模式，它提供了减少对象数量从而改善应用所需的对象结构的方式。

有点类似Android中Looper的Messager，Messager.obtain()方法会重用之前已经创建过但是没被回收的Message对象。