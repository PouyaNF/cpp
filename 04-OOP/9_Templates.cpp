/*

Allows programmers to define generic classes or functions that can work with different data
 types or values. 
 
Typically, template classes and functions are defined in header files (files with the extension ".h" 
or ".hpp"), which are included in the main source file of the program.

*/


#include <iostream>

// Example of Template function 

template <typename T>
T max(T a, T b){
	return (a>b) ? a : b; 
}	


int main(){
	int x = 5 , y = 10;
	std::cout<< "The maximum of "<< x << " and " << y << " is " << max(x,y)<< std::endl; 
	
	double a=3.14 , b= 2.7;
	std::cout<< "The maximum of "<< a << " and " << b << " is " << max(a,b)<< std::endl;
	
	return 0;
	
}



// Example of class template :
// generic class with one or more template parameters. 
template<typename T>
class Stack{

	// The Stack class contains an array of type T to store the data
	T data[100];
	int top;
	
	public: 
	Stack(){
		top = -1; 
	}
	
	void push(T item){
		
		data[++top] = item;
		
		}
	
	T pop(){
		return data[--top]; 
	}
	
	bool is_empty(){
		
		return top==-1;
	}
};	




int main(){
	Stack<int> int_stack;

	Stack<double> double_stack;
	return 0;
	
}

	