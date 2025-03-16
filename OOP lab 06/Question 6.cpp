#include <iostream>
using namespace std;

class Student {
protected:
    string studentName;
    int studentID;
public:
    Student(string name, int id) {
        studentName = name;
        studentID = id;
    }

    void display() {
        cout << "Student Name: " << studentName << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

class Marks : public Student {
protected:
    int oop, mvc, dld;
public:
    Marks(string name, int id, int o, int m, int d) : Student(name, id) {
        oop = o;
        mvc = m;
        dld = d;
    }

    void showMarks() {
        cout << "OOP: " << oop << ", MVC: " << mvc << ", DLD: " << dld << endl;
    }
};

class Result : public Marks {
public:
    Result(string name, int id, int o, int m, int d) : Marks(name, id, o, m, d) {}

    void showResult() {
        int totalMarks = oop + mvc + dld;
        float averageMarks = totalMarks / 3.0;
        
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }
};

int main() {
    Result student("Meharwan", 864, 85, 90, 78);

    student.display();
    student.showMarks();
    student.showResult();

    return 0;
}

