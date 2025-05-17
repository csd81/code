// Program 4_6 - Stage 2: Filling in first section of code                         
// Blood Pressure Analyzer                                                 
#include <iostream>
using namespace std;

int main() {                                                    
	//Read in systolic and diastolic blood pressures                            
	int sys, dia;                                                         

	cout << "Enter your systolic pressure (the larger, first number): ";           
	cin >> sys;
	cout << "Enter your diastolic pressure (the smaller, second number): ";
	cin >> dia;


		//Check for Elevated blood pressure: 120<=S<=129 and D<80
              if (sys >= 120 && sys <= 129 && dia < 80) {
		cout << "Elevated blood pressure" << endl; // output the resul
	}
		//Check for Stage 1 Hypertension: 130<=S<=139 or 80<=D<=89
     else if (sys >= 130 && sys <= 139 || dia >= 80 && dia <= 89) {
		cout << "Stage 1 Hypertension" << endl; // output the result
	}                                                        
		//Check for Stage 2 Hypertension: 180>S>=140 or 120>D>=90                   
	 else if (sys >= 140 && sys < 180 || dia >= 90 && dia < 120) {
		cout << "Stage 2 Hypertension" << endl;
	}
		//Check for Danger Zone: S>=180 or D>=120
	else if (sys >= 180 || dia >= 120) {
		cout << "Danger Zone" << endl; }
		//Check for Hypotension: S<=90 or D<=60
	else if (sys <= 90 || dia <= 60) {
		cout << "Hypotension" << endl; }
		//Say OK if nothing else applies          
		else {
		cout << "OK" << endl; }
}