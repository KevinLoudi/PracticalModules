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
#include "Algorithms.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void applyStack();
void applySTL();
void applyAlgorithms();

int main(int argc, char** argv) {
    //applyStack();
    //applySTL();
    applyAlgorithms();
    system("pause");
	return 0;
}

void applyAlgorithms()
{
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  //Algorithms<int> A;
  //A.bubbleSort(list, SIZE);
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";
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
  //S.withVector();
  S.withIterator();
}
