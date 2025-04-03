#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual double convertTo(const Currency &targetCurrency) const {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << currencySymbol << " " << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "", 1.1) {}
};

class PakistaniRupee : public Currency {
public:
    PakistaniRupee(double amt) : Currency(amt, "PKR", "rs", 0.0035) {}
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    PakistaniRupee pkr(5000);

    cout << "Original Amounts:" << endl;
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\nConversions:" << endl;
    cout << "100 USD to EUR: " << usd.convertTo(eur) << " EUR" << endl;
    cout << "50 EUR to PKR: " << eur.convertTo(pkr) << " PKR" << endl;
    cout << "5000 PKR to USD: " << pkr.convertTo(usd) << " USD" << endl;

    return 0;
}
