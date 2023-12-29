/*
Object-Oriented Programming (OOP) is a programming paradigm 
Based on the concept of objects, which can contain data and behavior.
Here are some key concepts of OOP in C++:
Classes: 
User-defined data type
Encapsulates data and the functions that operate on that data. 
To organize and modularize and reusable code.
Objects:
Instance of a class.  Have their own data and behavior 
Can communicate with other objects.
Encapsulation: 
Hiding the implementation details of a class / public interface for accessing its functionality. 
Inheritance: 
Is a mechanism in which a new class is derived from an existing class. 
Code reuse and hierarchical organization of classes.
Polymorphism:
Ability of an object to take on many forms. 
Enables code flexibility and extensibility.
Abstraction: 
Simplified view of a complex system. 
To focus on the essential features of a system and hide unnecessary details.

*/




#include <iostream>
#include <string>

// Base class representing a general vehicle
class Vehicle {
	
//Members declared as protected are similar to private members, 
//but they can be accessed by derived classes.
protected:
    std::string brand;

//Members declared as public are accessible from anywhere in the program,
// both from within the class and outside the class.
public:
	// constructor is called automatically when an object of the class is created. 
	// is used to initialize the object's data members to default values or user-specified values
	// has the same name as the class and no return type
	// It can be overloaded: can have the same name but different parameter lists
    Vehicle(const std::string& brand) : brand(brand) {}

    void displayBrand() const {
        std::cout << "Brand: " << brand << std::endl;
    }

    // Pure virtual function for polymorphism
    virtual void honk() const = 0;
};

// Derived class representing a specific type of vehicle (Car)
//The public keyword is used to specify the access level of a base class in class inheritance. 
//that the public members of the base class will be accessible by the derived class.
// establishes an "is-a" relationship between the derived class and the base class
class Car : public Vehicle {
//Members declared as private are only accessible from within the class. 
//They cannot be accessed from outside the class or by derived classes.
private:
    std::string model;

public:
	// you can use the constructor of the base class to define the derived class. 
    Car(const std::string& brand, const std::string& model) : Vehicle(brand), model(model) {}

    void displayModel() const {
        std::cout << "Model: " << model << std::endl;
    }

	//Since Car inherit from Vehicle have also access to displayBrand method of the Vehicle class.

    // Implementation of the honk function for Cars
    void honk() const override {
        std::cout << "Car honks: Beep beep!" << std::endl;
    }
};

// Another derived class representing a different type of vehicle (Bicycle)
class Bicycle : public Vehicle {
public:
	// you can use the constructor of the base class to define the derived class. 
    Bicycle(const std::string& brand) : Vehicle(brand) {}

    // Implementation of the honk function for Bicycles
    void honk() const override {
        std::cout << "Bicycle honks: Ring ring!" << std::endl;
    }
};

int main() {
    // Creating objects of different classes
    Car myCar("Toyota", "Camry");
    Bicycle myBicycle("Schwinn");

    // Accessing methods of the base class (Vehicle)
    myCar.displayBrand();
    myBicycle.displayBrand();

    // Accessing methods of the derived classes
    myCar.displayModel();
    myCar.honk();

    myBicycle.honk();

    return 0;
}
