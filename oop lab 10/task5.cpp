#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addTask() {
    ofstream file("tasks.txt", ios::app);
    string task;

    cout << "Enter a task: ";
    getline(cin, task);

    file << "[ ] " << task << endl;
    file.close();

    cout << "Task added!\n";
}

void viewTasks() {
    ifstream file("tasks.txt");
    string line;
    int number = 1;

    cout << "\nTasks:\n";
    while (getline(file, line)) {
        cout << number << ". " << line << endl;
        number++;
    }

    file.close();
}

void markTaskDone() {
    ifstream file("tasks.txt");
    string tasks[100];
    int count = 0;

    while (getline(file, tasks[count])) {
        count++;
    }

    file.close();

    viewTasks();

    int n;
    cout << "Enter task number to mark done: ";
    cin >> n;
    cin.ignore();

    if (n >= 1 && n <= count) {
        tasks[n - 1].replace(0, 3, "[X]");
    }

    ofstream out("tasks.txt");
    for (int i = 0; i < count; i++) {
        out << tasks[i] << endl;
    }

    out.close();
    cout << "Task marked as done!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\nTo-Do List\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
            addTask();
        else if (choice == 2)
            viewTasks();
        else if (choice == 3)
            markTaskDone();
        else if (choice == 4)
            break;
        else
            cout << "Invalid choice!\n";
    }

    return 0;
}