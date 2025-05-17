// Program 9_9
// char type
#include <iostream>
#include <string>
using namespace std;                                     

int main() {
    char testchar1, testchar2, testchar3;
    testchar1 = 'a';
    testchar2 = 'c';
    testchar3 = 'b';
    // string s1, s2, s3;
    string s1(1, testchar1);
    string s2(1, testchar2);
    string s3(1, testchar3);
    cout << s1 + s2 + s3 << endl;     
}

//  char type is a built-in data type in C++ that represents a single character. (e.g., 'a', 'b', '1', etc.)
//  The char type is typically used to store characters, such as letters, digits, and symbols.
//  The char type is a single-byte data type, which means it can store one character at a time.
// the + operator is used to perform arithmetic addition on char variables.
//  When you add two char variables, C++ converts them to their corresponding ASCII values and performs the addition.
//  The ASCII value of a character is its numerical representation in the ASCII character set.
//  For example, the ASCII value of 'a' is 97, 'b' is 98, and 'c' is 99.
// we can also concatenate char variables using the + operator.
// if we want to concatenate char variables, we need to convert them to strings first.
//  This can be done using the string constructor, which takes a char as an argument and creates a string object from it

//  string s1(1, c1);    // string of length 1 containing c1
// string s2(1, c2);

// 3) Concatenate the two strings
// string combined = s1 + s2;