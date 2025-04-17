#include <iostream>
#include <string>
#include <numeric>
using namespace std;

class Rational {
protected:
	int top;
	int bottom;

	void simplify() {
		int divisor = gcd(top, bottom);
		top /= divisor;
		bottom /= divisor;

		if (bottom < 0) {
			top = -top;
			bottom = -bottom;
		}
	}

public:
	Rational(int n = 1, int d = 1) : top(n), bottom(d) {
		if (bottom == 0) {
			throw invalid_argument("Zero denominator is not allowed.");
		}
		simplify();
	}

	friend Rational operator+(const Rational& a, const Rational& b);
	friend Rational operator-(const Rational& a, const Rational& b);
	friend Rational operator*(const Rational& a, const Rational& b);
	friend Rational operator/(const Rational& a, const Rational& b);

	friend bool operator==(const Rational& a, const Rational& b);
	friend bool operator!=(const Rational& a, const Rational& b);
	friend bool operator<(const Rational& a, const Rational& b);
	friend bool operator>(const Rational& a, const Rational& b);
	friend bool operator<=(const Rational& a, const Rational& b);
	friend bool operator>=(const Rational& a, const Rational& b);

	friend ostream& operator<<(ostream& os, const Rational& r);
	friend istream& operator>>(istream& is, Rational& r);

	void show() const {
		cout << top << "/" << bottom << endl;
	}
};

Rational operator+(const Rational& a, const Rational& b) {
	int num = a.top * b.bottom + b.top * a.bottom;
	int denom = a.bottom * b.bottom;
	return Rational(num, denom);
}

Rational operator-(const Rational& a, const Rational& b) {
	int num = a.top * b.bottom - b.top * a.bottom;
	int denom = a.bottom * b.bottom;
	return Rational(num, denom);
}

Rational operator*(const Rational& a, const Rational& b) {
	return Rational(a.top * b.top, a.bottom * b.bottom);
}

Rational operator/(const Rational& a, const Rational& b) {
	if (b.top == 0) {
		throw invalid_argument("Division by zero fraction.");
	}
	return Rational(a.top * b.bottom, a.bottom * b.top);
}

bool operator==(const Rational& a, const Rational& b) {
	return (a.top == b.top) && (a.bottom == b.bottom);
}

bool operator!=(const Rational& a, const Rational& b) {
	return !(a == b);
}

bool operator<(const Rational& a, const Rational& b) {
	return (a.top * b.bottom) < (b.top * a.bottom);
}

bool operator>(const Rational& a, const Rational& b) {
	return (a.top * b.bottom) > (b.top * a.bottom);
}

bool operator<=(const Rational& a, const Rational& b) {
	return (a < b) || (a == b);
}

bool operator>=(const Rational& a, const Rational& b) {
	return (a > b) || (a == b);
}

ostream& operator<<(ostream& os, const Rational& r) {
	os << r.top << "/" << r.bottom;
	return os;
}

istream& operator>>(istream& is, Rational& r) {
	char divider;
	is >> r.top >> divider >> r.bottom;
	if (r.bottom == 0) {
		throw invalid_argument("Zero is not a valid denominator.");
	}
	r.simplify();
	return is;
}

int main() {
	Rational r1, r2;

	cout << "Input the first rational number (e.g. 2/3): ";
	cin >> r1;
	cout << "Input the second rational number (e.g. 3/5): ";
	cin >> r2;

	cout << "\nYou entered:\n";
	cout << "r1 = " << r1 << "\n";
	cout << "r2 = " << r2 << "\n";

	cout << "\nOperations:\n";
	cout << "r1 + r2 = " << (r1 + r2) << "\n";
	cout << "r1 - r2 = " << (r1 - r2) << "\n";
	cout << "r1 * r2 = " << (r1 * r2) << "\n";
	cout << "r1 / r2 = " << (r1 / r2) << "\n";

	cout << boolalpha;
	cout << "\nComparisons:\n";
	cout << "r1 == r2: " << (r1 == r2) << "\n";
	cout << "r1 != r2: " << (r1 != r2) << "\n";
	cout << "r1 < r2: " << (r1 < r2) << "\n";
	cout << "r1 > r2: " << (r1 > r2) << "\n";
	cout << "r1 <= r2: " << (r1 <= r2) << "\n";
	cout << "r1 >= r2: " << (r1 >= r2) << "\n";

	return 0;
}
