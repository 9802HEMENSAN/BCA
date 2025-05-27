Runtime Polymorphism
Definition: Runtime polymorphism is a feature of object-oriented programming where a function call is resolved at runtime, allowing a single function to perform different tasks based on the object it is called on.
Purpose: It enables dynamic method dispatch, providing flexibility and extensibility in code.
Key Idea: The decision about which method to invoke is made during program execution, not at compile time.
How Is Runtime Polymorphism Achieved?
Runtime polymorphism is typically achieved through:

Inheritance: A base class defines a common interface that derived classes can override.
Function Overriding: A derived class provides its own implementation of a method that exists in the base class.
Pointers or References: The base class pointer or reference is used to call the overridden method.
Virtual Functions: In C++ and similar languages, methods in the base class are marked as virtual to enable dynamic dispatch.
Example in C++
Here’s an example to demonstrate runtime polymorphism using virtual functions: