#include <iostream>

using namespace std;

struct X
{
    X()
    {
        puts("Im X");
    }
};

struct Y
{
    int n;
    Y(int n)        //Y(int n = 0)
    :n{n}
    {
        puts("Im Y");
    }
};

struct Z: X, Y
{
    Z()             //llama a todos los constructores
    :X{}, Y{1240}  //hay que inicializar todos en orden
    {}
};

int main(int argc, char const *argv[])
{
    Z z;
    cout << z.n << "\n";
}
