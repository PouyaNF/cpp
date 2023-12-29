/*
lambda function (or lambda expression) is a shorthand syntax for defining a small, 
unnamed function object at the location where it is needed. It is a way to define a 
function "inline" without having to give it a name and define it separately.

[capture](parameters) -> return_type {
    // function body
}
[capture]: Specifies what variables from the surrounding scope are accessible inside the lambda function. The capture clause is optional.

(parameters): The list of parameters for the lambda function, similar to regular function parameters.

-> return_type: Optional, specifies the return type of the lambda function. If omitted, the return type is deduced by the compiler.

{ function body }: The body of the lambda function, where you write the actual code.

Inline functions are declared separately and can be called globally, while lambda functions are defined
 inline and have a limited scope within the context they are used.


*/

// Example 1: Simple Lambda
#include <iostream>

int main() {
    // Lambda function that takes two integers and returns their sum
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    // Using the lambda function
    std::cout << "Sum: " << add(3, 5) << std::endl;

    return 0;
}


//Example 2: Lambda with Capture
#include <iostream>

int main() {
    int x = 5;

    // Lambda function capturing a variable from the surrounding scope
    auto multiplyByX = [x](int y) -> int {
        return x * y;
    };

    // Using the lambda function
    std::cout << "Result: " << multiplyByX(3) << std::endl;

    return 0;
}


//Example 3: Lambda as a Function Argument
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Creating a vector of integers
    std::vector<int> numbers = {1, 5, 3, 2, 4};

    // Sorting the vector using a lambda function as a comparator
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) -> bool {
        return a > b;
    });

    // Printing the sorted vector
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
