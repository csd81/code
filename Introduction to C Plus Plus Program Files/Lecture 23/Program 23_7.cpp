// Program 23_7
// Map example - dictionary
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string, string> dictionary;
	dictionary["rock"] = "An object that breaks scissors";
	dictionary["paper"] = "An object that covers rocks";
	dictionary["scissors"] = "An object that cuts paper";

	for (auto& iter : dictionary) {
		cout << iter.first << ": " << iter.second << endl;
	}       
}