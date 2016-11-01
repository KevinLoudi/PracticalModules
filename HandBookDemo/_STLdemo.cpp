#include "_STLdemo.h"
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

_STLdemo::_STLdemo()
{
}

void _STLdemo::withVector()
{
  vector<int> vector1, vector2;
  cout << "Vector: " << endl;
  vector1.push_back(1);
  vector1.push_back(2);
  vector2.push_back(30);
  cout << "size of vector1: " << vector1.size() << endl;
  cout << "size of vector2: " << vector2.size() << endl;
  cout << "maximum size of vector2: " << vector1.max_size() << endl;
  vector1.swap(vector2);
  cout << "size of vector1: " << vector1.size() << endl;
  cout << "size of vector2: " << vector2.size() << endl;

  //double-ended queue
  deque<int> deque1, deque2;
  cout << "Deque: " << endl;
  deque1.push_back(1);
  deque1.push_back(2);
  deque2.push_back(30);
  cout << "size of deque1: " << deque1.size() << endl;
  cout << "size of deque2: " << deque2.size() << endl;
  cout << "maximum size of deque1: " << deque1.max_size() << endl;
  cout << "maximum size of deque2: " << deque2.max_size() << endl;
}

void _STLdemo::printContains(vector<int> v)
{
  vector<int>::iterator it= v.begin();
  //Not allowed to do modification
  vector<int>::const_iterator const_it = v.begin();

  for (; it!=v.end();it++)
  {
  	cout<<*it<<" ";
  }

  cout<<endl;
}

void _STLdemo::withIterator()
{
  //create and fill a vector
  vector<int> intVector;
  intVector.push_back(10);
  intVector.push_back(20);
  intVector.push_back(30);
  intVector.push_back(40);
  intVector.push_back(50);
  intVector.push_back(60);

  printContains(intVector);
}

_STLdemo::~_STLdemo()
{
}
