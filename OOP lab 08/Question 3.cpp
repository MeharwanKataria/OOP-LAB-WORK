#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigNum {
private:
    vector<int> value;   // Digits stored in reverse
    bool negative;

public:
    BigNum() : negative(false) {}
    BigNum(const string& str);

    BigNum operator+(const BigNum& rhs) const;
    BigNum operator-(const BigNum& rhs) const;
    BigNum operator*(const BigNum& rhs) const;

    bool operator==(const BigNum& rhs) const;
    bool operator!=(const BigNum& rhs) const;
    bool operator<(const BigNum& rhs) const;
    bool operator>(const BigNum& rhs) const;

    friend ostream& operator<<(ostream& out, const BigNum& num);
    friend istream& operator>>(istream& in, BigNum& num);
};

// Constructor from string
BigNum::BigNum(const string& str) {
    negative = (str[0] == '-');
    for (int i = str.size() - 1; i >= (negative ? 1 : 0); --i) {
        value.push_back(str[i] - '0');
    }
}

// Addition
BigNum BigNum::operator+(const BigNum& rhs) const {
    BigNum result;
    int carry = 0;
    int sum;

    size_t len = max(value.size(), rhs.value.size());
    for (size_t i = 0; i < len || carry; ++i) {
        sum = carry;
        if (i < value.size()) sum += value[i];
        if (i < rhs.value.size()) sum += rhs.value[i];

        result.value.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}


ostream& operator<<(ostream& out, const BigNum& num) {
    if (num.negative) out << "-";
    for (auto it = num.value.rbegin(); it != num.value.rend(); ++it)
        out << *it;
    return out;
}


istream& operator>>(istream& in, BigNum& num) {
    string s;
    in >> s;
    num = BigNum(s);
    return in;
}

int main() {
    BigNum A, B;
    cout << "Enter two large integers:\n";
    cin >> A >> B;

    BigNum total = A + B;
    cout << "Their sum is: " << total << endl;

    return 0;
}
