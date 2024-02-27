#include <iostream>

// 1 - Return Values:
// Functions can return a special value to indicate an error. 
int divide(int a, int b) {
    if (b == 0) {
        // Error: Division by zero
        return -1;
    }
    return a / b;
}


// 2- Exception Handling:
//C++ supports exception handling using try, catch, and throw blocks.
// Function throws an exception on error
int divide(int a, int b) {
    if (b == 0) {
        // Error: Division by zero
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


// 3- Error Codes:
// You can use error codes to represent different types of errors.

#include <iostream>

enum ErrorCode {
    OK,
    DivisionByZero,
    OtherError
};

// Function returns an error code
ErrorCode divide(int a, int b, int& result) {
    if (b == 0) {
        // Error: Division by zero
        return DivisionByZero;
    }
    result = a / b;
    return OK;
}

int main() {
    int result;
    ErrorCode status = divide(10, 0, result);
    if (status == DivisionByZero) {
        std::cerr << "Error: Division by zero" << std::endl;
    } else if (status == OK) {
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cerr << "Unknown error" << std::endl;
    }

    return 0;
}


//4 - Assertion:
//The assert macro can be used to check conditions during development. 
//It's typically disabled in release builds.

#include <cassert>

int divide(int a, int b) {
    // Assertion: Ensure b is not zero
    assert(b != 0);
    return a / b;
}

int main() {
    int result = divide(10, 0); // Assertion failure in debug mode
    return 0;
}


// 5-Logging and Printing:
//You can log or print error messages to help diagnose issues.

#include <iostream>

int divide(int a, int b) {
    if (b == 0) {
        // Log: Division by zero
        std::cerr << "Error: Division by zero" << std::endl;
        return 0; // or handle in some way
    }
    return a / b;
}

int main() {
    int result = divide(10, 0);
    // Continue with the program...
    return 0;
}
