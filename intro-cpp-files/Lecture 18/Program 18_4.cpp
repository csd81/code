// Program 18_4
// Calling constructor at allocation
#include <iostream>
#include <string>
using namespace std;

class hero {
public:
	string name;
	string superpower;

	// Default constructor
	hero() {
		name = "Braveheart";
		superpower = "courage";
	}
	~hero(){

		cout << "Destructor called for " << name << endl;
	}

	// Constructor to initialize name and characteristic
	hero(string n, string c) {
		name = n;
		superpower = c;
	}
};

int main()
{
	hero* h1; // Pointer to hero object, not initialized yet, but it is declared as a pointer to a hero object (hero*),
	hero* h2; // so the memory location that h1 points to has the same size as the class hero
	
	h1 = new hero;  
			// h1 is assigned the address of a new hero object, so h1 now points to a new hero object
			// h1 is initialized with the default constructor, so name is "hero1" and characteristic is "brave"	

	h2 = new hero("Hercules", "strength"); 
			// h2 is assigned the address of a new hero object, so h2 now points to a new hero object
			// h2 is initialized with the name "Hercules" and the characteristic "strength"

	cout << h1->name << " has the superpower: " << h1->superpower << endl;
		// since h1 is a pointer to a hero object, we can use the arrow operator (->) to access its members

	cout << (*h2).name << " has the superpower: " << (*h2).superpower << endl;                  
			// we can dereference the pointer using the * operator before the pointer variable h2,
			// to get the object itself, so we can use the dot operator to access its members

	hero* h3 = new hero("Superman", "can fly"); 
	cout << h3->name << " has the superpower: " << (*h3).superpower << endl;
			

	// we need to delete the memory allocated for the objects created using new operator

	// to avoid memory leaks, we need to deallocate the memory using the delete operator
	delete h1; // deallocating memory for the object pointed to by h1
	delete h2; // deallocating memory for the object pointed to by h2
	delete h3; // deallocating memory for the object pointed to by h3
}

// the new operator is used to allocate memory for a new object of the class hero
// it can be used to create objects dynamically at runtime
// but it can only be used if the object is a pointer to a class