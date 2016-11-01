#ifndef _GENERIC_H
#define _GENERIC_H

#include<vector>
using namespace std;

class _generic
{
	public:
		_generic();		
		template<typename T>
		void sort(T list[], int listSize);
		template<typename T>
		void printArray(const T list[], int listSize);
		~_generic();
		//I can only use the template-defined functions
		//within the class scope
		void usetem();
	private:
		bool State;
	protected:
};

#endif
