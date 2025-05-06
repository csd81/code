// Program 23_4
// Tuple example - extended
#include<iostream>
#include<string>
#include<tuple>
using namespace std;                                

typedef tuple<string, int, double> customer;

int main() {
	customer c;
	c = make_tuple("John", 3, 100.0);
	cout << get<0>(c) << " has made " << get<1>(c) << " purchases and owes $" 
		<< get<2>(c) << endl;
	get<1>(c)++;
	get<2>(c) += 50.0;
	cout << get<0>(c) << " has made " << get<1>(c) << " purchases and owes $" 
		<< get<2>(c) << endl;         
}
// // this program demonstrates the use of the tuple class in C++.
// // The program creates a tuple object that holds a string, an integer, and a double.
// // It assigns values to the elements of the tuple using the make_tuple function.
// // It prints out the values of the tuple to the console.