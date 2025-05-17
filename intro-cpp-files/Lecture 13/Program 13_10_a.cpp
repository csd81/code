// Program 13_10_a
// Error trying to pass a literal by reference
#include<iostream>
#include<string>
using namespace std;

string search_and_replace(string& main_string, string word_to_find, 
	string replacement) {                                                             
	//We can NOT manipulate main_string here!
	string modified_string = main_string; // Create a copy of the main_string
	modified_string.replace(modified_string.find(word_to_find), word_to_find.length(), replacement);
	return modified_string; // Return the modified string
}

int main() {
	string old_string = "Hi Robert, I hope you are doing great!"; 
	string new_string = search_and_replace(old_string, 
		"Robert", "Alex"); // Pass a string object by reference    
	cout << new_string << endl; // prints the updated value of new_string
}

// // This program demonstrates how to pass a string by reference to a function.
// // However, we cannot pass a string literal by reference because string literals are immutable in C++.
// // This means that we cannot modify the value of a string literal.
// // In this program, we declare a function search_and_replace that takes a reference to a string as its first parameter.
// // This means that the function can modify the value of the string.

// What is a string literal?	
// A string literal is a sequence of characters enclosed in double quotes.
// For example, "Hello, World!" is a string literal.

// what is the error?
// The error is that we are trying to pass a string literal to a function that expects a reference to a string.
// we can solve this by creating a string object and passing it to the function instead of passing a string literal.

// the difference between a string object and a string literal is that a string object is mutable, 
// meaning we can modify its value, while a string literal is immutable, meaning we cannot modify its value.

// In C++, string literals are stored in read-only memory, and attempting to modify them can lead to undefined behavior.
// we can only pass string objects to functions that expect a reference to a string.