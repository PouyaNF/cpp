

/**
 * 
 * It occurs when a class inherits from two or more classes 
 * that have a common base class. If the derived class doesn't handle 
 * the inherited members and methods from the base class correctly, ambiguity can arise.
 * 
 * 
 * The problem arises when you try to call the foo() method on an object of class D in the main() function. Since both B and
 *  C inherit from A, and class D inherits from both B and C, there are two paths through which D can reach the foo() 
 *  method. This ambiguity causes a compilation error.
 * 
 */


#include <iostream>

class A {
public:
    void foo() { std::cout << "A::foo()" << std::endl; }
};

class B : public A {};

class C : public A {};

class D : public B, public C {};

int main() {
    D d;
    d.foo();  // Ambiguity arises here, which foo() to call?
    return 0;
}





/**
 * 
 * To resolve the diamond problem, C++ introduced the concept of "virtual inheritance." 
 * By declaring the inheritance from A in B and C as virtual, you ensure that there's only
 * one instance of the common base class A in the hierarchy. Here's how it would look:
 * 
 */


#include <iostream>

class A {
public:
    void foo() { std::cout << "A::foo()" << std::endl; }
};

class B : virtual public A {};

class C : virtual public A {};

class D : public B, public C {};

int main() {
    D d;
    d.foo();  // No ambiguity, calls A::foo()
    return 0;
}