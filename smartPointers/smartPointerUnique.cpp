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
        cout << "Bye" << endl;
    }

    void print() const
    {
        cout << n << endl;
    }
};

class Point
{
    unique_ptr<A> x;
    unique_ptr<A> y;
public:
    Point(int x, int y)
    : x(new A{x}), y (new A{y})
    {
        s();
    }

    ~Point()
    {
    }

    void print() const
    {
        x->print();
        y->print();
    }

    void s()
    {
        throw nullptr;
    }
};


struct closer
{
    void operator()(FILE* f)
    {
        if (f == nullptr) return; 
        fclose(f);
        cout << "Bye file" << endl;
    }
};

int main(int argc, char const *argv[])
{
    /*
    unique_ptr<FILE, closer> ar{fopen("abc.txt","w")};

    fputs("hello ", ar.get());
    fputs( "world", ar.get());
*/

    try{
        Point q{10, 20};
        q.print();
    }
    catch(...)
    {
        cout << "error" << endl;
    }

    return 0;
}