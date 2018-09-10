#include <iostream>
#include <array>

using namespace std;

void show(const array<int, 3>& x)
{
    for (array<int,3>::const_iterator i = x.begin(); i != x.end(); ++i)
    {
        cout << *i << endl;
    }
}

void show2(const array<int, 3>& x)
{
    //auto=array<int, 3>::const_reverse_iterator
    for (auto i = x.rbegin(); i != x.rend(); ++i)
    {
        cout << *i << endl;
    }
}


int main(int argc, char const *argv[])
{
    array<int, 3> s;

    s[0] = 125;
    s[1] = 14;
    s[2] = 248;

    //cbegin sin importar en contexto
    for (array<int, 3>::iterator i = s.begin(); i != s.end(); ++i)
    {
        cout << *i << endl;
    }

    show2(s);

    return 0;
}