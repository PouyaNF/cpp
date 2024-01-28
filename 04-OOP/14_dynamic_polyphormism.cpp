#include <iostream>

/**
 * using keyword virtual enables a function to have different implementations/forms/morphs
 *  functions in base class with the same name and signature can be accessed through up-casted derived reference/pointer
 *
 * without keyword virtual, we will have a hidden function 
 * methods in derived class cannot be accessed through up-casted derived reference/pointer
 */

class Base1{
public:
  virtual void printMe()
  {
    std::cout << "I am in base class" << std::endl;
  }
};

class Base2{
public:
  void printMe()
  {
    std::cout << "I am in base class" << std::endl;
  }
};

class Derived1: public Base1{
public:
  void printMe() override
  {
    std::cout << "I am in derived class" << std::endl;
  }
};

class Derived2: public Base2{
public:
  void printMe()
  {
    std::cout << "I am in derived class" << std::endl;
    Base2::printMe(); // Calls the base class function explicitly
  }
};

Derived1 d1;
Derived2 d2;

int main() {
	
//// Base class references b1 and b2 are used to reference the derived class objects d1 and d2.
  Base1& b1{d1};
  Base2& b2{d2};
  


  b1.printMe();  // Calls the overridden function in Derived1
  b2.printMe();  // Calls the base class function in Base2

  /// The only way to access a hidden method in derived class is to use the name of base class
  Derived2 d;
  d.printMe();   // Calls the overridden function in Derived2 and also explicitly calls the base class function

  return 0;
}
