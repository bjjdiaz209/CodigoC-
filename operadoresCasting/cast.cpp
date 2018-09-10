#include <iostream>

using namespace std;

struct P
{
    virtual ~P()
    {}

    virtual void show() const = 0;
};

struct Q: P
{
    int n;
    Q(int n)
    :n{n}
    {}

    void show() const override
    {
        cout << n << endl;
    }

    string to_string() const
    {
        return std::to_string(n);
    }
};

struct R: P
{
    string s;
    R(const string& s)
    :s{s}
    {}

    void show() const override
    {
        cout << s << endl;
    }
};

void do_something(P& p)
{
    p.show();

    try
    {
        //instanceOf
        //si es puntero y no puede castear devueve nullptr
        //si es referencia y no puede caster devuelve una excepion
        Q& q = dynamic_cast<Q&>(p);
        cout << "TS: " << q.to_string() <<endl;
    }
    catch(...)
    {
        cout << "Bad_cast" << endl;
    }
    /*
    if(q == nullptr)
    {
        cout <<"NO to_string()\n";
    }
    else
    {
        cout << "TS: " << q->to_string() <<endl;
    }*/
}

int main(int argc, char const *argv[])
{
    P *q = new Q{114};
    P *r = new R{"hola"};

    do_something(*r);
    do_something(*q);
}
