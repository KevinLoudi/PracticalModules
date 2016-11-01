#include "_stack.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

_stack::_stack()
{
}

bool _stack::pop(string &elem)
{
	if (empty())
	{
		return false;
	}

	elem=_ss.back();
	_ss.pop_back();
	return true;
}

inline bool _stack::full()
{
	return _ss.size()==_ss.max_size();
}

bool _stack::push(const string &elem)
{
	if(full())
	   return false;
	
	_ss.push_back(elem);
	return true;
}

void _stack::printstack()
{
	vector<string>::iterator it;
	for(it=_ss.begin();it!=_ss.end();it++)
	{
		cout<<*it<<' ';	
	}
	cout<<endl;
}
	
_stack::~_stack()
{
}
