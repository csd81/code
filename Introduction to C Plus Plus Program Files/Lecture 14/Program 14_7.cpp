// Program 14_7
// Throwing exceptions - throwing directly
#include <iostream>
#include <stdexcept>
using namespace std;

int process_boxes(int num_boxes) {
	if (num_boxes < 1) {
		throw exception();
	}
	//Do other stuff here
	return 1;
}

int main() {
	try {
		process_boxes(-1);
	}
	catch (exception& e) {
		cout << "Had an exception!" << endl;
	}
}