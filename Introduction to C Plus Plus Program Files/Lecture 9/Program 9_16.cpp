// Program 9_16
// String find member function
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "This is a test string";
	string s2 = "test";
	cout << "The first occurrence occurs at position: " << s1.find(s2) << endl;                  
}