#include <iostream>

using namespace std;

struct SeMueve
{
    void mover(int pos)
    {
        cout << "me movi " << pos << endl;
    }
};

struct Vuela
{
    void volar(int a)
    {
        cout << "vuelo " << a << endl;
    }
};

struct Come
{
    void comer(int kg)
    {
        cout << "como " << kg << " kgs.\n";
    }
};

struct Vaca: SeMueve, Come
{
    void darCarne(int kg)
    {
        cout << "doy " << kg << " kgs.\n";
    }
};

struct Paloma: SeMueve, Come, Vuela
{
};

struct Helicoptero: Vuela
{

};

void alimentar(Come& c)
{
    c.comer(10);
}

int main(int argc, char const *argv[])
{
    //probar typeid(c).name();
    Helicoptero h;
    Paloma p;
    Vaca v;
    h.volar(100);
    p.volar(200);
    p.mover(5);

    puts("***");

    alimentar(p);
    alimentar(v);

    return 0;
}
