#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    Account(string name, int accNum, double bal) {
        accountHolderName = name;
        accountNumber = accNum;
        balance = bal;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", Remaining Balance: " << balance << endl;
        }
    }

    virtual void calculateInterest() = 0;

    virtual void printStatement() {
        cout << "Account Holder: " << accountHolderName << "\nAccount Number: " << accountNumber << "\nBalance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string name, int accNum, double bal, double rate, double minBal)
        : Account(name, accNum, bal), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Added: " << interest << ", New Balance: " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string name, int accNum, double bal) : Account(name, accNum, bal) {}

    void calculateInterest() override {
        cout << "Checking accounts do not earn interest." << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityYears;

public:
    FixedDepositAccount(string name, int accNum, double bal, double rate, int years)
        : Account(name, accNum, bal), fixedInterestRate(rate), maturityYears(years) {}

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100) * maturityYears;
        balance += interest;
        cout << "Fixed Deposit Interest Added: " << interest << ", New Balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount savings("Alice", 101, 5000, 5, 1000);
    CheckingAccount checking("Bob", 102, 3000);
    FixedDepositAccount fixedDeposit("Charlie", 103, 10000, 7, 5);

    cout << "\n-- Savings Account --" << endl;
    savings.deposit(2000);
    savings.withdraw(1000);
    savings.calculateInterest();
    savings.printStatement();

    cout << "\n-- Checking Account --" << endl;
    checking.deposit(1500);
    checking.withdraw(500);
    checking.calculateInterest();
    checking.printStatement();

    cout << "\n-- Fixed Deposit Account --" << endl;
    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();

    return 0;
}
