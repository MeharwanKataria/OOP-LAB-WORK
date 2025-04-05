#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class PolynomialUtils;

class Polynomial {
    vector<int> coeffs;

public:
    Polynomial() {}

    Polynomial(const vector<int>& coefficients) : coeffs(coefficients) {
        trimLeadingZeros();
    }

    void trimLeadingZeros() {
        while (coeffs.size() > 1 && coeffs.back() == 0) {
            coeffs.pop_back();
        }
    }

    friend class PolynomialUtils;

    Polynomial operator+(const Polynomial& other) const {
        size_t size = max(coeffs.size(), other.coeffs.size());
        vector<int> result(size, 0);

        for (size_t i = 0; i < coeffs.size(); ++i) {
            result[i] += coeffs[i];
        }

        for (size_t i = 0; i < other.coeffs.size(); ++i) {
            result[i] += other.coeffs[i];
        }

        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t size = max(coeffs.size(), other.coeffs.size());
        vector<int> result(size, 0);

        for (size_t i = 0; i < coeffs.size(); ++i) {
            result[i] += coeffs[i];
        }

        for (size_t i = 0; i < other.coeffs.size(); ++i) {
            result[i] -= other.coeffs[i];
        }

        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        size_t result_size = coeffs.size() + other.coeffs.size() - 1;
        vector<int> result(result_size, 0);

        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < other.coeffs.size(); ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }

        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coeffs.empty()) {
            os << "0";
            return os;
        }

        bool first = true;
        for (size_t i = p.coeffs.size(); i-- > 0;) {
            int coef = p.coeffs[i];
            if (coef != 0) {
                if (!first && coef > 0) {
                    os << " + ";
                }
                if (coef < 0) {
                    os << " - ";
                    coef = -coef;
                }
                if (i > 0) {
                    os << coef << "x";
                    if (i > 1) os << "^" << i;
                } else {
                    os << coef;
                }
                first = false;
            }
        }
        return os;
    }
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int powerOfX = 1;

        for (size_t i = 0; i < p.coeffs.size(); ++i) {
            result += p.coeffs[i] * powerOfX;
            powerOfX *= x;
        }

        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        if (p.coeffs.size() <= 1) {
            return Polynomial();
        }

        vector<int> derivativeCoeffs;
        for (size_t i = 1; i < p.coeffs.size(); ++i) {
            derivativeCoeffs.push_back(p.coeffs[i] * i);
        }

        return Polynomial(derivativeCoeffs);
    }
};

int main() {
	vector<int>coef;
	for(int i=1;i<5;i++){
		coef.push_back(i);
	}
	vector<int>coef1;
		for(int i=2;i<5;i++){
		coef.push_back(i);
	}
    Polynomial p1(coef);
    Polynomial p2(coef1);

    Polynomial sum = p1 + p2;
    cout << "p1 + p2 = " << sum << endl;

    Polynomial diff = p1 - p2;
    cout << "p1 - p2 = " << diff << endl;

    Polynomial prod = p1 * p2;
    cout << "p1 * p2 = " << prod << endl;

    int eval = PolynomialUtils::evaluate(p1, 2);
    cout << "p1 evaluated at x = 2: " << eval << endl;

    Polynomial deriv = PolynomialUtils::derivative(p1);
    cout << "Derivative of p1: " << deriv << endl;

    return 0;
}

