// Program 8_1
// Copying an array
#include <iostream>
using namespace std;

int main() {
	int a[5] = { 10, 20, 30, 40, 50 };
	int b[5];

	//Loop to copy array a to array b
	for (int i = 0; i < 5; i++) {
		b[i] = a[i];
	}                    
}