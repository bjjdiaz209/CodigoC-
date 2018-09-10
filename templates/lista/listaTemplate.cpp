#include <iostream>
#include <string>

using namespace std;

template<typename U>
struct linked_list_node
{
    U elem;
    linked_list_node<U> * next;
};

//final nos dice que esta clase no se puede heredar
template<typename T>
class linked_list final
{
    linked_list_node<T>* first;
    linked_list_node<T>* last;
public:
    linked_list()
        :first{nullptr}, last{nullptr}
    {}

    //si mi destructor no es virtual 
    //entonces el que herede de esta clase
    //todas sus hijas no se podran destruir
    ~linked_list()
    {
        auto aux = first;
        while(aux)
        {
            auto next = aux->next;
            delete aux;
            aux = next;
        }
    }
    void push_back(const T& obj)
    {
        //es de tipo de auto es linked_list_node<T>*
        auto new_node = new linked_list_node<T>{obj, nullptr};
        if(first == nullptr)
        {
            first = last = new_node;
            return;
        }
        last->next = new_node;
        last = new_node;
    }

    //f es un puntero a una funcion
    void iterate(void (*f)(T))
    {
        auto aux = first;
        while(aux)
        {
            f(aux->elem);
            aux = aux->next;
        }
    }
};

template<typename X>
void show(X x)
{
    cout << x << endl;
}

int main(int argc, char const *argv[])
{
    linked_list<int> x;
    x.push_back(12.3);
    x.push_back(20);
    x.push_back(12);
    x.push_back(18);
    //aca se hace un puntero a una funcion
    x.iterate(show<int>);

    puts("-----");

    linked_list<string> y;
    y.push_back("hola");
    y.push_back("hola otra vez");
    y.iterate(show<string>);
    return 0;
}
