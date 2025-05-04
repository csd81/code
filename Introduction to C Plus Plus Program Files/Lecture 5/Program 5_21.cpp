// Program 5_21
// New variable name inside loop
#include <iostream>
using namespace std;

int main() {
	int i;
	int j = 1;
	for (i = 1; i < 4; i++) {
		int j = 500;
		cout << "In loop: " << i << " " << j << endl;
		j++;
	}
	cout << "After loop: " << i << " " << j << endl;                                         
}