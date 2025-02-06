#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string name;
};

struct Student {
    int id;
    vector<Subject> subjects;
};

int main(int argc, char* argv[]) {
    int N = stoi(argv[1]);
    Student* students = new Student[N];
    int argIndex = 2;
    
    for (int i = 0; i < N; ++i) {
        students[i].id = stoi(argv[argIndex]);
        argIndex++;
        int num_subjects = stoi(argv[argIndex]);
        argIndex++;
        for (int j = 0; j < num_subjects; ++j) {
            students[i].subjects.push_back({argv[argIndex]});
            argIndex++;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << "Student ID: " << students[i].id << endl;
        for (const auto& subject : students[i].subjects) {
            cout << "  Subject: " << subject.name << endl;
        }
    }

    delete[] students;
    return 0;
}

