#include <iostream>

using namespace std;

template<class T>
void say_something(const T& x)
{
    cout << x << endl;
}//las espcializaciones siempre debajo
template<>
//es una especializacion lo que hace es usar
//esta especializacion para <float>
void say_something<float>(const float& n)
{
    if(n == 3.4f)
    {
        cout << "p" << endl;
    }
    else
    {
        cout << "no p" << endl;
    }
}

template<typename T>
T next(const T& n);
template<>
int next<int>(const int& n)
{
    return n+1;
}

int main(int argc, char const *argv[])
{
    say_something<int>(6);
    say_something<float>(3.14f);
    say_something<string>("hola");
    say_something((float)8);

    cout << next(6) << endl;
    //cout << next(8.15) << endl;
    return 0;
}
