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



struct Heavy
{
    char* x;
    Heavy()
    :x{new char[10'000'000]}
    {
    }

    ~Heavy()
    {
        delete[] x;
    }

    Heavy(const Heavy& src)
    :x{new char[10'000'000]}
    {
        for (int i = 0; i < 10'000'000; i++)
        {
            x[i] = src.x[i];
        }
    }

    Heavy& operator=(const Heavy& src)
    {
        delete[] x;
        x = new char[10'000'000];
        for (int i = 0; i < 10'000'000; i++)
        {
            x[i] = src.x[i];
        }
        return *this;
    }

    Heavy(Heavy&& src)
    :x{src.x}
    {
        src.x = nullptr;
    }

    Heavy& operator=(Heavy&& src)
    {
        delete[] x;
        x = src.x;
        src.x = nullptr;
        return *this;
    }
};

MyObj create()
{
    return MyObj{};
}

template<typename T>
void my_swap(T& a, T& b)
{
    T aux = move(a);
    a = move(b);
    b = move(aux);
    /*
    T aux = a;
    a = b;
    b = aux;
    */
}

int main()
{
    Heavy obj;
    Heavy obj2;
    for (int i = 0; i < 1'000'000; i++)
    {
        my_swap(obj, obj2);
    }
    return 0;
}
/*
int main()
{
    MyObj obj;
    obj = create();

    //aca siempre se usa el constructor de movida
    //MyObj obj = create();

    //aca llama al constructor copia
    //MyObj obj1 = obj;

    //aca obligamos a usar el constructor de movida
    //MyObj obj2 = std::move();

    //MyObj obj = create();
    //copy elidsin
    //para evitar esta caracteristica 
    //g++ -o x.exe -std=c++11 -fno-elide-constructors
}*/
