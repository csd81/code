// Program 5_20
// Declaring a static variable in a loop
#include <iostream>
using namespace std;

int main() {
	int i;
	for (i = 1; i < 4; i++) {
		static int j = 1;
		cout << "In loop: " << i << " " << j << endl;
		j++;
	}
	cout << "After loop: " << i << endl;                                 
}