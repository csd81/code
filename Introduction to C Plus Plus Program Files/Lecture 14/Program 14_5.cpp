// Program 14_5
// Exception example - vector past end of range
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<float> hours_worked = { 7.5, 8.5, 10.0, 7.0, 7.0 };
	for (int i = 0; i < 6; i++) { // maximum index is 4
		if (i >= hours_worked.size()) {
			cout << "Error: Index out of range!" << endl;
			break; // Exit the loop if index is out of range
		}
		cout << "On day " << i << ", " << hours_worked.at(i) << " hours were worked." 
			<< endl;
	}    
	return 0;
}

// // This program demonstrates how to use a vector to store and access a list of hours worked.
// // It initializes a vector with a list of hours worked for 5 days and then attempts to access the hours worked for 7 days.
// // However, the program will throw an exception because the vector only contains 5 elements,
// // and trying to access the 6th and 7th elements will result in an out-of-range error.