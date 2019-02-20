#pragma once
#include "stack.h"

template <class T>
class TQueue : public TStack<T>
{
protected:
  int start;             
  int count;             
public:
  TQueue(int n = 0);     
  TQueue(TQueue <T> &q); 
  virtual ~TQueue();     
  T Top();
  void Push(T a);         
  T Pop();               
  bool IsFull();         
  bool IsEmpty();        
  void Print();
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n)
{
  start = 0;
  count = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &q) : TStack<T>(q)
{
  start = q.start;
  count = q.count;
}

template <class T>
TQueue<T>::~TQueue()
{

}

template<class T>
inline T TQueue<T>::Top()
{
  return TStack<T>::mas[start];
}

template <class T>
void TQueue<T>::Push(T a)
{
  if (IsFull())
    throw -1;
  else
  {
    TStack<T>::Push(a);
    TStack<T>::top = TStack<T>::top % TStack<T>::size;
    count++;
  }
}

template <class T>
T TQueue<T>::Pop()
{
  if (IsEmpty())
    throw -1;
  else
  {
    T temp = TStack<T>::mas[start];
    start = (start + 1) % TStack<T>::size;
    count--;
    return temp;
  }
}

template <class T>
bool TQueue<T>::IsFull()
{
  if (count == TStack<T>::size)
    return 1;
  return 0;
}
template <class T>
bool TQueue<T>::IsEmpty()
{
  if (count == 0)
    return 1;
  return 0;
}

template<class T>
void TQueue<T>::Print()
{
  for (int i = start; i < TStack<T>::top; i = (i + 1) % TStack<T>::size)
    cout << TStack<T>::mas[i];
}