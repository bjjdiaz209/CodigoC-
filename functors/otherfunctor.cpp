#include <iostream>

using namespace std;

//pred -> predicado
//template<typename T>
//void show(const T* arr, size_t n, bool(*pred)(const T&))
template<typename T, typename PRED>
void show(const T* arr, size_t n, PRED pred)
{
    for (auto i = 0U; i < n; i++)
    {
        if(pred(arr[i]))
        {
            cout << arr[i]<< endl;
        }
    }
}


struct empieza_con
{
    char c;
    bool operator()(const string& s) const
    {
        return s[0]==c;
    }
};

bool empieza_con_m(const string& s)
{
    return s[0] == 'm';
}

int main(int argc, char const *argv[])
{
    string p[]={"enero", "febrero", "marzo", "abril", "mayo"};

    show(p, 5, empieza_con_m);

    empieza_con ec{'e'};
    show(p, 5, ec);

    puts("*****");
    //funcion anonima => lambda expression
    //esto es puntero a funcion
    show(p, 5, [](const auto& s)//[] le dice al compilador que es una funcion anonima
        {//desde c++14 se puede colocar auto
            return s.length() >= 5;
        });

    puts("*****");

    auto n = 0U;
    //[=] esto pasa todo lo que esta afuera de la funcion
    //[&] esto pasas todas variables que estan declaradas
    //[&n] esto pasa solamente la variable &n 
    //esto es fucntor
    show(p, 5, [&n](const auto& s)//[&n]closure.. esto pasa la variable n al puntero a la funcion
        {
            if(s[s.length()-1] == 'o')
            {
                n++;
                return true;
            }
            return false;
        });
}
