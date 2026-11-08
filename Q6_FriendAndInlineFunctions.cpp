
#include <iostream>
#include <cstdlib>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;

public:
    Time(int h, int m)
    {
        hours = h;
        minutes = m;
    }

    friend int minutesBetween(const Time& t1, const Time& t2);
    friend bool earlier(const Time& t1, const Time& t2);
};

inline int convertToMinutes(const Time& t)
{
    return t.hours * 60 + t.minutes;
}

int minutesBetween(const Time& t1, const Time& t2)
{
    return abs(convertToMinutes(t1) - convertToMinutes(t2));
}

bool earlier(const Time& t1, const Time& t2)
{
    return convertToMinutes(t1) < convertToMinutes(t2);
}

int main()
{
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "Time Difference: "
         << minutesBetween(departure, arrival)
         << " minutes" << endl;

    cout << boolalpha;

    cout << "Is Arrival Earlier Than Departure? "
         << earlier(arrival, departure) << endl;

    Time morning(10, 30);
    Time afternoon(14, 30);

    cout << "Morning Earlier Than Afternoon? "
         << earlier(morning, afternoon) << endl;

    Time sameTime1(12, 0);
    Time sameTime2(12, 0);

    cout << "Difference Between Same Times: "
         << minutesBetween(sameTime1, sameTime2)
         << " minutes" << endl;

    return 0;
}
