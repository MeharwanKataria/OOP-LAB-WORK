#include <iostream>
#include <string>

using namespace std;

int calculateHash(const string& password, int hash = 5381) {
    for (char c : password) {
        hash = hash * 33 + static_cast<int>(c);
    }
    return hash;
}

class User {
protected:
    string name;
    string id;
    string permissions[5];
    int permissionCount;
    string email;
    int hashedPassword;

public:
    User(const string& name, const string& id, const string permissions[], 
         int permCount, const string& email, const string& password) 
        : name(name), id(id), email(email), permissionCount(permCount) {
        hashedPassword = calculateHash(password);
        for (int i = 0; i < permCount; i++) {
            this->permissions[i] = permissions[i];
        }
    }

    bool authenticate(const string& password) {
        return hashedPassword == calculateHash(password);
    }

    virtual void display() {
        cout << "Name: " << name << "\nID: " << id << "\nEmail: " << email << "\nPermissions: ";
        for (int i = 0; i < permissionCount; i++) {
            cout << permissions[i] << " ";
        }
        cout << endl;
    }

    bool hasPermission(const string& action) {
        for (int i = 0; i < permissionCount; i++) {
            if (permissions[i] == action) return true;
        }
        return false;
    }

    bool accessLab(const string& action) {
        if (hasPermission(action)) {
            cout << name << " has permission to perform: " << action << endl;
            return true;
        }
        cout << name << " does not have permission to perform: " << action << endl;
        return false;
    }

    string getName() const { return name; }

    virtual ~User() {}
};

class Student : public User {
protected:
    int assignments[10];
    int assignmentCount;

public:
    Student(const string& name, const string& id, const string& email, const string& password)
        : User(name, id, new string[1]{"submit assignment"}, 1, email, password), assignmentCount(0) {
        for (int i = 0; i < 10; i++) assignments[i] = 0;
    }

    void display() override {
        cout << "Student Information:\n";
        User::display();
        cout << "Assignments Status:\n";
        for (int i = 0; i < assignmentCount; i++) {
            cout << "Assignment " << i+1 << ": " << (assignments[i] ? "Submitted" : "Pending") << endl;
        }
    }

    void addAssignment() {
        if (assignmentCount < 10) {
            assignments[assignmentCount++] = 0;
        }
    }

    void submitAssignment(int assignmentNum) {
        if (assignmentNum > 0 && assignmentNum <= assignmentCount) {
            assignments[assignmentNum-1] = 1;
            cout << name << " submitted assignment " << assignmentNum << endl;
        } else {
            cout << "Invalid assignment number\n";
        }
    }
};

class TA : public Student {
private:
    Student* managedStudents[10];
    int studentCount;
    string projects[2];
    int projectCount;

public:
    TA(const string& name, const string& id, const string& email, const string& password)
        : Student(name, id, email, password), studentCount(0), projectCount(0) {
        permissions[permissionCount++] = "view projects";
        permissions[permissionCount++] = "manage_students";
    }

    void display() override {
        cout << "Teaching Assistant Information:\n";
        User::display();
        cout << "Managed Students: " << studentCount << endl;
        cout << "Current Projects:\n";
        for (int i = 0; i < projectCount; i++) {
            cout << "- " << projects[i] << endl;
        }
    }

    bool addStudent(Student* student) {
        if (studentCount >= 10) {
            cout << "Cannot assign more than 10 students to a TA\n";
            return false;
        }
        managedStudents[studentCount++] = student;
        cout << "Assigned student " << student->getName() << " to TA " << name << endl;
        return true;
    }

    bool addProject(const string& projectName) {
        if (projectCount >= 2) {
            cout << "TA " << name << " is already working on 2 projects\n";
            return false;
        }
        projects[projectCount++] = projectName;
        cout << "Added project " << projectName << " to TA " << name << endl;
        return true;
    }

    void viewProjects() {
        cout << "TA " << name << "'s projects:\n";
        for (int i = 0; i < projectCount; i++) {
            cout << "- " << projects[i] << endl;
        }
    }
};

class Professor : public User {
public:
    Professor(const string& name, const string& id, const string& email, const string& password)
        : User(name, id, new string[2]{"assign projects", "full_lab_access"}, 2, email, password) {}

    void display() override {
        cout << "Professor Information:\n";
        User::display();
    }

    bool assignProject(TA* ta, const string& projectName) {
        return ta->addProject(projectName);
    }
};

void authenticateAndPerformAction(User* user, const string& password, const string& action) {
    if (user->authenticate(password)) {
        cout << "Authentication successful!\n";
        user->accessLab(action);
    } else {
        cout << "Authentication failed! Invalid password.\n";
    }
}

int main() {
    
    Student student1("Mehrwan ", "S001", "mehrwan@uni.edu", "student123");
    TA ta1("Aarav Patel", "T001", "aarav@uni.edu", "ta123");
    Professor prof1("Dr. Fatima Khan", "P001", "fatima@uni.edu", "prof123");

    student1.addAssignment();
    student1.addAssignment();
    student1.submitAssignment(1);

    ta1.addStudent(&student1);
    ta1.addProject("Lab Project 1");

    prof1.assignProject(&ta1, "Research Project");

    student1.display();
    ta1.display();
    prof1.display();

    authenticateAndPerformAction(&student1, "student123", "submit assignment");
    authenticateAndPerformAction(&ta1, "ta123", "manage_students");
    authenticateAndPerformAction(&prof1, "prof123", "full_lab_access");
    authenticateAndPerformAction(&prof1, "wrongpass", "full_lab_access");

    return 0;
}
