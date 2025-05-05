// Program 5_19
// Declaring a variable in a loop 
#include <iostream>
using namespace std;

int main() {
	int i;
	for (i = 1; i < 4; i++) {                                       
		int j = 1;
		cout << "In loop: " << i << " " << j << endl;
		j++;
	}
	cout << "After loop: " << i << endl;                                                          
}