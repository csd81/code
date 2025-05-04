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