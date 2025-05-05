// Program 9_16
// String find member function
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "This is a test string";
	string s2 = "test";
	string s3 = "string";
	cout << "The first occurrence of \"" << s2 << "\" occurs at position: " << s1.find(s2) << endl;                  
	cout << "The first occurrence of \"" << s3 << "\" occurs at position: " << s1.find(s3) << endl;                  
}
// find() is a member function of the string class that searches for a substring within a string.
// It returns the index of the first occurrence of the substring in the string.
// If the substring is not found, it returns string::npos, which is a constant representing the maximum value for size_t.
// string::npos  is a constant that represents the maximum value for size_t, 
// which is an unsigned integer type used to represent the size of objects in memory.
// size_t is a type defined in the C++ standard library that is used to represent the size of objects in memory.