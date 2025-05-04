// Program 7_7 -ERROR
#include <iostream>
using namespace std;

int main() {
	int team_members[];
	team_members[0] = 5;
	team_members[1] = 6;
	team_members[2] = 4;
	team_members[3] = 5;
	team_members[4] = 4;
	for (int i = 0; i < 5; i++) {
		cout << team_members[i] << endl;              
	}                      
}