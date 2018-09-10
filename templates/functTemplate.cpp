#include <iostream>

using namespace std;

template<int N>
void stars()
{
    printf("*");
    stars<N-1>();
}
template<>
void stars<0>()
{
}

int main(int argc, char const *argv[])
{
    stars<6>();
    cout << "hola " << endl;
    stars<4>();
    cout << "mundo" << endl;
    return 0;
}
