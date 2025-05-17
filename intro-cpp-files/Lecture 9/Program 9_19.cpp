// Program 9_19
// String substr member function
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "This string is not a knot";
	string s2 = s1.substr(7, 4);
	cout << "The substring is: " << s2 << endl;           
}

// substr() is a member function of the string class that returns a substring of the string.
// It takes two arguments: the starting index and the length of the substring.
// The starting index is the position of the first character of the substring, and the length is the number of characters in the substring.

// // "trin"  is the substring starting at index 7 and having a length of 4.

// it is actually "ring" because the first character of the string is at index 0.
// other member functions of the string class include:
// length() - returns the length of the string
// size() - returns the size of the string
// clear() - removes all characters from the string
// empty() - returns true if the string is empty, false otherwise
// find() - searches for a substring within the string and returns the index of the first occurrence
// substr() - returns a substring of the string starting at the specified index and with the specified length
// compare() - compares two strings and returns an integer indicating the result of the comparison
// append() - appends a string to the end of another string
// insert() - inserts a string at a specified position in another string
// erase() - removes a substring from a string
// replace() - replaces a substring in a string with another string