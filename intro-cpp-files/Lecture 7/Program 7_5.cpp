// Program 7_5
// Array Initialization
#include <iostream>
#include <string>
using namespace std;

int main() {
	int team_members[5] = { 5, 6, 4, 5, 4 };
	for (int i = 0; i < 5; i++) {
		cout << team_members[i] << endl;
	}                            

	string cabinet_members[] = { "DJT", "Elon", "Vivek", "Bush", "Marco", "Rumsfeld" };
	for (int i = 0; i < 6; i++) {
		cout << cabinet_members[i] << endl;
	}                            
}

// we can initialize an array with a list of values
// the size of the array is determined by the number of values in the list
// the array is initialized with the values in the list
// int team_members[5] = { 5, 6, 4, 5, 4 }; is equivalent to
// int team_members[] = { 5, 6, 4, 5, 4 };