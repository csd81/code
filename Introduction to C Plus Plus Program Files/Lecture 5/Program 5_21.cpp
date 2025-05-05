// Program 5_21
// New variable name inside loop
// This program demonstrates the use of a new variable name inside a loop
// and the scope of the variable name.
// The program uses a for loop to iterate through the numbers 1 to 3.
// Inside the loop, a new variable name is declared with the same name as
// the variable name outside the loop. The new variable name is initialized
// to 500. The program prints the value of the new variable name inside
// the loop. After the loop, the program prints the value of the variable
// name outside the loop. The program also prints the value of the variable
// name inside the loop after it has been incremented.
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