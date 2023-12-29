/*
In C++, an enum (enumeration) is a user-defined data type that consists of integral 
constants, known as enumerators. Enumerations provide a way to create named constants
 that represent a set of distinct values, improving code readability and maintainability.

*/


#include <iostream>

// Define an enumeration named Color
enum Color {
    RED,    // 0
    GREEN,  // 1
    BLUE    // 2
};

int main() {
    // Declare a variable of type Color
    Color myColor = GREEN;

    // Use the variable in a switch statement
    switch (myColor) {
        case RED:
            std::cout << "The color is red." << std::endl;
            break;
        case GREEN:
            std::cout << "The color is green." << std::endl;
            break;
        case BLUE:
            std::cout << "The color is blue." << std::endl;
            break;
        default:
            std::cout << "Unknown color." << std::endl;
    }

    return 0;
}

