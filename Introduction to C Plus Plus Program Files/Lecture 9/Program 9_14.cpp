// Program 9_14
// Comparing strings
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	                                                      
	cout << "Enter first string: ";
	cin >> s1;
	cout << "Enter second string: ";
	cin >> s2;
	if (s1 > s2) {
		cout << "\"" << s1 << "\" is greater than \"" << s2 << "\"" << endl;
	}
	else {
		cout << "\"" << s1 << "\" is NOT greater than \"" << s2 << "\"" << endl;
	}
}