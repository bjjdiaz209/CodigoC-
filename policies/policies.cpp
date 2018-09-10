#include <iostream>

using namespace std;

//HablarPolicy no es un tipo de dato es un comportamiento
template<typename HablarPolicy>
struct Primate
{
    HablarPolicy hablarPolicy;
    void  hablar() const
    {
        hablarPolicy.hablar();
    }
};

struct HumanoHablarPolicy
{
    void hablar() const
    {
        cout << "bla bla bla" << endl;
    }
};

struct MonoHablarPolicy
{
    void hablar() const
    {
        cout << "u u u" << endl;
    }
};

//cada vez que aparece using usamos lo que es igual
using Humano = Primate<HumanoHablarPolicy>;
using Mono = Primate<MonoHablarPolicy>;

int main(int argc, char const *argv[])
{
    Humano h;
    h.hablar();

    Mono m;
    m.hablar();
    return 0;
}