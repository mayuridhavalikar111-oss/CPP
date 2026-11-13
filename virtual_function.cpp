/*Abstract Class and Pure Virtual Function: Create an abstract base class Shape with a pure virtual function calculateArea(). Derive classes Circle, Rectangle, and Triangle that implement the function. Use base-class pointers to calculate and display the areas of different shapes.*/

#include <iostream>
using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;

    virtual ~Shape() {
        cout << "Shape Destructor called." << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    ~Circle() override {
        cout << "Circle Destructor called." << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }

    ~Rectangle() override {
        cout << "Rectangle Destructor called." << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double calculateArea() const override {
        return 0.5 * base * height;
    }

    ~Triangle() override {
        cout << "Triangle Destructor called." << endl;
    }
};

int main() {
    Shape* shapes[3];

    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 7.0);

    cout << "Calculating Areas Polymorphically" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Area of Shape [" << i + 1 << "]: "
             << shapes[i]->calculateArea() << endl;
    }

    cout << "\nCleaning up Memory" << endl;

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
