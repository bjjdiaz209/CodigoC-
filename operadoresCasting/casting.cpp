#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    //en C:
    /*
    int x = (int) 3.14;
    int* y = &x;
    long long z = (long long) y;
    char* p = (char*)"hola";
    */
    //cout << p << endl;

    //en C++:
    //no tienen costo
    //static_cast se evalua en tiempo de compilacion
    //barato en tiempo de ejecucion
    int x = static_cast<int>(3.14);

    //punteros a enteros enteros a punteros
    int* y = &x;
    long long z = reinterpret_cast<long long>(y);

    //convierte algo en constante y viceversa
    char* p = const_cast<char*>("hola");

    //tiene un costo en tiempo de ejecucion
    //dynamic_cast	se evalua en tiempo de ejecucion
}
