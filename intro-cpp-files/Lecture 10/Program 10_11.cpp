// Program 10_11
//Using concatenation to build a string
#include<iostream>
#include<string>
using namespace std;

int main() {
	int i = 77777; // declare an int variable and initialize it to 77777
	i /= 7;
	string s;
	s = "John Keyser\n";
	s += "123 Any Street\n";
	s += "Somewhere, TX ";
	s += to_string(i);
	s += '\n';
	cout << s << endl;             
}

// The += operator is used to concatenate strings in C++.
// It appends the right-hand operand to the left-hand operand and assigns the result to the left-hand operand.
// +=  is an overloaded operator for the string class, which means it can be used to concatenate strings.
// The to_string() function is used to convert a numeric value to a string.
// stoi() is a function in the C++ standard library that converts a string to an integer.
// to_string() is a member function of the string class that converts a numeric value to a string.
// stoi() is a member function of the string class that converts a string to an integer.