#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;

public:
    // Parameterized Constructor
    Student(int r, string n) {
        roll = r;
        name = n;
        cout << "Parameterized Constructor Called" << endl;
    }

    // Copy Constructor
    Student(const Student &s) {
        roll = s.roll;
        name = s.name;
        cout << "Copy Constructor Called" << endl;
    }

    // Display Function
    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};

// Case 1: Object initialized using another object
void case1() {
    cout << "\n--- Case 1: Initialization using another object ---" << endl;
    Student s1(101, "Hemensan");
    Student s2 = s1;  // Copy constructor called
    s1.display();
    s2.display();
}

// Case 2: Object passed by value to a function
void showStudent(Student s) {
    cout << "Inside function showStudent(): ";
    s.display();
}

void case2() {
    cout << "\n--- Case 2: Passing object by value ---" << endl;
    Student s1(102, "Alex");
    showStudent(s1);  // Copy constructor called
}

// Case 3: Object returned by value from a function
Student createStudent() {
    Student temp(103, "Riya");
    return temp;  // Copy constructor may be called (depending on compiler optimization)
}

void case3() {
    cout << "\n--- Case 3: Returning object by value ---" << endl;
    Student s3 = createStudent();  // Copy constructor may be called
    s3.display();
}

// Main function
int main() {
    case1();
    case2();
    case3();

    return 0;
}


// Output 
/* 
[?2004l

--- Case 1: Initialization using another object ---
Parameterized Constructor Called
Copy Constructor Called
Roll: 101, Name: Hemensan
Roll: 101, Name: Hemensan

--- Case 2: Passing object by value ---
Parameterized Constructor Called
Copy Constructor Called
Inside function showStudent(): Roll: 102, Name: Alex

--- Case 3: Returning object by value ---
Parameterized Constructor Called
Roll: 103, Name: Riya
[?2004h

 */