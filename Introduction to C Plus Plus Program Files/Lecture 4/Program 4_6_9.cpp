// Program 4_6 - Stage 9: Final Version
// Blood Pressure Analyzer
// this code is already in the final version

#include <iostream>
using namespace std;

int main() {                                                    
	//Read in systolic and diastolic blood pressures                            
	int systolic, diastolic;
	cout << "Enter your systolic pressure (the larger, first number): ";
	cin >> systolic;
	cout << "Enter your diastolic pressure (the smaller, second number): ";
	cin >> diastolic;

	if ((systolic >= 120) && (systolic <= 129) && (diastolic < 80)) {
		//Check for Elevated blood pressure: 120<=S<=129 and D<80
		cout << "You have elevated blood pressure." << endl;
	}
	else if (((systolic >= 130) && (systolic <= 139)) 
			|| ((diastolic >= 80) && (diastolic <= 89))) {
		//Check for Stage 1 Hypertension: 130<=S<=139 or 80<=D<=89
		cout << "You have stage 1 hypertension." << endl;
	}
	else if (((systolic >= 140) && (systolic < 180))
			|| ((diastolic >= 90) && (diastolic < 120))) {
		//Check for Stage 2 Hypertension: 180>S>=140 or 120>D>=90
		cout << "You have stage 2 hypertension!" << endl;
	}
	else if ((systolic >= 180) || (diastolic >= 120)) {
		//Check for Danger Zone: S>=180 or D>=120
		cout << "Your blood pressure is in the danger zone!" << endl;
	}
	else if ((systolic <= 90) || (diastolic <= 60)) {
		//Check for Hypotension: S<=90 or D<=60
		cout << "You have hypotension." << endl;
	}
	else {
		//Say OK if nothing else applies
		cout << "Your blood pressure is in a healthy range." << endl;
	}            
}