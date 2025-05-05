// Program 22_8
// List example, including insertion
#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	list<string> instructions;
	instructions.push_back("Get bread");
	instructions.push_back("Put on jelly");
	instructions.push_back("Put two halves together");
	list<string>::iterator insert_spot;
	insert_spot = instructions.begin();  // Refers to first element
	insert_spot++;  //Refers to second element
	instructions.insert(insert_spot, "Put on peanut butter");
	for (auto iter = instructions.begin(); iter != instructions.end(); iter++) {
		cout << *iter << endl;
	}               
}