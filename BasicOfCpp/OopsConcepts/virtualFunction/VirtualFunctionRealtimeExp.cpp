#include <iostream>
using namespace std;

// Base class Employee
class Employee {
public:
    virtual void raiseSalary() {
        // common raise salary code
        cout << "Raising salary of an employee" << endl;
    }

    virtual void promote() {
        // common promote code
        cout << "Promoting an employee" << endl;
    }

    virtual ~Employee() {}
};

// Derived class Manager
class Manager : public Employee {
public:
    void raiseSalary() override {
        // Manager specific raise salary code
        cout << "Raising salary of a manager" << endl;
    }

    void promote() override {
        // Manager specific promote code
        cout << "Promoting a manager" << endl;
    }
};

// Another derived class Engineer
class Engineer : public Employee {
public:
    void raiseSalary() override {
        // Engineer specific raise salary code
        cout << "Raising salary of an engineer" << endl;
    }

    void promote() override {
        // Engineer specific promote code
        cout << "Promoting an engineer" << endl;
    }
};

// Another derived class Intern
class Intern : public Employee {
public:
    void raiseSalary() override {
        // Intern specific raise salary code
        cout << "Raising salary of an intern" << endl;
    }

    void promote() override {
        // Intern specific promote code
        cout << "Promoting an intern" << endl;
    }
};

// Function to raise salary of all employees
void globalRaiseSalary(Employee* emp[], int n) {
    for (int i = 0; i < n; i++) {
        // Polymorphic Call: Calls raiseSalary()
        // according to the actual object, not
        // according to the type of pointer
        emp[i]->raiseSalary();
    }
}

// Main function to test the code
int main() {
    // Creating objects of different types of employees
    Manager m1, m2;
    Engineer e1, e2, e3;
    Intern i1;

    // Creating an array of pointers to Employee
    Employee* employees[] = { &m1, &m2, &e1, &e2, &e3, &i1 };

    // Total number of employees
    int n = sizeof(employees) / sizeof(employees[0]);

    // Raising salary of all employees
    globalRaiseSalary(employees, n);

    return 0;
}
