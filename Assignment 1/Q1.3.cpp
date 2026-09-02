/*
 * Q1_3.cpp 
 *
 *  Created on: 28-Aug-2026
 *      Author: Samruddhi
 */

#include <iostream>
#include <iomanip>
using namespace std;

double arr[3][3];

void acceptReadings(){

	cout << "Enter Temperature Readings: " << endl;


	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> arr[i][j];
		}
	}
}


void displayTable(){

	cout << "          " << "Room1   " << "Room2   " << "Room3" << endl;

	cout << fixed << setprecision(1);

	for(int i = 0; i < 3; i++){

		cout << "Floor " << i + 1 << " : ";

		for(int j = 0; j < 3; j++){

			cout << arr[i][j] << "    ";

		}

		cout << endl;
	}
	cout << endl;

}

void hottestRoom(){

	double hottest = arr[0][0];
	int floor;
	int room;
	int i, j;

	for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){

				if(arr[i][j] > hottest){
					hottest = arr[i][j];
				    floor = i + 1;
				    room = j + 1;
				}
			}

		}

	cout << "Hottest Room : ";
	cout << "Floor " << floor << ", ";
	cout << "Room " << room << " \u2192 ";
	cout << fixed << setprecision(1) << hottest << "\u00B0C" << endl;
}

void hottestFloor(){

	double temp;
	double floor1 = 0;
	double floor2 = 0;
	double floor3 = 0;

	int j;

			for(j = 0; j < 3; j++){
				floor1 = (floor1 + arr[0][j]);
				floor2 = (floor2 + arr[1][j]);
				floor3 = (floor3 + arr[2][j]);
			}

			floor1 = floor1/3;
			floor2 = floor2/3;
			floor3 = floor3/3;


	cout << "Hottest Floor : ";

	if(floor1 > floor2 && floor1 > floor3){
		        	cout << "Floor 1, ";
		        } else if(floor2 > floor1 && floor2 > floor3){
		        	cout << "Floor 2, ";
		        } else{
		        	cout << "Floor 3, ";
		        }


	if(floor1 > floor2 && floor1 > floor3){
		        	temp = floor1;
		        } else if(floor2 > floor1 && floor2 > floor3){
		            temp = floor2;
		        } else{
		        	temp = floor3;
		        }
	cout << fixed << setprecision(2) << "(avg " << temp << "\u00B0C" << ")" << endl;
}

void warningStatus(){
	int counts = 0;
	for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(arr[i][j] >= 30){
					counts++;
				}
			}
		}
	cout << "Rooms at WARNING or above : " << counts;
}

int main3(){

  acceptReadings();
  displayTable();
  hottestRoom();
  hottestFloor();
  warningStatus();



	return 0;
}
