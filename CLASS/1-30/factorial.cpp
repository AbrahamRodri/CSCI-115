#include <iostream>
using namespace std;
#include <cmath>

int f(int n){

    int sum = 1;

    if(n==0){
        return 0;
    }
    
    else{

    for(int i = n; i > 1 ; i--){

        sum *= i;

    }
    

    return sum;
}
}

int recursiveFactorial (int n){
    int sum;
    if(n == 0 ){
        sum = 1;
    }
    else {
        sum = sum * recursiveFactorial(n - 1);
    }

    return sum;
}

int main(){

    cout << f(6) << endl;

    return 0;
}