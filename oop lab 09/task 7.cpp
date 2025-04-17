#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
	string fullName;
	float basePay;

public:
	virtual void inputDetails() {
		cout << "Enter full name: ";
		cin >> fullName;
		cout << "Enter base pay: ";
		cin >> basePay;
	}

	virtual void showDetails() {
		cout << "Name: " << fullName << ", Base Pay: " << basePay << endl;
	}

	virtual void calculateBonus() = 0;

	virtual ~Employee() {}
};

class Manager : virtual public Employee {
public:
	void inputDetails() override {
		cout << "[Manager Input]\n";
		Employee::inputDetails();
	}

	void showDetails() override {
		cout << "[Manager Details]\n";
		Employee::showDetails();
	}

	void calculateBonus() override {
		cout << "Manager Bonus: $" << (basePay * 0.10f) << endl;
	}
};

class Finance : virtual public Employee {
public:
	void inputDetails() override {
		cout << "[Finance Input]\n";
		Employee::inputDetails();
	}

	void showDetails() override {
		cout << "[Finance Details]\n";
		Employee::showDetails();
	}

	void calculateBonus() override {
		cout << "Finance Bonus: $" << (basePay * 0.08f) << endl;
	}
};

class Director : public Manager, public Finance {
public:
	void inputDetails() override {
		cout << "[Director Input]\n";
		Employee::inputDetails();
	}

	void showDetails() override {
		cout << "[Director Details]\n";
		Employee::showDetails();
	}

	void calculateBonus() override {
		cout << "Director Bonus: $" << (basePay * 0.15f) << endl;
	}
};

int main() {
	Employee* empPtr;

	cout << "\n--- Manager Profile ---\n";
	Manager mgr;
	empPtr = &mgr;
	empPtr->inputDetails();
	empPtr->showDetails();
	empPtr->calculateBonus();

	cout << "\n--- Finance Profile ---\n";
	Finance fin;
	empPtr = &fin;
	empPtr->inputDetails();
	empPtr->showDetails();
	empPtr->calculateBonus();

	cout << "\n--- Director Profile ---\n";
	Director dir;
	empPtr = &dir;
	empPtr->inputDetails();
	empPtr->showDetails();
	empPtr->calculateBonus();

	return 0;
}
