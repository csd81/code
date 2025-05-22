// Program 3_3
// Using ! (not) to reverse Boolean values
// this operator is called the logical NOT operator;
#include <iostream>
using namespace std;

int main() {
	bool raining = true;
	bool windy = false;
	cout << "raining is: " << raining << endl;
	cout << "windy is: " << windy << endl;
	cout << "Not raining is: " << !raining << endl;                          // using the logical NOT operator
	// The logical NOT operator reverses the value of a Boolean variable. If the value is true, it becomes false; if the value is false, it becomes true.
	
	cout << "Not windy is: " << !windy << endl;
}