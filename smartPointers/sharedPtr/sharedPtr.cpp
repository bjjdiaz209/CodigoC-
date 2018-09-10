#include <iostream>
#include <memory>

using namespace std;

struct mama_de_marco;

struct  marco
{
    shared_ptr<mama_de_marco> mdm;

    ~marco()
    {
        cout << "No te vayas mama" << endl;
    }

    void hi()
    {
        cout << "hola mama" << endl;
    }
};

struct  mama_de_marco
{
    weak_ptr<marco> hijo;

    ~mama_de_marco()
    {
        cout << "adios marco" << endl;
    }
};

int main(int argc, char const *argv[])
{
    auto m = make_shared<marco>();
    auto mdm = make_shared<mama_de_marco>();

    m->mdm = mdm;
    mdm->hijo = m;
    //hijo es un wp y m es sp

    m->hi();

    //esto blckea la destruccion del hijo en la madre.. XD
    mdm->hijo.lock()->hi();

    return 0;
}