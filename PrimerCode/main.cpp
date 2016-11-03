#include <iostream>
#include "BankAccount.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int applyBankAccount();
void usestock();
void usestocktmp();

int main(int argc, char** argv) {
	using std::string;
	//applyBankAccount();
	//usestock();
	usestocktmp();
	system("pause");
	return 0;
}

void usestocktmp()
{
	const int STKS=4;
	//create an array of initialized objects
	Stock stocks[STKS]={
		Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
	};
	
	
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
