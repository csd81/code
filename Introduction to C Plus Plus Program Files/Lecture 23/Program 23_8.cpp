// Program 23_8
// Find example
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> ages = { 23, 21, 18, 22, 21, 19, 20, 19, 27, 22 };
	vector<int>::iterator findval;
	int agetofind;

	cout << "I have a list of ages of participants." << endl;
	while (true) {
		cout << "What age do you want to find? ";
		cin >> agetofind;
		findval = find(ages.begin(), ages.end(), agetofind);
		if (findval != ages.end()) {
			cout << "Found : " << *findval << endl;
		}
		else {
			cout << agetofind << " not found" << endl;
		}
	}           
}