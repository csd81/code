// Program 8_2
// Example of a vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> Victor;        // ha-ha, Victor is a vector of integers
	Victor.push_back(1); // add 1 to the end of the vector
	Victor.push_back(2); // add 2 to the end of the vector
	Victor.push_back(3); 
	Victor.pop_back(); // remove the last element of the vector
	cout << Victor[0] << " " << Victor[1] << 	" " 
	// << Victor[2] // this will cause an error because the vector has only two elements
	<< endl;          
	
	for (int i : Victor) {
 	cout << i << " ";
	
	}
	cout << endl;          
	cout << endl;          

	vector<vector<int>> matrix;
matrix.push_back({1, 2, 3});
matrix.push_back({4, 5, 6});
matrix.push_back({7, 8, 9});

cout << endl;          
cout << endl;          
// this will create a 2D array with 3 rows and 3 columns
// we can access the elements of the 2D array using the following syntax:

cout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << endl; // this is the same as with 2d-array 
cout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << endl;
cout << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << endl;

cout << endl;          
cout << endl;          
// this will print the elements of the 2D array
// we can also use the range-based for loop to iterate over the elements of the 2D array

for (auto row : matrix) {
	for (auto col : row) {
		cout << col << " ";
	}
	cout << endl;
}	
}

// a vector in cpp is a dynamic array meaning that it can grow and shrink in size
// a vector is a sequence container meaning that it can store a sequence of elements

// a vector is a class template meaning that it can store any type of data
// a vector is a class in the standard template library meaning that it is a part of the standard library

// a vector is a dynamic array meaning that it can grow and shrink in size
// a vector is a class template 
// a vector is a class

// vectors have a lot of advantages over arrays
// vectors have overloaded operators meaning that we can use the assignment operator to copy a vector
// vectors have member functions meaning that we can use the member functions to manipulate the vector
// vectors have iterators meaning that we can use the iterators to iterate over the elements of the vector

// member functions of a vector include:	
// push_back() - adds an element to the end of the vector
// pop_back() - removes the last element of the vector
// size() - returns the number of elements in the vector
// clear() - removes all elements from the vector
// empty() - returns true if the vector is empty, false otherwise
// begin() - returns an iterator to the first element of the vector
// end() - returns an iterator to the last element of the vector

// we can iterate over the elements of the vector using a for loop
// we can also use the range-based for loop to iterate over the elements of the vector
// the the range-based for loop can be used as follows:
// for (int i : Victor) {
// 	cout << i << " ";
// }

// we can use multi-dimensional vectors to create a 2D array like this:
// vector<vector<int>> matrix;
// matrix.push_back({1, 2, 3});
// matrix.push_back({4, 5, 6});
// matrix.push_back({7, 8, 9});
// // this will create a 2D array with 3 rows and 3 columns
// // we can access the elements of the 2D array using the following syntax:
// cout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << endl;
// cout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << endl;
// cout << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << endl;
// // this will print the elements of the 2D array
// // we can also use the range-based for loop to iterate over the elements of the 2D array
// for (auto row : matrix) {
// 	for (auto col : row) {
// 		cout << col << " ";
// 	}
// 	cout << endl;
// }	