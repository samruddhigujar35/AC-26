/*
 * Q1_2.cpp
 *
 *  Created on: 27-Aug-2026
 *      Author: Samruddhi
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int errorCount = 0;
	int N;
	cout << "Enter No. of Readings:" << endl;
	cin >> N;

	while (N < 1 || N > 100) {
	        cout << "Invalid input! Enter Readings between 1 to 100: ";
	        cin >> N;
	    }

	cout << "Readings Entered: " << N <<endl;

	double reading[N];
	cout << "Valid readings: ";

	for(int i = 0; i < N; i++){
		cin >> reading[i];
	}

	cout << "Valid readings: ";

	for(int i = 0; i < N; i++){

		if(reading[i] < 0){
			errorCount++;
			continue;
		}

		cout << reading[i] << " ";
	}
	cout << endl;

	cout << "Skipped (errors): " << errorCount << endl;

	cout << "First CRITICAL: ";

	for(int i = 0; i < N; i++){
		if(reading[i] >= 45){
			cout << "Index " << i << " -> " << reading[i] << "'C  " << endl;
		}
	}

	double min = reading[0];
	double max = reading[0];
	double sum = 0;
	double avg;
	int count = 0;


	for(int i = 0; i < N; i++){
		if(reading[i] < min){
			min = reading[i];
		}

		if(reading[i] > max){
			max = reading[i];
		}

		sum = sum + reading[i];

		count++;
	}

	cout << "Min: " << min << "'C";
	cout << "   Max: " << max << "'C";
	cout << "   Count: " << count;

	avg = sum / count;
	cout << "   Avg: " << avg << "'C" << endl;

	int normal = 0;
	int warning = 0;
	int critical = 0;
	int shutdown = 0;

	for(int i = 0; i < N; i++){
		if(reading[i] >= 0 && reading[i] < 30){
			normal++;
		}
		else if(reading[i] >= 30 && reading[i] < 45){
			warning++;
		}
		else if(reading[i] >= 45 && reading[i] < 60){
			critical++;
		}
		else if(reading[i] >= 60){
			shutdown++;
		}
	}

	cout << "Normal: " << normal  <<"   Warning: " << warning  << "   Critical: " << critical  << "   Shutdown: "<< shutdown;

	return 0;
}

