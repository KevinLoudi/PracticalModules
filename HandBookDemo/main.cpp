/*
Created on Mon Nov 1 13:25:45 2016
Propose: Demo example from "Essential C++"
Enviroment: C++ (Dev C++)
@author: kevin 
*/

#include <iostream>
#include "_stack.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	_stack *S = 0;
	S->push("ab");
	S->push("cd");
	S->printstack();
	return 0;
}
