#include <iostream>

using namespace std;

string internal_join(const string& w, const string& sep, const string& b)
{
    cout << "X" << b << endl;
    string aux;
    aux = b;
    return aux;
}

template<typename...ARGS>
string internal_join(const string& w, const string& sep, const ARGS&...args)
{
    cout << "IJ: " << " " << w << " " << sep << " " << "" << endl;
    string aux;
    aux = w + internal_join(args...);
    return aux;
}

template<typename...ARGS>
string join(const string& sep, const string& w, const ARGS&...args)
{
    string aux = "";
    cout << w << " " << sep << endl;
    aux = w + sep;
    aux = aux + internal_join(args...);
    return aux;
}

int main()
{
    string p = join(",", "Juan", "Pedro", "Jose", "Maria");
    cout << "P: " << p << endl;

    return 0;
}
