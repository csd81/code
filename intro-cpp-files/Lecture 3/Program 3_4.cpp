// Program 3_4
// The && (and) operator for logical AND Boolean operations
// this operator is called the logical AND operator;
// it is used to combine two Boolean expressions. The result is true if both expressions are true; otherwise, it is false.

#include <iostream>
using namespace std;

// function to test the values of Early_to_Bed, Early_to_Rise, and HWW
void test(bool Early_to_Bed, bool Early_to_Rise, bool HWW) {
	cout << "If Early to Bed is "  << (Early_to_Bed ? "true" : "false") << " AND " << "Early to Rise is " << (Early_to_Rise ? "true" : "false") << " then: " << (HWW ? "HEALTHY, WEALTHY, AND WISE" : "UNHEALTHY, POOR, AND STUPID") << endl; // HWW means "MAKES A MAN HEALTHY, WEALTHY, AND WISE"
} 

int main() {
	bool Early_to_Bed = true;
	bool Early_to_Rise = true;
	bool HWW;
	HWW = Early_to_Bed && Early_to_Rise;
	test(Early_to_Bed, Early_to_Rise, HWW);

	Early_to_Bed = true;
	Early_to_Rise = false;
	HWW = Early_to_Bed && Early_to_Rise;
	test(Early_to_Bed, Early_to_Rise, HWW);

	Early_to_Bed = false;
	Early_to_Rise = true;
	HWW = Early_to_Bed && Early_to_Rise;
	test(Early_to_Bed, Early_to_Rise, HWW);
	
	Early_to_Bed = false;
	Early_to_Rise = false;
	HWW = Early_to_Bed && Early_to_Rise;
	test(Early_to_Bed, Early_to_Rise, HWW);

}