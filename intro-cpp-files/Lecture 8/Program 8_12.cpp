// Program 8_12
// Vector resizing and initializing
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> v(3); //  the default values are 0, 0, 0
	v.resize(5, 1); // 0,0,0,1,1
	//cout << "Resized vector  : ";
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;                
	for (int i : v) { // here i is a reference to each *element* of the vector, but it is not an index, it can be of any type, not only int
		cout << i << " ";
	}
	cout << endl;           

	vector<string> z(3); //  the default values are "b", "b", "b"
	 z.resize(5);   // "b", "b", "b", "a", "a"
	//cout << "Resized vector  : ";
		
	     
	for (auto i : z) { // here i is a reference to each *element* of the vector, but it is not an index, it can be of any type, not only int
		cout << i << " ";
	}
}