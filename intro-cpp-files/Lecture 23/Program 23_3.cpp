// Program 23_3
// Tuple example
#include<iostream>
#include<string>
#include<tuple>
using namespace std;

int main() {
	// Tuple will hold name, team, age, height, weight 
	tuple<string, string, int, double, double> c;
	c = make_tuple("James Smith", "Cubs", 22, 73.5, 182.1);
	cout << get<0>(c) << " is " << get<3>(c) << " inches tall and weighs " 
		<< get<4>(c) << " pounds." << endl;             
}

// this program demonstrates the use of the tuple class in C++.
// The program creates a tuple object that holds a string, a string, an integer, a double, and another double.
// It assigns values to the elements of the tuple using the make_tuple function.
// Finally, it prints out the values of the tuple to the console.	