// Program 7_7
// Array Initialization 
//- size not explicitly specified
#include <iostream>
using namespace std;

int main() {
	int my_array[] = { 5, 6, 4, 5, 4, 5, 6, 4, 5, 4 };
	// the size of the array is determined by the number of values in the list

	int size = sizeof(my_array) / sizeof(my_array[0]);
	cout << "The size of the array is: " << size << endl;

	for (int i = 0; i < size; i++) {
		cout << my_array[i] << endl;                                
	}                      
}



// we can initialize an array with a list of values
// the size of the array is determined by the number of values in the list
// the array is initialized with the values in the list
// int my_array[] = { 5, 6, 4, 5, 4 }; is equivalent to
// int my_array[5] = { 5, 6, 4, 5, 4 };

// we can get the size of the array using the sizeof operator
// the sizeof operator returns the size of the array in bytes

// if we divide the size of the array by the size of the type of the array, we get the number of elements in the array
// an example of this is shown below
// int size = sizeof(my_array) / sizeof(my_array[0]);
// cout << "The size of the array is: " << size << endl;
// this will print the size of the array
// the size of the array is 5
// we can use this in the for loop to iterate over the array
// for (int i = 0; i < size; i++) {
// 	cout << my_array[i] << endl;
// }

//this way we can get the size of the array without explicitly specifying the size of the array