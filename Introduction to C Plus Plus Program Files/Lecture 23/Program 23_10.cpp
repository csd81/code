// Program 23_10
// Find example - finding all instances
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
		findval = ages.begin();
		while (true) {
			findval = find(findval, ages.end(), agetofind);
			if (findval != ages.end()) {
				cout << "Found : " << *findval << endl;
				findval++;
			}
			else {
				cout << agetofind << " not found any more" << endl;
				break;
			}
		}
	}    
}
