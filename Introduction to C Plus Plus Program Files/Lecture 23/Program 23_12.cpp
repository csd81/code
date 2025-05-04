// Program 23_12
// Lower_bound example - using binary search 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> ages = { 23, 21, 18, 22, 21, 19, 20, 19, 27, 22 };
	vector<int>::iterator findval;
	int agetofind;

	cout << "What age do you want to find? ";
	cin >> agetofind;
	sort(ages.begin(), ages.end());
	findval = lower_bound(ages.begin(), ages.end(), agetofind);
	if (findval != ages.end()) {
		cout << "Found : " << *findval << endl;
	}
	else {
		cout << agetofind << " not found" << endl;
	}             
}