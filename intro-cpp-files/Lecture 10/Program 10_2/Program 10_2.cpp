// Program 10_2
// Streaming input from a file
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	fstream grocery_file;
	grocery_file.open("GroceryList.dat", fstream::in);      
	string s;
	grocery_file >> s;             
	cout << s << endl;		
	grocery_file >> s;             
	cout << s << endl;	
	grocery_file.close();                                             

	grocery_file.open("GroceryList2.dat", fstream::in);      
	 
	grocery_file >> s;             
	cout << s << endl;
	grocery_file >> s;             
	cout << s << endl;
	grocery_file.close();   
}

// The fstream class is used to create a file stream object that can be used to read from and write to files.
// The open() function is used to open a file for input and/or output.
// The fstream::in mode is used to open the file for input (reading).
// The >> operator is used to read data from the file into the string variable s.
// The close() function is used to close the file when it is no longer needed.
// THE read() function is used to read data from the file.
// The read() function takes two arguments: a pointer to the buffer where the data will be stored and the number of bytes to read.