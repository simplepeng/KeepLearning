## 模板(泛型)

模板是泛型编程的基础，我们可以使用模板来定义函数和类。所以c++中有两种模板

* `模板类`
* `模板函数`

```c++
#include <iostream>

using namespace std;

template<typename T> void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    //交换 int 变量的值
    int n1 = 100, n2 = 200;
    Swap(n1, n2);
    cout<<n1<<", "<<n2<<endl;
   
    //交换 float 变量的值
    float f1 = 12.5, f2 = 56.93;
    Swap(f1, f2);
    cout<<f1<<", "<<f2<<endl;
  
   return 0;
}
```

```c++
#include <iostream>
using namespace std;

template<class T1, class T2>  //这里不能有分号
class Point{
public:
    Point(T1 x, T2 y): m_x(x), m_y(y){ }
public:
    T1 getX() const;  //获取x坐标
    void setX(T1 x);  //设置x坐标
    T2 getY() const;  //获取y坐标
    void setY(T2 y);  //设置y坐标
private:
    T1 m_x;  //x坐标
    T2 m_y;  //y坐标
};

template<class T1, class T2>  //模板头
T1 Point<T1, T2>::getX() const /*函数头*/ {
    return m_x;
}

template<class T1, class T2>
void Point<T1, T2>::setX(T1 x){
    m_x = x;
}

template<class T1, class T2>
T2 Point<T1, T2>::getY() const{
    return m_y;
}

template<class T1, class T2>
void Point<T1, T2>::setY(T2 y){
    m_y = y;
}

int main(){
    Point<int, int> p1(10, 20);
    cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;
    Point<int, char*> p2(10, "东经180度");
    cout<<"x="<<p2.getX()<<", y="<<p2.getY()<<endl;
    Point<char*, char*> *p3 = new Point<char*, char*>("东经180度", "北纬210度");
    cout<<"x="<<p3->getX()<<", y="<<p3->getY()<<endl;
    return 0;
}
```

`typename`关键字也可以使用`class`关键字替代，它们没有任何区别。C++ 早期对模板的支持并不严谨，没有引入新的关键字，而是用 class 来指明类型参数，但是 class 关键字本来已经用在类的定义中了，这样做显得不太友好，所以后来 C++ 又引入了一个新的关键字 typename，专门用来定义类型参数。

## STL-标准模板库

C++ 的`标准模板库（Standard Template Library，STL）`是泛型程序设计最成功应用的实例。

STL 是一些常用数据结构（如链表、可变长数组、排序二叉树）和算法（如排序、查找）的模板的集合