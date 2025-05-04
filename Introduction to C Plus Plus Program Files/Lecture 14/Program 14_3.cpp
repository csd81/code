// Program 14_3
// Example program creating error due to user input
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num_boxes;
	cout << "How many boxes do you have? ";
	cin >> num_boxes;
	double cost = 12.50 * num_boxes;
	cout << "It will cost you " << cost << " to ship them." << endl;            
}