#include <iostream>

using namespace std;
/*
    no se puede agarrar excepciones 
    de operaciones aritmeticas
    memory leaks
*/

struct A
{
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "bye A" <<endl;
    }
};

void z()
{
    /*
    int x = 2;
    int y = 0;

    //cuando hay un error de aritmetica el programa muere
    cout << (x/y) << endl;  //en windows SEH exceptions
    */

    //int* y = nullptr;
    //*y = 4;
    //throw "hola"; //ecepcion const char*
    throw 4;
    /*
    try
    {
        cout << "exc" << endl;
        throw 1;  //retorna hata donde ocurrio catch
    }
    catch(...){
        cout << "z catch" << endl;
    }*/
}

void y()
{
    try
    {
        cout << "oops" << endl;
        z();
        cout << "ID ID IT again" << endl;
    }
    catch(const char* s)
    {
        cerr << "Error: " << s << endl;
    }
}

void x()
{
    y();
    cout << "ufff" << endl;
}

int main(int argc, char const *argv[])
{
    //A* a = nullptr;
    try
    {
    //si una variable es concreta el compilador se encarga de borrarla
    A a;  //RAII
    //a = new A();
    x();
    }
    catch(const int x)
    {
        cerr << "Error codigo: " << x << endl;
    }
    catch(...)
    {
        cerr << "Unknow error" << endl;
        //delete a;
    }

      cout << "bye" << endl;

    // x();
    return 0;
}
