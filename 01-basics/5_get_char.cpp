/*
In C++, getchar() is a standard library function that reads a single character from the input stream. 
It is defined in the <cstdio> header file.
It returns an integer value that represents the ASCII value of the character read. If the function encounters 
an end-of-file (EOF) condition, it returns the special value EOF.

*/



#include <iostream>
#include <cstdio> // for getchar

int main() {
    std::cout << "Enter a character: ";

    // Using getchar() to read a character from standard input
    int ch = getchar();

    // Displaying the entered character
    std::cout << "You entered: ";

    // Checking for EOF (End of File) or an error
    if (ch == EOF) {
        std::cout << "Error or End of File reached." << std::endl;
    } else {
        std::cout << static_cast<char>(ch) << std::endl;
    }

    return 0;
}
