// Program 22_3
// Customer order program
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	queue<string> customers; // Queue to hold customer names
	string person = "";
	while (person != "None") {
		cout << "Enter the next person in line (enter \"None\" to stop): ";
		cin >> person;
		if (person != "None") {
			customers.push(person); // Add customer to the queue
		}
	}

	cout << "The order to serve customers is: " << endl;
	while (!customers.empty()) {
		cout << "Serve " << customers.front() << endl; // Print the front customer
		customers.pop(); // Remove the front customer from the queue
	}                  
}

// This code is a simple customer order program that demonstrates how to use the queue data structure in C++.
// It includes the necessary header files, creates a queue of strings to represent customers, and allows the user to
// enter customer names until "None" is entered. The program then prints the order in which customers will be served.
// The program uses the standard namespace to avoid prefixing standard library functions and types with "std::".
// The queue is a First In First Out (FIFO) data structure, meaning that the first customer added to the queue is the
// first one to be served. The program uses a while loop to check if the queue is empty and prints the front value of
// the queue before popping it off. The program ends when the queue is empty, demonstrating the basic operations of a
// queue in C++. The program is a simple example of how to manage customer orders using a queue data structure.

// queue has several functions:
// 1. push() - adds an element to the back of the queue
// 2. pop() - removes the front element from the queue
// 3. front() - returns the front element of the queue
// 4. back() - returns the back element of the queue
// 5. empty() - checks if the queue is empty
// 6. size() - returns the number of elements in the queue
// 7. swap() - swaps the contents of two queues
// 8. emplace() - constructs an element in place at the back of the queue
// 9. emplace_front() - constructs an element in place at the front of the queue
// 10. emplace_back() - constructs an element in place at the back of the queue
// 11. emplace_at() - constructs an element in place at a specific position in the queue
 