/*

RTTI (Run-Time Type Identification) is a mechanism that allows the program to obtain information about
 the type of an object at runtime.
 This can be useful in situations where the type of an object is not known until runtime or when 
 the program needs to perform different operations based on the type of an object.
The RTTI feature provides two operators, typeid and dynamic_cast, which are used to perform
 runtime type identification.
 

1. The 'typeid':
 operator is used to obtain information about the type of an object. It returns a reference to an object
 of type 'type_info', which contains information about the type of the object.
 The 'typeid' operator is often used in conjunction with 'dynamic_cast' to perform runtime type checking.
 
2. The 'dynamic_cast':
operator is used to perform a safe downcast of an object from a base class to a 
derived class. It checks at runtime whether the object is of the desired type and returns a pointer
 to the object if the cast is successful, or a null pointer if the cast fails. 
If the object is not polymorphic, then 'dynamic_cast' cannot be used and it will result in a 
compile- time error.
 
 */
 
 


#include <iostream>
#include <typeinfo>

using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* animal = new Dog();
	
	//We then use typeid to check if the object is of type Dog.
	//If it is, we use dynamic_cast to safely downcast the pointer to a Dog pointer and
	//call the makeSound method of the Dog class. If the cast fails, dynamic_cast returns 
	//a null pointer.

    if (typeid(*animal) == typeid(Dog)) {
        cout << "Animal is a dog" << endl;

        Dog* dog = dynamic_cast<Dog*>(animal);

        if (dog != nullptr) {
            dog->makeSound();
        }
    }

    delete animal;

    return 0;
}
