/*Hybrid Inheritance: Create a class Person containing the data members name and age. Derive two classes, Student and Employee, from Person. Create a class TeachingAssistant that inherits from both Student and Employee. Demonstrate the diamond problem and resolve it using virtual inheritance.*/

#include <iostream>
using namespace std;

class person {
protected:
    string name;
    int age;
public:
    person(string n, int a)
    {
        name=n;
        age=a;
    }
};

class student:  virtual public person{
public:
    student(string n, int a) : person(n, a) {
        cout<<"Student class constructor"<<endl;
    }
};

class employee : virtual public person{
public:
    employee(string n, int a) : person(n, a) {
        cout<<"Employee class constructor"<<endl;
    }
};

class TeachingAssistant : public student, public employee {
public:
    TeachingAssistant(string n, int a) :person(n, a), student(n, a), employee(n, a) {
        cout<<"TeachingAssistant class constructor"<<endl;
    }
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    TeachingAssistant t("John Doe", 25);
    t.displayDetails();
    return 0;
}