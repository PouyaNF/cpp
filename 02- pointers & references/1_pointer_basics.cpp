/*
* Pointers store the memory address of another variable. 
* They allow for direct manipulation of memory
*
*/


int main() {
	
	int num =  42;
	
	//declare and assign a pointer 
	int *ptr = &num;
	
	std::cout<< "value of num" << num << std::endl; // value of num: 42
	std::cout<< "Memory address of num" << &num << std::endl; //Memory address of num: 0x7ffdc4774f74
	std::cout<< "Value of pointer" << ptr << std::endl; // Value of pointer: 0x7ffdc4774f74
	std::cout<< "Value stored at memory address pointed by ptr: " << *ptr << std::endl;// Value stored at memory address pointed by ptr: 42
	
	// initializing pointer : 1 
	int* ptr1;
	int a = 10; 
	*ptr1 = a;
	std::cout<< *ptr1 << std::endl;  // 10 
	
	// initializing pointer : 2 
	int* ptr2;
	int b = 10; 
	ptr2 = &b;
	std::cout<< *ptr2 << std::endl; // 10
	
	//dynamically allocation of memory : 3
	
	int* ptr3 = new int;
	int c = 10;
	*ptr3 = c;
	std::cout<< *ptr3 << std::endl; // 10
	delete ptr3;
	
	// initializing pointer : 4 
	// allocating dynamic memory initially, 
	// but later, it abandons that dynamically allocated memory and makes ptr4 
	// point to the address of a stack variable (d).
	//doesn't involve dynamic memory deallocation.can lead to a memory leak if not handled properly.
	int* ptr4 = new int;
	int d = 10;
	ptr4 = &d; //This means that ptr4 no longer points to the dynamically allocated memory; instead, it now points to the address of d.
	std::cout<< *ptr4 << std::endl; // 10
	
	
	// wild pointer 
	int* ptr5; // Declaring a pointer without initializing it
    *ptr5 = 10; // Dereferencing the uninitialized pointer
	std::cout << *ptr5 << std::endl; // Accessing the value pointed to by the wild pointer

	
	return 0;
}