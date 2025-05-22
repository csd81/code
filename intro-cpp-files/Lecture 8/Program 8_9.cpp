// Program 8_9
// Vector initialization
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3 };
	cout << "Initial vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;   

	vector<int> z = { 8, 3 };
	cout << "Initial vector  : ";
	for (int i = 0; i < z.size(); i++) {
		cout << z[i] << " ";
	}
	cout << endl;   
}

// we can also use the constructor to initialize a vector
// the vector is a class template
// each class template has a constructor
// the constructor is a special member function
// that is called when an object of the class is created
// the constructor initializes the object
// the constructor can take arguments
// the constructor can be overloaded

// in this example, we use the constructor to initialize a vector
// the constructor takes two arguments, which are the size of the vector and the initial value of each element
// or we can use the constructor to initialize a vector with a list of values

// vector<int> v = { 1, 2, 3 };
// here we use the constructor to initialize a vector with three elements
// the first element is 1, the second element is 2, and the third element is 3
// the constructor initializes the vector with the given size and initial value

// if we pass only one argument to the constructor, the vector will be initialized with that size
// and all elements will be initialized to 0
// vector<int> v(3);

// if we pass two arguments to the constructor, the vector will be initialized with that size
// and all elements will be initialized to the given value
// vector<int> v(3, 5);
// here we use the constructor to initialize a vector with three elements
// the first element is 5, the second element is 5, and the third element is 5

// vector<int> v = { 1, 2, 3 };
// here we use the assignment operator to initialize a vector with three elements, so this is not a constructor
