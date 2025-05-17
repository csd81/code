// Program 5_18
// Declaring variable in a for loop header
#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i < 4; i++) { // declare i in the for loop header
		cout << i << endl;
	}                               
}

// Declaring variable in a for loop header is a common practice in C++.
// It is a good practice to declare loop control variables in the for loop header because it limits their scope to the loop.
// This makes the code more readable and easier to understand.
// It also prevents accidental modification of the loop control variable outside the loop.
// The loop control variable is only accessible within the loop, and it is automatically destroyed when the loop terminates.
// The reason for this is that the loop control variable is declared in the for loop header, which is a block scope.
// The block scope is a region of code where a variable is declared and can be accessed.
// The block scope is created by the for loop header, and it ends when the loop terminates.
// This variable is stored in the stack memory, which is a region of memory used for temporary storage of variables.
// The stack memory is automatically managed by the compiler, and it is automatically released when the variable goes out of scope.