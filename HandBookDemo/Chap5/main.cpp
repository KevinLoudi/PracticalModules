#include <iostream>
#include "_libMat.h"
#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void print(const _libMat &mat);

int main(int argc, char** argv) {
	// objects are in local blocks to force destruction
	{   
        cout << "\n" << "Creating a LibMat object to print()\n";
  	    _libMat m;
	    print( m );
	}
	
	//create and print a book object
	{
		cout << "\n" << "Creating a Book object to print()\n";
		_book b("Essential C++","Stanley B. Lippman");
		//dynamic binding via virtual invocation
		print(b);
	}
	
	//create and print a audiobook object
	{
		cout << "\n" << "Creating a Book object to print()\n";
		_audioBook a("Essential C++","Stanley B. Lippman","Kevin Zhu");
		print(a);
	}
	
	//create and print a audiobook object
	{
		cout << "\n" << "Creating a magazine object to print()\n";
		_magazine m("Spectrum Learning","Kevin Zhu","Health Physics");
		print(m);
	}
	system("pause");
	return 0;
}

void print(const _libMat &mat)
{
	cout << "in global print(): about to print mat.print()\n";
	mat.print();
}
