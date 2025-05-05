// Program 23_6
// Map example - animal shelter
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string, int> numanimals;
	numanimals["cat"] = 12;
	numanimals["dog"] = 23;
	numanimals["rabbit"] = 2;

	string whichanimal;
	cout << "Which animal do you want a count of? ";
	cin >> whichanimal;
	if (numanimals.count(whichanimal) > 0) {
		cout << "There are " << numanimals[whichanimal] << " in the shelter." << endl;      
	}
	else {
		cout << "That animal is not in the shelter." << endl;
	}         
}