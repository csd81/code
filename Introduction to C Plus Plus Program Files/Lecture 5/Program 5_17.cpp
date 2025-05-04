// Program 5_17
// Nested for loops
#include <iostream>
using namespace std;

int main() {
	int i;
	int j;
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			cout << i << " times " << j << " is " << i * j << endl;
		}
	}                      
}