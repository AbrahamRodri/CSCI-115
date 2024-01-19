//Create a function that takes an array a of size n as an input and return a boolean if there exists a value in the array superior to x, which is given as an input.

#include <iostream>
using namespace std;

bool f(int* a, int n, int x){
    for (int i = 0 ; i < n ; i++){
        if(a[i] > x){
            break;
        }
        return false;
    }
    return true;
}

int main() {

int n , x;

cout << "input a size:";

cin >> n ;

cout << "input a value:";

cin >> x;

int array[n]; 

for (int i = 0; i < n; ++i) {
        array[i] = 10;
    };

if (f(array,n,x)){
    cout << "true";
}

else cout << "false";

    return 0;
}