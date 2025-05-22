// Program 14_4
// Exception example - reading a nonexistent file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream infile;
	string filename;
	cout << "What is the file name? ";
	cin >> filename;
	infile.open(filename, fstream::in);
	if (!infile) {
		cout << "Error opening file: " << filename << endl;
		return 1; // Exit the program with an error code
	} else {
		cout << "File opened successfully." << endl;
	}
	// Read an integer from the file
	int a;
	infile >> a;
	cout << "Read in: " << a << endl;             
	infile.close();
	return 0;
}

// we must have a file with the name specified in the filename variable
// in the same directory as the program
// if the file does not exist, the program will not be able to read from it
// and will throw an exception
// this is a common error when working with file I/O in C++
// to handle this error, we can use a try-catch block
// to catch the exception and handle it gracefully
// this will allow us to provide a better user experience
// and prevent the program from crashing
// we can also use the ifstream class to open the file
// and check if the file was opened successfully
// if the file was not opened successfully, we can print an error message
// and exit the program gracefully
// this is a better way to handle file I/O errors in C++