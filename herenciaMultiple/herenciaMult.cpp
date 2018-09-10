#include <iostream>

using namespace std;

class A
{
public:
    int x;
    A(){}
    ~A(){}
    void m()
    {
        puts("hello");
    }
};

class B
{
public:
    int y;
    B(){}
    ~B(){}
    void n()
    {
        puts("bye");
    }
};

class AB: public A, public B
{
public:
    AB(){}
    ~AB(){}
};

int main(int argc, char const *argv[])
{
    AB ab;
    ab.x = 1;
    ab.y = 2;
    cout << ab.x << endl;
    cout << ab.y << endl;
    ab.m();
    ab.n();
    return 0;
}
