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

    void insertAtEnd(int value)
    {
        // check is array has enough size
        if (length == capacity) {
 
            // if not then grow the array by double
            resize( length * 2);
        }

            //sets index length + 1 (end) to requested value
        data[length] = value;
        length++;
    }

    void insertAtIndex( int value , int index)
    {
        // check is array has enough size
        if (length == capacity) {
 
            // if not then grow the array by double
            resize( capacity * 2);}
        else if (index >= capacity) {

            // if index is not in capacity makes enough room for it to be there
            int new_index;

            cout << "index not in available scope" << endl;
            cout << "Choose a index <= " << length << " : " << endl;

            cin >> new_index;

            insertAtIndex(value , new_index);
            return;
        }

            //loop pushing all value in array already to the right of the index by one

            for (int i = length - 1; i >= index; i--) {
            data[i + 1] = data[i];

        }

        //sets request index to requested value
            data[index] = value;
            length++;

    }


        // Count elements with specific value
        int count(int x) {
            int count = 0;
            for (int i = 0; i < length; i++) {
                if (data[i] == x) count++;
            }
            return count;
        }

        // Delete at the beginning
        void deleteAtBeginning() {
            if (length == 0) return;
            for (int i = 0; i < length - 1; i++) {
                data[i] = data[i + 1];
            }
            length--;
        }

        // Delete at the end
        void deleteAtEnd() {
            if (length == 0) return;
            length--;
        }

        // Delete at a specific position
        void deleteAtPosition(int index) {
            if (index < 0 || index >= length) {
                throw std::out_of_range("Index out of range");
            }
            for (int i = index; i < length - 1; i++) {
                data[i] = data[i + 1];
            }
            length--;
        }

        // Delete a specific element
        void deleteElement(int x) {
            for (int i = 0; i < length; i++) {
                if (data[i] == x) {
                    deleteAtPosition(i);
                    return;
                }
            }
        }

        // Delete all occurrences of a specific element
        void deleteAll(int x) {
            int i = 0;
            while (i < length) {
                if (data[i] == x) {
                    deleteAtPosition(i);
                } else {
                    i++;
                }
            }
        }

        // Binary Search (Iterative)
        int binarySearchIterative(int x) {
            int low = 0, high = length - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (data[mid] == x) return mid;
                else if (data[mid] < x) low = mid + 1;
                else high = mid - 1;
            }
            return -1;
        }

        // Binary Search (Recursive)
        int binarySearchRecursive(int x, int low, int high) {
            if (high < low) return -1;
            int mid = low + (high - low) / 2;
            if (data[mid] == x) return mid;
            else if (data[mid] < x) return binarySearchRecursive(x, mid + 1, high);
            else return binarySearchRecursive(x, low, mid - 1);
        }

        // Helper function to initiate recursive binary search
        int binarySearchRecursive(int x) {
            return binarySearchRecursive(x, 0, length - 1);
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
    myArray.insertAtEnd(1);
    myArray.printArray();
     cout << endl;
    myArray.insertAtBeginning(4);
    myArray.printArray();
     cout << endl;
    myArray.insertAtEnd(6);
    myArray.printArray();
     cout << endl;
    myArray.insertAtIndex(3,4);
    myArray.printArray();
    cout << endl;
    myArray.insertAtEnd(5);
    myArray.printArray();
     cout << endl;



    return 0;
};