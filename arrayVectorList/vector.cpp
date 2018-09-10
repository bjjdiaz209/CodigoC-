#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void show(const T& x)
{
    for (auto& i:x)
    {
        cout << i << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> p = {6,8,4,2,1,9};

    p.push_back(12);
    size_t len = p.size();

    try
    {
        for (size_t i = 0U; i < len+100000; i++)
        {
            //cout << p[i] << endl;
            //el operador at verifica que tengamos los elementos
            cout << p.at(i) << endl;
            //at vota una excepsion del tipo std::out_of_bounds
        }
    }
    catch(const exception& ex)
    {
        cout << ex.what() << endl;
    }

    show(p);

    puts("#####");

    //este operador + y - para begin esta en vector, array, no en las listas
    for (auto i = p.begin() + 1; i!=p.end()-1;++i)
    {
        cout << *i<< endl;
    }
    return 0;
}