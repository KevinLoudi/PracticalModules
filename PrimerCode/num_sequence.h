#ifndef NUM_SEQUENCE_H
#define NUM_SEQUENCE_H

#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

typedef unsigned int UINT;

class num_sequence
{
	public:
		typedef vector<UINT>::iterator iterator;
		
//		//I cannot put the 
//		num_sequence(vector<UINT> & ele,int len=0,int beg=0):_relems(ele),_length(len),_beg_pos(beg)
//		{
//			//an abstract class cannot be instanlized
//			cout<<"build a num_sequence object";  
//        }    
		virtual ~num_sequence();
		virtual num_sequence *clone() const=0;
		
		UINT elem(int) const;
		bool is_elem(UINT) const;
		int pos_elem(UINT) const;
		
		const char* what_am_i() const;
		static int max_elems()
		{
			return _max_elems;
		}
		ostream& print(ostream &os=cout) const;
		
		int length() const
		{
			return _length;
		}
		int beg_pos() const
		{
			return _beg_pos;
		}
		
		iterator begin() const
		{
			return _relems.begin()+_beg_pos-1;
		}
		iterator end() const
		{
			return _relems.end()+_beg_pos+_length;
		}
		
		void set_position(int pos);
		void set_length(int len);
		
		bool operator ==(const num_sequence&) const;
		bool operator !=(const num_sequence&) const;
		
		const vector<UINT>* sequence() const
		{
			return &_relems; 
		}
		
	protected:
		static const int _max_elems=1024;
		//the only method derived class have to specify is 
		//the way to generate a sequences
		virtual void gen_elems(int pos) const=0;
		int _calc_pos(UINT elem) const;
		bool check_integrity(int pos,int size) const;
		
		num_sequence(int,int,vector<UINT>&);
		
		int _length;
		int _beg_pos;
		vector<UINT> &_relems;
};

class Fibonacci: public num_sequence
{
	public:
		Fibonacci(int beg_pos,int len):num_sequence(beg_pos,len,_elems)
		{
			cout<<"build a fibonacci object.";
		}
		
		virtual num_sequence *clone() const;
	protected:
		virtual void gen_elems(int) const;
		static vector<UINT> _elems;
};

#endif
