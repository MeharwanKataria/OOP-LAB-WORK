#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Forward declaration
class Poly;

// Utility class for operations
class PolyOperations {
public:
    static int evaluateAt(const Poly& poly, int x);
    static Poly computeDerivative(const Poly& poly);
};

class Poly {
private:
    vector<int> coeffs;

public:
    friend class PolyOperations;

    Poly() {}

    Poly(const vector<int>& c) : coeffs(c) {}

    // Addition
    Poly operator+(const Poly& rhs) const {
        size_t maxLength = max(coeffs.size(), rhs.coeffs.size());
        vector<int> sum(maxLength, 0);

        for (size_t i = 0; i < coeffs.size(); ++i)
            sum[i] += coeffs[i];

        for (size_t i = 0; i < rhs.coeffs.size(); ++i)
            sum[i] += rhs.coeffs[i];

        return Poly(sum);
    }

    // Subtraction
    Poly operator-(const Poly& rhs) const {
        size_t maxLength = max(coeffs.size(), rhs.coeffs.size());
        vector<int> diff(maxLength, 0);

        for (size_t i = 0; i < coeffs.size(); ++i)
            diff[i] += coeffs[i];

        for (size_t i = 0; i < rhs.coeffs.size(); ++i)
            diff[i] -= rhs.coeffs[i];

        return Poly(diff);
    }

    // Multiplication
    Poly operator*(const Poly& rhs) const {
        vector<int> product(coeffs.size() + rhs.coeffs.size() - 1, 0);

        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < rhs.coeffs.size(); ++j) {
                product[i + j] += coeffs[i] * rhs.coeffs[j];
            }
        }

        return Poly(product);
    }

    // Display
    friend ostream& operator<<(ostream& out, const Poly& poly) {
        bool printed = false;
        for (int i = static_cast<int>(poly.coeffs.size()) - 1; i >= 0; --i) {
            int coef = poly.coeffs[i];
            if (coef == 0) continue;

            if (printed) out << (coef > 0 ? " + " : " - ");
            else if (coef < 0) out << "-";

            out << abs(coef);
            if (i > 0) out << "x^" << i;

            printed = true;
        }

        if (!printed) out << "0";
        return out;
    }
};

int PolyOperations::evaluateAt(const Poly& poly, int x) {
    int result = 0;
    int power = 1;
    for (int coef : poly.coeffs) {
        result += coef * power;
        power *= x;
    }
    return result;
}

Poly PolyOperations::computeDerivative(const Poly& poly) {
    int n = static_cast<int>(poly.coeffs.size());
    if (n <= 1) return Poly({0});

    vector<int> deriv(n - 1);
    for (int i = 1; i < n; ++i) {
        deriv[i - 1] = poly.coeffs[i] * i;
    }

    return Poly(deriv);
}

int main() {
    Poly A({3, 0, 5});   // 3 + 0x + 5x^2
    Poly B({1, 2, 4});   // 1 + 2x + 4x^2

    cout << "Polynomial A: " << A << endl;
    cout << "Polynomial B: " << B << endl;

    cout << "A + B = " << (A + B) << endl;
    cout << "A - B = " << (A - B) << endl;
    cout << "A * B = " << (A * B) << endl;

    cout << "Value of A at x = 2: " << PolyOperations::evaluateAt(A, 2) << endl;
    cout << "Derivative of A: " << PolyOperations::computeDerivative(A) << endl;

    return 0;
}
