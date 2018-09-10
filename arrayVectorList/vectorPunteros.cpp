#include <iostream>
#include <vector>
#include <memory>

#include <functional>//para reference_wrapper

using namespace std;

struct  P
{
    int n;

    P(int n)
    :n(n)
    {
    }

    ~P()
    {
        cout << "bye" << endl;
    }

};

int main(int argc, char const *argv[])
{
    vector<unique_ptr<P>> x;

    x.emplace_back(new P{10});
    x.emplace_back(new P{15});


    //el elemento en la posision 1 es un unique pointer
    //hacer move si queremos usarlo
    auto& q = x[1];
    cout << q->n << endl;


    //vector<P&> rx;
    vector<reference_wrapper<P>> rx;


    for(auto& i:x)
    {
        rx.push_back(*i);
    }

    for (auto& i:rx)
    {
        //cout << i.get().n << endl;
        cout << static_cast<P&>(i).n << endl;
    }
    /*
    x.emplace_back(new P(15));

    */

    return 0;
}