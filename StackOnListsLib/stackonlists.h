#pragma once
#include "list.h"

template <class T>
class TStackList : public TList<T>
{
protected:
  int size;
public:
  TStackList<T>(int _size = 10);
  TStackList<T>(TStackList<T> &A);
  ~TStackList();
  void Push(T A);
  T Pop();
  int GetMaxSize();
  int GetSize();
  bool IsEmpty();
  bool IsFull();
  void Print();
};

template <class T>
TStackList<T>::TStackList(int _size) : TList<T>()
{
  if (_size <= 0)
    throw -1;
  size = _size;
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A) : TList<T>(A)
{
  TList<T>::count = A.count;
}

template<class T>
TStackList<T>::~TStackList() 
{
}

template <class T>
void TStackList<T>::Push(T A)
{
  if (this->IsFull())
    throw -1;
  TList<T>::PushFront(A);
}

template <class T>
T TStackList<T>::Pop() 
{
  if (this->IsEmpty())
    throw -1;
  return TList<T>::PopFront();
}

template <class T>
int TStackList<T>::GetMaxSize() 
{
  return size;
}
template<class T>
inline int TStackList<T>::GetSize()
{
  return TList<T>::count;
}

template <class T>
bool TStackList<T>::IsEmpty() 
{
  if (TList<T>::count == 0)
    return true;
  return false;
}

template<class T>
bool TStackList<T>::IsFull()
{
  if (TList<T>::count == size)
    return true;
  return false;
}

template<class T>
void TStackList<T>::Print()
{
  if (this->IsEmpty())
    throw -1;
  TList<T>::Print();
}