#include <iostream>
#include <cstring>

using namespace std;

class Animal
{
public:
    size_t size;
    size_t edad;
};

class Perro:public Animal
{
public:
    char raza[16];
};

class P
{
public:
    int x;
public:
    P(int x)
    :x{x}
    {}

    //destructor virtual en la clase base
    virtual ~P()
    {}

    virtual void show() const
    {
        cout<<x<<endl;
    }
protected:
    size_t getX() const
    {
        return x;
    }
};

class Q final : public P
{
    int y;
public:
    Q(int x, int y)
    :P{x}, y{y}
    {}

    void show2() const
    {
        P::show(); // :: -> operador de ambito
        cout<<y<<endl;
    }

    void show() const override//HIDING -> ocultar metodos de la clse padre
    //override sirve para hacer explicito el virtual
    {
        cout<<getX()<<","<<y<<endl;
    }
};


int main(int argc, char const *argv[])
{
    /*En el heap*/
    //reserva memoria , llama al contructor
    P* pp = new P{25};
    pp->show();

    Q* qq = new Q{100,105};
    qq->show();

    P* pq = new Q{36,666};
    pq->show();	

    delete pp;
    delete qq;
    delete pq;

    /*En el stack*/
/*  P p{16};
    p.show();

    Q q{8, 14};
    q.show();
    q.show2();
    */
/*  Animal a{60, 5};
    cout<<a.size<<endl;

    Perro p;
    strcpy(p.raza, "chapi");

    cout<<p.raza<<endl;
    p.size = 40;

    cout<<p.size<<endl;
*/  return 0;
}