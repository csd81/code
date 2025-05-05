// Program 22_9
// Forward_list example, including insertion
#include<iostream>
#include<string>
#include<forward_list>
using namespace std;

int main() {
	forward_list<string> instructions;
	instructions.push_front("Put two halves together");
	instructions.push_front("Put on jelly");
	instructions.push_front("Get bread");
	forward_list<string>::iterator insert_spot;
	insert_spot = instructions.begin();  // Refers to first element
	insert_spot++;  //Refers to second element
	instructions.insert_after(insert_spot, "Put on peanut butter");
	for (auto iter = instructions.begin(); iter != instructions.end(); iter++) {
		cout << *iter << endl;
	}                
}