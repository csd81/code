// Program 10_1
// Streaming output to a file
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	string s1;
	string s2, s3;
	fstream grocery_file;
	grocery_file.open("GroceryList.dat", fstream::in);
	grocery_file >> s1;
	grocery_file >> s2;
	grocery_file >> s3;
	grocery_file.close();                          
	cout << "The first item in the grocery list is: " << s1 << endl;
	cout << "The second item in the grocery list is: " << s2 << endl;
	cout << "The 3 item in the grocery list is: " << s3 << endl;
}                             

// fstream is a class in the C++ standard library that provides input and output operations on files.
// It is used to create, read, write, and manipulate files.
// The fstream class is derived from the ifstream and ofstream classes, which are used for input and output operations on files, respectively.
// The fstream class allows you to perform both input and output operations on the same file.
// The fstream class provides several member functions for file operations, including:
// 1. open(): Opens a file for input and/or output.
// 2. close(): Closes the file.
// 3. read(): Reads data from the file.
// 4. write(): Writes data to the file.
 

//  the open() function is used to open a file for input and/or output.
//  The open() function takes two arguments: the name of the file to be opened and the mode in which to open the file.
//  The mode can be one of the following:
// 1. ios::in: Open the file for input (reading).
// 2. ios::out: Open the file for output (writing).
// 3. ios::app: Open the file for output (writing) and append data to the end of the file.
// 4. ios::ate: Open the file and move the read/write position to the end of the file.
// 5. ios::trunc: Truncate the file to zero length if it already exists.