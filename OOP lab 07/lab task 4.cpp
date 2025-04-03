#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phone, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phone(p), email(e) {}
    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address << "\nPhone: " << phone << "\nEmail: " << email << endl;
    }
};

class Student : public Person {
    vector<string> courses;
    double gpa;
    int year;
public:
    Student(string n, string i, string a, string p, string e, vector<string> c, double g, int y) 
        : Person(n, i, a, p, e), courses(c), gpa(g), year(y) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << gpa << "\nYear: " << year << "\nCourses: ";
        for (const string &c : courses) cout << c << " ";
        cout << endl;
    }
};

class Professor : public Person {
    string dept;
    vector<string> courses;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, vector<string> c, double s)
        : Person(n, i, a, p, e), dept(d), courses(c), salary(s) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Dept: " << dept << "\nSalary: " << salary << "\nCourses: ";
        for (const string &c : courses) cout << c << " ";
        cout << endl;
    }
};

class Staff : public Person {
    string dept, pos;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string d, string ps, double s)
        : Person(n, i, a, p, e), dept(d), pos(ps), salary(s) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Dept: " << dept << "\nPos: " << pos << "\nSalary: " << salary << endl;
    }
};

int main() {
    Student s1("Ali Khan", "S123", "Lahore", "123456789", "ali@gmail.com", {"CS101", "MATH101"}, 3.8, 2022);
    Professor p1("Dr. Ahmed", "P456", "Karachi", "987654321", "ahmed@gmail.com", "CS", {"CS101", "AI"}, 150000);
    Staff st1("Sara Malik", "ST789", "Islamabad", "1122334455", "sara@gmail.com", "Admin", "HR Manager", 80000);
    
    cout << "\n--- Student Info ---\n";
    s1.displayInfo();
    cout << "\n--- Professor Info ---\n";
    p1.displayInfo();
    cout << "\n--- Staff Info ---\n";
    st1.displayInfo();
    
    return 0;
}
