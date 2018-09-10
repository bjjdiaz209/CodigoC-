#include <iostream>
#include <list>


/*
vector                      lista

push_back O(1)              O(1)
push_front ----             O(1)
[]          O(1)            ---
remove elem O(N)            O(1)
insert elem O(N)            O(1)

memory footprint v           x
cache            v           x          //acceso

al final el vector es mas rapido

evitar heredar de std::
porque sus destructores no son virtuales
*/

using namespace std;

template<typename T>
void show(const T& x)
{
    for (auto& i:x)
    {
        cout << i << endl;
    }
}

int main(int argc, char const *argv[])
{
    list<string> dd = {"tuesday", "wednesday", "thursday"};

    dd.push_back("friday");
    dd.push_front("monday");

    cout<< dd.back() << endl;
    cout<< dd.front() << endl;

    dd.pop_front();
    dd.pop_back();

    cout<< dd.back() << endl;

    puts("ssssssssss");

    show(dd);


    return 0;
}