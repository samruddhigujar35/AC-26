#include <iostream>
using namespace std;

// Function 1
double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

// Function 2
double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}

// Function 3
double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;
    double tax = cost * taxRate / 100;

    return cost + tax;
}

// Default argument
double applyDiscount(double price, double discountPercent = 10.0)
{
    double discount = price * discountPercent / 100;

    return price - discount;
}

int main()
{
    // Calling first function
    cout << "Cost 1: "
         << reorderCost(10, 50.0) << endl;

    // Calling second function
    cout << "Cost 2: "
         << reorderCost(5.5, 100.0) << endl;

    // Calling third function
    cout << "Cost 3: "
         << reorderCost(10, 50.0, 18.0) << endl;

    // Calling with default discount = 10%
    cout << "Discounted Price: "
         << applyDiscount(1000) << endl;

    // Calling with our own discount
    cout << "Discounted Price: "
         << applyDiscount(1000, 20) << endl;

    return 0;
}
