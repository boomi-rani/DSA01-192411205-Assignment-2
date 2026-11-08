
#include <iostream>
#include <iomanip>
using namespace std;

struct Parcel
{
    double weight;
    bool express;
    bool insured;
};

double charge(int weight, bool express = false, bool insured = false)
{
    double amount = weight * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    return amount;
}

double charge(double weight, bool express = false, bool insured = false)
{
    double amount = weight * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    return amount;
}

double charge(const Parcel& p)
{
    return charge(p.weight, p.express, p.insured);
}

int main()
{
    Parcel p = {4.5, true, true};

    cout << fixed << setprecision(2);

    cout << "Courier Charge Details\n";

    cout << "1. Integer weight (2 kg): Rs. "
         << charge(2) << endl;

    cout << "2. Float weight (2 kg): Rs. "
         << charge(2.0f) << endl;

    cout << "3. Double weight (2.5 kg): Rs. "
         << charge(2.5) << endl;

    cout << "4. Express delivery: Rs. "
         << charge(3, true) << endl;

    cout << "5. Express and insured: Rs. "
         << charge(3, true, true) << endl;

    cout << "6. Parcel object: Rs. "
         << charge(p) << endl;

    return 0;
}
