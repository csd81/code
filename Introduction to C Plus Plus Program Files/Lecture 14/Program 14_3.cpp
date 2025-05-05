// Program 14_3
// Example program creating error due to user input
#include <iostream>
#include <string>
using namespace std;

int main() {
	int num_boxes;
	cout << "How many boxes do you have? ";
	cin >> num_boxes;
	if (num_boxes == 0) {
		cout << "You must have at least one box!" << endl;
	} else if (num_boxes < 0) {
		cout << "You can't have a negative number of boxes!" << endl;
		return 1; // Exit the program with an error code
	} else if (num_boxes > 100) {
		cout << "That's a lot of boxes! Are you sure you want to ship that many?" << endl;
	
	// Ask for confirmation
		string confirmation;
		cout << "Type 'yes' to confirm: ";
		cin >> confirmation;
		if (confirmation != "yes") {
			cout << "Shipping cancelled." << endl;
			return 0; // Exit the program without shipping
		}
	} else {
		cout << "Shipping will proceed." << endl;
	
	double cost = 12.50 * num_boxes;
	cout << "It will cost you $" << cost << " to ship them." << endl;            
	cout << "Thank you for using our shipping service!" << endl;
}
	return 0; // Exit the program successfully
}