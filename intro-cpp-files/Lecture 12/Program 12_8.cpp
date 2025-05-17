// Program 12_8
// A more complete function: counting words in a string,           
//alternative handling multiple spaces
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int word_count(string str_to_count) {
	// Count number of spaces
	int count = 0;
	int i;
	for (i = 0; i < str_to_count.size(); i++) {
		// Only count if not a consecutive space
		if (str_to_count[i] == ' '  // check if subscript i of the string is a space
			&& str_to_count[i - 1] != ' ') {  // check if the previous character is not a space 
				// if both conditions are true, increment the count
			count++;
		}
	}
	// Number of words is one more than number of spaces
	return count + 1;
}

int main() {
	string s = " This is a string that has   eight words. ";
	cout << "There are " << word_count(s) << " words in the string." << endl; 
}
// // The program defines a function called word_count() that takes a string as input and counts the number of words in the string.
// // The function uses a for loop to iterate through the string and counts the number of spaces.
// // The number of words is one more than the number of spaces.