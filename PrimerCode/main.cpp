#include <iostream>
#include "BankAccount.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int applyBankAccount();
void usestock();

int main(int argc, char** argv) {
	using std::string;
	//applyBankAccount();
	usestock();
	system("pause");
	return 0;
}

void usestock()
{
	Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000,40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000,0.125);
    fluffy_the_cat.show();
}

int applyBankAccount()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	BankAccount checking("Jerry", "2104032405", 2000.00);
	cout << "Here is our account: " << endl;
	checking.printAccount();
	cout << "Now we deposit $100" << endl;
	checking.deposit(100);
	checking.printAccount();
	cout << "And now we withdraw $1500" << endl;
	checking.withdraw(1500);
	checking.printAccount();
	cout << "Now let's try some illegal operations" << endl;
	cout << "Let's deposit $-200" << endl;
	checking.deposit(-200);
	checking.printAccount();
	cout << "Let's withdraw $-500" << endl;
	checking.withdraw(-500);
	checking.printAccount();
	cout << "Finally let's withdraw $10,000" << endl;
	checking.withdraw(10000);
	checking.printAccount();
	
	return 0;
}
