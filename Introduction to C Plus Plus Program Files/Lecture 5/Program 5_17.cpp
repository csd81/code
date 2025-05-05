// Program 5_17
// Nested for loops
#include <iostream>
using namespace std;

int main() {
	int i;
	int j;
	for (i = 1; i < 11; i++) {
		cout << " | ";
		for (j = 1; j < 11; j++) {
			cout <<  i * j << " | ";
		}
		cout << endl;
	}                      
}

// The nested for loop is a control flow statement that allows code to be executed
// repeatedly based on a given boolean condition.
// The outer loop is executed first, and for each iteration of the outer loop,
// the inner loop is executed completely.		
// The syntax of the nested for loop is as follows:
// for (initialization; condition; increment/decrement) {
//     for (initialization; condition; increment/decrement) {
//         // block of code to be executed
//     }
// }
// The nested for loop is useful when you want to repeat a block of code multiple times,
// and you want to repeat another block of code for each iteration of the outer loop.
// The nested for loop is commonly used in programming to traverse multi-dimensional arrays,
// matrices, and other data structures.
// The outer loop is used to iterate over the rows, and the inner loop is used to iterate over the columns.
// The nested for loop is also used to generate combinations and permutations of a set of values.

// By convention, we use i for the outer loop and j for the inner loop.
// This is a common convention in programming, but it is not a requirement.