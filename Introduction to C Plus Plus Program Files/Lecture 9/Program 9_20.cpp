// Program 9_20
// Replacing a subset of a string with another string
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string timezone = "Central Standard Time";
	timezone.replace(timezone.begin() + 8, timezone.begin() + 16, "Daylight");
	timezone.replace(timezone.begin() + 0, timezone.begin() + 7, "Eastern");
	cout << timezone << endl;        
}

// replace() is a member function of the string class that replaces a substring in a string with another string.
// It takes three arguments: 
// 1. the starting position of the substring to be replaced, 
// 2. the ending position of the substring to be replaced, 
// 4.  and the new string to replace it with.
// so in this case, the substring "Standard" is replaced with "Daylight".

// the new string does not have to be the same length as the substring being replaced.


// begin() is a member function of the string class that returns an iterator pointing to the first character of the string.
// end() is a member function of the string class that returns an iterator pointing to one past the last character of the string.
// iterators are objects that point to a specific position in a container, such as a string or an array.
// They are used to traverse the elements of the container and perform operations on them.