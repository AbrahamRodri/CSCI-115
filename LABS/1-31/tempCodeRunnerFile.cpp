#include <iostream>
using namespace std;


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
        array = new int**[n];  //setting the first pointer of int*** array = to a dynamic array of int** pointers
        for (int i = 0; i < n; i++) {
            array[i] = new int*[m];
            for (int j = 0; j < m; j++) {
                array[i][j] = new int[l];
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

int main() {
    
    
 return 0;   
};