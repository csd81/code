// Program 9_8_a
// ERROR - can't add string literals
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2, s3;
	s1 = "Happy";
	s2 = "Birthday";
	s3 = s1 + " " + s2; 
	cout << s3 << endl;                                                
}
// string literals are enclosed in double quotes (e.g., "Happy"), while string variables are defined using the string class (e.g., string s1).
// The + operator is used to concatenate strings, and it can be used with both string literals and string variables.
// In this case, the program concatenates the string literals "Happy" and "Birthday" with a space in between, resulting in the output "Happy Birthday".
// The program demonstrates how to concatenate string literals and string variables using the + operator.
// The program will output "Happy Birthday" to the console.