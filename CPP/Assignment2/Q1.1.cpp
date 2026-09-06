#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:

    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const
    {
        cout << productId << "\t"
             << name << "\t"
             << price << "\t"
             << quantity << "\t"
             << totalValue() << endl;
    }

    double totalValue() const
    {
        return price * quantity;
    }

    bool isLowStock(int threshold) const
    {
        return quantity < threshold;
    }
};

int main()
{
    Product products[5];

    // Accept details
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details of Product " << i + 1 << endl;
        products[i].acceptDetails();
    }

    // Display products
    cout << "\n===== INVENTORY REPORT =====" << endl;
    cout << "ID\tName\tPrice\tQty\tTotal Value" << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }

    // Find highest value product
    int highest = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() > products[highest].totalValue())
        {
            highest = i;
        }
    }

    cout << "\nHighest Value Product:" << endl;
    products[highest].displayDetails();

    // Low stock
    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "\nLow Stock Products:" << endl;

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            products[i].displayDetails();
        }
    }

    return 0;
}
