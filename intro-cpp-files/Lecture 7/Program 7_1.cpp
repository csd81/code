// Program 7_1
// Declaring an array


#include <iostream>
using namespace std;

int main() {
	int test_array[20];
	test_array[0] = 10;
	test_array[1] = 20;
	test_array[2] = 25;
	cout << test_array[0] << " " << test_array[1] << " " << test_array[2] << endl;                    
	cout << test_array[4] << " " << test_array[5] << " " << test_array[6] << endl;    // this will print garbage values                
}

// an array is a collection of variables of the same type
// we can declare an array of any type
// the size of the array must be a constant expression
// the size of the array must be a positive integer
// the syntax for declaring an array is:
// type array_name[size];
// we can also initialize an array at the time of declaration
// the syntax for initializing an array is:
// type array_name[size] = {value1, value2, ..., valueN};
// we can also initialize an array with a loop
// the syntax for initializing an array with a loop is:
// for (int i = 0; i < size; i++) {
//     array_name[i] = value;
// }	

// we can also use the array subscript operator to access the elements of an array
// the syntax for accessing an element of an array is:
// array_name[index];
// the index of an array starts from 0
// the last index of an array is (size - 1)

// to traverse an array, we can use a loop
// the syntax for traversing an array is:
// for (int i = 0; i < size; i++) {
//     cout << array_name[i] << " ";
// }
// cout << endl;
// we can also use a range-based for loop to traverse an array
// the syntax for a range-based for loop is:
// for (type element : array_name) {
//     cout << element << " ";