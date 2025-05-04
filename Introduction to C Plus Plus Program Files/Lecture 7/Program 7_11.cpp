// Program 7_11
// ERROR in output due to array out of bounds
#include <iostream>
using namespace std;

int main() {
	int my_array[3];
	my_array[0] = 10;
	my_array[1] = 20;
	my_array[2] = 30;
	for (int i = 0; i < 4; i++) {
		cout << my_array[i] << endl;
	}              
}