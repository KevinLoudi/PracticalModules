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
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void applyStack();

int main(int argc, char** argv) {
    applyStack();
    system("pause");
	return 0;
}

void applyStack()
{
   //Stack<int> intStack;
   _stack<int> intStack;
   for(int i=0;i<10;i++)
      intStack.push(i);
    intStack.printstack();
}
