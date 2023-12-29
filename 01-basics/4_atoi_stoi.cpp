/*
The std::stoi() function provides better error handling by throwing 
exceptions (std::invalid_argument and std::out_of_range) in case of 
conversion errors or overflow conditions.

*/

#include <iostream>
#include <cstdlib> // for atoi



int main() {
	
	// for atoi
    // Example string containing digits
    const char* str1 = "12345";

    // Using the atoi() function to convert the string to an integer
    int result = atoi(str1);

    // Displaying the result
    std::cout << "Converted integer: " << result << std::endl;
	
	 // Example string containing digits
    std::string str2 = "12345";

    try {
        // Using std::stoi() for more robust conversion with error handling
        int result = std::stoi(str2);

        // Displaying the result
        std::cout << "Converted integer: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }


    return 0;
}
