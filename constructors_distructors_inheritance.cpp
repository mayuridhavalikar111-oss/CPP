/*Constructor and Destructor in Inheritance: Create a base class Vehicle and a derived class Car. Define constructors and destructors in both classes. Write a program to demonstrate the order of constructor and destructor execution when a derived-class object is created and destroyed.*/

#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle Constructor ." << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle Destructor" << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        cout << " Car (Derived) Constructor." << endl;
    }

    ~Car() override {
        cout << "Car (Derived) Destructor." << endl;
    }
};

int main() {
    {
        Car myCar; 
    } 

    cout << "Program Finished " << endl;
    return 0;
}
