// Program 9_4
// Reading and using multiple strings
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string username, favoritecolor;
	cout << "What's your name? ";
	cin >> username;
	cout << "What's your favorite color? ";
	cin >> favoritecolor;
	cout << username << ", I like the color " << favoritecolor << ", too!" << endl;                
}