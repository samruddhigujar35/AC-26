/*
 * Q1.1.cpp
 *
 *  Created on: aug 27, 2026
 *      Author: Samruddhi
 */
#include <iostream>
using namespace std;

int main()
{
    double temperature;
    int status;

    cout << "Enter temperature: ";
    cin >> temperature;

    // Decide the status
    if (temperature < 0)
    {
        status = -1;
    }
    else if (temperature < 30)
    {
        status = 0;
    }
    else if (temperature < 45)
    {
        status = 1;
    }
    else if (temperature < 60)
    {
        status = 2;
    }
    else
    {
        status = 3;
    }

    // Convert Celsius to Fahrenheit
    double fahrenheit = (temperature * 9 / 5) + 32;

    cout << "Temperature : " << temperature << " C / "
         << fahrenheit << " F" << endl;

    // Print status and action
    cout << "Status : ";

    switch (status)
    {
        case -1:
            cout << "SENSOR_ERROR" << endl;
            cout << "Action : Sensor fault - check wiring" << endl;
            break;

        case 0:
            cout << "NORMAL" << endl;
            cout << "Action : No action required" << endl;
            break;

        case 1:
            cout << "WARNING" << endl;
            cout << "Action : Alert sent to supervisor" << endl;
            break;

        case 2:
            cout << "CRITICAL" << endl;
            cout << "Action : Cooling system triggered" << endl;
            break;

        case 3:
            cout << "SHUTDOWN" << endl;
            cout << "Action : Emergency shutdown initiated" << endl;
            break;
    }

    // Ternary operator
    cout << "Reading : "
         << (temperature >= 25 ? "Above Average" : "Below Average")
         << endl;

    return 0;
}
