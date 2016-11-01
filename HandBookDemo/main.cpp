/*
Created on Mon Nov 1 13:25:45 2016
Propose: Demo example from "Essential C++"
Enviroment: C++ (Dev C++)
@author: kevin 
*/

#include <iostream>
#include <vector>
#include "_stack.h"
#include "_generic.h"
#include "_STLdemo.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void applyStack();
void applySTL();

int main(int argc, char** argv) {
    //applyStack();
    applySTL();
    system("pause");
	return 0;
}

void applyStack()
{
   //Stack<int> intStack;
   _stack<int> intStack;
   _stack<double> doubleStack(12.5,20);
   for(int i=0;i<10;i++)
      intStack.push(i);
    intStack.printstack();
    doubleStack.printstack();
}

void applySTL()
{
  _STLdemo S;
  S.withVector();
}
