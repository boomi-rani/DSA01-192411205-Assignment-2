
#include <iostream>
using namespace std;

void applyByValue(int fee, int percentage)
{
    fee = fee - (fee * percentage / 100);
    cout << "Fee inside call by value: " << fee << endl;
}

void applyByReference(int& fee, int percentage)
{
    fee = fee - (fee * percentage / 100);
}

void applyByPointer(int* fee, int percentage)
{
    *fee = *fee - (*fee * percentage / 100);
}

void change(int a, int& b, int* c)
{
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q)
{
    return (p > q) ? p : q;
}

void show(int x, int y = 5, int z = 10)
{
    cout << x + y + z << " ";
}

int main()
{
    int fee = 45000;

    cout << "Original Hostel Fee: " << fee << endl;

    applyByValue(fee, 10);
    cout << "After Call by Value: " << fee << endl;

    applyByReference(fee, 10);
    cout << "After Call by Reference: " << fee << endl;

    applyByPointer(&fee, 10);
    cout << "After Call by Pointer: " << fee << endl;

    cout << "\nFunction Demonstration:\n";

    int a = 1, b = 2, c = 3;

    change(a, b, &c);
    cout << a << " " << b << " " << c << endl;

    bigger(a, c) = 100;
    cout << a << " " << c << endl;

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << endl;

    return 0;
}
