#include <iostream>

using namespace std;

template<typename T>
T sumar(const T& x, const T&y)
{
    return x + y;
}

template<typename T, typename...ARGS>
T sumar(const T& x, const ARGS&...args)
{
    return x + sumar(args...);
}

//T es un tipo
//ARGS es un conjunto de tipos
//ARGS => PARAMETER PACK
template<typename...ARGS>
//args => pack expansion
//args es una representacion de un conjunto de tipos
void sum(const ARGS&...args)
{
    //en sumar(args...)  args se expande
    cout << sumar(args...) << endl;
}





void show()
{
}

template<typename T, typename...ARGS>
void show(const T& p, const ARGS&...args)
{
    cout << p << endl;
    show(args...);// << endl;
}




string join(const string& , const string& cad)
{
    return cad;
}

template<typename...ARGS>
string join(const string& sep, 
            const string& w,
            const ARGS&...args)
{
    return w + sep +join(sep, args...);
}

int main()
{
/*
    sum(6, 8);
    sum(6.34, 8.95);

    sum(6, 9, 2);

    sum(5.4, 9.81, 2.16);

    sum(1, 2, 3, 4, 5, 6);
*/
    //-O0
    //-O2
    //-O3
//    show(6, 8, true, "hola");
  //  show("hola", "mundo", 26, "hello");

    string p = join(",", "Juan", "Pedro", "Jose", "Maria");
    cout << p << endl;

    return 0;
}
