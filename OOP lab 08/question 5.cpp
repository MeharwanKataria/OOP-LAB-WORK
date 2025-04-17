#include <iostream>
using namespace std;

class Surface {
private:
    double size;

public:
    Surface(double s) : size(s) {}

    // Overloading + operator to add sizes
    Surface operator+(const Surface& other) const {
        return Surface(size + other.size);
    }

    void show() const {
        cout << "Surface Area: " << size << endl;
    }
};

int main() {
    Surface s1(25.5), s2(30.7);

    cout << "First Surface: ";
    s1.show();

    cout << "Second Surface: ";
    s2.show();

    Surface combined = s1 + s2;
    cout << "Combined Surface Area: ";
    combined.show();

    return 0;
}
