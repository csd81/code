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
	cout << laboring_hero->name << " has the characteristic of " 
		<< laboring_hero->characteristic << endl;
	cout << (*laboring_hero).name << " has the characteristic of " 
		<< (*laboring_hero).characteristic << endl;          
}