#ifndef _STLDEMO_H
#define _STLDEMO_H

#include <vector>
using namespace std;

class _STLdemo
{
	public:
		_STLdemo();
		void withVector();
		void withIterator();
		void printContains(vector<int> v);
		~_STLdemo();
	protected:
};

#endif
