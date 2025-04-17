#include <iostream>
#include <string>
using namespace std;

class DigitalWallet {
private:
    double currentBalance;
    double totalDepositedToday;
    double totalWithdrawnToday;
    const double DAILY_DEPOSIT_LIMIT = 10000.0;
    const double DAILY_WITHDRAW_LIMIT = 5000.0;

public:
    DigitalWallet() : currentBalance(0.0), totalDepositedToday(0.0), totalWithdrawnToday(0.0) {}

    bool addFunds(double amount) {
        if (amount <= 0) {
            cout << "Amount to deposit must be greater than zero.\n";
            return false;
        }
        if (totalDepositedToday + amount > DAILY_DEPOSIT_LIMIT) {
            cout << "Cannot deposit: daily limit reached.\n";
            return false;
        }
        currentBalance += amount;
        totalDepositedToday += amount;
        cout << "Successfully added " << amount << " | Available Balance: " << currentBalance << "\n";
        return true;
    }

    bool removeFunds(double amount) {
        if (amount <= 0) {
            cout << "Amount to withdraw must be positive.\n";
            return false;
        }
        if (amount > currentBalance) {
            cout << "Not enough balance for this withdrawal.\n";
            return false;
        }
        if (totalWithdrawnToday + amount > DAILY_WITHDRAW_LIMIT) {
            cout << "Withdrawal blocked: daily limit exceeded.\n";
            return false;
        }
        currentBalance -= amount;
        totalWithdrawnToday += amount;
        cout << "Withdrawn: " << amount << " | Remaining Balance: " << currentBalance << "\n";
        return true;
    }

    double viewBalance() const {
        return currentBalance;
    }

    void clearDailyLimits() {
        totalDepositedToday = 0.0;
        totalWithdrawnToday = 0.0;
    }
};

class AccountHolder {
private:
    string accountID;
    string holderName;
    DigitalWallet wallet;

public:
    AccountHolder(string id, string name) : accountID(id), holderName(name) {}

    bool depositCash(double amount) {
        cout << "[" << holderName << "] ";
        return wallet.addFunds(amount);
    }

    bool withdrawCash(double amount) {
        cout << "[" << holderName << "] ";
        return wallet.removeFunds(amount);
    }

    void displayBalance() const {
        cout << "[" << holderName << "] Wallet Balance: " << wallet.viewBalance() << "\n";
    }

    void resetLimits() {
        wallet.clearDailyLimits();
    }
};

int main() {
    AccountHolder client1("ACC01", "Lena");
    AccountHolder client2("ACC02", "Tom");

    client1.depositCash(3000);
    client1.withdrawCash(1000);
    client1.displayBalance();

    cout << "========================\n";

    client2.depositCash(8000);
    client2.depositCash(3000); 
    client2.displayBalance();

    cout << "========================\n";

    client1.withdrawCash(5000);
    client1.displayBalance();

    cout << "========================\n";

    client1.resetLimits();
    client1.depositCash(6000);

    return 0;
}
