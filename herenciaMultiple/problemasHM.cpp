#include <iostream>

using namespace std;

class M
{
public:
    void p()
    {
    puts("M");
    }
};

class N
{
public:
    void p()
    {
    puts("N");
    }
};

class MN: public M, public N
{
public:
    /*
    void p()
    {
        puts("MN");	//hiding (ocultar)
    }
    */
};
int main(int argc, char const *argv[])
{
    M m;
    m.p();

    N n;
    n.p();

    MN mn;
    //mn.p();
    mn.M::p();
    mn.N::p();
}
