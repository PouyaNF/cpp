/*
* Pass-by-reference with a reference argument is more direct and often considered more idiomatic
* in C++, while pass-by-reference with a pointer argument offers more flexibility, such as the 
* ability to work with variables indirectly and handle null pointers.
*/

#include <bits/stdc++.h>
using namespace std;

// Call by value
void func1(int var) {
	var = 10;
}


//Call-by-reference with Reference Argument
void func2(int& var){
	var = 20;
}

// Call-by-reference with Pointer Argument
void func3(int* var){
	*var = 30;
}

// to change the value of a variable stored in a different scope
void doubleValue(int * ptr){
    if (ptr != nullptr){
        *ptr *= 2;
    }
}


void  doubleValue(int& val){
    val *=2;
}



int main(){
	
	int var = 5;
	
	func1(var);
	cout<< var <<endl; // 5
	
	func2(var);
	cout<< var <<endl; // 20 
	
	func3(&var);
	cout<< var <<endl;  // 30
	
	int num = 5;
	int* ptr = &num;
	
	
	doubleValue(ptr);
	cout<< num <<endl; // 10 
	
	doubleValue( &num);
	cout<< num <<endl; // 20 
	
	return 0;
}

