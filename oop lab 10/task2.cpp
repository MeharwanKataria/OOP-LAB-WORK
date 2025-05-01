#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Staff {
	int staffID;
	string fullName;
	string role;
	int serviceYears;
};

class FileProcessor {
private:
	Staff currentStaff;
	string dataFile;

public:
	FileProcessor(string file, Staff staff) {
		this->dataFile = file;
		this->currentStaff = staff;
	}

	void appendStaffToFile(const Staff& staff, const string& file) {
		ofstream out(file, ios::app);
		if (out.is_open()) {
			out << staff.staffID << "\n";
			out << staff.fullName << "\n";
			out << staff.role << "\n";
			out << staff.serviceYears << "\n";
			out.close();
		}
	}

	Staff readStaffFromFile(const string& file) {
		ifstream in(file);
		Staff staff;
		if (in.is_open()) {
			in >> staff.staffID;
			in.ignore();
			getline(in, staff.fullName);
			getline(in, staff.role);
			in >> staff.serviceYears;
			in.close();
		}
		return staff;
	}

	void filterManagerWithExperience(const string& file) {
		ifstream in(file);
		if (!in) {
			cout << "Unable to open file.\n";
			return;
		}

		Staff temp;
		bool matchFound = false;

		while (in >> temp.staffID) {
			in.ignore();
			getline(in, temp.fullName);
			getline(in, temp.role);
			in >> temp.serviceYears;
			in.ignore();

			if (temp.role == "Manager" && temp.serviceYears >= 2) {
				matchFound = true;
				currentStaff = temp;
				break;
			}
		}
		in.close();

		if (!matchFound) {
			cout << "No qualified manager with 2+ years found.\n";
			return;
		}

		ofstream out(file, ios::trunc);
		out << currentStaff.staffID << "\n";
		out << currentStaff.fullName << "\n";
		out << currentStaff.role << "\n";
		out << currentStaff.serviceYears << "\n";
		out.close();

		cout << "Qualified manager saved: " << currentStaff.fullName << endl;
	}
};

int main() {
	Staff s1 = {101, "Kamil", "Manager", 3};
	Staff s2 = {102, "Aly", "Clerk", 1};
	Staff s3 = {103, "Frank", "Manager", 1};

	FileProcessor processor("Records.txt", s1);
	processor.appendStaffToFile(s1, "Records.txt");
	processor.appendStaffToFile(s2, "Records.txt");
	processor.appendStaffToFile(s3, "Records.txt");

	processor.filterManagerWithExperience("Records.txt");

	return 0;
}