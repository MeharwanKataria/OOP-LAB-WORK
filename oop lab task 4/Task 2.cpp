#include <iostream>
#include <cmath>
using namespace std;
class Polynomial {
private:
    double* coefficients;
    int degree;

public:
    Polynomial() : degree(0) {
        coefficients = new double[1]{0};
    }

    Polynomial(int deg, const double* coeffs) : degree(deg) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            this->coefficients[i] = coeffs[i];
        }
    }

    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * std::pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]{};

        for (int i = 0; i <= maxDegree; ++i) {
            if (i <= degree) newCoeffs[i] += coefficients[i];
            if (i <= other.degree) newCoeffs[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]{};

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(newDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }

    void display() const {
        for (int i = 0; i<= degree; i++) {
            cout << coefficients[i] << "x^" << i;
         if (i<degree) cout << " + ";
        }
        cout<<endl;
    }
};

int main() {
    double coeffs1[] = {1, 2, 3};
    double coeffs2[] = {0, 1, 4};

    Polynomial p1(2, coeffs1);
    Polynomial p2(2, coeffs2);

    cout << "Polynomial 1: ";
    p1.display();
    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();

    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.display();

    double x = 2;
    cout << "p1 evaluated at x=" << x << " : " << p1.evaluate(x) << endl;
    cout << "p2 evaluated at x=" << x << " : " << p2.evaluate(x) << endl;

    return 0;
}

