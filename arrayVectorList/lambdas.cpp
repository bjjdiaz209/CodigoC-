#include <iostream>
#include <vector>
#include <memory>

#include <functional>//para reference_wrapper

using namespace std;


int main(int argc, char const *argv[])
{
    vector<int(*)(int, int)> ops;
    ops.push_back([](int a, int b){return a+b;});
    ops.push_back([](int a, int b){return a-b;});

    for (auto& op:ops)
    {
        cout << op(6, 4) << endl;
    }

/*
    any;
    varian<int, string, A>
    vector<variant<string, int, float>>
*/

/*
    //o tiene el valor o no tiene
    optional<int>
    

*/
    return 0;
}