// Program 10_12
// Reading from a stringstream
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	cout << "Enter several integers on one line:" << endl;
	string input_line;
	getline(cin, input_line);
	stringstream string_input(input_line); // create a stringstream object
	int val;
	while (!string_input.eof()) { // check if the end of the string stream has been reached
		string_input >> val; // read an integer from the string stream, until the first whitespace character (space, tab, newline)
		cout << "You entered: " << val << endl; // output the integer and restart the loop
	}                            
}

// we created a stringstream object called string_input and initialized it with the input_line string.
// we initialized the stringstream object with the  constructor that takes a string as an argument.
