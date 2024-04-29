
#include <memory>
#include <iostream>

/*
*  When an object has exclusive ownership, and there should be a single, unique owner.
* It cannot be shared or copied, only moved.
* Express clear ownership and responsibility for a resource.
* It is more lightweight than std::shared_ptr since it doesn't need to maintain a reference count.
* If performance is a critical concern and shared ownership is not required, prefer std::unique_ptr.
*/


class Rectangle {
    int length;
    int breadth; 

public: 
    Rectangle(int length , int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }
    
    ~Rectangle() {
        std::cout << "MyClass Destructor\n";
    }
    
    
    int area() { return length* breadth;}
    
};


int main() {

// unique pointer 
//when using std::unique_ptr, ownership of the memory is transferred to the unique pointer,
//and it will automatically deallocate the memory when it goes out of scope. 
//This helps prevent memory leaks and simplifies memory management in C++.

std::unique_ptr<int> myUniquePtr(new int(42));

auto anotherUniquePtr = std::make_unique<double> (3.14); 

// initializing a unique pointer with nullptr 
std::unique_ptr<char> nullUniquePtr(nullptr);

// initializing empty unique pointer 
auto emptyUniquePtr= std::unique_ptr<float>();

// the memory will be automatically release when pointer goes out of scope 
std::cout<< *myUniquePtr << std::endl; // 42 
std::cout<< *anotherUniquePtr << std::endl; //  3.14
//std::cout<< *emptyUniquePtr << std::endl; //  Segmentation fault

std::unique_ptr<Rectangle> R1 (new Rectangle(10,5));  
auto R2 = std::make_unique<Rectangle> (10,8);
std::cout << R1->area() << std::endl; // 50
std::cout << R2->area() << std::endl; // 80 

std::unique_ptr<Rectangle> R3; 
// removing R1 and assigning R3 
R3 = move(R1);
std::cout << R3->area() << std::endl; // 50
// std::cout << R1->area() << std::endl; // Segmentation fault

return 0;
}