#include <iostream>
#include <string>

using namespace std;

class Skill {
private:
    string skillId;
    string skillName;
    string description;
public:
    Skill() {}
    Skill(string id, string name, string desc) : skillId(id), skillName(name), description(desc) {}

    string getSkillId() { return skillId; }
    string getSkillName() { return skillName; }
    string getDescription() { return description; }

    void showSkills() {
        cout << "Skill ID: " << skillId << "\nSkill Name: " << skillName << "\nDescription: " << description << endl;
    }

    void updateSkills(string newDesc) {
        description = newDesc;
    }
};

class Sports {
private:
    string sportsId;
    string name;
    string description;
    Skill requiredSkills[5];
    int skillCount;
public:
    Sports() {}
    Sports(string id, string n, string desc) : sportsId(id), name(n), description(desc), skillCount(0) {}

    string getSportsId() { return sportsId; }
    string getSportsName() { return name; }
    string getDescription() { return description; }

    void addSkill(Skill s) {
        if (skillCount < 5) {
            requiredSkills[skillCount++] = s;
            cout << "Skill " << s.getSkillName() << " added to sport " << name << ".\n";
        } else {
            cout << "Cannot add more skills. Limit reached.\n";
        }
    }

    void removeSkill(string skillId) {
        bool found = false;
        for (int i = 0; i < skillCount; i++) {
            if (requiredSkills[i].getSkillId() == skillId) {
                found = true;
                for (int j = i; j < skillCount - 1; j++) {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                skillCount--;
                cout << "Skill " << skillId << " removed from sport " << name << ".\n";
                break;
            }
        }
        if (!found) {
            cout << "Skill not found in this sport.\n";
        }
    }

    void showSkills() {
        cout << "Skills for " << name << ":\n";
        for (int i = 0; i < skillCount; i++) {
            requiredSkills[i].showSkills();
        }
    }

    void display() {
        cout << "Sports ID: " << sportsId << "\nSports Name: " << name << "\nDescription: " << description << endl;
    }
};

class Student;

class Mentor {
private:
    string mentorId;
    string name;
    string sportsExpertise[5];
    int maxLearners;
    Student* assignedLearners[10];
    int learnerCount;
public:
    Mentor() {}
    Mentor(string id, string n, string expertise[], int max) : mentorId(id), name(n), maxLearners(max), learnerCount(0) {
        for (int i = 0; i < 5; i++) {
            sportsExpertise[i] = expertise[i];
        }
        for (int i = 0; i < 10; i++) {
            assignedLearners[i] = nullptr;
        }
    }

    string getMentorId() { return mentorId; }
    string getName() { return name; }
    int getMaxLearners() { return maxLearners; }
    int getLearnerCount() { return learnerCount; }

    bool assignLearner(Student* s);
    void removeLearner(Student* s);
    void viewDetails();
    void provideGuidance() {
        cout << name << " is providing guidance to students.\n";
    }
};

class Student {
private:
    string studentId;
    string name;
    Sports sportsInterests[5];
    int interestCount;
    Mentor* assignedMentor;
public:
    Student() { assignedMentor = nullptr; }
    Student(string id, string n) : studentId(id), name(n), interestCount(0), assignedMentor(nullptr) {}

    string getStudentId() { return studentId; }
    string getName() { return name; }
    Mentor* getAssignedMentor() { return assignedMentor; }

    void updateSportsInterest(Sports s) {
        if (interestCount < 5) {
            sportsInterests[interestCount++] = s;
            cout << "Sport " << s.getSportsName() << " added to student " << name << "'s interests.\n";
        } else {
            cout << "Cannot add more sports interests.\n";
        }
    }

    void registerMentor(Mentor* m) {
        if (m->assignLearner(this)) {
            assignedMentor = m;
            cout << name << " has been assigned to mentor " << m->getName() << "\n";
        } else {
            cout << "Mentor is at full capacity.\n";
        }
    }

    void displayMentorDetails() {
        if (assignedMentor) {
            assignedMentor->viewDetails();
        } else {
            cout << "No mentor assigned.\n";
        }
    }
};

bool Mentor::assignLearner(Student* s) {
    if (learnerCount < maxLearners) {
        assignedLearners[learnerCount++] = s;
        return true;
    }
    return false;
}

void Mentor::removeLearner(Student* s) {
    bool found = false;
    for (int i = 0; i < learnerCount; i++) {
        if (assignedLearners[i] == s) {
            found = true;
            for (int j = i; j < learnerCount - 1; j++) {
                assignedLearners[j] = assignedLearners[j + 1];
            }
            assignedLearners[learnerCount - 1] = nullptr;
            learnerCount--;
            cout << "Student " << s->getName() << " removed from mentor " << name << ".\n";
            break;
        }
    }
    if (!found) {
        cout << "Student not found under this mentor.\n";
    }
}

void Mentor::viewDetails() {
    cout << "Mentor ID: " << mentorId << "\nMentor Name: " << name << "\nExpertise: ";
    for (int i = 0; i < 5; i++) {
        cout << sportsExpertise[i] << " ";
    }
    cout << "\nAssigned Learners: ";
    for (int i = 0; i < learnerCount; i++) {
        if (assignedLearners[i]) {
            cout << assignedLearners[i]->getName() << " ";
        }
    }
    cout << endl;
}

int main() {
    
    Mentor mentors[3] = {
        Mentor("M001", "Ali", (string[]){"Football", "Basketball", "Cricket", "Tennis", "Swimming"}, 3),
        Mentor("M002", "Sara", (string[]){"Badminton", "Hockey", "Volleyball", "Table Tennis", "Athletics"}, 3),
        Mentor("M003", "Usman", (string[]){"Karate", "Judo", "Wrestling", "Boxing", "MMA"}, 3)
    };

    Student students[10];
    int studentCount = 0;

 
    Sports sportsList[3] = {
        Sports("SP001", "Football", "A team sport played with a round ball"),
        Sports("SP002", "Basketball", "A team sport played with a ball and hoop"),
        Sports("SP003", "Tennis", "A sport played with a racket and ball")
    };

  
    Skill skills[3] = {
        Skill("SK001", "Dribbling", "Ability to control the ball while moving"),
        Skill("SK002", "Shooting", "Ability to score goals"),
        Skill("SK003", "Passing", "Ability to pass the ball accurately")
    };

    int choice;
    do {
        cout << "\nWelcome to the Mentorship System" << endl;
        cout << "------ Student Options-------" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Assign Mentor to Student" << endl;
        cout << "3. Update Sports Interest of Student" << endl;
        cout << "4. View Student’s Mentor Details" << endl;
        cout << " ----Mentor Options------" << endl;
        cout << "5. View Mentor Details" << endl;
        cout << "6. Remove Student from Mentor" << endl;
        cout << "7. Add Skill to Sport" << endl;
        cout << "8. Update Skill Description" << endl;
        cout << "9. Remove Skill from Sport" << endl;
        cout << "10. Provide Guidance to Students" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
              
                if (studentCount < 10) {
                    string id, name;
                    cout << "Enter Student ID: ";
                    cin >> id;
                    cout << "Enter Student Name: ";
                    cin >> name;
                    students[studentCount++] = Student(id, name);
                    cout << "Student registered successfully!\n";
                } else {
                    cout << "Student limit reached.\n";
                }
                break;
            }
            case 2: {
            
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                string studentName;
                cout << "Enter Student Name: ";
                cin >> studentName;

                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].getName() == studentName) {
                        cout << "1. Ali\n2. Sara\n3. Usman\n";
                        int mentorChoice;
                        cout << "Enter mentor number: ";
                        cin >> mentorChoice;

                        if (mentorChoice >= 1 && mentorChoice <= 3) {
                            students[i].registerMentor(&mentors[mentorChoice - 1]);
                        } else {
                            cout << "Invalid choice.\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 3: {
               
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                string studentName;
                cout << "Enter Student Name: ";
                cin >> studentName;

                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].getName() == studentName) {
                        cout << "1. Football\n2. Basketball\n3. Tennis\n";
                        int sportChoice;
                        cout << "Enter sport number: ";
                        cin >> sportChoice;

                        if (sportChoice >= 1 && sportChoice <= 3) {
                            students[i].updateSportsInterest(sportsList[sportChoice - 1]);
                        } else {
                            cout << "Invalid choice.\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                string studentName;
                cout << "Enter Student Name: ";
                cin >> studentName;

                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].getName() == studentName) {
                        students[i].displayMentorDetails();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 5: {
             
                cout << "1. Ali\n2. Sara\n3. Usman\n";
                int mentorChoice;
                cout << "Enter mentor number: ";
                cin >> mentorChoice;

                if (mentorChoice >= 1 && mentorChoice <= 3) {
                    mentors[mentorChoice - 1].viewDetails();
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 6: {
           
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                string studentName;
                cout << "Enter Student Name: ";
                cin >> studentName;

                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].getName() == studentName) {
                        Mentor* mentor = students[i].getAssignedMentor();
                        if (mentor) {
                            mentor->removeLearner(&students[i]);
                        } else {
                            cout << "No mentor assigned to this student.\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 7: {
               
                cout << "1. Football\n2. Basketball\n3. Tennis\n";
                int sportChoice;
                cout << "Enter sport number: ";
                cin >> sportChoice;

                if (sportChoice >= 1 && sportChoice <= 3) {
                    sportsList[sportChoice - 1].addSkill(skills[sportChoice - 1]);
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 8: {
                
                cout << "1. Dribbling\n2. Shooting\n3. Passing\n";
                int skillChoice;
                cout << "Enter skill number: ";
                cin >> skillChoice;

                if (skillChoice >= 1 && skillChoice <= 3) {
                    string newDesc;
                    cout << "Enter new description: ";
                    cin.ignore();
                    getline(cin, newDesc);
                    skills[skillChoice - 1].updateSkills(newDesc);
                    cout << "Skill description updated.\n";
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 9: {
                
                cout << "1. Football\n2. Basketball\n3. Tennis\n";
                int sportChoice;
                cout << "Enter sport number: ";
                cin >> sportChoice;

                if (sportChoice >= 1 && sportChoice <= 3) {
                    string skillId;
                    cout << "Enter Skill ID to remove: ";
                    cin >> skillId;
                    sportsList[sportChoice - 1].removeSkill(skillId);
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 10: {
               
                cout << "1. Ali\n2. Sara\n3. Usman\n";
                int mentorChoice;
                cout << "Enter mentor number: ";
                cin >> mentorChoice;

                if (mentorChoice >= 1 && mentorChoice <= 3) {
                    mentors[mentorChoice - 1].provideGuidance();
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 11: {
              
                cout << "Exiting the program. Thank you!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 11);

    return 0;
}
