
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    static const int SIZE = 5;

    struct Transaction
    {
        string type;
        double amount;
    };

    Transaction transactions[SIZE];
    int start;
    int count;

public:
    SavingsAccount(int accNo, double initialBalance)
    {
        accountNumber = accNo;
        balance = initialBalance;
        start = 0;
        count = 0;
    }

    void addTransaction(string type, double amount)
    {
        int position;

        if (count < SIZE)
        {
            position = (start + count) % SIZE;
            count++;
        }
        else
        {
            position = start;
            start = (start + 1) % SIZE;
        }

        transactions[position] = {type, amount};
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            return;

        balance += amount;
        addTransaction("Deposit", amount);
    }

    void withdraw(double amount)
    {
        if (amount <= 0 || amount > balance)
            return;

        balance -= amount;
        addTransaction("Withdrawal", amount);
    }

    void miniStatement()
    {
        cout << fixed << setprecision(2);

        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
        cout << "Recent Transactions:\n";

        for (int i = 0; i < count; i++)
        {
            int position = (start + i) % SIZE;

            cout << transactions[position].type
                 << ": Rs. " << transactions[position].amount << endl;
        }
    }
};

int main()
{
    SavingsAccount account(1001, 10000);

    account.deposit(500);
    account.withdraw(200);
    account.deposit(1000);
    account.withdraw(300);
    account.deposit(700);
    account.withdraw(400);

    cout << "Redesigned Circular Buffer Implementation\n";
    account.miniStatement();

    return 0;
}
