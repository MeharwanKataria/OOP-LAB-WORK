#include <iostream>
using namespace std;

class Counter {
private:
    int data;

public:
    Counter(int val) : data(val) {}

    
    Counter& operator--() {
        data *= 4;
        return *this;
    }

    Counter operator--(int) {
        Counter copy = *this;
        data /= 4;
        return copy;
    }

    void show() const {
        cout << "Current Value: " << data << endl;
    }
};

int main() {
    Counter obj(44);

    cout << "Starting value: ";
    obj.show();

    --obj;
    cout << "After applying prefix (--obj): ";
    obj.show();

    obj--;
    cout << "After applying postfix (obj--): ";
    obj.show();

    return 0;
}
