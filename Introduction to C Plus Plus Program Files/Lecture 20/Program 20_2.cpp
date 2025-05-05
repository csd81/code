// Program 20_2
// Defining our own exception
#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;

class bad_value_exception : public logic_error {
private:
	int value;

public:
	bad_value_exception(int n, string s = "") : logic_error(s) {
		value = n;
	}

	void printval() {
		cout << "The number " << value << " was used when it wasn't allowed." << endl;
	}
};

void something_to_do(int x) {
	// Print the value if it's less than 3, throw an exception otherwise
	if (x > 3) {
		throw(bad_value_exception(x, "Bad Value"));
	}
	else {
		cout << x << " is a good number." << endl;
	}
}

int main() {
	try {
		something_to_do(1);
		something_to_do(5);
		something_to_do(10);
	}
	catch (bad_value_exception e) {
		e.printval();
	}                            
}