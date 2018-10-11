#include <iostream>
#include <string>

using namespace std;

class Person
{
  public:
    Person();
    Person(string name);
    ~Person();
};

Person::Person()
{
    cout << "执行了构造函数" << endl;
}

Person::Person(string name)
{
    cout << "执行了带参数构造函数" << endl;
}

Person::~Person()
{
    cout << "执行了析构函数" << endl;
}

int main(int argc, char const *argv[])
{
    Person p;
    Person p1("zhang san");
    return 0;
}
