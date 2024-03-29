# 设计模式的六大原则

[维基百科](https://zh.wikipedia.org/wiki/SOLID_(面向对象设计))

* 开闭原则（Open Close Principle）
* 里氏替换原则（Liskov Substitution Principle）
* 依赖倒置原则（Dependence Inversion Principle）
* 接口隔离原则（Interface Segregation Principle）
* 迪米特法则，又称最少知道原则（Demeter Principle）
* 合成复用原则（Composite Reuse Principle）

## 开闭原则

对扩展开放，对修改关闭

尽量使用接口和抽象类，而不是去修改原有代码

## 里氏替换原则

里氏代换原则中说，任何基类可以出现的地方，子类一定可以出现

只有当派生类可以替换掉基类，且软件单位的功能不受到影响时，基类才能真正被复用，而派生类也能够在基类的基础上增加新的行为

## 依赖倒置原则

依赖抽象而不依赖具体

## 接口隔离原则

使用多个隔离的接口，比使用单个接口要好

降低类之间的耦合度

## 迪米特法则

一个实体应当尽量少地与其他实体之间发生相互作用，使得系统功能模块相对独立

## 合成复用原则

尽量使用合成/聚合的方式，而不是使用继承