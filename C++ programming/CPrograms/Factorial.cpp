// (b) Write C++ program to find factorial of a
// given number using copy constructor.

#include <iostream>
using namespace std;

class Factorial {
    int number;
    long long fact;

public:
    // Parameterized constructor
    Factorial(int n) {
        number = n;
        fact = 1;
        for (int i = 1; i <= number; i++) {
            fact *= i;
        }
    }

    // Copy Constructor
    Factorial(const Factorial &f) {
        number = f.number;
        fact = f.fact;
    }

    // Display function
    void display() {
        cout << "Factorial of " << number << " is " << fact << endl;
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    Factorial f1(num);   // Original object calculates factorial
    Factorial f2 = f1;   // Copy constructor is called

    cout << "Original Object: ";
    f1.display();

    cout << "Copied Object: ";
    f2.display();

    return 0;
}
