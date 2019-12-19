#include <iostream>
#include <exception>

using namespace std;

class CustomException : public exception
{
    public:
    const char *what() const throw()
    {
        return "This is CustomException";
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        throw CustomException();
    }
    catch (CustomException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
