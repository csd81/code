// Program 5_5
// Infinite Loop
// we must strive to avoid infinite loops in our programs.
// An infinite loop is a loop that never terminates. It continues to execute indefinitely,
// or until the program is terminated by the user or the operating system.
// Infinite loops can occur when the loop condition is always true, or when the loop
// does not have a proper exit condition.
// Infinite loops can cause a program to hang or become unresponsive, and they can
// consume system resources, leading to performance issues.
// In this program, we will demonstrate an infinite loop using a while loop.

#include <iostream>
using namespace std;

int main() {
	int count = 1;
	while (count > 0) { // this condition is always true, so the loop will never terminate
		cout << count << endl;
		count++;
	}                                   
}