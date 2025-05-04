// Program Fragment 11_1_e
// Program to Predict Electricity Usage
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main() {
	/***** Read Past Data *****/
	/*** Read Past Electricity Data ***/
	/* Open File */
	fstream electricfile;
	electricfile.open("MeterReadings.dat", fstream::in);
	/* Loop Through All Lines */      
	string date;
	int meter;
	electricfile >> date >> meter; 
	while (!electricfile.eof()) {
		/* Store Date and Meter Reading in Parallel Vectors */  
		
		electricfile >> date >> meter; 
	}
	electricfile.close();
	/*** Read Past Weather Data ***/

	/*** Read Past Individual Schedule ***/


	/***** Get Detail To Predict *****/


	/***** Calculate Predicted Usage *****/


	/***** Present Prediction *****/

}