#include <iostream>

using namespace std;

template <typename T>
struct A
{
    T n;
    void show()const
    {
        cout << n << endl;
    }
};
template<typename T>//esto lo usa cuando se le pasa una referencia
struct A<T*>//A -> es distinto de: A<int*>
{
    T *n;
    void print() const
    {
        cout << *n << endl;
    }

    ~A(){
        cout << "des" << endl;
        delete n;
    }
};

struct  X
{
    int p = 8;
    X()
    {
        cout << "hola X" << endl;
    }

    ~X()
    {
        cout << "chau X" << endl;
    }
};

ostream& operator<<(ostream& os, const X& obj)
{
    os<< obj.p;
    return os;
}

int main(int argc, char const *argv[])
{
    A<int> a{614};
    a.show();

    A<string> b{"hola"};
    b.show();

    A<int*> c{new int{418}};
    c.print();

    A<X*> d{new X{}};
    d.print();

    return 0;
}