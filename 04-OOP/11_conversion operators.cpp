#include <iostream>


/* 
This C++ code demonstrates the use of conversion operators in classes. 
Conversion operators allow a class to define how an object of that class can be converted to another type. 
In this case, the classes MyInt and MyString define conversion operators to int and const char* types, respectively.
/// operator output_type () { ... do sth ... }

*/

class MyInt
{
 public:
  MyInt(int ii): i(ii){}
  operator int ()
  {
    return i;
  }
 private:
  int i;
};

class MyString
{
 public:
  MyString(const char* s)
  {
    cstring = s;
  }

  operator const char* () const {return cstring;}

 private:
  const char* cstring;
};


int main() {
  MyInt myInt(10);
  std::cout << myInt << std::endl;
  MyString myString("I am a geek");
  std::cout << myString<< std::endl;
  return 0;
}
