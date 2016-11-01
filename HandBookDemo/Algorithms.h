#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "_stack.h"


class Algorithms
{
	public:
		Algorithms(){};
		template<typename T,int N>
		void bubbleSort(T (&list)[N],int _size);
		~Algorithms(){};
	protected:
};


template<typename T,int N>
void Algorithms::bubbleSort(T (&list)[N],int _size)
{
	bool NextPass=true;

	for(int k=1; (k<_size)&&NextPass;k++)
		for(int j=0; j<_size-k;j++)
		{
			if (list[j]>list[j+1])
			{
				T tmp=list[j];
				list[j]=list[j+1];
				list[j+1]=tmp;
				//if swap in no longer needed, terminate the loop
				NextPass=true;
			}
		}
}

#endif
