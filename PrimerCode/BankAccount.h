#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include<iostream>
using namespace std;

class BankAccount
{
private:
	string name;
	string account;
	double balance;
public:
	BankAccount(string name, string account, 
		double balance= 0.0);
	void printAccount(void) const;
	void deposit(double sum);
	void withdraw(double sum);
};

class Stock  // class declaration
{
private: 
    std::string company;
    long shares;
    double share_val;
    double total_val;
    //calculate total value
    void set_tot() { total_val = shares * share_val; }
public:
	//initialize shares
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};    // note semicolon at the end

#endif
