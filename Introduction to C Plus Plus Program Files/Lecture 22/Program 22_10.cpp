// Program 22_10
// Example of for-each statement
#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	list<string> instructions;
	instructions.push_back("Get bread");
	instructions.push_back("Put on peanut butter");
	instructions.push_back("Put on jelly");
	instructions.push_back("Put two halves together");

	for (string& step : instructions) {
		step = "Step: " + step;
	}

	for (auto step : instructions) {
		cout << step << endl;
	}                
}