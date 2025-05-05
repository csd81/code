// Program 9_20
// Replacing a subset of a string with another string
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string timezone = "Central Standard Time";
	timezone.replace(timezone.begin() + 8, timezone.begin() + 16, "Daylight");
	cout << timezone << endl;        
}