
#include <iostream>
using namespace std;

int& highestMark(int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
        {
            highest = i;
        }
    }

    return marks[highest];
}

int getHighestIndex(int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
        {
            highest = i;
        }
    }

    return highest;
}

int& unsafeFunction()
{
    int value = 100;
    return value;
}

int main()
{
    int marks[5] = {85, 92, 78, 96, 88};

    cout << "Original Marks: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    highestMark(marks, 5) += 2;

    cout << "Marks After Adding 2 to Highest Mark: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    int index = getHighestIndex(marks, 5);

    cout << "Highest Mark: " << marks[index] << endl;
    cout << "Highest Mark Index: " << index << endl;

    return 0;
}
