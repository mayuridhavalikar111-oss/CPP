#include <iostream>
class Animal {
public:
    void staticBind() { std::cout << "Animal\n"; }
    virtual void dynamicBind() { std::cout << "Animal Sound\n"; }
};
class Dog : public Animal {
public:
    void staticBind() { std::cout << "Dog\n"; }
    void dynamicBind() override { std::cout << "Bark\n"; }
};
int main() {
    Animal* ptr = new Dog(); // Animal pointer to a Dog object

    ptr->staticBind();  // Prints "Animal" (Uses pointer type at compile-time)
    ptr->dynamicBind(); // Prints "Bark"   (Uses actual object type at runtime)
    delete ptr;
}
