// Program 18_3
// Pointer to object with "arrow" to dereference
#include <iostream>
#include <string>
using namespace std;

class hero {
public:
	string name;
	string characteristic;
};

int main()
{
	hero h;
	h.name = "Hercules";
	h.characteristic = "strength";
	hero* laboring_hero;
	laboring_hero = &h;
	cout << laboring_hero->name << " has the characteristic of "  // this will print the name of the hero, which is Hercules, 
										// because we are using the arrow operator, which is used to access the members of a class or structure through a pointer
		<< laboring_hero->characteristic << endl;
	cout << (*laboring_hero).name << " has the characteristic of " // this will print the name of the hero, which is Hercules, 
						// but we are using the dereference operator (*),
						// which means we are dereferencing the pointer laboring_hero to get the object itself, 
						// and then using the dot operator to access its members
		<< (*laboring_hero).characteristic << endl;          
}

// the arrow operator is also called the member access operator, because it is used to access members of a class or structure through a pointer
// so it is a pointer member access operator

// the arrow operator (->) is used to access members of a class or structure through a pointer
// name and characteristic are two member variables of the class hero

// laboring_hero is a pointer to an object of the class hero, because it is declared as a pointer to a hero object (hero*), 
// which means it can point to a memory location that contains an object of the class hero, and has the same size as the class hero

// we can dereference the pointer using the arrow operator (->) to access the members of the class hero
// meaning that we can access the members of the class hero using the pointer laboring_hero

// the dot  operator (object_._member) is used to access members of a class or structure through an object
// the arrow operator (->) is used to access members of a class or structure through a pointer

// the dot operator is also called the member access operator, because it is used to access members of a class or structure through an object
// so it is an object member access operator

// when we dereference the pointer to the object using the * operator before the pointer variable laboring_hero, 
// we get the object itself, so we can use the dot operator to access its members