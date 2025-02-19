#include <iostream>
using namespace std;

class dynamicarray {
private:
    int* dynamic;
    int n;

public:
    dynamicarray() : n(0), dynamic(nullptr) {}

    dynamicarray(int n) : n(n) {
        dynamic = new int[n]{0};
    }

    dynamicarray(const dynamicarray& other) : n(other.n) {
        dynamic = new int[n];
        for (int i = 0; i < n; ++i) {
            dynamic[i] = other.dynamic[i];
        }
    }

    dynamicarray(dynamicarray&& other) noexcept : n(other.n), dynamic(other.dynamic) {
        other.dynamic = nullptr;
        other.n = 0;
    }

    dynamicarray& operator=(const dynamicarray& other) {
        if (this != &other) {
            delete[] dynamic;
            n = other.n;
            dynamic = new int[n];
            for (int i = 0; i < n; ++i) {
                dynamic[i] = other.dynamic[i];
            }
        }
        return *this;
    }

    dynamicarray& operator=(dynamicarray&& other) noexcept {
        if (this != &other) {
            delete[] dynamic;
            dynamic = other.dynamic;
            n = other.n;
            other.dynamic = nullptr;
            other.n = 0;
        }
        return *this;
    }

    ~dynamicarray() {
        delete[] dynamic;
    }

    int size() const {
        return n;
    }

    int& at(int index) {
        if (index < 0 || index >= n) {
            cout << "Out of Range" << endl;
            return dynamic[0]; 
        }
        return dynamic[index];
    }

    void resize(int newSize) {
        if (newSize == n) return;

        int* newData = nullptr;

        if (newSize > 0) {
            newData = new int[newSize]();
            int minSize = (newSize < n) ? newSize : n;
            for (int i = 0; i < minSize; ++i) {
                newData[i] = dynamic[i];
            }
        }

        delete[] dynamic;
        dynamic = newData;
        n = newSize;
    }

    void display() const {
        for (int i = 0; i < n; ++i) {
            cout << dynamic[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    dynamicarray arr(5);
    for (int i = 0; i < arr.size(); ++i) {
        arr.at(i) = i * 5;
    }

    cout << "Array before resize: ";
    arr.display();

    arr.resize(8);
    cout << "Array after resizing: ";
    arr.display();

    dynamicarray arr1 = arr;
    cout << "Array after copying: ";
    arr1.display();

    dynamicarray arr2 = std::move(arr);
    cout << "Array after moving: ";
    arr2.display();

    return 0;
}

