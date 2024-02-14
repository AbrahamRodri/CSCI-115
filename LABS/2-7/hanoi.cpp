#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

// Class Array implementation

class Array {
private:
    int* data;
    int size;
    int capacity;
    int copy_count;

public:
    Array() {
        size = 0;
        capacity = 1;
        data = new int[capacity];
        copy_count = 0;
    }

    ~Array() {
        delete[] data;
    }

    void insert(int element) {
        if (size == capacity) {
            int* new_data = new int[capacity * 2];
            copy_count++;
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity *= 2;
        }
        data[size++] = element;
    }

    int getCopyCount() const {
        return copy_count;
    }
};

double mean(const std::vector<double>& values) {
    double sum = 0.0;
    for (double value : values) {
        sum += value;
    }
    return sum / values.size();
}


double standardDeviation(const std::vector<double>& values) {
    double mean_value = mean(values);
    double variance = 0.0;
    for (double value : values) {
        variance += pow(value - mean_value, 2);
    }
    variance /= values.size();
    return sqrt(variance);
}

int main() {
    // Define number of repetitions and array size
    const int repetitions = 100;
    const int array_size = 10000;


    std::vector<double> durations(repetitions);


    srand(time(nullptr));

 
    for (int rep = 0; rep < repetitions; ++rep) {

        clock_t start_time = clock();


        Array array;
        for (int i = 0; i < array_size; ++i) {
            array.insert(rand()); 
        }


        clock_t end_time = clock();
        double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;


        durations[rep] = duration;
    }


    double mean_duration = mean(durations);
    double std_dev_duration = standardDeviation(durations);


    cout << "Mean duration: " << mean_duration << " seconds\n";
    cout << "Standard deviation of duration: " << std_dev_duration << " seconds\n";

    return 0;
}

// Results:
//Mean duration: 0.00015 seconds
//Standard deviation of duration: 0.000357071 seconds
// Machine: CPU: 12th Gen Intel(R) Core(TM) i5-12400   2.50 GHz, RAM: 32GB