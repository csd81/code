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