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

  deque<int> deque1, deque2;
  cout << "Deque: " << endl;
  deque1.push_back(1);
  deque1.push_back(2);
  deque2.push_back(30);
  cout << "size of deque1: " << deque1.size() << endl;
  cout << "size of deque2: " << deque2.size() << endl;
  cout << "maximum size of deque1: " << deque1.max_size() << endl;
  cout << "maximum size of deque2: " << deque2.max_size() << endl;
  list1.swap(list2);
  cout << "size of deque1: " << deque1.size() << endl;
  cout << "size of deque2: " << deque2.size() << endl;
  cout << "deque1 < deque2? " << (deque1 < deque2) << endl << endl;
}

_STLdemo::~_STLdemo()
{
}
