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

// this program demonstrates the use of typedef to create a new name for a type in C++.
// The program uses the pair class to create a new type called person, which is a pair of an integer and a string.
// It assigns values to the first and second elements of the person object.
// Finally, it prints out the values of the person object to the console.