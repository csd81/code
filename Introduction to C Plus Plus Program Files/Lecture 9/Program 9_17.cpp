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

// string::npos is defined as 18446744073709551615 
// (or 0xFFFFFFFF FFFFFFFF in hexadecimal), which is the maximum value for size_t.
// so the memory address is 16 bytes long.
// How many addresses are there in 16 bytes?
// The number of addresses in 16 bytes is 2^64, which is the maximum value for size_t.
// size_t is an unsigned integer type used to represent the size of objects in memory.
// The maximum value for size_t is 2^64 - 1, which is 18446744073709551615.