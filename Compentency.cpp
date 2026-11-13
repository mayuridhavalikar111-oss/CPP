/*1.	Create three classes: Student, Marks, and Result. Derive Marks from Student and Result from Marks. Accept student details and marks in three subjects, then calculate the total, percentage, and grade.*/

#include<iostream>
using namespace std;

class student{
    public:
    string name;
    student(string n){
        name=n;
    }
};

class marks: public student{
    public:
    int sub1, sub2, sub3;
    marks(string n, int s1, int s2, int s3): student(n){
        sub1=s1;
        sub2=s2;
        sub3=s3;
    }
};

class result: public marks{
    public:
    int total;
    float percentage;
    char grade;
    result(string n, int s1, int s2, int s3): marks(n, s1, s2, s3){
        total=sub1+sub2+sub3;
        percentage=(total/300.0)*100;
        if(percentage>=80)
            grade='A';
        else if(percentage>=60)
            grade='B';
        else
            grade='C';
    }
};

int main(){
    string name;
    int s1, s2, s3;
    cout<<"Enter student name: ";
    cin>>name;
    cout<<"Enter marks in three subjects: ";
    cin>>s1>>s2>>s3;
    result r(name, s1, s2, s3);
    cout<<"Name: "<<r.name<<endl;
    cout<<"Total Marks: "<<r.total<<endl;
    cout<<"Percentage: "<<r.percentage<<endl;
    cout<<"Grade: "<<r.grade<<endl;
    return 0;
}

//2.	Create a base class Shape and derive classes Circle, Rectangle, and Triangle. Calculate and display the area of each shape.
#include <iostream>
using namespace std;

class Shape {
public:
void display() {
cout << "Calculating Area of Shapes" << endl;
}
};

class Circle : public Shape {
public:
float radius;

void calculateArea() {
    cout << "Enter radius of circle: ";
    cin >> radius;
    cout << "Area of Circle = " << 3.14 * radius * radius << endl;
}
};

class Rectangle : public Shape {
public:
float length, breadth;

void calculateArea() {
    cout << "Enter length and breadth of rectangle: ";
    cin >> length >> breadth;
    cout << "Area of Rectangle = " << length * breadth << endl;
}
};

class Triangle : public Shape {
public:
float base, height;

void calculateArea() {
    cout << "Enter base and height of triangle: ";
    cin >> base >> height;
    cout << "Area of Triangle = " << 0.5 * base * height << endl;
}
};

int main() {
Circle c;
Rectangle r;
Triangle t;

c.display();
c.calculateArea();

r.calculateArea();
t.calculateArea();

return 0;
}


//3.	Create classes Academic and Sports. Derive a class Result from both classes. Store academic marks and sports scores and display the student's overall performance.

#include<iostream>
using namespace std;

class academic{
    public:
    int marks;

    void getacademicMarks(){
        cout<<"Enter academic marks:"<<endl;
        cin>>marks;
    }
};

class sports{
    public:
    int score;

    void getsportsScore(){
        cout<<"Enter sports score:"<<endl;
        cin>>score;
    }
};

class result: public academic, public sports{
    public:
    void display(){
        cout<<"Academic Marks: "<<marks<<endl;
        cout<<"Sports Score: "<<score<<endl;
        int total=marks+score;
        cout<<"Total Score: "<<total<<endl;
    }
};

int main(){
    result r;

    r.getacademicMarks();
    r.getsportsScore(); 
    r.display();
    return 0;
}

//4.	Implement a hybrid inheritance structure involving classes Person, Student, Employee, and TeachingAssistant. Demonstrate the relationships and display the relevant details.

#include <iostream>
using namespace std;

class Person {
public:
string name;

void getPersonDetails() {
    cout << "Enter name: ";
    cin >> name;
}
};

class Student : public Person {
public:
int rollNo;

void getStudentDetails() {
    cout << "Enter roll number: ";
    cin >> rollNo;
}
};

class Employee : public Person {
public:
int employeeId;

void getEmployeeDetails() {
    cout << "Enter employee ID: ";
    cin >> employeeId;
}

};

class TeachingAssistant : public Student, public Employee {
public:
void display() {
cout << "\nStudent Name = " << Student::name << endl;
cout << "Roll Number = " << rollNo << endl;
cout << "Employee ID = " << employeeId << endl;
cout << "Employee Name = " << Employee::name << endl;
}
};

int main() {
TeachingAssistant ta;

ta.Student::getPersonDetails();
ta.getStudentDetails();
ta.getEmployeeDetails();
ta.Employee::getPersonDetails();

ta.display();

return 0;

}



//6.	Create a class Person, derive classes Student and Employee from it, and derive TeachingAssistant from both. Use a virtual base class to ensure that TeachingAssistant contains only one copy of the Person data.

#include <iostream>
using namespace std;

class Person {
public:
string name;

void getPersonDetails() {
    cout << "Enter name: ";
    cin >> name;
}
};

class Student : virtual public Person {
public:
int rollNo;

void getStudentDetails() {
    cout << "Enter roll number: ";
    cin >> rollNo;
}
};

class Employee : virtual public Person {
public:
int employeeId;
void getEmployeeDetails() {
    cout << "Enter employee ID: ";
    cin >> employeeId;
}
};

class TeachingAssistant : public Student, public Employee {
public:
void display() {
cout << "\nName = " << name << endl;
cout << "Roll Number = " << rollNo << endl;
cout << "Employee ID = " << employeeId << endl;
}
};

int main() {
TeachingAssistant ta;

ta.getPersonDetails();
ta.getStudentDetails();
ta.getEmployeeDetails();
ta.display();
return 0;

}

//6.	Create a base class Vehicle and a derived class Car. Implement default and parameterized constructors and destructors in both classes. Display messages to demonstrate the order in which constructors and destructors are called.

#include <iostream>
using namespace std;

class vehicle {
    public:
    vehicle(){
        cout<<"Vehicle constructor called."<<endl;
    }
    vehicle(int x){
        cout<<"VVehicle parameterized constructor called."<<endl;
    }
    ~vehicle(){
        cout<<"Vehicle destructor called."<<endl;
    }
};

class car: public vehicle{
    public:
    car(){
        cout<<"Car default constructor is called"<<endl;
    }

    car(int x): vehicle(x){
        cout<<"Car parameterized constructor is called"<<endl;
    }

    ~car(){
        cout<<"Car destrouctor is called"<<endl;
    }
};

int main(){
    cout << "Creating default object:" << endl;
    car c1;
    cout << "\nCreating parameterized object:" << endl; Car c2(10); return 0;
}

//7.	Create a base class Employee with a function display(). Override display() in the derived class Manager. Use the scope resolution operator to call both the base-class and derived-class versions of the function

#include <iostream>
using namespace std;

class employee{
    public:
    void display(){
        cout<<"Employee display function called."<<endl;
    }
};
class manager: public employee{
    public:
    void display(){
        cout<<"Manager display function called."<<endl;
    }
};

int main(){
    manager m;
    m.employee::display();
    m.manager::display();
    return 0;
}

//8.	Create a base class Payment with a function processPayment(). Derive classes CreditCardPayment, UPIPayment, and NetBankingPayment. Redefine the function in each derived class to display the corresponding payment process.

#include <iostream>
using namespace std;

class payment{
    public:
    virtual void processpayment(){
        cout<<"Processing payment..."<<endl;
    }
};

class creditcardpayment: public payment{
    public:
    void processpayment() override {
        cout<<"Processing credit card payment..."<<endl;
    }
};

class upipayment: public payment{
    public:
    void processpayment() override {
        cout<<"Processing UPI payment..."<<endl;
    }
};

class netbankingpayment: public payment{
    public:
    void processpayment() override {
        cout<<"Processing net banking payment..."<<endl;
    }
};

int main(){
    creditcardpayment c;
    upipayment u;
    netbankingpayment n;

    c.processpayment();
    u.processpayment();
    n.processpayment();

    return 0;
}

//9.	Create a class Student with data members rollNo, name, and marks. Use the this pointer in the constructor to distinguish data members from parameters. Display the student details.
#include<iostream>
using namespace std;

class student{
    public:
    int rollNo;
    string name;
    float marks;

    student(int rollNo, string name, float marks){
        this->rollNo=rollNo;
        this->name=name;
        this->marks=marks;
    }

    void display(){
        cout<<"Roll No: "<<rollNo<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
};

int main(){
    student s(101,'ABC',89.9);
    s.display();

    return 0;

}

//10.	Create overloaded functions named area() to calculate the area of a circle, rectangle, and square using different parameter lists.

#include <iostream>
using namespace std;

class Area {
public:
double area(double radius) {
return 3.14 * radius * radius;
}
double area(double length, double breadth) {
    return length * breadth;
}

int area(int side) {
    return side * side;
}
};

int main() {
Area a;
cout << "Area of Circle = " << a.area(5.0) << endl;
cout << "Area of Rectangle = " << a.area(4.0, 6.0) << endl;
cout << "Area of Square = " << a.area(5) << endl;

return 0;

}

//12.	Implement a class Complex with real and imaginary parts. Overload the + and * operators to perform addition and multiplication of two complex numbers.

#include <iostream>
using namespace std;

class Complex {
public:
int real, imag;

Complex(int r = 0, int i = 0) {
    real = r;
    imag = i;
}

Complex operator+(const Complex& c) {
    return Complex(real + c.real, imag + c.imag);
}

Complex operator*(const Complex& c) {
    return Complex(
        real * c.real - imag * c.imag,
        real * c.imag + imag * c.real
    );
}

void display() {
    cout << real;

    if (imag >= 0)
        cout << " + " << imag << "i" << endl;
    else
        cout << " - " << -imag << "i" << endl;
}
};

int main() {
Complex c1(3, 2);
Complex c2(2, 4);

Complex sum = c1 + c2;
Complex product = c1 * c2;

cout << "First Complex Number = ";
c1.display();

cout << "Second Complex Number = ";
c2.display();

cout << "Addition = ";
sum.display();

cout << "Multiplication = ";
product.display();

return 0;

}

//12.	Create a base class Shape with a virtual function calculateArea(). Derive classes Circle, Rectangle, and Triangle. Use a base-class pointer to call the appropriate derived-class function.

#include <iostream>
using namespace std;

class shape{
    public:
    virtual void calculatearea(){
        cout<<"Calculating area of shape..."<<endl;
    }
};

class circle: public shape{
    public:
    float radius;
    void calculatearea() override {
        cout<<"Enter radius of circle: ";
        cin>>radius;
        cout<<"Area of Circle = "<<3.14*radius*radius<<endl;
    }
};

class rectangle: public shape{
    public:
    float length, breadth;
    void calculatearea() override {
        cout<<"Enter length and breadth of rectangle: ";
        cin>>length>>breadth;
        cout<<"Area of Rectangle = "<<length*breadth<<endl;
    }
};

class triangle: public shape{
    public:
    float base, height;
    void calculatearea() override {
        cout<<"Enter base and height of triangle: ";
        cin>>base>>height;
        cout<<"Area of Triangle = "<<0.5*base*height<<endl;
    }
};

int main(){
    shape *s;
    circle c;
    rectangle r;
    triangle t;

    s=&c;
    s->calculatearea();

    s=&r;
    s->calculatearea();

    s=&t;
    s->calculatearea();

    return 0;
}

//13.	Create a base class Employee with a virtual function calculateSalary(). Derive classes PermanentEmployee and ContractEmployee, each implementing its own salary calculation. Demonstrate run-time polymorphism using base-class pointers.

#include <iostream>
using namespace std;

class employee{
    public:
    virtual void calculateSalary(){
        cout<<"Calculating salary of employee..."<<endl;
    }
};

class permentEmployee: public employee{
    public:
    void calculateSalary() override {
        cout<<"Calculating salary of permanent employee..."<<endl;
        return 5000+ 10000;
    }
};

class contractEmployee: public employee{
    public:
    void calculateSalary() override {
        cout<<"Calculating salary of contract employee..."<<endl;
        return 1000*20;
    }
};

int main(){
    employee *e;
    permentEmployee pe;
    contractEmployee ce;

    e=&pe;
    e->calculateSalary();

    e=&ce;
    e->calculateSalary();

    return 0;
}


//14.	Create a program demonstrating both concepts. Include overloaded functions in a base class and an overridden virtual function in a derived class. Explain how the compiler selects each function.

#include <iostream>
using namespace std;

class Base {
public:
// Function overloading
void display() {
cout << "Base display without arguments" << endl;
}
void display(int x) {
    cout << "Base display with integer: " << x << endl;
}

// Virtual function
virtual void show() {
    cout << "Base show function" << endl;
}

virtual ~Base() {}
};

class Derived : public Base {
public:
// Function overriding
void show() override {
cout << "Derived show function" << endl;
}
};

int main() {
Base b;
Derived d;

b.display();
b.display(10);

Base* ptr = &d;
ptr->show();

return 0;
}

//15.	Write a C++ program to implement a payment processing system using an abstract class Payment and derived classes CreditCardPayment, UPIPayment, and CashPayment.

#include <iostream>
using namespace std;

class Payment {
public:
virtual void processPayment() = 0;
virtual ~Payment() {}
};

class CreditCardPayment : public Payment {
public:
void processPayment() override {
cout << "Payment processed using Credit Card" << endl;
}
};

class UPIPayment : public Payment {
public:
void processPayment() override {
cout << "Payment processed using UPI" << endl;
}
};

class CashPayment : public Payment {
public:
void processPayment() override {
cout << "Payment processed using Cash" << endl;
}
};

int main() {
CreditCardPayment c;
UPIPayment u;
CashPayment cash;

Payment* ptr;

ptr = &c;
ptr->processPayment();

ptr = &u;
ptr->processPayment();

ptr = &cash;
ptr->processPayment();

return 0;
}
