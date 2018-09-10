#include <iostream>
#include <stdexcept>

using namespace std;
//std::exception


class my_exception: public std::exception
{
public:
    my_exception(){}
    ~my_exception(){}

    //si el programa no bota una excepcion el programa termina
    const char* what() const noexcept override
    {
        return "Today is wendsday";
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        cout << "hola" << endl;
        throw my_exception{};
    }
    catch(const exception& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}

//exceptions in c++.....
//bad cast      ->
//bad alloc     -> hacer new  y no hay memoria
//out of range  ->

