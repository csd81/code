// Program 3_8
// Comparisons: equality/inequality
#include <iostream>
using namespace std;

int main() {
	int numFish = 1; 
	int numCats = 2; 
	int numDogs = 2;
	std::cout << (numFish == numCats) << std::endl; // False
	std::cout << (numFish != numCats) << std::endl; // True
	std::cout << (numCats == numDogs) << std::endl;	 // True
	std::cout << (numCats != numDogs) << std::endl;         // False                    
}