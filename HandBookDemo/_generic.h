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
		// const the value is not allowed to change 
		// in the function body
		void printArray(const T list[], int listSize);
		~_generic();
		//I can only use the template-defined functions
		//within the class scope
		void usetem();
	private:
		bool State;
	protected:
};

_generic::_generic()
{
}

template<typename T>
void _generic::sort(T list[], int listSize) 
{
  for (int i = 0; i < listSize; i++) 
  {
    // Find the minimum in the list[i..listSize-1]
    T currentMin = list[i];
    int currentMinIndex = i;

    for (int j = i + 1; j < listSize; j++) 
    {
      if (currentMin > list[j]) 
      {
        currentMin = list[j];
        currentMinIndex = j;
      }
    }

    // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMinIndex != i) 
    {
      list[currentMinIndex] = list[i];
      list[i] = currentMin;
    }
  }
}

template<typename T>
void _generic::printArray(const T list[], int listSize)
{
  for (int i = 0; i < listSize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

void _generic::usetem()
{
	int _list[8] = {3,5,7,9,2,4,8,10};
    sort(_list,8);
    printArray(_list,8);
}

_generic::~_generic()
{
}

#endif
