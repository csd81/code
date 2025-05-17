// Program 9_18
// Using npos to check whether a string is not found
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "This is a test string";
	string s2 = "apple";
	string s3 = " is";
	if (s1.find(s3) != string::npos) {
		cout << "The first occurrence occurs at position: " << s1.find(s3) << endl;
	}
	else {
		cout << "The string does not appear" << endl;
	}              
}