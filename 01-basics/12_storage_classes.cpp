/*

In C++, storage classes determine the scope, visibility, and lifetime of variables. 
There are four main storage classes in C++: auto, register, static, and extern.
*/


//auto:
//The auto storage class is the default for local variables. 
//It automatically deduces the type of the variable at compile time.
//They are created when the program enters the block in which they are 
//defined and destroyed when the program exits the block. 
#include <iostream>

int main() {
    auto x = 5; // Compiler deduces x as int
    std::cout << "Value of x: " << x << std::endl;
    return 0;
}

//The register storage class suggests to the compiler that the variable should
// be stored in a CPU register for faster access. 
//Note that the compiler is free to ignore this suggestion.

#include <iostream>

int main() {
    register int count = 10; // Suggesting to store 'count' in a register
    std::cout << "Value of count: " << count << std::endl;
    return 0;
}

//static:

//The static storage class is used to specify that a variable has a static (global) scope 
//if declared outside a function or has a persistent value between function calls if declared 
//inside a function.

#include <iostream>

int globalVar = 5; // Static variable with global scope

int main() {
    static int localVar = 10; // Static variable with local scope
    std::cout << "Global variable: " << globalVar << std::endl;
    std::cout << "Local variable: " << localVar << std::endl;
    return 0;
}


//extern:

//The extern storage class is used to declare a variable or function that is 
//defined in another file or at the later part of the current file.

// File1.cpp
#include <iostream>
extern int sharedVar; // Declaring sharedVar from another file

int main() {
    std::cout << "Shared variable: " << sharedVar << std::endl;
    return 0;
}
