// Program 22_10
// Example of for-each statement
#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	list<string> instructions;
	instructions.push_back("Get bread");
	instructions.push_back("Put on peanut butter");
	instructions.push_back("Put on jelly");
	instructions.push_back("Put two halves together");

	for (string& step : instructions) { // for-each statement
		step = "Step: " + step;
	}

	for (auto step : instructions) { // for-each statement
		cout << step << endl;
	}                
}

// this program demonstrates the use of the for-each statement to iterate through a list of strings.
// The program first initializes a list of instructions for making a peanut butter and jelly sandwich.
// It then uses a for-each loop to prepend "Step: " to each instruction in the list.
// Finally, it prints out each modified instruction to the console.
// The program uses the C++ standard library's list and string classes to manage the list of instructions.
// The for-each loop is a convenient way to iterate through the elements of a container without needing to manage an index or iterator explicitly.
// The program is a simple example of how to use the for-each statement in C++ to manipulate and display elements in a list.