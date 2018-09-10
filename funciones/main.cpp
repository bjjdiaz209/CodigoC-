#include <iostream>
#include "myfuncs.h"
#include "myfuncs.h"

using namespace std;

int main(){
    cout<<"Ingrese un numero: ";
    double n;
    cin>>n;
    bool x = isEven(n);
    bool y = isPrime(n);
    long long z = myround(n);

    int r = factorial(n);

    cout<<"Es: "<<z<<"\n";
}
/*
int factorial(int n){
    int res=n;
    if(n<=1){
        return res;
    }
    else{
        return res*factorial(n-1);
    }
}
*/
/*
int factorial(int n){
        int s=1;
        for(int i=2; i<=n; i++){
                s*=i;
        }
        return s;
}
*/
