#include <set>
//es un arbo binario de busqueda equilibrado
//O(log2N)

#include <iostream>
using namespace std;
//contiene un elemento de un mismo tipo
//los elementos se pueden iterar
//se puede ver si el elemento esta en el set

int main(int argc, char const *argv[])
{
    set<string> ds;
    ds.insert("irving");
    ds.insert("mauricio");
    ds.insert("paolo");
    ds.insert("marco");
    ds.insert("rai");

    //for (auto e:ds)
    for (const string& e:ds)
    {
        cout << e << endl;
    }

    set<string>::iterator it = ds.find("asl");
    if (it == ds.end())
    {
        cerr << "not found" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    for (auto& e:ds)//O(N)
    {
        if (e == "mauricio")
        {
            cout << "si hay" << endl;
        }
    }

    auto ot = ds.erase("rai");

    cout << ot << endl;

    for (const string& e:ds)
    {
        cout << e << endl;
    }
    return 0;
}