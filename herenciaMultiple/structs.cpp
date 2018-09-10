#include <iostream>
//Dreaded Diamond Problem
//problema del rombo temido
//se soluciona con herencia virtual
using namespace std;

struct R
{
    int x;
};

struct S1: R
{};

struct S2: R
{};

struct T: S1, S2
{};

int main(int argc, char const *argv[])
{
    T p;
    p.S1::x = 14;
    p.S2::x = 25;

    cout << p.S1::x << endl;
    cout << p.S2::x << endl;
}
