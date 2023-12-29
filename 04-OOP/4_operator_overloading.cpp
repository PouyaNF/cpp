/*
In C++, operator overloading is a technique that allows operators such as +, -, *, /, %, etc.
 to be given additional meanings when applied to user-defined data types. 

*/



#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Operator overloading for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Display the complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    // Create two complex numbers
    Complex num1(3.0, 4.0);
    Complex num2(1.0, -2.0);

    // Use operator overloading to add the complex numbers
    Complex sum = num1 + num2;

    // Display the result
    std::cout << "Sum: ";
    sum.display();

    return 0;
}
