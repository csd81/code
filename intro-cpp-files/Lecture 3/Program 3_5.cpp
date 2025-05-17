// Program 3_5
// The || (or) operator for logical OR Boolean operations      
// logical OR operator;
// this operator is called the logical OR operator;
#include <iostream>
using namespace std;                                             

int main() {
	bool chocolate_syrup = true;
	bool chocolate_ice_cream = true;
	bool chocolate_sundae; // chocolate_sundae is a Boolean variablem; we declare it but do not initialize it

	cout << "if either chocolate_syrup or chocolate_ice_cream is true, then chocolate_sundae is true; otherwise, it is false"  << endl;
	chocolate_sundae = chocolate_syrup || chocolate_ice_cream; // if either chocolate_syrup or chocolate_ice_cream is true, then chocolate_sundae is true; otherwise, it is false
	cout << chocolate_syrup << " OR " << chocolate_ice_cream << " is: " << chocolate_sundae << endl;
	chocolate_syrup = true;
	chocolate_ice_cream = false;
	chocolate_sundae = chocolate_syrup || chocolate_ice_cream;
	cout << chocolate_syrup << " OR " << chocolate_ice_cream << " is: " << chocolate_sundae << endl;
	chocolate_syrup = false;
	chocolate_ice_cream = true;
	chocolate_sundae = chocolate_syrup || chocolate_ice_cream;
	cout << chocolate_syrup << " OR " << chocolate_ice_cream << " is: " << chocolate_sundae << endl;
	chocolate_syrup = false;
	chocolate_ice_cream = false;
	chocolate_sundae = chocolate_syrup || chocolate_ice_cream;
	cout << chocolate_syrup << " OR " << chocolate_ice_cream << " is: " << chocolate_sundae << endl;
}