/*
In C++, the new keyword is used to dynamically allocate memory for an object 
or an array of objects.You should use the new keyword when you need to allocate
 memory for an object or an array of objects at runtime, i.e., when the size or
 number of objects to be allocated is not known at compile time or when the object
 needs to exist beyond the scope of the current function.
*/

// new int allocates a memory block of size sizeof(int) and returns a pointer to
// the beginning of the block.  
int* p = new int;
// assing value to dynamic memory block
*p = 42;
// release the memory block 
delete p; 

// creation of an array dinamically 
//assign a memory block of sizeof(int)* 10 and returning a pointer to the beginning of it   
int* p2 = new int[10];   
// assign a value to the first element of the block 
p2[0] = 42;
// release the memory block 
delete p2; 

// creating an object of a class dynamically 
Myclass *p3 = new Myclass(); 
delete p3; 


// polymorphic objects
// dynamically creating a derived object and assign it to base pointer 
Base* p4 = new Derived();
delete p4; 




// Dynamically create a vector of integers
std::vector<int>* dynamicVector = new std::vector<int>();

// Add elements to the dynamically created vector
dynamicVector->push_back(10);
dynamicVector->push_back(20);
dynamicVector->push_back(30);

// Access and print elements of the dynamically created vector
for (int i = 0; i < dynamicVector->size(); ++i) {
	std::cout << "Element " << i << ": " << (*dynamicVector)[i] << std::endl;
}

// Don't forget to delete the dynamically allocated vector to avoid memory leaks
delete dynamicVector;
