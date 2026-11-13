/*Multilevel Inheritance: Create three classes: Employee, Manager, and SeniorManager, where Manager inherits from Employee and SeniorManager inherits from Manager. Initialize the data members using parameterized constructors and demonstrate constructor chaining.*/

#include<iostream>
using namespace std;

class employee{
protected:
    int id;
    string name;

public:
    employee(int id, string name): id(id), name(name) 
    {
        cout<<"Employee class constructor"<<endl;
    }
};

class manager: public employee{
protected:
    string department;

public:
    manager(int id, string name, string department): employee (id, name), department(department)
    {
        cout<<"Manager class constructor"<<endl;
    }
};


class seniorManager: public manager{
protected:
    int teamsize;

public:
    seniorManager(int id, string name, string department, int teamsize): manager ( id, name, department), teamsize(teamsize)
    {
        cout<<"SeniorManager class constructor"<<endl;
    }


void displayseniorManagerInfo(){
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Department: " << department << endl;
    cout << "Team Size: " << teamsize << endl;
}
};

int main(){
    seniorManager sm( 101,"Alice Smith", "Engineering", 15);

    cout << "--- SeniorManager Details ---" << endl;
    sm.displayseniorManagerInfo();

    return 0;

}

