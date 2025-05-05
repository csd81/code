// Program 3_7
// Comparisons: less than/greater than to give a Boolean result
#include <iostream>
using namespace std;

int main() {
	int Team1points = 17, Team2points = 20;
	cout << (Team1points < Team2points) << endl; // less than is TRUE
	cout << (Team1points <= Team2points) << endl; // less than or equal to is TRUE
	cout << (Team1points > Team2points) << endl; // greater than is FALSE
	cout << (Team1points >= Team2points) << endl;  // greater than or equal to is FALSE                                        
	cout << (Team1points == Team2points) << endl; // equal to is FALSE
	cout << (Team1points != Team2points) << endl; // not equal to is TRUE
}