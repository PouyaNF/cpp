/*
An abstract class is a class that cannot be instantiated.
An abstract class serves as a blueprint for creating other classes that inherit from it.
An abstract class typically contains one or more pure virtual functions, which are declared 
using the "= 0" syntax in the function declaration. 

*/


#include <iostream>

// Abstract base class with a pure virtual function
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double calculateArea() const = 0;

	//Virtual Member function of a class  can be overridden in derived classes. 
	//// destructor is called automatically when an object of the class is destroyed or goes out of scope.	
    virtual ~Shape() {
        std::cout << "Base class destructor\n";
    }

    // Non-virtual function
    void displayInfo() const {
        std::cout << "This is a shape.\n";
    }
};

// Derived class 1
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the pure virtual function for Circle
    double calculateArea() const override {
        std::cout << "Circle calculateArea\n";
        return 3.14 * radius * radius;
    }

    // Destructor for Circle
	
    ~Circle() override {
        std::cout << "Circle destructor\n";
    }
};

// Derived class 2
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override the pure virtual function for Rectangle
    double calculateArea() const override {
        std::cout << "Rectangle calculateArea\n";
        return length * width;
    }

    // Destructor for Rectangle
    ~Rectangle() override {
        std::cout << "Rectangle destructor\n";
    }
};

int main() {
    // Error: Cannot create an instance of an abstract class
    // Shape* shape = new Shape();

    // Creating objects of derived classes
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);

    // Using virtual function to calculate area (polymorphism)
    std::cout << "Area of circle: " << circle->calculateArea() << std::endl;
    std::cout << "Area of rectangle: " << rectangle->calculateArea() << std::endl;

    // Using non-virtual function
    circle->displayInfo();
    rectangle->displayInfo();

    // Deleting objects (calls appropriate destructors)
    delete circle;
    delete rectangle;

    return 0;
}



/*
output:
Area of circle: Circle calculateArea
78.5
Area of rectangle: Rectangle calculateArea
24
This is a shape.
This is a shape.
Circle destructor
Base class destructor
Rectangle destructor
Base class destructor


*/