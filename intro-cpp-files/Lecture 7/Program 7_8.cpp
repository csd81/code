// Program 7_8
// Parallel Arrays
#include <iostream>
using namespace std;

int main() {
	int year[100];
	int month[100];
	int day[100];

	//January 1, 2000 in element 0
	year[0] = 2000; month[0] = 1; day[0] = 1;
	//February 12, 2007 in element 1
	year[1] = 2007; month[1] = 2; day[1] = 12;                  

	// if we want to display the date in a table
	cout << "Year\tMonth\tDay" << endl;
	for (int i = 0; i < 2; i++) {
		cout << year[i] << "\t" << month[i] << "\t" << day[i] << endl;
	}
}

// Parallel arrays are arrays that are used to store related data
// Parallel arrays are used to store related data

// it is like a table
// each array is a column in the table
// each element in the array is a row in the table

// or it can be uses as key-value pairs
// the first array is the key
// the second array is the value

// we can make relational data structures using parallel arrays

// we can also use it to store a matrix	
// a matrix is a two-dimensional array
// a matrix is a collection of rows and columns
// a matrix is a collection of elements

//but a better way to store a matrix is to use a two-dimensional array
// a two-dimensional array is an array of arrays

//in this example we are using parallel arrays to store the date
// we are using three arrays to store the year, month, and day
// we can use the arrays to store the date in a table