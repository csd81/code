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