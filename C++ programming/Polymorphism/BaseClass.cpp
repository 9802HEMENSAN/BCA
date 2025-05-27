#include <iostream>
using namespace std;

class Base {
public:
    int x;

    // Parameterized constructor for base class
    Base(int a) {
        x = a;
        cout << "Base class constructor called with value: " << x << endl;
    }
};

class Derived : public Base {
public:
    int y;

    // Parameterized constructor for derived class
    // Note how the base class constructor is called explicitly using the initializer list
    Derived(int a, int b) : Base(a) {
        y = b;
        cout << "Derived class constructor called with value: " << y << endl;
    }
};

int main() {
    // Create an object of Derived class
    Derived obj(10, 20);

    return 0;
}
