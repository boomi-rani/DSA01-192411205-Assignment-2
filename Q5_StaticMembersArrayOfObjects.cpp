
#include <iostream>
#include <string>
using namespace std;

class BusTicket
{
private:
    static int issued;
    static const int capacity = 3;
    int seatNumber;
    string passengerName;

public:
    BusTicket(string name)
    {
        passengerName = name;

        if (issued < capacity)
        {
            issued++;
            seatNumber = issued;
        }
        else
        {
            seatNumber = 0;
        }
    }

    void display()
    {
        if (seatNumber == 0)
        {
            cout << passengerName << ": Waiting" << endl;
        }
        else
        {
            cout << passengerName << ": Seat " << seatNumber << endl;
        }
    }

    static int count()
    {
        return issued;
    }
};

int BusTicket::issued = 0;

int main()
{
    BusTicket tickets[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    cout << "Bus Ticket Booking Details\n";

    for (int i = 0; i < 4; i++)
    {
        tickets[i].display();
    }

    cout << "Issued: " << BusTicket::count() << endl;

    return 0;
}
