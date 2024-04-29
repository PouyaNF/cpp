#include <iostream>
using namespace std;



int main(){
	
	// pointer is a var that holds a memory address of another variable
	int var = 10;
	int* ptr = &var;
	
	// reference works as the alias : another name for a var that declared previously 
	int& ref = var;
	
	cout<< ptr <<endl;  // 0x7ffffa873dec
	cout<< ref <<endl; // 10
	
	// modifying var via pointer 
	* ptr = 12;
	cout<< var <<endl; 
	
	// modifying var via reference 
	ref = 14;
	cout<< ref <<endl; 

	return 0;
	
}




// Function Parameters:
// Function to swap two integers using references
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


//Function Return Values:
int& max(int& a, int& b) {
    return (a > b) ? a : b;
}


// Optional Parameters: with pointer we can decide 
// Function to print the value pointed to by a pointer if it's not null
void printValue(int* ptr) {
    if (ptr != nullptr) {
        std::cout << "Value: " << *ptr << std::endl;
    } else {
        std::cout << "Pointer is null." << std::endl;
    }
}