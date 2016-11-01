#include "_generic.h"
#include<vector>
#include<iostream>
using namespace std;

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
