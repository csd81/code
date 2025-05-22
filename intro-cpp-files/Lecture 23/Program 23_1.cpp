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

// this program demonstrates the use of the pair class in C++.
// The program creates a pair object that holds an integer and a string.
// It assigns values to the first and second elements of the pair.
// Finally, it prints out the values of the pair to the console.