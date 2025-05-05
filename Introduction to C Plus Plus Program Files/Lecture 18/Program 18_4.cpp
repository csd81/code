// Program 18_4
// Calling constructor at allocation
#include <iostream>
#include <string>
using namespace std;

class hero {
public:
	string name;
	string characteristic;

	// Default constructor
	hero() {
		name = "John Doe";
		characteristic = "nothing";
	}

	// Constructor to initialize name and characteristic
	hero(string n, string c) {
		name = n;
		characteristic = c;
	}
};

int main()
{
	hero* h1;
	hero* h2;
	h1 = new hero;
	h2 = new hero("Hercules", "strength");
	cout << h1->name << " has the characteristic of " << h1->characteristic << endl;
	cout << h2->name << " has the characteristic of " << h2->characteristic << endl;                  
}