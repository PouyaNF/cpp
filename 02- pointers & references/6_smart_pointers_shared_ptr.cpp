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
	// Using std::make_shared : preferred way due to its efficiency.
	std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(42);
	
	// Using shared_ptr constructor
	std::shared_ptr<MyClass> sharedPtr2(new MyClass(24));
	
	// Creating a shared_ptr from another shared_ptr
	std::shared_ptr<MyClass> sharedPtr3 = sharedPtr1;
	
	// Using reset to change the object owned by a shared_ptr
	sharedPtr3.reset(new MyClass(100));
	
	// Displaying data using shared_ptrs
	sharedPtr1->displayData();
	sharedPtr2->displayData();
	sharedPtr3->displayData();
	
	
	// automatically released when the last shared_ptr is destroyed.
	{
	    // sharedPtr4 is only valid in this scope 
		std::shared_ptr<MyClass> sharedPtr4 = sharedPtr1;
		sharedPtr4->displayData();
	}
	sharedPtr1->displayData();
	
	return 0;
}