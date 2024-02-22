#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to generate random array of given size
vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, n * 10);
    generate(arr.begin(), arr.end(), [&]() { return dis(gen); });
    return arr;
}

// Function to permute 10% of the elements
void permuteElements(vector<int>& arr) {
    int n = arr.size();
    int numElementsToPermute = n / 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, n - 1);

    for (int i = 0; i < numElementsToPermute; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        swap(arr[idx1], arr[idx2]);
    }
}

// Function to check if array is sorted
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to run sorting algorithms and measure time
void runSortAlgorithms(int n, vector<int>& arr) {
    auto start = high_resolution_clock::now();
    selectionSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    insertionSort(arr);
    stop = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    bubbleSort(arr);
    stop = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop - start);

    cout << "n = " << n << endl;
    cout << "Selection Sort: " << duration1.count() << " microseconds" << endl;
    cout << "Insertion Sort: " << duration2.count() << " microseconds" << endl;
    cout << "Bubble Sort: " << duration3.count() << " microseconds" << endl;
    cout << endl;
}

int main() {
    vector<int> sizes = {100, 1000, 10000, 100000};
    for (int n : sizes) {
        cout << "Random Array" << endl;
        vector<int> arr = generateRandomArray(n);
        runSortAlgorithms(n, arr);

        cout << "Sorted Array" << endl;
        sort(arr.begin(), arr.end());
        runSortAlgorithms(n, arr);

        cout << "90% Sorted Array" << endl;
        vector<int> sorted90percent(arr.begin(), arr.end());
        sort(sorted90percent.begin(), sorted90percent.end());
        permuteElements(sorted90percent);
        runSortAlgorithms(n, sorted90percent);

        cout << "50% Sorted Array" << endl;
        vector<int> halfSorted(arr.begin(), arr.end());
        sort(halfSorted.begin(), halfSorted.begin() + n / 2);
        runSortAlgorithms(n, halfSorted);

        cout << "-------------------------------------------------" << endl;
    }

    return 0;
}
