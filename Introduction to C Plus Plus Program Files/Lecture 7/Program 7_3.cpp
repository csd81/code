// Program 7_3
// Setting all elements of an array
#include <iostream>
using namespace std;

int main() {
	int player_money[4];
	int i;
	for (i = 0; i < 4; i++) {
		player_money[i] = 200;
	}
	// Show output
	for (i = 0; i < 4; i++) {
		cout << player_money[i] << endl;
	}                      
}