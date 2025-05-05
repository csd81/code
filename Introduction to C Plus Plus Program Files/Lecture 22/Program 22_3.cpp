// Program 22_3
// Customer order program
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	queue<string> customers;
	string person = "";
	while (person != "None") {
		cout << "Enter the next person in line (enter \"None\" to stop): ";
		cin >> person;
		if (person != "None") {
			customers.push(person);
		}
	}

	cout << "The order to serve customers is: " << endl;
	while (!customers.empty()) {
		cout << "Serve " << customers.front() << endl;
		customers.pop();
	}                  
}