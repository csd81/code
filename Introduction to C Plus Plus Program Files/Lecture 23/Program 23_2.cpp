// Program 23_2
// Using typedef to create a new name for a type
#include<iostream>
#include<string>
using namespace std;

typedef pair<int, string> person;

int main() {
	person p;
	p = make_pair(45, "John");
	cout << p.second << " is " << p.first << " years old." << endl;                   
}