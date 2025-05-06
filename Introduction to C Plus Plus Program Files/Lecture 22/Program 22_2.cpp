// Program 22_2
// Queue example
#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> q;
	q.push(10);
	q.push(15);
	q.push(20);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}              
}

// This code is a simple queue example that demonstrates how to use the queue data structure in C++.
// It includes the necessary header files, creates a queue of integers, pushes some values onto the queue,
// and then pops and prints the values until the queue is empty. The program uses the standard namespace to avoid
// prefixing standard library functions and types with "std::". The queue is a First In First Out (FIFO) data structure,
// meaning that the first value pushed onto the queue is the first one to be popped off. The program uses a while loop
// to check if the queue is empty and prints the front value of the queue before popping it off. The program ends when
// the queue is empty, demonstrating the basic operations of a queue in C++.