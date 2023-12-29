
/*
simple template class to provide basic functionality similar to a smart pointer
*/

#include <iostream>



template<class T>
class SmartPtr {
private:
    T* ptr;

public:
    explicit SmartPtr(T* p = nullptr) : ptr(p) {}

    ~SmartPtr() {
        delete ptr;
    }

    // Copy constructor (copying SmartPtr objects is not allowed)
	// This is because copying might lead to confusion about which pointer owns the underlying object.
    SmartPtr(const SmartPtr&) = delete;

    // Copy assignment operator (copying SmartPtr objects is not allowed )
    SmartPtr& operator=(const SmartPtr&) = delete;

    // Move constructor
	//The && in the parameter list represents an rvalue reference, and it's a way to say that you're willing
	//to take ownership from another object. After moving, the source object (other in this case) is left in a 
	//state where it no longer owns the pointer (setting other.ptr to nullptr ensures that).
	//noexcept is used to indicate that these operations won't throw exceptions. This is important for move operations
	//because they are expected to be efficient and are commonly used in scenarios where throwing exceptions is not desired (e.g., resource management).
    SmartPtr(SmartPtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment operator
    SmartPtr& operator=(SmartPtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
};


int main() {
    // Creating a SmartPtr to manage an integer
    SmartPtr<int> intPtr(new int(42));

    // Accessing the integer through the SmartPtr
    std::cout << "Value through SmartPtr: " << *intPtr << std::endl;

    // Creating another SmartPtr using the move constructor
    SmartPtr<int> intPtr2(std::move(intPtr));

    // Accessing the integer through the new SmartPtr
    std::cout << "Value through moved SmartPtr: " << *intPtr2 << std::endl;

    // Creating another SmartPtr using the move assignment operator
    SmartPtr<int> intPtr3;
    intPtr3 = std::move(intPtr2);

    // Accessing the integer through the new SmartPtr
    std::cout << "Value through moved SmartPtr (assignment): " << *intPtr3 << std::endl;

    // No need to explicitly delete, memory is automatically managed by SmartPtr

    return 0;
}


