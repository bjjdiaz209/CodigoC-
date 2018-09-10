#include <iostream>
#include <cstdio>
#include <memory>

using namespace std;

struct  A
{
    int n;

    A(int n)
    :n(n){}
    ~A()
    {
        cout << "Bye: " << n << endl;
    }

    void print() const
    {
        cout << n << endl;
    }
};

void p(const A& x)
{
    x.print();
}

int main(int argc, char const *argv[])
{
    shared_ptr<A> a{new A{15}};

    auto b = make_shared<A>(18);
    auto c = make_shared<A>(100);
    auto d = make_shared<A>(50);

    auto e = a;
    auto f = b;

    b = make_shared<A>(168);
    f = make_shared<A>(168);

    auto g = c;

    p(*a);
    p(*b);
    p(*c);
    p(*d);
    p(*e);
    p(*f);
    p(*g);

/*
    auto a = new A(15);
    auto b = new A(18);
    auto c = new A(40);
    auto d = new A(18);
    auto e = a;
    auto f = b;

    b = new A(668);
    f = new A(269);

    auto g = c;

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;

*/
    return 0;
}