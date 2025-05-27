#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { // Virtual function
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override { // Overridden function
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override { // Overridden function
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animal; // Pointer to base class

    Dog dog;
    Cat cat;

    animal = &dog; // Base class pointer points to derived class object
    animal->sound(); // Calls Dog's sound() method (runtime polymorphism)

    animal = &cat; // Base class pointer points to another derived class object
    animal->sound(); // Calls Cat's sound() method (runtime polymorphism)

    return 0;
}

 