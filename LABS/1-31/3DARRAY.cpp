#include <iostream>
using namespace std;
#include <cmath>


class ThreeDArray {
private:
    int n, m, l;
    int*** array; //Pointer to Array of int** , each element is a page, (contains address of first element)

public:
    ThreeDArray(int n, int m, int l) {
        this->n = n; //Makes sure that it is assigning the member variables using the local variable since same name
        this->m = m;
        this->l = l;

        // Allocate memory for a 3D array of size n x m x l
        array = new int**[n];  //setting the first pointer of int*** array = to a dynamic array of int** pointers (Array of "sheets" has adress of first one)
        for (int i = 0; i < n; i++) {
            array[i] = new int*[m]; //Populate each sheet with array of row pointers
            for (int j = 0; j < m; j++) {
                array[i][j] = new int[l];//Populate each row with int pointer 
            }
        }
    }

    ~ThreeDArray() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                delete[] array[i][j];
            }
            delete[] array[i];
        }
        delete[] array;
    }
};

class Part1 {

private: 

public: 

    int function1Iterative (){

        int sum = 0;
        int i = 0;

        for ( ; i <= 100 ; ++i){

            sum += (2 * i + 9);

        }

        return sum;

    };

    int function1Recursive( int sum , int i ){

        sum += (2 * i + 9);

        if(i == 100){
            return sum;
        }

        return function1Recursive(sum , ++i);  

    };

    int function2Iterative (){

        int sum = 1;
        int i = 1;

        for ( ; i <= 100 ; ++i){

            sum *= (5*i^3 + i^2);

        };

        return sum;

    };

    int function2Recursive ( int sum , int i ){

        sum *= (5*i^3 + i^2);

        if ( i == 100 ){

            return sum;

        };

        return function2Recursive ( sum , ++i );

    };

    double function3Iterative (){

        double sum = 0;
        int i = 1;

        for ( ; i <= 500 ; ++i){

            sum += pow ((5 * i),-0.5);

        };

        return sum;

    };

    double function3Recursive ( double sum , int i ){

        sum += pow ((5 * i),-0.5);

        if( i == 500 ){

            return sum;

        };

        return function3Recursive( sum , ++i );

    };




};

int main() {

    Part1 obj;

    cout << obj.function1Iterative() << endl;
    cout << obj.function2Iterative() << endl;
    cout << obj.function3Iterative() << endl;
    cout << obj.function1Recursive( 0 , 0 ) << endl;
    cout << obj.function2Recursive( 1 , 1 ) << endl;
    cout << obj.function3Recursive( 0 , 1 ) << endl;
    
 return 0;   
};