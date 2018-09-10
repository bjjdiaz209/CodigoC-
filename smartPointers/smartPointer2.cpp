#include <iostream>
#include <memory>

using namespace std;


struct  A
{
    int n;

    A(int n)
    :n(n){}
    ~A()
    {
        cout << "Bye" << endl;
    }

    void print() const
    {
        cout << n << endl;
    }
};

int main(int argc, char const *argv[])
{
    //desde c++14
    auto c = make_unique<A>(4058);

    //unique_ptr<A> c{new A{2048}};

    c.get()->print();

    c->print();

    unique_ptr<A> d = move(c);
    d->print();

    if (c == nullptr)
    {
        cout << "null" << endl;
    }

    (*d).print();

    d.reset();
    cout << "September" << endl;

    return 0;
}