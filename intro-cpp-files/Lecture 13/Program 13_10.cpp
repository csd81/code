// Program 13_10
// Passing by const reference - incomplete program
#include<iostream>
#include<string>
using namespace std;

string search_and_replace(const string& main_string, string word_to_find, string replacement) {
	
	string modified_string = main_string; // Create a copy of the main_string
	modified_string.replace(modified_string.find(word_to_find), word_to_find.length(), replacement);
	return modified_string; // Return the modified string
}

int main() {
	string new_string = search_and_replace("Hi Robert, I hope you are doing great!", 
		"Robert", "Trump");           
	cout << new_string << endl; // prints the updated value of new_string
}

// const reference allows us to pass a variable to a function without copying it,
// while also ensuring that the function does not modify the original variable.
// This is useful when we want to avoid copying large objects and ensure that the original variable remains unchanged.
// In this program, we declare a function search_and_replace that takes a const reference to a string as its first parameter.
// This means that the function can read the value of the string but cannot modify it.