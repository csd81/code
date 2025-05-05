// Program 9_15
// String empty member function
#include <iostream>
#include <string>
using namespace std;

int main() {
	string news_today = "";
	
		cout << (news_today.empty() ? "It is empty" : "It is full") << endl;
	    

	news_today = "news";
	
		cout << (news_today.empty() ? "It is empty" : "It is full") << endl;
	               
}
// the empty() member function is used to check if a string is empty.
// It returns true if the string is empty (i.e., it has no characters) and false otherwise.
// it is a boolean function that returns true if the string is empty and false otherwise.