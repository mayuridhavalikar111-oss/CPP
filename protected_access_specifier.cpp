/*Use of the protected Access Specifier: Create a base class Employee with protected data members employeeId and salary. Derive a class Manager and access these members through a member function of the derived class. Display the employee details*/

#include <iostream>
using namespace std;


class Employee {
protected:
    int employeeId;
    double salary;

public:
    Employee(int id, double sal) {
        employeeId = id;
        salary = sal;
    }
};

class Manager : public Employee {
public:
    Manager(int id, double sal) : Employee(id, sal) {}

    void displayDetails() {
        cout << "Manager Details " << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Manager m(101, 85500.50);
        m.displayDetails();
    return 0;
}
