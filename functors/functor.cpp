//Functors o function objects
//es un objeto de una clase normal que se invoca como si fuera una funcion;
#include <iostream>

using namespace std;


class incr
{
public:
    incr(){}
    ~incr(){}

    void operator()(int n) const//esto nos dice que es un functor
    {
        cout << (n + 1) << endl;
    }
};

int main(int argc, char const *argv[])
{
    incr p;

    //es como una funcion pero es un objeto
    p(16);//function-object

    return 0;
}
