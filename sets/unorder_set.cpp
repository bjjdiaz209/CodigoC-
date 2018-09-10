#include <unordered_set>

#include <iostream>
using namespace std;
//inserciones O(1)+m
//busquedas es O(1)
// es una tabla hash
//


struct alumno
{
    string nombre;
    int id;
};


//la eficiencia depende de el hash
struct alumno_hash
{
    size_t operator()(const alumno& s) const
    {
        //#include <unordered_ser>
        hash<string> hs;
        return (s.id*17) + hs(s.nombre);
    }
};

struct alumno_eq
{
    bool operator()(const alumno& a, const alumno& b) const
    {
        return tie(a.nombre, a.id) == tie(b.nombre, b.id);
    }
};


int main(int argc, char const *argv[])
{
    unordered_set<string>  ms;

    //ms.insert("alumno");
    ms.insert("alvaro");
    ms.insert("romulo");
    ms.insert("pablo");
    ms.insert("daniela");
    ms.insert("vivian");

    for(auto& m:ms)
    {
        cout << m << endl;
    }

    puts("sssssssssssssssssssssssss");


    //funcion que calcule el codigo hash de los alumons
    //funcion que compare dos alumnos
    unordered_set<alumno,alumno_hash,alumno_eq> al2;
    al2.insert(alumno{"jose", 123});
    al2.insert(alumno{"maria", 456});
    al2.insert(alumno{"jesus", 789});

    for(auto& a:al2)
    {
        cout << a.nombre << " " << a.id << endl;
    }

    auto i = al2.find(alumno{"jesus", 789});

    if (i == al2.end())
    {
        cerr << "not found" << endl;
    }
    else
    {
        cout << "found" << endl;
    }

    return 0;
}