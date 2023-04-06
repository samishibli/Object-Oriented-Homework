
#include <iostream>
using namespace std;

class BankAccount
{
public:
    BankAccount(string name) : name(name), bal(0) {} // constructor

    BankAccount(string name, double amt) : name(name), bal(amt) {} // 2-argument constructor

    void deposit()
    {
        double amt;
        cout << "Amount to deposit: " << endl;
        cin >> amt;
        while (amt < 0)
        {
            cout << "Amount cannot be negative: " << endl;
            cin >> amt;
        }
        bal += amt;
    } // simple mutator

    void deposit(double amt)
    {
        bal += amt;
    }

    double withdraw(); // declare without defining

    double withdraw(double amt);

    double getBalance() { return bal; } // simple accessor

    void output(); // print account information

    void setPin(); // set pin variable

private:
    string name;
    double bal;
    int pin;
};

// test program
int main()
{
    BankAccount acct1("Jenny Smith");
    BankAccount acct2("Calvin Lim", 2500);
    acct1.setPin();
    acct2.setPin();
    cout << "Jenny Smith Initial balance: " << acct1.getBalance() << endl;
    cout << "Calvin Lim Initial balance: " << acct2.getBalance() << endl;
    acct1.deposit();
    acct2.withdraw();
    cout << "Jenny Smith balance: " << acct1.getBalance() << endl;
    cout << "Calvin Lim balance: " << acct2.getBalance() << endl;
    acct1.deposit(500);
    acct2.withdraw(1000);
    cout << "Jenny Smith balance: " << acct1.getBalance() << endl;
    cout << "Calvin Lim balance: " << acct2.getBalance() << endl;
    return 0;
}

// note scope resolution syntax for non-inline member function definitions
double BankAccount::withdraw()
{
    int enteredPin;
    double amt;
    cout << "Enter four-digit pin: " << endl;
    cin >> enteredPin;
    if (enteredPin != pin)
    {
        cout << "Incorrect pin: " << endl;
        return 0;
    }
    cout << "Enter amount to withdraw: " << endl;
    cin >> amt;
    if (amt < 0)
    {
        cout << "Cannot deposit negative values" << endl;
        return 0;
    }
    else if (bal <= amt)
    {
        bal = 0;
    }
    else
    {
        bal -= amt;
    }
    return bal;
}

double BankAccount::withdraw(double amt)
{
    int enteredPin;
    cout << "Enter four-digit pin: " << endl;
    cin >> enteredPin;
    if (enteredPin != pin)
    {
        cout << "Incorrect pin: " << endl;
        return 0;
    }
    if (amt < 0)
    {
        cout << "Cannot deposit negative values" << endl;
        return 0;
    }
    else if (bal <= amt)
    {
        bal = 0;
    }
    else
    {
        bal -= amt;
    }
    return bal;
}

void BankAccount::output()
{
    cout << "Account holder: " << name << endl;
    cout << "Balance: $" << bal << endl;
}

void BankAccount::setPin()
{
    cout << "Enter a 4-digit pin: " << endl;
    cin >> pin;
    while (sizeof(pin) < 4)
    {
        cout << "Pin must be 4 digts: " << endl;
        cin >> pin;
    }
}