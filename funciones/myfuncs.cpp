#include <math.h>
class A{
};

bool isEven(int n){
    bool res = false;
    if(n%2 == 0){
        res = true;
    }else{
        res = false;
    }
    return res;
}

bool isPrime(int n){
    for(int i=2; i<n/2; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

long long myround(double n){
    return llround(n);
}

int factorial(int n){
        int res=n;
        if(n<=1){
                return res;
        }
        else{
                return res*factorial(n-1);
        }
}

