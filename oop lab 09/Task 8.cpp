#include <iostream>
#include <string>
using namespace std;

class Learner {
public:
	virtual double calculateFee(const string& level, int hours) = 0;
	virtual ~Learner() {}
};

class Postgraduate : public Learner {
private:
	string thesisTitle;

public:
	void assignThesis(const string& title) {
		thesisTitle = title;
	}

	string retrieveThesis() const {
		return thesisTitle;
	}

	double calculateFee(const string& level, int hours) override {
		if (level == "bachelor") {
			return 200.0 * hours;
		} else if (level == "masters") {
			return 300.0 * hours;
		} else if (level == "phd") {
			return 400.0 * hours;
		} else {
			cout << "Unknown academic level.\n";
			return 0.0;
		}
	}
};

int main() {
	Postgraduate pgStudent;
	pgStudent.assignThesis("Analyzing Milk Production in Bovines");

	string academicLevel;
	int creditCount;

	cout << "Enter academic level (bachelor/masters/phd): ";
	cin >> academicLevel;
	cout << "Enter total credit hours: ";
	cin >> creditCount;

	cout << "Thesis Title: " << pgStudent.retrieveThesis() << endl;
	cout << "Total Fee: Rs " << pgStudent.calculateFee(academicLevel, creditCount) << endl;

	return 0;
}
