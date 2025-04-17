#include <iostream>
using namespace std;

class Employee {
protected:
    int id;

public:
    void inputData() {
        cout << "Input Employee ID: ";
        cin >> id;
    }

    void showData() const {
        cout << "ID: " << id << endl;
    }
};

class Manager : public Employee {
protected:
    string fullName;
    double salary;

public:
    void inputData() {
        Employee::inputData();
        cout << "Input Full Name: ";
        cin >> fullName;
        cout << "Input Monthly Salary: ";
        cin >> salary;
    }

    double calculateBonus() const {
        return salary * 0.05 * 12;
    }

    void showData() const {
        Employee::showData();
        cout << "Name: " << fullName << endl;
        cout << "Monthly Salary: " << salary << endl;
        cout << "Yearly Bonus: " << calculateBonus() << endl;
    }
};

class Finance : public Employee {
protected:
    string fullName;
    double salary;

public:
    void inputData() {
        Employee::inputData();
        cout << "Input Full Name: ";
        cin >> fullName;
        cout << "Input Monthly Salary: ";
        cin >> salary;
    }

    double calculateBonus() const {
        return salary * 0.05 * 12;
    }

    void showData() const {
        Employee::showData();
        cout << "Name: " << fullName << endl;
        cout << "Monthly Salary: " << salary << endl;
        cout << "Yearly Bonus: " << calculateBonus() << endl;
    }
};

int main() {
    Manager mgr;
    Finance fin;

    cout << "Enter Manager Details:\n";
    mgr.inputData();

    cout << "\nEnter Finance Officer Details:\n";
    fin.inputData();

    cout << "\n--- Employee Summary ---\n";
    mgr.showData();
    cout << endl;
    fin.showData();

    return 0;
}
