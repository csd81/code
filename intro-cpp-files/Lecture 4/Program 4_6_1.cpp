// Program 4_6 - Stage 1: Pseudocode converted to comments                                         
// Blood Pressure Analyzer                                                 
#include <iostream>
using namespace std;

int main() {                                                    
	//Read in systolic and diastolic blood pressures                            
	int S, D;
	cout << "Enter systolic and diastolic blood pressures: ";
	cin >> S >> D; // input the systolic and diastolic blood pressures

		//Check for Elevated blood pressure: 120<=S<=129 and D<80
    if (S >= 120 && S <= 129 && D < 80) {
		cout << "Elevated blood pressure" << endl; // output the result
	                                                                                  
		//Check for Stage 1 Hypertension: 130<=S<=139 or 80<=D<=89
    } else if (S >= 130 && S <= 139 || D >= 80 && D <= 89) {
		cout << "Stage 1 Hypertension" << endl; // output the result
	
			//Check for Stage 2 Hypertension: 180>S>=140 or 120>D>=90                   
		} else if (S >= 140 && S < 180 || D >= 90 && D < 120) {
		cout << "Stage 2 Hypertension" << endl; // output the result
	                                                                                  
			//Check for Hypertensive Crisis: S>=180 or D>=120
		} else if (S >= 180 || D >= 120) {	
		//Check for Danger Zone: S>=180 or D>=120
		cout << "Hypertensive Crisis" << endl; // output the result
	                                                                                  
			//Check for Normal: S<120 and D<80
		} else if (S < 120 && D < 80) {
		cout << "Normal" << endl; // output the result
	                                                                                  
			//Check for Prehypertension: 120<=S<=139 or 80<=D<=89
		} else if (S >= 120 && S <= 139 || D >= 80 && D <= 89) {
		cout << "Prehypertension" << endl; // output the result
	                                                                                  
			//Check for Stage 3 Hypertension: S>=140 or D>=90
		} else if (S >= 140 || D >= 90) {
		cout << "Stage 3 Hypertension" << endl; // output the result
	                                                                                  
			//Check for Stage 4 Hypertension: S>=180 or D>=120
		} else if (S >= 180 || D >= 120) {
		cout << "Stage 4 Hypertension" << endl; // output the result
	                                                                                  
			//Check for Stage 5 Hypertension: S>=200 or D>=130
		} else if (S >= 200 || D >= 130) {	
		//Check for Hypotension: S<=90 or D<=60
		cout << "Hypotension" << endl; // output the result
	                                                                                  
			//Check for Stage 6 Hypertension: S>=220 or D>=140
		} else if (S >= 220 || D >= 140) {}	
		//Say OK if nothing else applies            
}