#include <set>
//es un arbo binario de busqueda equilibrado
//O(log2N)

#include <unorder_set>

#include <tuple>
#include <iostream>
using namespace std;
//contiene un elemento de un mismo tipo
//los elementos se pueden iterar
//se puede ver si el elemento esta en el set


struct alumno
{
    string name;
    int id;
};

struct less_alumno
{
    bool operator()(const alumno& a, const alumno& b) const
    {
        return a.name < b.name;
    }
};

int main(int argc, char const *argv[])
{
    //con functor
    //set<alumno, less_alumno> al;
    

    //con lambda
    auto f = [](auto& a, auto& b)
    {
        //tie(a.id, a.name)  devuelve
        //tuple<int&,string&>
        return tie(a.id, a.name) < tie(b.id, b.name);
    };
    set<alumno, decltype(f)> al{f};


    al.insert(alumno{"juan", 123});
    al.insert(alumno{"pedro", 456});
    al.insert(alumno{"jorge", 642});
    al.insert(alumno{"maria", 123});

    for (auto& a:al)
    {
        cout << a.name << " " << a.id << endl;
    }


    return 0;
}