#include <iostream>
using namespace std;



int main(){
	
	// pointer is a var that holds a memory address of another variable
	int var = 10;
	int* ptr = &var;
	
	// reference works as the alias : another name for a var that declared previously 
	int& ref = var;
	
	cout<< ptr <<endl;
	cout<< ref <<endl;

	return 0;
	
}