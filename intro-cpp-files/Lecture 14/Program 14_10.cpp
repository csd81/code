// Program 14_10
// Exception example - vector past end of range - alternative catches
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main() {
	vector<float> hours_worked = { 7.5, 8.5, 10.0, 7.0, 7.0 };
	for (int i = 0; i < 7; i++) {
		try {
			cout << "On day " << i << ", " << hours_worked.at(i) 
				<< " hours were worked." << endl;
		}
		catch (runtime_error& except) {
			cout << except.what() << endl;
			throw except;
		}
		catch (logic_error& except) {
			cout << except.what() << endl;
			throw except;
		}
	}          
}

// this program demonstrates how to use a vector to store and access a list of hours worked.
// it initializes a vector with a list of hours worked for 5 days and then attempts to access the hours worked for 7 days.
// however, the program will throw an exception because the vector only contains 5 elements,