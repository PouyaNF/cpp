/*
std::weak_ptr::lock() is a member function of std::weak_ptr.
It is used to obtain a std::shared_ptr that shares ownership with 
the std::shared_ptr the std::weak_ptr is associated with.
If the std::weak_ptr is associated with an object (i.e., it has not expired),
 lock() will return a valid std::shared_ptr. This means that you can safely 
 use the shared object and manage it as long as the returned std::shared_ptr exists.
If the std::weak_ptr is associated with an expired object (i.e., the object it was 
observing has been deleted), lock() will return an empty (default-constructed) std::shared_ptr.
Using lock() is a way to check if the object still exists and obtain a std::shared_ptr to it if
 it does. This can help you avoid accessing a deleted object and prevent dangling pointers.
*/

#include <iostream>
#include <memory>

class MyClass {
	public:
		MyClass(int value) : data(value) {
			std::cout << "Constructing MyClass: "<< data << std::endl;
		}
		
		~MyClass() {
			std::cout << "Destructing MyClass: "<< data << std::endl;
		}
		
		void displayData() const {
			std::cout << "Data: " << data << std::endl;
		}
	private:
		
		int data;
};




int main() {
	// 1. Initializing from a shared_ptr
	std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(42);
	std::weak_ptr<MyClass> weakPtr1 = sharedPtr;
	
	std::cout << sharedPtr.use_count()<<std::endl; // 1 
	 
	 
	// 2. Initializing from another weak_ptr
	std::weak_ptr<MyClass> weakPtr2 = weakPtr1;
	
	// 3. Initializing from a shared_ptr, but without shared ownership 
	std::weak_ptr<MyClass> weakPtr3;
	{
	std::shared_ptr<MyClass> localSharedPtr = std::make_shared<MyClass>(55);
	weakPtr3 = localSharedPtr;
	// localSharedPtr goes out of scope, object is destroyed, weakPtr3 is expired
	} 
	
	// Displaying information
	if (auto sharedPtrFromWeak1 = weakPtr1.lock()) {
		std::cout << "WeakPtr1 Data: ";
		sharedPtrFromWeak1->displayData();
	} 
	
	else {
		std::cout << "WeakPtr1 is expired\n";
	}
	
	// Try to lock expired weak_ptr
	if (auto sharedPtrFromWeak3 = weakPtr3.lock()){
		std::cout << "WeakPtr3 Data: ";
		sharedPtrFromWeak3->displayData();
		} 
	
	else {
		std::cout << "WeakPtr3 is expired\n";
	}
	
	
	
	
	return 0;
}