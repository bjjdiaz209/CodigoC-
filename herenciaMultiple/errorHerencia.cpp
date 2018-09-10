#include <iostream>

using namespace std;

struct X
{
    int p;
    virtual void doSomething() = 0;
};

struct Y: public virtual X
{
    void doSomething() override
    {
        puts("Ooops");
    }
};

struct Z: public virtual X
{
    void doSomething() override
    {
        puts("Ooops   ZZZZZZZZZZ");
    }
};

struct ZZZ: public virtual Y, public virtual Z
{
    void doSomething() override
    {
        puts("Hello from dev 26");
    }
};

int main(int argc, char const *argv[])
{
    //ZZZ z;
    //z.doSomething();
    X* x = new ZZZ();
    Y* y = new Y();
    Z* z1 = new Z();
    ZZZ* z2 = new ZZZ();

    x->doSomething();
    y->doSomething();
    z1->doSomething();
    z2->doSomething();
    x->p = 8;

    return 0;
}
