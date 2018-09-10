#include <iostream>

using namespace std;

//no hay finally

//unique_ptr<>

struct wint //wraper int
{
    int* s;

    ~wint()
    {
        delete s;
        cout << ";P" << enld;
    }
};

int main(int argc, char const *argv[])
{
    int* s = nullptr;
    try
    {
        wint s{new int{10}};  //s es una variable de stack
        throw 2;
    }
    catch(...)
    {
        cerr << "Leak: " << endl;
    }
    return 0;
}
