#include <iostream>
//Smartpointer
//Es una variable de stack
//Implementa el operador ->
//Tiene alguna politica de manejo structurado de memoria

using namespace std;

template<typename T>
class wrapper
{
    T* item;

public:
    wrapper(T* item)
    :item{item}
    {
    }
    
    ~wrapper()
    {
        delete item;
    }
    
    T* get()
    {
        return item;
    }

    T* operator ->()
    {
        return item;
    }

    //no permite constructor copia
    wrapper(const wrapper<T>&) = delete;

    wrapper(wrapper<T>&& src)
    :item(src.item)
    {
        src.item = nullptr;
        cout << "moved" << endl;
    }
};

struct  A
{
    int n;

    A(int n)
    :n(n){}
    ~A()
    {
        cout << "Bye" << endl;
    }

    void print() const
    {
        cout << n << endl;
    }
};

int main(int argc, char const *argv[])
{
    wrapper<A> w{new A{155}};

    w.get()->print();

    //smart pointer
    w->print();

    wrapper<A> b = move(w);
    b->print();

    return 0;
}