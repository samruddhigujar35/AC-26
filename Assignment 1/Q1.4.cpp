/*
 * Q1_4.cpp 
 *
 *  Created on: 28-Aug-2026
 *      Author: Samruddhi
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function to classify temperature
int classifyTemperature(int temperature, int warn, int critical){
	if (temperature < warn) {
		return 0; //normal
	}
	else if (temperature < critical) {
		return 1; //warn
	}
	else if (temperature > critical) {
		return 2; //critical
	}
	else {
		return 3; //shutdown
	}
}


int main4(int argc, char* argv[]){

//	Check if required arguments are provided
	if(argc != 4){
		cout << "Usage : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
		cout << "Error : Missing arguments." << endl;

		return 1;
	}


//Convert command line arguments from string to integer.
	int warn = atoi(argv[1]);
	int  critical =  atoi(argv[2]);
	int num_readings = atoi(argv[3]);

	//Validate number of readings
	if(warn >= critical) {
		cout << "Error : threshold must be less than Critical threshold." << endl;

		return 1;
	}

	if(num_readings < 1 && num_readings > 500){
		cout << "Error : Number of readings must be between 1 to 500" << endl;
	}

//	Seed random number generator
	srand(time(0));

	int normal = 0;
	int warning = 0;
	int criticalCount = 0;
	int shutdown = 0;

	cout << "Config : Warn=" << warn << "\u00B0C" << " Critical=" << critical << "\u00B0C" << " Readings=" << num_readings << endl;

//	Generate and classify readings
	for(int i = 0; i < num_readings; i++){

		int temperature = rand() % 70;

		int result = classifyTemperature(temperature, warn, critical);

		if (result == 0) {
			normal++;
		}
		else if (result == 1) {
			warning++;
		}
		else if (result == 2) {
			criticalCount++;
		}
		else {
			shutdown++;
		}
	}

	// Display Summary
	cout << "Results : " << "Normal:" << normal << " ";
	cout << "Warning:" << warning;
	cout << " Critical:" << criticalCount;
	cout << " Shutdown:" << shutdown;

	return 0;
}
