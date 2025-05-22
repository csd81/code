// Program 22_9
// Forward_list example, including insertion
#include<iostream>
#include<string>
#include<forward_list>
using namespace std;

int main() {
	forward_list<string> instructions;
	instructions.push_front("Put two halves together");
	instructions.push_front("Put on jelly");
	instructions.push_front("Get bread");
	forward_list<string>::iterator insert_spot;
	insert_spot = instructions.begin();  // Refers to first element
	insert_spot++;  //Refers to second element
	instructions.insert_after(insert_spot, "Put on peanut butter");
	for (auto iter = instructions.begin(); iter != instructions.end(); iter++) {
		cout << *iter << endl;
	}                
}

// this program demonstrates the use of the forward_list class in C++.
// It creates a forward_list of strings representing instructions for making a sandwich.
// The program uses the forward_list class from the C++ Standard Library to manage the instructions.
// It includes the necessary headers, such as <iostream>, <string>, and <forward_list>.
// The program begins by including the required headers and using the standard namespace.
// It then creates a forward_list of strings called "instructions" and populates it with three initial instructions.
// The program then creates an iterator called "insert_spot" and initializes it to point to the first element of the list.
// The iterator is then incremented to point to the second element of the list.
// The program then uses the insert_after() function to add a new instruction ("Put on peanut butter") at the position of the iterator.
// Finally, the program uses a for loop to iterate through the list and print each instruction to the console.