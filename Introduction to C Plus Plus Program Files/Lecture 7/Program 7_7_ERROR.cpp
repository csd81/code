// Program 7_7 -ERROR
#include <string>
#include <iostream>
using namespace std;

int main() {
	// int team_members[]; 
	 int team_members[5];
	
	team_members[0] = 5;
	team_members[1] = 6;
	team_members[2] = 4;
	team_members[3] = 5;
	team_members[4] = 4;
	for (int i = 0; i < 5; i++) {
		cout << team_members[i] << endl;              
	}   
	
	string team[] = { "DJT", "Elon", "Vivek", "Bush", "Marco", "Rumsfeld" };
	for (int i = 0; i < 6; i++) {
		cout << team[i] << endl;
	}
}

// // this program will not compile because the size of the array is not specified
// // the size of the array must be specified when it is declared
// // the size of the array can be specified using a constant expression
// // the size of the array can also be specified using a variable

// but if we initialize the array with a list of values, we do not need to specify the size of the array