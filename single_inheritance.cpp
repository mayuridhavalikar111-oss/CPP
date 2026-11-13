/*Single Inheritance: Create a class Person with data members name and age. Derive a class Student that inherits from Person and adds rollNumber and course. Initialize the data members using constructors and display the complete student details.*/


#include<iostream>
using namespace std;

class person{
    protected:
    string name;
    int age;

    public:
    person(string n, int a){
        name=n;
        age=a;
    }
};

class student : public person
{
    protected:
    int rollNo;
    string course;

    public:
    student(string n, int a, int rn, string c) : person(n, a){
        rollNo=rn;
        course=c;
    }
void displayDetails() 
{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Course: " << course << endl;
}
};

int main()
{
    student s1("ABC", 20, 101, "Computer Science");
    s1.displayDetails();
    return 0;
}