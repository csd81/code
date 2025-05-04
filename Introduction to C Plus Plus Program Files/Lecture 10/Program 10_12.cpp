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
	stringstream string_input(input_line);
	int val;
	while (!string_input.eof()) {
		string_input >> val;
		cout << "You entered: " << val << endl;
	}                            
}