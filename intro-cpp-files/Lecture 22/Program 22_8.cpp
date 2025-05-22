// Program 22_8
// List example, including insertion
#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	list<string> instructions;
	instructions.push_back("Get bread");
	instructions.push_back("Put on jelly");
	instructions.push_back("Put two halves together");
	list<string>::iterator insert_spot;
	insert_spot = instructions.begin();  // Refers to first element
	insert_spot++;  //Refers to second element
	instructions.insert(insert_spot, "Put on peanut butter");
	for (auto iter = instructions.begin(); iter != instructions.end(); iter++) {
		cout << *iter << endl;
	}               
}

// this program demonstrates the use of the list class in C++.
// It creates a list of strings representing instructions for making a sandwich.
// The program uses the list class from the C++ Standard Library to manage the instructions.
// It includes the necessary headers, such as <iostream>, <string>, and <list>.
// The program begins by including the required headers and using the standard namespace.
// It then creates a list of strings called "instructions" and populates it with three initial instructions.
// The program then creates an iterator called "insert_spot" and initializes it to point to the first element of the list.
// The iterator is then incremented to point to the second element of the list.
// The program then uses the insert() function to add a new instruction ("Put on peanut butter") at the position of the iterator.
// Finally, the program uses a for loop to iterate through the list and print each instruction to the console.
// The output of the program will be the list of instructions, including the newly inserted instruction.