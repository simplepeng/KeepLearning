#include <iostream>
#include <string>

using namespace std;

class Person
{
  private:
    string _name;

  public:
    void eat()
    {
        cout << "增加我的卡路里" << endl;
    }
    string getName()
    {
        return _name;
    }
    void setName(string name)
    {
        _name = name;
    }
};

int main()
{
    Person person;
    person.eat();

    person.setName("zhang san");
    cout << person.getName() << endl;
    return 0;
}