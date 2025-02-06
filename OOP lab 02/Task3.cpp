#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
 
    int capacity = 5;
    int size = 0;
    int* arr = new int[capacity];

    for (int i = 1; i < argc; ++i) {
        int element = atoi(argv[i]);

        if (size == capacity) {
            capacity *= 2;
            int* temp = new int[capacity];
            for (int j = 0; j < size; ++j) {
                temp[j] = arr[j];
            }
            delete[] arr;
            arr = temp;
        }

        arr[size++] = element;
    }

    int* final_arr = new int[size];
    for (int i = 0; i < size; ++i) {
        final_arr[i] = arr[i];
    }

    delete[] arr;

    cout << "Final Array (after resizing to fit the exact number of elements):\n";
    for (int i = 0; i < size; ++i) {
        cout << final_arr[i] << " ";
    }

    delete[] final_arr;
    return 0;
}

