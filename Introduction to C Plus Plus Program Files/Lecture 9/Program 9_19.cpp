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