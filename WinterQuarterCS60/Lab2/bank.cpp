// Starter code for Lab 2: A BankAccount class that stores a name of an
// account holder and the balance on the account. Public member functions
// include a 1-argument constructor, two mutators, and an accessor. Most are
// defined inline but withdraw is defined below main using scope resolution.

#include <iostream>
using namespace std;

class BankAccount
{
public:
	BankAccount(string name) : name(name), bal(0) {} // constructor

	BankAccount(string name, double amt) : name(name), bal(amt) {}

	void deposit(double amt)
	{
		// code for when we were taking in user inputs
		//  int amt;
		//  cout << "enter in an amount you would like to deposit" << endl;
		//  cin >> amt;
		if (amt > 0)
		{
			bal += amt;
		}
		else
		{
			cout << "error deposit real money" << endl;
		}

	} // simple mutator
	int setPin();

	void withdraw(double amt); // declare without defining

	void printacct();

	double getBalance() { return bal; } // simple accessor

	// Write a 2-argument constructor that allows someone opening a new account to specify an
	// initial amount of money to deposit.

private:
	string name;
	double bal;
	int pin;
};

// test program
int main()
{
	BankAccount myAcct("Jenny Smith");
	BankAccount Acct1("Sami Shibli", 10000);
	BankAccount Acct2("Calvin Lim", 2500);

	cout << "Set 4-digit Pin for Sami Shibli: " << endl;
	Acct1.setPin();
	cout << "Set 4-digit Pin for Calvin Lim: " << endl;
	Acct2.setPin();

	Acct1.printacct();
	Acct2.printacct();

	Acct1.withdraw(1000);
	Acct1.printacct();

	Acct2.withdraw(1000);
	Acct2.printacct();

	cout << "Now depositing 200 into each account" << endl;
	Acct1.deposit(200);
	Acct2.deposit(200);

	Acct1.printacct();
	Acct2.printacct();

	return 0;
}

// note scope resolution syntax for non-inline member function definitions
void BankAccount::withdraw(double amt)
{
	// int amt;
	int tempPin;
	cout << "Please enter the pin for " << name << "'s account" << endl;
	cin >> tempPin;
	while (tempPin != pin)
	{
		cout << "Incorrect pin! Try again" << endl;
		cin >> tempPin;
	}
	if (tempPin == pin)
	{
		// cout << "Enter Amount you would like to withdraw" << endl;
		// cin >> amt;
		bal -= amt;
	}
	if ((bal - amt) < 0)
	{
		cout << "Insufficent funds cannot withdraw!" << endl;
	}
	else
	{
		bal -= amt;
	}
}
void BankAccount::printacct()
{
	cout << "Account Holder: " << name << endl;
	cout << "Balance: $" << bal << endl;
	cout << "Pin: " << pin << endl;
}
int BankAccount::setPin()
{
	int digits;
	// cout << "Enter in 4-digit pin: " << endl;
	cin >> digits;
	while (digits > 10000 || digits < 1000)
	{
		cout << "Your pin must be 4 digits" << endl;
		cin >> digits;
	}
	pin = digits;
}
