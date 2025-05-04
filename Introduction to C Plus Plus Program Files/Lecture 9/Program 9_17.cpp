// Program 9_17
// String find member function - string::npos marks not-found position
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "This is a test string";
	string s2 = "apple";
	cout << "The first occurrence occurs at position: " << s1.find(s2) << endl;
	cout << "string::npos is defined as " << string::npos << endl;                      
}