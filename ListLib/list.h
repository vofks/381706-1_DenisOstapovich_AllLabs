#pragma once 

#include "elem.h"
#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:
  TElem<T>* begin;            
  int count;                  
public:
  TList();                    
  TList(TList<T> &L);         
  virtual ~TList();           
  int GetSize();              
  void Push(int _n, T elem);   
  T Pop(int _n);              
  void PushFront(T A);         
  void PushBack(T A);           
  T PopFront();               
  T PopBack();                 
  bool IsFull();               
  bool IsEmpty();             
  void Print();               
};

template <class T>
TList<T>::TList()
{
  begin = 0;
  count = 0;
}
template <class T>
TList<T>::TList(TList<T> &L)
{
  count = L.count;
  TElem<T>* a = L.begin;
  TElem<T>* b;
  if (L.begin == 0)
    begin = 0;
  else
  {
    begin = new TElem<T>(*L.begin);
    b = begin;
    while (a->GetNext() != 0)
    {
      b->SetNext(new TElem<T>(*(a->GetNext())));
      a = a->GetNext();
      b = b->GetNext();
    }
  }
}

template <class T>
TList<T>::~TList()
{
  while (begin != 0)
  {
    TElem<T>* temp = begin;
    begin = begin->GetNext();
    delete temp;
  }
}

template<class T>
int TList<T>::GetSize()
{
  return count;
}

template<class T>
void TList<T>::Push(int _n, T elem)
{
  if (this->IsFull())
    throw -1;
  if (_n < 1 || _n > count - 1)
    throw -1;
  else
  {
    int i = 0;
    TElem<T>* a = begin;
    while (i != _n - 1)
    {
      a = a->GetNext();
      i++;
    }
    TElem<T>* temp = new TElem<T>(elem, a->GetNext());
    a->SetNext(temp);
    count++;
  }
}

template<class T>
T TList<T>::Pop(int _n)
{
  if (this->IsEmpty())
    throw -1;
  if (_n < 1 || _n > count - 1)
    throw -1;
  else
  {
    int i = 0;
    count--;
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    while (i != _n - 1)
    {
      a = b;
      b = b->GetNext();
      i++;
    }
    T temp = b->GetData();
    a->SetNext(b->GetNext());
    delete b;
    return temp;
  }
}

template <class T>
void TList<T>::PushFront(T A)
{
  if (this->IsFull())
    throw -1;
  if (begin == 0)
  {
    TElem<T>* temp = new TElem<T>(A, 0);
    begin = temp;
  }
  else
  {
    TElem<T>* temp = new TElem <T>(A, begin);
    begin = temp;
  }
  count++;
}

template <class T>
void TList<T>::PushBack(T A)
{
  if (this->IsFull())
    throw -1;
  if (begin != 0)
  {
    TElem<T>* a = begin;
    while (a->GetNext() != 0)
      a = a->GetNext();
    a->SetNext(new TElem <T>(A, 0));
  }
  else
    begin = new TElem<T>(A, 0);
  count++;
}

template <class T>
T TList<T>::PopFront()
{
  if (IsEmpty())
    throw -1;
  else
  {
    TElem<T>* a = begin;
    T temp = begin->TElem<T>::GetData();
    begin = begin->TElem<T>::GetNext();
    delete a;
    count--;
    return temp;
  }
}

template <class T>
T TList<T>::PopBack()
{
  if (IsEmpty())
    throw-1;
  else
  {
    count--;
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    if (b == 0)
    {
      T temp = a->TElem<T>::GetData();
      delete a;
      begin = 0;
      return temp;
    }
    else
    {
      while (b->GetNext() != 0)
      {
        a = b;
        b = b->GetNext();
      }
      T temp = b->GetData();
      delete b;
      a->SetNext(0);
      return temp;
    }
  }
}

template <class T>
bool TList<T>::IsFull()
{
  try
  {
    TElem<T>* a = new TElem<T>();
    if (a == NULL)
      return 1;
    else
    {
      delete a;
      return 0;
    }
  }
  catch (...)
  {
    return 0;
  }
  return true;
}

template <class T>
bool TList<T>::IsEmpty()
{
  if (begin == 0)
    return 1;
  return 0;
}

template<class T>
inline void TList<T>::Print()
{
  if (begin == 0)
    throw -1;
  else
  {
    TElem<T>* a = begin;
    while (a->GetNext() != 0)
    {
      cout << a->GetData() << " ";
      a = a->GetNext();
    }
    cout << a->GetData() << " ";
  }
}