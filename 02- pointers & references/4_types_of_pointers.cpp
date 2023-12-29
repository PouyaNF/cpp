#include <iostream>
using namespace std;

int* getLocalptr();
int* getDynamicPtr();

int main() {
	
	// null pointer
	
	//is pointing to nothing. In many cases, 
	//we do not have an exact address to assign to the pointer
	//variable in that case it is good practice to assign it as NULL.
    //In C++ the null pointers have a constant value of zero
	
	int *ptr1 = NULL; // or nullptr in modern c++ 
	cout<< "The value of ptr1 (NULL pointer) is : "<< ptr1<<endl;; // The value of Null pointer is : 0
	
	// Dangling pointers 
	int* ptr2 = (int *) malloc(sizeof(int));
	free(ptr2);
	//The output is not predictable. It could print garbage values, crash the
	//program, or behave in any other unexpected way.
	cout<< "The value of ptr2 is : "<< *ptr2 <<endl; //
	ptr2= NULL; // no more dangling pointer
	
	//ptr3 become a dangling pointer
	int* ptr3 = getLocalptr();
	//cout<< "The value taht ptr3 points to : "<< *ptr3 <<endl; //Segmentation fault
	
	//ptr 4 is a valid pointer 
	int* ptr4 = getDynamicPtr();
	cout<< "The value that ptr4 points to  : "<< *ptr4 <<endl; // 10 
	delete ptr4; 
	
	// void pointer
	
	//A void pointer is also called a general-purpose pointer. Void pointers represent 
	//a pointer to an object of any data type, without specifying its type. 

	int x = 2; 
	float y = 2.5;
	
	// declare a void pointer 
	void *ptr5;
	// void pointer is now int 
	ptr5 = &x; 
	printf("Integer variable = %d", *((int*)ptr5));
	
	// void pointer is now float 
	ptr5 = &y;
	printf("Integer variable = %f", *((float*)ptr5));
	
	
	// invalid pointer 
	int* ptr6 = NULL;
	
	//the pointer ptr is initialized to null, meaning it does not point to a valid memory location.
    // When we try to dereference, the pointer using the * operator, we are trying to access 
	//the value at an undefined memory address, which can cause a segmentation fault or other
	//runtime error. Also, note that an uninitialized pointer is also an invalid pointer.

	*ptr6 = 10;
	
	
	
	return 0; 
}




int* getLocalptr(){
	int num = 10; // num is a local variable
	return &num;
}


int* getDynamicPtr(){
	int* num = new int(10); //dynamic memory allocation in heap 
	return num;
	
	
	
}