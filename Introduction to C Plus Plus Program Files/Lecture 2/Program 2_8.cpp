// Program 2_8
// Initializing variables in declaration
#include <iostream>
using namespace std;

int main() {                                   
	int weeks = 20; // declare and initialize weeks

	int days = weeks * 7; // calculate days in weeks at the same time as declaring
	
	// output the result
	cout << "There are " << days << " days in " << weeks << " weeks." << endl;
}