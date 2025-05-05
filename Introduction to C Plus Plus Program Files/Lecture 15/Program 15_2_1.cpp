// Program 15_2_1
// Example bottom-up program - string processing (incomplete) - Stage 1
#include <iostream>
#include <string>
using namespace std;

int pos_first(string& string_to_find, string& string_to_search) {
	/* Returns the position of the first occurrence of string_to_find in 
	string_to_search, or -1 if it is not found */
	int pos = string_to_search.find(string_to_find);
	if (pos == string::npos) {
		return -1; // Not found
	}
	else {
		return pos; // Found
	}
}

void replace_string(string& string_to_modify, int start_pos, int end_pos, 
	string& string_to_insert) {
	/* Replaces the substring in string_to_modify from start_pos to end_pos with
	string_to_insert */
	string_to_modify.replace(start_pos, end_pos - start_pos, string_to_insert);
}

bool search_and_replace(string& string_to_modify, string& old_string, 
	string& new_string) {
	/* Searches for old_string in string_to_modify and replaces it with new_string */
	int pos = string_to_modify.find(old_string);
	if (pos != string::npos) {
		// Found old_string, replace it with new_string
		replace_string(string_to_modify, pos, pos + old_string.length(), new_string);
		return true; // Replacement successful
	}
	else {
		return false; // old_string not found
	}
}

int main()
{
	string long_document;
	//Assign something to long_document here
	long_document = "Robert is a good boy?";

	;
	//Code Here           
	pos_first
	replace_string
	search_and_replace
}

// This program demonstrates how to use string processing functions in C++.
// It defines functions to find the first occurrence of a substring in a string,
// replace a substring with another substring, and search and replace a substring in a string.
// The main function calls these functions to demonstrate their functionality.
// The program is incomplete and needs to be filled in with the actual code for the functions.