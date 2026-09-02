/*
 * Q2_2.cpp
 *
 *  Created on: 30-Aug-2026
 *      Author: Samruddhi
 */

#include <iostream>
#include <cmath>
using namespace std;

// Returns sqrt( sum of (each element squared) / n )
  double computeRMS(double* signal, int n){

	  double sum  = 0;

	  for(int i = 0; i < n; i++){
		  sum = sum + (*(signal + i) * *(signal + i));
	  }

	  return sqrt(sum / n);
  }


 // Divides every element by the max absolute value in the array (in-place)
  void normalise(double* signal, int n){

	  double mav = 0;

	  for(int i = 0; i < n; i++){

		  if(abs(*(signal + i)) > mav)
			  mav = abs(*(signal + i));
	  }

	  for(int i = 0; i < n; i++){
		  *(signal + i) = *(signal + i) / mav;
	  }
  }


  // Returns count of positions where adjacent elements have opposite signs
  int countZeroCrossings(double* signal, int n){

	  int count = 0;

	  for(int i = 0; i < n - 1; i++){
	  	if((*(signal + i) < 0 && *(signal + i + 1) > 0) ||
	  	   (*(signal + i) > 0 && *(signal + i + 1) < 0)) {
	  		   count++;
	  	}
	  }

	  return count;
  }



  // Multiplies every element by gainFactor (in-place)
  void applyGain(double* signal, int n, double gainFactor){

	  for(int i = 0; i < n; i++){
		  *(signal + i) = *(signal + i) * gainFactor;
	  }
  }



int main(){
	int n;
	cout << "Enter number of signals: " << endl;
	cin >> n;

	double signal[n];
	cout << "Enter " << n << " signal value: ";

	for(int i = 0; i < n; i++){
		cin >> signal[i];
	}

	double gf;
	cout << "Enter gain factor: " << endl;
	cin >> gf;

	cout << "Test signal: {";
	for(int i = 0; i < n; i++){
		cout << signal[i];
		if (i < n - 1)
		   cout << ", ";
	}
	cout << "}" << endl;


	cout << "Normalised signal: {";
	normalise(signal, n);
	for(int i = 0; i < n; i++){
		cout << signal[i];
		if (i < n - 1)
		   cout << ", ";
	}
	cout << "}" << endl;


	cout << "Signal after applying gain: {";
	applyGain(signal, n, gf);
	for(int i = 0; i < n; i++){
			cout << signal[i];
			if (i < n - 1)
			   cout << ", ";
		}
		cout << "}" << endl;



	double rms = computeRMS(signal, n);
	cout << "RMS of Signals: " << rms << endl;


	int crossings = countZeroCrossings(signal, n);
	cout << "Count of adjacent elements having opposite signs: ";
	cout << crossings;

	return 0;
}
