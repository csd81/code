// Program 23_13
// Sorting Pairs
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>                     
using namespace std;

int main() {
	vector<pair<double, string> > salaries;
	cout << "Enter a person's name and salary, one name and then one salary per line." 
		<< endl;
	cout << "Enter a negative salary to stop." << endl;
	string personname;
	double sal;
	cin >> personname >> sal;
	while (sal >= 0.0) {
		salaries.push_back(make_pair(sal, personname));
		cin >> personname >> sal;
	}
	sort(salaries.begin(), salaries.end());
	for (auto& iter : salaries) {
		cout << iter.first << " " << iter.second << endl;
	}                
}