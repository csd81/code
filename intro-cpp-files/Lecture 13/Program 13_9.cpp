// Program 13_9
// Passing by Reference - Incomplete program
#include<iostream>
#include<string>
using namespace std;

void search_and_replace(string& main_string, string word_to_find, string replacement) { // main_string is passed by reference
	// so it can be changed in the function
	// this allows us to modify the original variable directly
	// without creating a copy of it
	// this is useful when we want to modify the original variable directly
	// or when we want to avoid copying large objects 
	// main_string is a relatively large object.

	main_string.replace(main_string.find(word_to_find), word_to_find.length(), replacement); 
	//Manipulate main_string here
}

int main() {
	string long_document;
	//Assign something to long_document here
	long_document = "Robert is a good boy. Robert is a good student. Robert is a good friend.";

	search_and_replace(long_document, "Robert", "Bob");              
	search_and_replace(long_document, "Robert", "Alice");              
	search_and_replace(long_document, "Robert", "Donald");              
	cout << long_document << endl; // prints the updated value of long_document
}

// this program demonstrates how to pass a string by reference to a function.