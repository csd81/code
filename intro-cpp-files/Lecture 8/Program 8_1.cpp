// Program 8_1
// Copying an array
#include <iostream>
using namespace std;

int main() {
	int a[5] = { 10, 20, 30, 40, 50 };
	int b[5];

	//Loop to copy array a to array b
	for (int i = 0; i < 5; i++) {
		b[i] = a[i];
	}                    
}
// we cannot copy an array using the assignment operator
// instead we have to use a loop to copy the elements of the array
// we can use a for loop to copy the elements of the array
// we can use the assignment operator to copy the elements of the array, one by one

// but we can use the assignment operator to copy a vector

// vector is a class in the standard template library
// vector is a dynamic array
// arrays are not dynamic - arrays are static 
// vector is a sequence container
// vector is a class template

// arrays are not a class
// arrays are not a class template
// arrays are not a sequence container


// but we cannot use the assignment operator to copy an array 
// arrays vs vectors
// arrays are fixed size
// arrays are not resizable
// arrays are static
// arrays are not dynamic



// the only way to copy an array is to use a loop
// this can be done the following way:
// int a[5] = { 10, 20, 30, 40, 50 };
// int b[5];
// for (int i = 0; i < 5; i++) {
// 	b[i] = a[i];
// }
// // this will copy the elements of array a to array b

//  we can use the assignment operator to copy a vector the following way
// vector<int> a = { 10, 20, 30, 40, 50 };
// vector<int> b;
// b = a;
// // this will copy the elements of vector a to vector b
// // we can also use the assignment operator to copy a vector the following way
// vector<int> a = { 10, 20, 30, 40, 50 };
// vector<int> b(a);