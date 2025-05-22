// Program 23_5
// Priority Queue example
#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef pair<int, string> person;

int main() {
	priority_queue<person> pq;
	// Could have been priority_queue<pair<int, string> > pq;
	pq.push(make_pair(18, "Jack"));
	pq.push(make_pair(16, "Jill"));
	pq.push(make_pair(19, "Joe"));
	pq.push(make_pair(17, "Jessica"));
	cout << "The oldest person in the group is: " << pq.top().second << endl;
	pq.pop();
	cout << "The next oldest person in the group is: " << pq.top().second << endl;      
}
// // this program demonstrates the use of the priority queue class in C++.
// // The program creates a priority queue object that holds pairs of integers and strings.
// // It assigns values to the elements of the priority queue using the push function.
// // Finally, it prints out the values of the priority queue to the console.