// Program 4_6 - Stage 5: Filling in next section of code                  
// Blood Pressure Analyzer                                                 
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
                                                                                      
		//Check for Stage 1 Hypertension: 130<=S<=139 or 80<=D<=89
                                                             
		//Check for Stage 2 Hypertension: 180>S>=140 or 120>D>=90                   

		//Check for Danger Zone: S>=180 or D>=120

		//Check for Hypotension: S<=90 or D<=60

		//Say OK if nothing else applies            
		else if ((systolic >= 130) && (systolic <= 139) || (diastolic >= 80) && (diastolic <= 89)) {
		cout << "You have Stage 1 Hypertension." << endl;
	} else if ((systolic >= 140) && (systolic < 180) || (diastolic >= 90) && (diastolic < 120)) {	
		//Check for Stage 2 Hypertension: 180>S>=140 or 120>D>=90                   
		cout << "You have Stage 2 Hypertension." << endl;
	} else if ((systolic >= 180) || (diastolic >= 120)) {
		//Check for Danger Zone: S>=180 or D>=120
		cout << "You are in the Danger Zone." << endl;
	} else if ((systolic <= 90) || (diastolic <= 60)) {
		//Check for Hypotension: S<=90 or D<=60
		cout << "You have Hypotension." << endl;
	} else {
		cout << "Your blood pressure is OK." << endl;
	}
}