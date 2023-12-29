/*
In C++, a functor or function object is an object that acts like a function or function pointer.
Functors are created by overloading the function call operator () in a class, which allows
 instances of the class to be called like functions.

used to pass behavior as an argument to a function, similar to how function pointers are used. 
However, functors have some advantages over function pointers, such as the ability to store state 
information and the ability to be inlined by the compiler.


 */
 
 #include <iostream>

// Functor class
class MultiplyBy {
public:
    MultiplyBy(int factor) : factor_(factor) {}

    // Overloaded function call operator
    int operator()(int x) const {
        return x * factor_;
    }

private:
    int factor_;
};

int main() {
    // Create instances of the MultiplyBy functor
    MultiplyBy multiplyBy2(2);
    MultiplyBy multiplyBy5(5);

    // Use the functors as if they were functions
    int result1 = multiplyBy2(3);  // Equivalent to calling multiplyBy2.operator()(3)
    int result2 = multiplyBy5(4);  // Equivalent to calling multiplyBy5.operator()(4)

    // Print the results
    std::cout << "Result 1: " << result1 << std::endl;  // Output: 6
    std::cout << "Result 2: " << result2 << std::endl;  // Output: 20

    return 0;
}

 
 
