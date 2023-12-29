/*
Allows objects of different types to be treated as objects of a common superclass. 
It enables a single interface to represent different underlying data types or classes allowing 
greater flexibility and extensibility in software design.

Compile-time (Static) Polymorphism:
Method Overloading: This occurs when a class has multiple methods with the same name but different
 parameter lists (number or type of parameters). The appropriate method to be called is determined 
 at compile time based on the number or types of arguments provided to the method call.
 Operator Overloading: It allows operators (e.g., +, -, *, /) to be used with custom data types, 
 defining specific behaviors for those operators with respect to the objects of the class.
 
Runtime (Dynamic) Polymorphism:
Method Overriding: This occurs when a subclass provides a specific implementation of a method that 
is already defined in its superclass. When a method is called on an object of the subclass, the
 overridden method in the subclass is executed, rather than the one in the superclass.
Interface Polymorphism: This is achieved using interfaces or abstract classes. Multiple classes
 can implement the same interface or extend the same abstract class, and they can be used 
 interchangeably through the common interface or abstract class type.

*/


// Example of Runtime Polymorphism : 

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
};

// Derived class 1: Circle
class Circle : public Shape {
public:
    // Implementation of the draw function for Circle
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

// Derived class 2: Square
class Square : public Shape {
public:
    // Implementation of the draw function for Square
    void draw() override {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    int choice;
    Shape* shapePtr; // Pointer to Shape object

    cout << "Enter 1 for circle or 2 for square: ";
    cin >> choice;

    if (choice == 1) {
        shapePtr = new Circle(); // Create a Circle object dynamically
    } else {
        shapePtr = new Square(); // Create a Square object dynamically
    }

    shapePtr->draw(); // Call draw() function of the appropriate derived class
    delete shapePtr;  // Free memory allocated for the object

    return 0;
}

