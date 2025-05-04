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