#include <iostream>

using namespace std;

struct MyObj
{
    char* p;

    MyObj()
    :p{new char[10000000]}
    {
        cout << "Create\n";
    }
    ~MyObj()
    {
        delete[] p;
        cout << "Delete\n";
    }

    MyObj(const MyObj& src)
    :p{new char[1000000]}
    {
        for (int i = 0; i < 100000; i++)
        {
            p[i] = src.p[i];
        }
        cout<<"Copied\n";
    }

    MyObj& operator=(const MyObj& src)
    {
        delete[] p;
        p = new char[1000000];
        for (int i = 0; i < 1000000; i++)
        {
            p[i] = src.p[i];
        }
        cout <<"=ed\n";
        return *this;
    }

    //move semantics
    MyObj(MyObj&& src)
    :p{src.p}
    {
        src.p = nullptr;
        cout <<"moved\n";
    }
};

MyObj create()
{
    return MyObj{};
}

int main()
{
    MyObj obj;
    obj = create();

    //MyObj obj = create();
    //copy elidsin
    //para evitar esta caracteristica 
    //g++ -o x.exe -std=c++11 -fno-elide-constructors
}
