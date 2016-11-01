#ifndef _STACK_H
#define _STACK_H

#include<vector>
#include<string>
#include<iostream>
using namespace std;

//I have to make implementation in the header file
//or "dereference" errors will happen

template<typename T>
class _stack
{
	public:
		_stack();
		_stack(T _t,int _s);
		bool empty() const;
		T peek() const;
		void push(T value);
		T pop();
		//const after a function declaration means 
		//that the function is not allowed to change 
		//any class members (except ones that are marked mutable)
		int getSize() const;
		//compare the current size of the underlying vector with max_size()
		bool full();
		//print out all elements
		void printstack() const;
		
	protected:
		//vector<T> _ss;
		//implment via array
		T elements[100];
		int size;
};

template<typename T>
_stack<T>::_stack()
{
  size = 0;
  cout<<"Default Constructor"<<endl;
}

template<typename T>
_stack<T>::_stack(T _t,int _s)
{
   if(_t>100) return;
   size=_s;
   for(int i=0; i< size; i++)
   {
   	 elements[i]=_t;
   }
   cout<<"Customized Constructor"<<endl;
}

template<typename T>
bool _stack<T>::empty() const
{
  return (size == 0);
}

template<typename T>
T _stack<T>::peek() const
{
  return elements[size - 1];
}

template<typename T>
void _stack<T>::push(T value)
{
  elements[size++] = value;
}

template<typename T>
T _stack<T>::pop()
{
  return elements[--size];
}

template<typename T>
int _stack<T>::getSize() const
{
  return size;
}

template<typename T>
void _stack<T>::printstack() const
{
  for(int i=0; i<size; i++)
  {
    cout<<elements[i]<<" ";
    if(i%10==0&&i!=0)
      cout<<endl;
  } 
  cout<<endl; 
}


#endif
