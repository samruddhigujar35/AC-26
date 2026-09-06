#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:

    // Default constructor
    Patient()
        : patientId(0), name("Unknown"), age(0),
          ward("General"), bloodGroup("O+")
    {
        cout << "[Constructor] Default patient registered." << endl;
    }

    // Emergency constructor
    Patient(int id, const string& name)
        : patientId(id), name(name), age(0),
          ward("Emergency"), bloodGroup("O+")
    {
        cout << "[Constructor] Emergency: " << name << endl;
    }

    // Full constructor
    Patient(int id, const string& name, int age,
            const string& ward, const string& bg)
        : patientId(id), name(name), age(age),
          ward(ward), bloodGroup(bg)
    {
        cout << "[Constructor] Full admission: "
             << name << endl;
    }

    // Destructor
    ~Patient()
    {
        cout << "[Destructor] Patient "
             << name << " discharged." << endl;
    }

    // Display patient
    void displayRecord() const
    {
        cout << "\nPatient Record:" << endl;
        cout << "ID : " << patientId << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Ward : " << ward << endl;
        cout << "Blood Grp : " << bloodGroup << endl;
    }

    // Transfer ward
    void transferWard(const string& newWard)
    {
        ward = newWard;
        cout << "Ward Transfer: "
             << name << " -> " << ward << endl;
    }
};

int main()
{
    // Three different types of patients

    Patient p1;
    Patient p2(1001, "Raj");
    Patient p3(1002, "Meera", 34, "Cardiology", "B+");

    p1.displayRecord();
    p2.displayRecord();
    p3.displayRecord();

    return 0;
}
