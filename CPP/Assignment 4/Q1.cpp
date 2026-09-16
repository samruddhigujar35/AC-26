#include <iostream>
#include <string>
#include <cstring>
#include <utility>
using namespace std;

class LedgerEntry
{
    string description;
    double* amounts;
    int days;

public:

    static int totalEntries;

    // Constructor
    LedgerEntry(string desc, int d)
    {
        description = desc;
        days = d;
        amounts = new double[days];

        for(int i = 0; i < days; i++)
            amounts[i] = 0;

        totalEntries++;

        cout << "[Created] " << description << endl;
    }

    // Copy Constructor
    LedgerEntry(const LedgerEntry& other)
    {
        description = other.description;
        days = other.days;

        amounts = new double[days];

        for(int i = 0; i < days; i++)
            amounts[i] = other.amounts[i];

        totalEntries++;

        cout << "[Copied]" << endl;
    }

    // Move Constructor
    LedgerEntry(LedgerEntry&& other)
    {
        description = other.description;
        days = other.days;
        amounts = other.amounts;

        other.amounts = nullptr;
        other.days = 0;

        totalEntries++;

        cout << "[Moved]" << endl;
    }

    // Copy Assignment
    LedgerEntry& operator=(const LedgerEntry& other)
    {
        if(this != &other)
        {
            delete[] amounts;

            description = other.description;
            days = other.days;

            amounts = new double[days];

            for(int i = 0; i < days; i++)
                amounts[i] = other.amounts[i];
        }

        return *this;
    }

    // Move Assignment
    LedgerEntry& operator=(LedgerEntry&& other)
    {
        if(this != &other)
        {
            delete[] amounts;

            description = other.description;
            days = other.days;
            amounts = other.amounts;

            other.amounts = nullptr;
            other.days = 0;
        }

        return *this;
    }

    // Destructor
    ~LedgerEntry()
    {
        delete[] amounts;
        totalEntries--;
    }

    // [] operator
    double& operator[](int index)
    {
        if(index < 0 || index >= days)
            throw out_of_range("Invalid index");

        return amounts[index];
    }

    // + operator
    LedgerEntry operator+(const LedgerEntry& other)
    {
        LedgerEntry result("Combined", days);

        for(int i = 0; i < days; i++)
            result.amounts[i] = amounts[i] + other.amounts[i];

        return result;
    }

    // == operator
    bool operator==(const LedgerEntry& other)
    {
        for(int i = 0; i < days; i++)
        {
            if(amounts[i] != other.amounts[i])
                return false;
        }

        return true;
    }

    // > operator
    bool operator>(const LedgerEntry& other)
    {
        double sum1 = 0;
        double sum2 = 0;

        for(int i = 0; i < days; i++)
        {
            sum1 += amounts[i];
            sum2 += other.amounts[i];
        }

        return sum1 > sum2;
    }

    // << operator
    friend ostream& operator<<(ostream& out, const LedgerEntry& e)
    {
        out << e.description << " : [";

        double total = 0;

        for(int i = 0; i < e.days; i++)
        {
            out << e.amounts[i];

            total += e.amounts[i];

            if(i < e.days - 1)
                out << ", ";
        }

        out << "] Total: " << total;

        return out;
    }
};

int LedgerEntry::totalEntries = 0;


int main()
{
    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200;
    jan[1] = 3400;
    jan[2] = 800;
    jan[3] = 2100;
    jan[4] = 650;

    LedgerEntry feb("February Sales", 5);

    feb[0] = 900;
    feb[1] = 2200;
    feb[2] = 1750;
    feb[3] = 3000;
    feb[4] = 475;

    cout << jan << endl;
    cout << feb << endl;

    LedgerEntry combined = jan + feb;

    cout << "Combined: " << combined << endl;

    cout << "Jan == Feb: "
         << (jan == feb ? "Yes" : "No") << endl;

    cout << "Jan > Feb: "
         << (jan > feb ? "Yes" : "No") << endl;

    LedgerEntry moved = move(jan);

    cout << "Moved: " << moved << endl;

    LedgerEntry q1("Q1", 5);

    q1 = move(feb);

    cout << "Q1: " << q1 << endl;

    cout << "Live objects: "
         << LedgerEntry::totalEntries << endl;

    return 0;
}
