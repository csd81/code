// Program 8_10
// Vector initialization for all elements
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(3, 10);
	cout << "Initial vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;    
	
	vector<int> a(10, 3);
	cout << "Initial vector  : ";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl; 
}

// here we use the constructor to initialize a vector with three elements
// we hav to put the arguments in the constructor between the parentheses
// the first element is 10, the second element is 10, and the third element is 10