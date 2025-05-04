// Program 14_5
// Exception example - vector past end of range
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<float> hours_worked = { 7.5, 8.5, 10.0, 7.0, 7.0 };
	for (int i = 0; i < 7; i++) {
		cout << "On day " << i << ", " << hours_worked.at(i) << " hours were worked." 
			<< endl;
	}           
}