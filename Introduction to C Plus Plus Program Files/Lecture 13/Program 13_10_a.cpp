// Program 13_10_a
// Error trying to pass a literal by reference
#include<iostream>
#include<string>
using namespace std;

string search_and_replace(string& main_string, string word_to_find, 
	string replacement) {                                                             
	//We can NOT manipulate main_string here!
}

int main() {
	string new_string = search_and_replace("Hi Robert, I hope you are doing great!", 
		"Robert", "Bob");           
}