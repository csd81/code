// Program 5_4
// While loop for printing 100 to 200, only even numbers
#include <iostream>
using namespace std;

int main() {
	int num = 100;
	while (num <= 200) {
		cout << num << endl;
		num = num + 2; // increment by 2 to get the next even number
	}                                    
}
