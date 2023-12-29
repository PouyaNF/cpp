/*
Runtime Polymorphism: 
When you want to create objects of derived classes at runtime based on user input 
or other conditions, you need to use dynamic memory allocation to create objects 
of the appropriate derived class.

Memory Management:
 When you want to allocate memory for objects on the heap rather than the stack, 
 you can dynamically create class objects using the "new" operator.

Object Lifetime:
 When you want to create an object that persists beyond the scope of the function
 or block in which it was created, you can create the object dynamically.
 
 Resource Allocation: 
 When you need to manage limited resources such as file handles, network connections, 
 or database connections, you can create objects dynamically and release them when
 they are no longer needed.
*/


#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass(int id) : id_(id) {
        cout << "Creating MyClass with id " << id_ << endl;
    }

    ~MyClass() {
        cout << "Destroying MyClass with id " << id_ << endl;
    }

    void doSomething() {
        cout << "MyClass with id " << id_ << " is doing something" << endl;
    }

private:
    int id_;
};

void myFunction() {
    MyClass *ptr = new MyClass(1); // create a MyClass object dynamically
    // use ptr to access object...
    ptr->doSomething();
    // don't delete ptr here, as we want to keep the object alive
    return;
}

int main() {
    myFunction();
    // object created in myFunction() still exists here
    MyClass *ptr2 = new MyClass(2); // create another MyClass object dynamically
    ptr2->doSomething();
    delete ptr2;
    return 0;
}
