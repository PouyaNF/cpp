/*
The purpose of using placement new in this context is to control the memory where an 
object is created. This can be useful in scenarios where you want to manage memory manually 
or allocate objects in a specific memory region (e.g., in embedded systems or custom memory
 management scenarios).
*/



#include <iostream>

struct A{

    int a;
    float b;

    A(int x, float y): a(x), b(y)
    {
          std::cout<<"customer constructed\n";
    }

    A(){
        std::cout<<"default constructed\n";
    }
};



int main()
{
    // Reserve 8 bytes of memory
    unsigned char ptr2[8];
    // creates an object of type A at the memory location pointed to by ptr2.
	//This allows manual control over the memory where the object is created.
    auto objPtr = new (static_cast<void*>(ptr2)) A(5, 5.5);
    // Check the correctness of the allocation and construction 
    std::cout<<objPtr->a<<", "<<objPtr->b<<"\n";

    return 0;
}