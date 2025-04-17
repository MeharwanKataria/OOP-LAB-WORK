#include <iostream>
using namespace std;

class Shape {
public:
	virtual float getArea() = 0;
};

class Rectangle : public Shape {
private:
	float width;
	float height;

public:
	Rectangle(float w, float h) : width(w), height(h) {}

	float getArea() override {
		return width * height;
	}
};

// Derived class: Triangle
class Triangle : public Shape {
private:
	float base;
	float height;

public:
	Triangle(float b, float h) : base(b), height(h) {}

	float getArea() override {
		return 0.5 * base * height;
	}
};

int main() {
	Rectangle rect(10, 5);
	Triangle tri(6, 4);

	cout << "Area of Rectangle: " << rect.getArea() << endl;
	cout << "Area of Triangle: " << tri.getArea() << endl;

	return 0;
}