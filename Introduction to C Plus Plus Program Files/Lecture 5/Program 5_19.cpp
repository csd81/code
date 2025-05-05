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
	// cout << "After loop: " << j << endl;            // this will cause an error because j is not declared in this scope                                              
}

// The value of i after the loop is 4 because the loop condition is checked before each iteration.

// Declaring a variable in a loop is a common practice in C++.
// It is a good practice to declare loop control variables in the for loop header because it limits their scope to the loop.
// In this case, the variable j is declared inside the loop, so it is only accessible within the loop, but the variable i is declared outside the loop, so it is accessible after the loop.