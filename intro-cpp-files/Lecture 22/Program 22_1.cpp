// Program 22_1
// Stack example
#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> s;
	s.push(10);
	s.push(15);
	s.push(20);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}       
}


// This code is a simple stack example that demonstrates how to use the stack data structure in C++.
// It includes the necessary header files, creates a stack of integers, pushes some values onto the stack,
// and then pops and prints the values until the stack is empty. The program uses the standard namespace to avoid
// prefixing standard library functions and types with "std::". The stack is a Last In First Out (LIFO) data structure,
// meaning that the last value pushed onto the stack is the first one to be popped off. The program uses a while loop
// to check if the stack is empty and prints the top value of the stack before popping it off. The program ends when
// the stack is empty, demonstrating the basic operations of a stack in C++.