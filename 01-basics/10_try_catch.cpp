// Basic Try-Catch Example: 
#include <iostream>	 	 
int main() {
    try {
        // Code that might throw an exception
        int divisor = 0;
        int result = 10 / divisor;

        // This line won't be executed if an exception occurs above
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        // Catch and handle the exception
        std::cerr << "Exception caught: " << e.what() << std::endl; // in many cases, triggers a floating-point exception
    }

    return 0;
}

// Basic Try-Catch with more catch blocks: 
//try block contains a call to the std::stoi function, which may throw exceptions 
//of type std::invalid_argument or std::out_of_range if the input string cannot be 
//converted to an integer

#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    try {
        int num = std::stoi(input); // Convert input string to integer 
        std::cout << "You entered: " << num << std::endl;
    } 
	catch (const std::invalid_argument& ex) {
        std::cout << "Invalid input: " << ex.what() << std::endl;
    } 
	catch (const std::out_of_range& ex) {
        std::cout << "Input out of range: " << ex.what() << std::endl;
    } 
	catch (...) {
        std::cout << "Something went wrong." << std::endl;
    }

    return 0;
}



// Catching Specific Exceptions:

//Here, we throw a std::runtime_error exception explicitly.
// The catch blocks can handle specific types of exceptions. 
//If no catch block matches the thrown exception type, the program terminates.

#include <iostream>
#include <stdexcept>

int main() {
    try {
        // Code that might throw an exception
        int divisor = 0;
        if (divisor == 0) {
            throw std::runtime_error("Division by zero");
        }
        int result = 10 / divisor;
        // This line won't be executed if an exception occurs above
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        // Catch and handle the specific exception
        std::cerr << "Runtime error caught: " << e.what() << std::endl; //Runtime error caught: Division by zero
    } catch (const std::exception& e) {
        // Catch any other exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}


// Using Custom Exceptions
#include <iostream>
#include <stdexcept>

class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom exception";
    }
};

int main() {
    try {
        // Code that might throw a custom exception
        throw CustomException();
    } catch (const CustomException& e) {
        // Catch and handle the custom exception
        std::cerr << "Custom exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catch any other exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}


// Rethrowing Exceptions:

#include <iostream>
#include <stdexcept>

void foo() {
    throw std::runtime_error("Exception from foo");
}

int main() {
    try {
        foo();
    } 
	catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
        // Rethrow the exception
		//This rethrowing is useful in scenarios where you want to catch an exception
		//at a higher level in your program to perform additional handling or logging 
		//before allowing the exception to continue propagating.
		// At this higher level, you might want to log the error, display a user-friendly
		//message, or take some other appropriate action
		
        throw;
    }

    return 0;
}
