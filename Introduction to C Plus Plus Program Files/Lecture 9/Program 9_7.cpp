// Program 9_7
// Adding strings that are numbers
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "addition on strings" << endl;
	string s1, s2, s3;
	s1 = "3";
	s2 = "4";
	s3 = s1 + s2; // 34
	cout << s3 << endl;                 

	cout << "addition on ints" << endl;
	int i1, i2, i3;
	i1 = stoi(s1);
	i2 = stoi(s2);
	i3 = i1 + i2; // 7
	cout << i3 << endl;                 
}

// The program concatenates two strings that represent numbers, resulting in a new string "34".
// This is because the + operator for strings performs concatenation, not arithmetic addition.
// If you want to perform arithmetic addition, you need to convert the strings to integers first.

// we can cast the string to an int using the (int) operator.
// However, this will not work as expected because the (int) operator does not convert strings to integers in C++.
// Instead, you should use the stoi() function (string to integer) to convert the strings to integers before performing the addition.
// The stoi() function is part of the <string> library and is used to convert a string to an integer.