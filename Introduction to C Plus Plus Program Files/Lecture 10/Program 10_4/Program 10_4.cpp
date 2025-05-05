// Program 10_4
// Use of the eof function in a while loop
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	fstream my_file;
	my_file.open("GroceryList.dat");                                   
	string s;                                         
	my_file >> s; // read the first string from the file UNTIL the first whitespace character (space, tab, newline)
	while (!my_file.eof()) { // eof() is a member function of the fstream class
		cout << s << endl; // output the string
		my_file >> s;                   
	}
	my_file.close();                 
}

// eof() is a member function of the fstream class that checks if the end of the file has been reached.
// It returns true if the end of the file has been reached and false otherwise.
// eof() is commonly used in loops to read data from a file until the end of the file is reached.
// In this example, the while loop continues to read data from the file until the end of the file is reached.