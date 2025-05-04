// Program 14_11
// Example returning different exception types
#include <iostream>
#include <stdexcept>
using namespace std;

int find_result(int a) {
	if (a < 0) {
		throw logic_error("Negative argument!");
	}
	if (a > 10) {
		runtime_error my_error("Argument too large.");
		throw my_error;
	}
	return a * a;
}                

int main() {
	int x;
	while (true) {
		try {
			cin >> x;
			cout << find_result(x) << endl;
		}
		catch (logic_error e) {
			cout << "Logic error: " << e.what() << endl;
		}
		catch (runtime_error e) {
			cout << "Runtime error: " << e.what() << endl;
		}
	}                      
}