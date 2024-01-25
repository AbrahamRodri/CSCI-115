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

        void insertAtBeginning( int value)
    {
        // check is array has enough size
        if (length == capacity) {
 
            // if not then grow the array by double
            resize( length * 2);
        }
            //loop pushing all value in array already to the right by one
        for (int i = length - 1; i >= 0; i--) {
            data[i + 1] = data[i];
        }
            //sets index 0 (beginning) to requested value
        data[0] = value;
        length++;
    }

        void printArray(){
            for (int i = 0; i < length; i++){
                cout << data[i];
            }
        }

    
};

int main(){

    Array myArray(4);

    myArray.insertAtBeginning(2);
    myArray.printArray();
    cout << endl;
    myArray.insertAtBeginning(3);
    myArray.printArray();
     cout << endl;
    myArray.insertAtBeginning(4);
    myArray.printArray();
     cout << endl;


    return 0;
};