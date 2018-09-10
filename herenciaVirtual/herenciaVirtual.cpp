#include <iostream>
#include <string>

using namespace std;

class A
{
    int n;
public:
    A(int n)
    :n{n}
    {
        cout << "A: " << n << "\n";
    }

    virtual ~A()
    {}
};

class X: public virtual A
{
public:
    X()
    :A(843)
    {}
};

class B: public virtual A
{
    string s;
public:
    B(const string& s)
    :A{321}, s{s}
    {
        cout << "B\n";
    }
};

class C: public virtual X, public virtual B
{
public:
    C()
    :A(400), X(), B{"hola"}
    {

    }
};

int main(int argc, char const *argv[])
{
    A* a = new C();
    delete a;
}
