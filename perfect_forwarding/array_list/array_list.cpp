#include <iostream>

using namespace std;

template<typename T>
class array_list
{
    T* items;
    size_t cap;
    size_t count;
public:
    array_list(size_t cap = 4)
    :items{new T[cap]}, cap{cap}, count{0}
    {}

    ~array_list()
    {
        delete[] items;
    }

    template<typename U>
    void push_back(U&& item)
    {
        resize();
        items[count++] = forward<U>(item);
    }

    void resize()
    {
        if (cap != count)
        {
            return;
        }
        size_t ncap = cap * 2;
        T* aux = new T[ncap];
        for (auto i = 0U; i < count; i++)
        {
            aux[i] = move(items[i]);
        }
        delete[] items;
        items = aux;
        cap = ncap;
    }

    template<class  U>
    void emplace_back(U&& x)
    {
        resize();
        items[count++] = T{forward<U>(x)};
    }

    

private:
    //array_list_iterator
    struct al_it
    {
        T* item_pos;

        bool operator!=(const al_it& src)
        {
            return item_pos != src.item_pos;
        }

        al_it& operator++()
        {
            item_pos++;
            return *this;
        }

        al_it operator++(int)
        {
            al_it n = {item_pos};
            item_pos++;
            return n;
        }

        T& operator*()
        {
            return *item_pos;
        }

        const T& operator*() const
        {
            return *item_pos;
        }
    };

public:
    //
    using iterator = al_it;

    iterator begin()
    {
        return iterator{items};
    }

    iterator end()
    {
        return iterator{items+count};
    }

};



int main(int argc, char const *argv[])
{
    array_list<string> p;
    p.push_back("hola");
    p.push_back("mundo");
    p.push_back("today");
    p.push_back("diez");

    //debemos implementar los operadores
    //==    ++i     i++     !=      

    for (auto& i : p)
    {
        cout << i << endl;
    }

    for (auto i = p.begin(); i != p.end(); ++i)
    {
        cout << *i << endl;
    }

    //
    //s.emplace_back("Septiembre");

    //cout << s[2] << "\n";


/*
    //copia
    string p = "agosto";
    s.push_back(p);
*/
    return 0;
}