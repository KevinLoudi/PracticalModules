#ifndef _LIBMAT_H
#define _LIBMAT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class _libMat
{
	public:
		_libMat(){cout << "LibMat::LibMat() default constructor!\n";}
		virtual ~_libMat(){cout << "LibMat::~LibMat() destructor!\n";}
		virtual void print() const
		{cout << "LibMat::print() -- I am a LibMat object!\n";}
};

#endif
