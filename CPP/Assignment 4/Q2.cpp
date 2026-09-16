#include <iostream>
#include <vector>
using namespace std;

class Vehicle
{
protected:
    string reg;
    string owner;
    int year;
    double km;

public:

    Vehicle(string r, string o, int y, double k)
    {
        reg = r;
        owner = o;
        year = y;
        km = k;
    }

    virtual double fuelCost(double distance) = 0;

    virtual string vehicleType() = 0;

    virtual void display()
    {
        cout << reg << "  "
             << owner << "  "
             << year << "  "
             << km << " km" << endl;
    }

    virtual ~Vehicle()
    {
        cout << "Vehicle destroyed" << endl;
    }
};


class Car : public Vehicle
{
    string fuel;
    double mileage;

public:

    Car(string r, string o, int y, double k,
        string f, double m)
        : Vehicle(r, o, y, k)
    {
        fuel = f;
        mileage = m;
    }

    double fuelCost(double distance)
    {
        double price;

        if(fuel == "Petrol")
            price = 106;
        else
            price = 93;

        return distance / mileage * price;
    }

    string vehicleType()
    {
        return "Car";
    }
};


class Truck : public Vehicle
{
protected:
    double payload;
    double mileage;

public:

    Truck(string r, string o, int y, double k,
          double p, double m)
        : Vehicle(r, o, y, k)
    {
        payload = p;
        mileage = m;
    }

    double fuelCost(double distance)
    {
        double actualMileage = mileage - (mileage * 0.05 * payload);

        return distance / actualMileage * 93;
    }

    string vehicleType()
    {
        return "Truck";
    }
};


class ElectricTruck : public Truck
{
    double battery;
    double range;

public:

    ElectricTruck(string r, string o, int y, double k,
                  double p, double m,
                  double b, double rg)
        : Truck(r, o, y, k, p, m)
    {
        battery = b;
        range = rg;
    }

    double fuelCost(double distance)
    {
        return (distance / range) * battery * 9.50;
    }

    string vehicleType()
    {
        return "Electric Truck";
    }
};


class Van : public Vehicle
{
    int seats;
    double mileage;

public:

    Van(string r, string o, int y, double k,
        int s, double m)
        : Vehicle(r, o, y, k)
    {
        seats = s;
        mileage = m;
    }

    double fuelCost(double distance)
    {
        return distance / mileage * 106;
    }

    string vehicleType()
    {
        return "Van";
    }
};


void printFleetReport(vector<Vehicle*>& fleet, double distance)
{
    for(int i = 0; i < fleet.size(); i++)
    {
        fleet[i]->display();

        cout << "Type: "
             << fleet[i]->vehicleType() << endl;

        cout << "Cost: Rs. "
             << fleet[i]->fuelCost(distance)
             << endl;

        cout << "----------------" << endl;
    }
}


int main()
{
    Car c1("MH01AA001", "Ramesh", 2022, 45000,
           "Petrol", 15);

    Truck t1("MH02BB002", "Shyam", 2021, 60000,
             2, 8);

    ElectricTruck e1("MH03CC003", "Green Fleet",
                     2024, 20000,
                     1, 7, 85, 300);

    Van v1("MH04DD004", "Amit", 2023, 30000,
           7, 12);

    vector<Vehicle*> fleet;

    fleet.push_back(&c1);
    fleet.push_back(&t1);
    fleet.push_back(&e1);
    fleet.push_back(&v1);

    printFleetReport(fleet, 200);

    return 0;
}
