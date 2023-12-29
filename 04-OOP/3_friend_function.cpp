/*
Friend functions are often used when a non-member function needs access to private or
 protected data stored within a class, or when two or more classes need to access each 
 other's private or protected members.
 
 Encapsulation:
 By using friend functions, we can keep the data members of a class private and provide
 controlled access to them only through the friend functions. This helps in achieving 
 encapsulation and better security of data.
 
Improved functionality: 
Sometimes, we may need to perform certain operations that require access to private or 
protected members of a class. In such cases, we can define a friend function to perform
 that operation more efficiently.
 
Operator overloading:
 Friend functions are often used to overload operators such as +, -, *, /, etc., 
 for a class. This allows us to perform arithmetic or other operations on objects of the class.

*/


#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Friend function declaration
    friend Complex addComplex(const Complex& c1, const Complex& c2);

    // Display the complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

// Friend function definition for adding two complex numbers
Complex addComplex(const Complex& c1, const Complex& c2) {
    // Access private members of Complex directly
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    // Create two complex numbers
    Complex num1(3.0, 4.0);
    Complex num2(1.0, -2.0);

    // Use the friend function to add the complex numbers
    Complex sum = addComplex(num1, num2);

    // Display the result
    std::cout << "Sum: ";
    sum.display();

    return 0;
}
