
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    string transactions[10];
    int count;

public:
    SavingsAccount(int accNo, double initialBalance)
    {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement();
};

void SavingsAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount!" << endl;
        return;
    }

    balance += amount;

    if (count < 10)
    {
        transactions[count] = "Deposited Rs. " + to_string(amount);
        count++;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            transactions[i] = transactions[i + 1];
        }

        transactions[9] = "Deposited Rs. " + to_string(amount);
    }
}

void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount!" << endl;
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance!" << endl;
        return;
    }

    balance -= amount;

    if (count < 10)
    {
        transactions[count] = "Withdrawn Rs. " + to_string(amount);
        count++;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            transactions[i] = transactions[i + 1];
        }

        transactions[9] = "Withdrawn Rs. " + to_string(amount);
    }
}

void SavingsAccount::miniStatement()
{
    cout << "\nAccount Number: " << accountNumber << endl;
    cout << "Current Balance: Rs. " << balance << endl;

    cout << "\nRecent Transactions:\n";

    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << transactions[i] << endl;
    }
}

int main()
{
    SavingsAccount account(1001, 5000);

    account.deposit(2000);
    account.withdraw(1000);
    account.deposit(1500);
    account.withdraw(500);

    account.miniStatement();

    return 0;
}
