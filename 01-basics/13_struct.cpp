/*
struct Is a user-defined data type that groups related data items of different data types together. 
Like classes, structs can have member functions, constructors, and destructors.
 The main difference between struct and class is that the default access level for 
 members and inheritance is public in a struct, whereas it is private in a class.
 
struct is part of both C and C++, making it compatible with C code.
 If you are working in a mixed C and C++ environment or need to interact with C libraries, 
 using struct can simplify interoperability.
For simple data holders without complex behaviors, struct is often preferred for its simplicity. 
It reflects a plain data structure without encapsulation or the need for private members.
 

*/


#include <iostream>
#include <string>

// Define a struct named Person
struct Person {
    // Public members by default
    std::string name;
    int age;
};

int main() {
    // Create an instance of the Person struct
    Person person1;

    // Access and set values for the members
    person1.name = "John Doe";
    person1.age = 25;

    // Print the values
    std::cout << "Name: " << person1.name << ", Age: " << person1.age << std::endl;

    return 0;
}

