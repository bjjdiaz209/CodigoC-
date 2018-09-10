#include <iostream>

using namespace std;

//usamos realloc cuando T es POD

struct CI
{
    string n;
    string city;
};

template<class T>
struct eq
{
    bool are_equal(const T& a, const T& b) const
    {
        return a == b;
    }
};
struct CIeq
{
    bool are_equal(const CI& x, const CI& y) const
    {
        return x.n == y.n && x.city == y.city;
    }
};
template<typename T>
struct  eq<T*>
{
    bool are_equal(const T* a, const T* b) const
    {
        eq<T> cmp;
        return cmp.are_equal(*a,*b);
    }
};


template<typename T>
struct deleter
{
    void free(const T&)
    {

    }
};
template<typename T>
struct deleter<T*>
{
    void free(T* obj)
    {
        delete obj;
    }
};


//EQ=eq<T>     si no usamos EQ entonces EQ tomara el valor de T
template<typename T, typename EQ=eq<T>, typename DELETER=deleter<T>>
class array_list
{
    size_t count;
    size_t cap;
    T* items;
public:
    array_list(size_t cap = 4)
    :count{0}, cap{cap},items{new T[cap]}
    {
    }

    ~array_list()
    {
        DELETER d;
        for(auto i = 0U; i<count; i++)
        {
            d.free(items[i]);
        }
        delete []items;
    }

    void push_back(const T& obj)
    {
        if (count == cap)
        {
            resize();
        }
        items[count] = obj;//esto puede llamar al operador= de string
        count++;
    }
private:
    void resize()
    {
        auto heap = cap*2;
        auto nitems =new T[heap];
        for(auto i= 0U; i < count; i++)
        {
            nitems[i] = items[i];
        }
        cap = heap;
        delete []items;
        items = nitems;
    }
public:
    int index_of(const T& obj) const
    {
        EQ eq;
        for(auto i = 0U; i < count; i++)
        {
            if(eq.are_equal(obj,items[i]))//items[i] == obj)
            {
                return i;
            }
        }
        return -1;
    }
};

struct P
{
    int n;
    ~P()
    {
        puts("bye P");
    }
};
template<>
struct  eq<P>
{
    bool are_equal(const P& a, const P& b) const
    {
        return a.n == b.n;
    }
};


template<typename T>
class R
{
public:
    //template<typename T>
    void show(const T& x)
    {
        cout << "x: " << x << endl;
    }//no funciona especializacion de funciones
    /*
    template<>
    void show<double>(const double& x)
    {
        cout << "double" << x << endl;
    }*/
};
template<>
class R<double>
{
public:
    void show(double d)
    {
        cout << "x double: " << d << endl;
    }
};

int main(int argc, char const *argv[])
{
    array_list<CI, CIeq> q{2};
    //array_list<CI> q{2};
    q.push_back(CI{"1248564", "lp"});
    q.push_back(CI{"1248588", "pt"});
    q.push_back(CI{"1248523", "cb"});

    array_list<int> x;
    x.push_back(15);
    x.push_back(18);
    x.push_back(45);
    x.push_back(4);
    x.push_back(2);
    x.push_back(1);

    auto pos = x.index_of(2);
    auto pos1 = q.index_of(CI{"1248523", "cb"});
    if(pos != -1)
    {
        cout << "pos: " << pos << endl;
        cout << "pos1: " << pos1 << endl;
    }
    else
    {
        cout << "not found" << endl;
    }


    array_list<int*> a;
    a.push_back(new int{6});
    a.push_back(new int{8});
    a.push_back(new int{14});

    array_list<P*> ps;
    ps.push_back(new P{1});
    ps.push_back(new P{2});

    int c = 14;
    auto idd = a.index_of(&c);
    cout << "pos idd: " << idd << endl;

    P d{1};
    auto ide = ps.index_of(&d);
    cout << "hi " << ide << endl;

    /*
    R r;
    r.show(6);
    r.show("hello world");
    r.show(3.14);
    */
    R<int> r;
    r.show(10);
    R<double> dou;
    dou.show(3.14);
    return 0;
}