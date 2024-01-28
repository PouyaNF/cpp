/*
Inline functions are often used for short, simple functions that are called frequently. 
The benefits of using inline functions include potentially improved performance by reducing
 the overhead of function calls. Keep in mind that the decision to inline a function is 
 ultimately up to the compiler, and the inline keyword is more of a suggestion than a 
 strict directive. Modern compilers are usually good at making these decisions based on 
 optimization settings and other factors.
 
 * Not all functions should be declared as inline. Generally, functions with larger or complex bodies might not be good candidates for inlining.
 * Modern compilers are often capable of automatically determining whether a function should be inlined, even without the inline keyword.
 * Inline functions are typically defined in header files to ensure that the function's definition is available at the call site.

*/

#include <iostream>

// Inline function to calculate the square of a number
inline int square(int x) {
    return x * x;
}

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    // Using the inline function
    int result = square(num);

    std::cout << "Square of " << num << " is: " << result << std::endl;

    return 0;
}
