#include <iostream>

using namespace std;

//usamos realloc cuando T es POD

struct CI
{
    string n;
    string city;
};

struct P
{
    int n;
    ~P()
    {
        puts("bye P");
    }
};

template<class T>
struct are_equal
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
    bool are_equal(T* a, T* b) const
    {
        return*a = *b;
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
///


///
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




int main(int argc, char const *argv[])
{
    //para soportar polimorfismo deben ser punteros
    //arraylist eliminar arraylist punteros
    array_list<int*> a;
    a.push_back(new int{6});
    a.push_back(new int{8});
    a.push_back(new int{14});

    array_list<P*> ps;
    ps.push_back(new P{1});
    ps.push_back(new P{2});

    int c = 14;
    auto idd = a.index_of(&c);
    cout << idd << endl;
    return 0;
}