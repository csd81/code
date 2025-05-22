// Program 8_4
// Example of a vector named Victor, ha-ha
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> Victor;
	Victor.push_back(1);
	Victor.push_back(2);
	Victor.push_back(3);
	cout << Victor[0] << " " << Victor[1] << " " << Victor[2] << endl;              
	Victor.pop_back(); // remove the last element of the vector which is 3;
 
	for (int i : Victor){
	cout << i << " ";	
	}
	cout << endl;
}

// // this will create a 1D array with 3 elements