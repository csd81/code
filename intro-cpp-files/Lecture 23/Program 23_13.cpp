// Program 23_13
// Sorting Pairs
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>                     
using namespace std;

int main() {
	vector<pair<double, string> > salaries;
	cout << "Enter a person's name and salary, one name and then one salary per line." 
		<< endl;
	cout << "Enter a negative salary to stop." << endl;
	string personname;
	double sal;
	cin >> personname >> sal;
	while (sal >= 0.0) {
		salaries.push_back(make_pair(sal, personname));
		cin >> personname >> sal;
	}
	sort(salaries.begin(), salaries.end());
	for (auto& iter : salaries) {
		cout << iter.first << " " << iter.second << endl;
	}                
}

// this program demonstrates how to sort a vector of pairs in C++.
// The program creates a vector of pairs, where each pair contains a double (salary) and a string (person's name).
// It prompts the user to enter a person's name and salary, one name and then one salary per line.
// The user can enter multiple names and salaries, and the program will store them in the vector.
// The program stops accepting input when the user enters a negative salary.
// After the input is complete, the program sorts the vector of pairs in ascending order based on the salary.
// Finally, it prints out the sorted list of salaries and names.
// The program uses the standard library's sort function, which is a part of the <algorithm> header.
// The sort function takes two iterators as arguments, representing the beginning and end of the range to be sorted.
// The program uses a range-based for loop to iterate through the vector and print its elements.
// The program uses the make_pair function to create pairs of salary and name.
// The program uses the vector class from the <vector> header to create a dynamic array of pairs.
