#include <iostream>
#include <string>
//generic programing
//plantillas
//puede existir metodos template dentro cada template
using namespace std;

//debe ir junto a su funcion
template<typename T, typename U>    //typename es un tipo
//template<class T>     //class es lo mismo
auto sum(const T& a, const U& b)  //desde c++14
//    ->decltype(a+b) //desde c++11
{
    cout << "XD" << endl;
    return a + b;
}

struct N
{
    int n;
    N operator+(const N& src) const
    {
        return N{n + src.n};
    }
};



/*
int sum(int a, int b)
{
    return a + b;
}

double sum(double a, double b)
{
    return a + b;
}
*/
int main(int argc, char const *argv[])
{
    //sumar dos numeros
    //auto p = sum(8, 10);

    //double q = sum(3.14, 8.16);
/*
    auto s = sum(6.5, 8.5);

    cout << s << endl;*/
/*
    cout << p << endl;
    cout << q << endl;
*/
    //string a = "hola";
    //string b = " mundo";
    //auto m = sum(a, b);

    //auto m = sum<string, string>("hola", " mundo");
    //cout << m << endl;

    N x = sum(N{10}, N{11});
    cout << x.n << endl;
    return 0;
}
