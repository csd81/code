// Program 7_11
// ERROR in output due to array out of bounds


#include <iostream>
using namespace std;

int main() {
	// int my_array[3];
	// my_array[0] = 10;
	// my_array[1] = 20;
	// my_array[2] = 30;
	// for (int i = 0; i < 4; i++) {
	// 	cout << my_array[i] << endl;
	// }         
	
	
	int my_array[3];
	my_array[0] = 10;
	my_array[1] = 20;
	my_array[2] = 30;

	int size = sizeof(my_array) / sizeof(int);
	for (int i = 0; i < size; i++) {
		cout << my_array[i] << endl;
	}    
}

// array out of bounds is a common error in c++
// it occurs when we try to access an element of the array that is not in the array
// in this case we are trying to access the fourth element of the array
// but the array has only three elements
// this will cause an error
// the program will compile but it will give an error at runtime
// the error will be "array out of bounds"

// we can avoid this error by using the sizeof operator
// the sizeof operator returns the size of the array in bytes

// we can divide the size of the array by the size of the type of the array
// to get the number of elements in the array
// we can use this in the for loop to iterate over the array

/* 
for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); i++) {
 	cout << my_array[i] << endl;
}
*/

// // or we can store the size of the array in a variable
// // we can use this variable in the for loop to iterate over the array

/*
int size = sizeof(my_array) / sizeof(my_array[0]);
for (int i = 0; i < size; i++) {
 	cout << my_array[i] << endl;
}
*/