#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    double borderThickness;

public:
    Shape(string col, double border) : color(col), borderThickness(border) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    double centerX, centerY;

public:
    Circle(string col, double border, double r, double x, double y) : Shape(col, border), radius(r), centerX(x), centerY(y) {}
    void draw() override {
        cout << "Drawing Circle with radius " << radius << " at (" << centerX << ", " << centerY << ")\n";
    }
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    double topLeftX, topLeftY;

public:
    Rectangle(string col, double border, double w, double h, double x, double y) : Shape(col, border), width(w), height(h), topLeftX(x), topLeftY(y) {}
    void draw() override {
        cout << "Drawing Rectangle with width " << width << " and height " << height << " at (" << topLeftX << ", " << topLeftY << ")\n";
    }
    double calculateArea() override {
        return width * height;
    }
    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(string col, double border, double b, double h) : Shape(col, border), base(b), height(h) {}
    void draw() override {
        cout << "Drawing Triangle with base " << base << " and height " << height << "\n";
    }
    double calculateArea() override {
        return 0.5 * base * height;
    }
    double calculatePerimeter() override {
        return base + 2 * sqrt((base / 2) * (base / 2) + height * height);
    }
};

int main() {
    Circle circle("Red", 2.0, 5.0, 0.0, 0.0);
    Rectangle rectangle("Blue", 1.5, 4.0, 6.0, -2.0, 3.0);
    Triangle triangle("Green", 1.0, 3.0, 4.0);

    cout << "\n-- Circle --" << endl;
    circle.draw();
    cout << "Area: " << circle.calculateArea() << "\nPerimeter: " << circle.calculatePerimeter() << endl;

    cout << "\n-- Rectangle --" << endl;
    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << "\nPerimeter: " << rectangle.calculatePerimeter() << endl;

    cout << "\n-- Triangle --" << endl;
    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << "\nPerimeter: " << triangle.calculatePerimeter() << endl;

    return 0;
}
