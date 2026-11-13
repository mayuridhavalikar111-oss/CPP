/*Hierarchical Inheritance: Create a base class Shape with a member function display(). Derive three classes, Circle, Rectangle, and Triangle. Each derived class should calculate and display the area of its respective shape.*/

#include<iostream>
using namespace std;

class Shape 
{
public:
    virtual void display() const {
        cout << "This is a generic shape." << endl;
    }
    virtual ~Shape()
    {}   // destructor 
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double Area()
    {
        return 3.14 * radius * radius;
    }
    void display() 
    {
        cout << "Shape: Circle Radius: " << radius << endl;
        cout << " Area: " << Area() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double Area() 
    {
        return length * breadth;
    }
    void display() 
    {
        cout << "Shape: Rectangle Length: " << length << ", Breadth: " << breadth << endl;
        cout << " Area: " << Area() << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double Area() const {
        return 0.5 * base * height;
    }

    void display() const override 
    {
        cout << "Shape: Triangle Base: " << base << ", Height: " << height << endl;
        cout << " Area: " << Area() << endl;
    }
};

int main() {
    Circle myCircle(5);
    Rectangle myRectangle(4, 6);
    Triangle myTriangle(3, 7);

    Shape* shapePtr;

    shapePtr = &myCircle;
    shapePtr->display();

    shapePtr = &myRectangle;
    shapePtr->display();

    shapePtr = &myTriangle;
    shapePtr->display();

    return 0;
}
