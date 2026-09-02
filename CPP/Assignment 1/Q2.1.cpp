/*
 * Q2_1.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: Samruddhi
 */

#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2){ // Original bug — Call by Value
  int temp = reading1;
   reading1 = reading2;
   reading2 = temp;
}

void resetSensorPairV2(int &reading1, int &reading2){ // Fix 1 — Call by Reference
	int temp = reading1;
	   reading1 = reading2;
	   reading2 = temp;
	}

void resetSensorPairV3(int* reading1, int* reading2){ // Fix 2 — Call by Pointer
int temp = *reading1;
  *reading1 = *reading2;
  *reading2 = temp;
}


int main(){

	int a = 55;
	int b = 12;

    cout << "--- V1: Call by Value ---" << endl;
	cout << "Before : A=" << a <<" B=" << b <<endl;
	resetSensorPairV1(a, b);
	cout << "After  : A=" << a <<" B=" << b << endl;
    cout << endl;

// V1 uses call by value, so copies of a and b are passed.
// The function swaps only the copied values.
// The original variables a and b are not changed.
// Therefore, the swapped values are lost when the function ends.

    cout << "--- V2: Call by Value ---" << endl;
	cout << "Before : A=" << a <<" B=" << b <<endl;
	resetSensorPairV2(a, b);
    cout << "After  : A=" << a <<" B=" << b << endl;
    cout << endl;


//  V2 calls by reference, so no copies are passed here.
//  reading1 and reading2 refers to the same variable as a and b,
//  which are then swapped in the function.
//  Hence it changes the value of
//  original variable a and b too (permanently).


    cout << "--- V3: Call by Value ---" << endl;
	cout << "Before : A=" << a <<" B=" << b <<endl;
	resetSensorPairV3(&a, &b);
	cout << "After  : A=" << a <<" B=" << b << endl;
	cout << endl;

//  As value of a and b were permanently changed after
//	calling function v2, the value of a and b in
//	function v3 is passed as 12 and 55.

  return 0;
}
