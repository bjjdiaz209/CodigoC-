#include <iostream>
#include <string>
#include <string>
//generic programing
//plantillas
//puede existir metodos template dentro cada template
using namespace std;

//se puede colocar enteros, no soporta double
template<int N>
void stars()
{
    for(int i = 0; i < N; i++)
    {
        printf("*");
    }
    puts(" ");
}

int main(int argc, char const *argv[])
{
    constexpr int r = 5;    //constexpr le dice al compilador que es una constante
    stars<r>(); //stars<r>  tiene que ser conocido en tiempo de compilacion
    puts("Hello");
    stars<6>();
    return 0;
}
