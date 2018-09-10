#include <iostream>

using namespace std;

template<typename A, typename B, typename C>
struct Test
{
    A a;
    B b;
    C c;

    void show() const
    {
        cout << a << " " << b << " " << c << endl;
    }
};
template<typename X>
struct Test<int,X,int>// <x> esto nos ayuda a saber que es especializacion
{
    int x;
    X y;
    int z;

    void show() const
    {
        cout << (x+z) << " " << y << endl;
    }
};
template<>//<> especializacion total
struct Test<int,int,int>
{
    string s;
    void print() const
    {
        cout << s << endl;
    }
};

//SFINAE
//sustitusion failled in...

int main(int argc, char const *argv[])
{
    Test<int,int,string>test{1,6,"h"};
    test.show();

    Test<int,string,int>test2{6,"x",20};
    test2.show();

    Test<int,float,int>test3{8,3.4f,9};
    test3.show();

    Test<int,int,int>test4{"hola mundo"};
    test4.print();

    return 0;
}