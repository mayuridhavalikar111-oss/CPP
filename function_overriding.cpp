/*Function Overriding and Runtime Polymorphism: Create a base class Animal with a virtual function makeSound(). Derive classes Dog, Cat, and Cow, and override makeSound() in each derived class. Use base-class pointers to demonstrate runtime polymorphism.*/

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "The animal makes a generic sound." << endl;
    }
    ~Animal() {
        cout << "Animal destructor called." << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "The dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "The cat meows" << endl;
    }
};

class Cow : public Animal {
public:
    void makeSound()  {
        cout << "The cow moos: Moo! Moo!" << endl;
    }
};

int main() {
    const int ARRAY_SIZE = 4;
    Animal* animals[ARRAY_SIZE];
    
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();
    animals[3] = new Animal();  

    for (int i = 0; i < ARRAY_SIZE; i++) {
        animals[i]->makeSound(); 
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete animals[i];
    }

    return 0;
}
