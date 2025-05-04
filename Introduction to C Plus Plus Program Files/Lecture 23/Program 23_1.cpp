// Program 23_1
// Pair example
#include<iostream>
#include<string>
using namespace std;

int main() {
	pair<int, string> p;
	p.first = 45;
	p.second = "John";
	cout << p.second << " is " << p.first << " years old." << endl;            
}