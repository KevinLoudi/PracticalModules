#include<iostream>
#include "BankAccount.h"

BankAccount::BankAccount(std::string name, std::string account, 
	double balance)
{
	using std::cout;
	using std::endl;

	this->name = name;
	this->account = account;

	if (balance >= 0)
		this->balance = balance;
	else
	{
		cout << "You can't have a negative balance.";
		cout << endl << "Setting balance to 0.";
		cout << endl;
		this->balance = 0.0;
	}
}

void BankAccount::printAccount(void) const
{
	using std::cout;
	using std::endl;
	
	cout << "Name: " << name << endl;
	cout << "Account #: " << account << endl;
	cout << "Balance: " << balance << endl;
}

//deposit moneny from the account
void BankAccount::deposit(double sum)
{
	using std::cout;
	using std::endl;

	if (sum < 0)
	{
		cout << "You can't deposit negative money" << endl;
		cout << "Deposit aborted" << endl;
	}
	else
		balance += sum;
}

void BankAccount::withdraw(double sum)
{
	using std::cout;
	using std::endl;

	if (sum <= balance && sum >= 0)
		balance -= sum;
	else if (sum < 0)
	{
		cout << "You can't withdraw negative money" << endl;
		cout << "Withdrawal aborted" << endl;
	}
	else if (sum > balance)
	{
		cout << "You can't withdraw more than you have";
		cout << endl << "Withdrawal aborted" << endl;
	}
}

void Stock::acquire(const std::string & co, long n, double pr)
{
	//set company name
    company = co;
    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        //set share num
        shares = n;
    //set share price
    share_val = pr;
    //calculate total price
    set_tot();
}

void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cerr;
    if (num < 0)
    {
        cerr << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cerr << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::ios_base;
	
	ios_base::fmtflags orig=cout.setf(ios_base::fixed);
	int prec=cout.precision(3);
	
    cout << "Company: " << company
              << "  Shares: " << shares << '\n';
    cout<< "  Share Price: $" << share_val;
    
    cout.precision(2);
    cout<< "  Total Worth: $" << total_val << '\n';
    
    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

