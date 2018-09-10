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

    template<typename...ARGS>
    void emplace_back(const ARGS&&...args)
    {
        resize();
        //parameter pack expansion
        //fordward(),fordward(),fordward()
        items[count++] = T{forward<ARGS>(args)...};
    }

    /*
    template<class  U>
    void emplace_back(U&& x)
    {
        resize();
        items[count++] = T{forward<U>(x)};
    }
    */

    T& operator[](size_t index)
    {
        return items[index];
    }

    const T& operator[](size_t index) const
    {
        return items[index];
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

//  using type = T;
    using type = T;
};

struct Point
{
    int x, y;
};

template<typename T>
void info(const T& x)
{
    typename T::type aux;
    cout << "type: " << aux << endl;
}

int main(int argc, char const *argv[])
{
    array_list<Point> pts;

    pts.push_back(Point{6, 8});
    pts.push_back(Point{12, 2});
    pts.push_back(Point{10, 2});

    //pts.emplace_back(125, 180);
/*
    for (auto& p:pts)
    {
        cout << p.x << ";" << p.y << endl;
    }
*/
    //info(pts);

    array_list<string> q;
    info(q);

    array_list<int> r;
    info(r);

    return 0;
}