#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef struct employee {
    string employee_name;
    int employee_id;
    int employee_salary;
} employee;

typedef struct organisation {
    string organisname;
    string organisno;
    employee organis_emp;
} organisation;

int main(int argc, char *argv[]) {
    
	organisation org;
    org.organisname = argv[1];
    org.organisno = argv[2];
    org.organis_emp.employee_id = stoi(argv[3]);
    org.organis_emp.employee_name = argv[4];
    org.organis_emp.employee_salary = stoi(argv[5]);

    cout << "Organisation Name: " << org.organisname << endl;
    cout << "Organisation Number: " << org.organisno << endl;
    cout << "Employee ID: " << org.organis_emp.employee_id << endl;
    cout << "Employee Name: " << org.organis_emp.employee_name << endl;
    cout << "Employee Salary: " << org.organis_emp.employee_salary << endl;

    return 0;
}
