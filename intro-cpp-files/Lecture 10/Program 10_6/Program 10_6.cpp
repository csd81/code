// Program 10_6
// Writing an address to a file
#include<fstream>
#include<string>
using namespace std;

int main() {
	//fstream my_file("address.txt", fstream::out);
	fstream my_file;
	my_file.open("GroceryList.dat", fstream::out);
	my_file << "first line\n";
	my_file << "2nd line\n";
	my_file << "TEXAS OHIO" << endl;                       
	my_file.close();                                    
}

// // fstream is a class in the C++ standard library that provides input and output operations on files.
// in this case, the fstream class is used to create a file stream object that can be used to write to a file.
// The fstream::out mode is used to open the file for output (writing).
// The << operator is used to write data to the file.
// The endl manipulator is used to insert a newline character and flush the output buffer.
// The close() function is used to close the file when it is no longer needed.

// we didn't open the file in the fstream::in mode, so we can't read from it.
// we didn't use the open() function to open the file, so we can't use the close() function to close it.
// instead, we used the fstream constructor to open the file and the destructor to close it.

// we can first declare a file stream object; and later, we can use the open() function to open the file.
// or we can use the fstream constructor to open the file.