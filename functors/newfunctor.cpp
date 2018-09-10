#include <iostream>

using namespace std;
using namespace std::string_literals;//desde c++14

int cint(int x, int y)
{
    return x-y;
}

int cstr(string x, string y)
{
    return x.compare(y);
}

template<typename T, typename PROC>
//void msort(const T& a, const T& b, int(*p)(T a, T b))//aca se usa puntero a funcion
void msort(const T& a, const T& b, PROC p)//aca se usa un tipo de dato cualquiera
{
    if(p(a,b) < 0)
    {
        cout << a << endl;
        cout << b << endl;
    }
    else
    {
        cout << b << endl;
        cout << a << endl;
    }
}

template<typename T>
struct mcomp
{
    bool asc;

    int operator()(const T& a, const T& b) const
    {
        if (a == b)
        {
            return 0;
        }
        if (asc)
        {
            return a < b ? -1:1;
        }
        return b < a ? -1:1;
    }
};

int main(int argc, char const *argv[])
{
    msort(9, 6, cint);//recibe dos enteros y un puntero a una funcion
    puts("---");
    msort("hola "s, "amigos "s, cstr);

    mcomp<int> c1{true};
    msort(16, 14, c1);//aca le pasamos dos enteros pero este objeto se comporta como si fuera un funcion con un estado

    mcomp<string> c2{false};
    msort("gatos"s, "perros"s, c2);//("hola"s) esto es un string
    return 0;
}
