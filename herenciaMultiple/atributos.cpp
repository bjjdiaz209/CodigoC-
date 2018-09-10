#include <iostream>

using namespace std;

struct B1
{
    int x;
    int y;
};

struct B2
{
    int x;
    int h;
};

struct H1: B1, B2
{
    H1(int x, int y, int h)	//tiene 4 variables x,y x,h
    :B1{x, y}, B2{x, h}
    {
    }
};

int main(int argc, char const *argv[])
{
    H1 h{1,4,5};

    cout << h.B1::x << endl;
    cout << h.y << endl;
    cout << h.h << endl;
    cout << h.B2::x << endl;
    h.B2::x = 100;
    cout << h.B1::x << endl;
    cout << h.B2::x << endl;
}
