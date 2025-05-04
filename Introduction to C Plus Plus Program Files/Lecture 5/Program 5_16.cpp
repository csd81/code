// Program 5_16
// Illustrating value of variable after a loop
#include <iostream>
using namespace std;

int main() {
	int i;
	for (i = 1; i < 4; i++) {
		cout << "In loop: " << i << endl;
	}
	cout << "After loop: " << i << endl;                                     
}