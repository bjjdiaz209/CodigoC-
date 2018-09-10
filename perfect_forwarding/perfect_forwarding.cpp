#include <iostream>
//perfect forwarding
using namespace std;

struct person
{
    string fn;
    string ln;
};

void print(const string& s)
{
    cout << s << "\n";
}


void inc(int& n)
{
    n++;
}

void print2(int n)
{
    cout << n << "\n";
}

template<typename PROC, typename T>
void invoke(T&& src, PROC p)
{
    cout << "*****\n";
    //forward se encarga de transformar src al tipo original
    p(forward<T>(src));
    cout << "*****\n";
}

int main()
{
    invoke("hola ", print);
    int p = 18;
    invoke(p, inc);
    cout << p << "\n";
    invoke(14, print2);
    invoke("g++"s, print2);
    return 0;
}
