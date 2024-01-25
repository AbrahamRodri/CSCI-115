#include <iostream>
using namespace std;

class Array{
    private:

    int* data;
    int length;
    int capacity;

    void resize (int new_capacity){
        int* new_data = new int[new_capacity];

        for(int i=0; i < length ; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;

    
    }
    public: 

        Array(){
            length = 0;
            data = nullptr;
        }

        Array(int size){
            length = 0;
            capacity = size;
            data = new int[capacity];
        }

        ~Array(){
            delete[] data;
        }

        void insertAt(int index, int value)
    {
        // check is array having size to store element or
        // not
        if (length == capacity) {
 
            // if not then grow the array by double
            resize( length * 2);
        }
 
        for (int i = length - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
 
        data[index] = value;
        length++;
    }

        void printArray(){
            for (int i = 0; i < length; i++){
                cout << endl;
                cout << data[i];
            }
        }

    
};

int main(){

    Array myArray(4);

    myArray.insertAt(0,4);
    myArray.printArray();
    myArray.insertAt(0,4);
    myArray.printArray();
    myArray.insertAt(0,4);
    myArray.printArray();


    return 0;
};