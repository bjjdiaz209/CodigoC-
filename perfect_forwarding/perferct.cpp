#include <iostream>
//perfect forwarding
using namespace std;

struct A
{
    A()
    {
        cout <<"ctor\n";
    }

    ~A()
    {
        cout << "bye\n";
    }

    A(const A& x)
    {
        cout << "copy\n";
    }

    A& operator=(const A& x)
    {
        cout << "=\n";
        return *this;
    }

    A(A&&)
    {
        cout << "move ctor\n";
    }

    A& operator=(A&&)
    {
        cout << "move =\n";
        return *this;
    }
};


struct B
{
    A a;

    template<typename T>
    B(T&& x)
    :a{forward<T>(x)}
    {
        cout << "ctorB\n";
    }
    /*//constructores de movida
    B(const A& x)
    :a{x}
    {
        cout << "ctorB\n";
    }

    B(A&& x)
    :a{move(x)}
    {
        cout << "move ctorB\n";
    }
    */
};

int main()
{
    //todas las clses que reciban contructor referencia deben tener 
    //dos constructores
    A a;
    B b{a};
    B c{A{}};
    cout << ":P\n";
    return 0;
}
