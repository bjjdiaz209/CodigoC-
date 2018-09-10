#include <iostream>

using namespace std;

struct ME //main exception
{
    int n;

    ~ME()
    {
        cout << "bye ex" << endl;
    }
};

void m()
{
    cout << "hola" << endl;
    throw ME{18};
}

int main(int argc, char const *argv[])
{
    try
    {
        m();
    }
    catch(const ME &ex) //el compilador se encarga de eliminar
    {
        cerr << "Error: " << ex.n << endl;
        //delete ex;
    }
    return 0;
}
