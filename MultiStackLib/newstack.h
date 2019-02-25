#pragma once
#include <iostream>
#include "stack.h"

using namespace std;

template <class T>
class TNewStack : public TStack<T>
{
public:
  TNewStack(int _size, T* _mas);
  TNewStack(TNewStack<T>& A);
  int GetFreeMemory();
  T Pop();
  void Push(T _A);
  int GetSize();
  int GetTop();
  void SetMas(int _size, T* _mas);
  void Print();       
};

template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas)
{
  if (_size <= 0)
    throw -1;
  TStack<T>::top = 0;
  TStack<T>::size = _size;
  TStack<T>::mas = _mas;
}

template <class T>
TNewStack<T>::TNewStack(TNewStack<T>& A)
{
  TStack<T>::top = A.top;
  TStack<T>::size = A.size;
  TStack<T>::mas = A.mas;
}

template <class T>
int TNewStack<T>::GetFreeMemory()
{
  return TStack<T>::size - TStack<T>::top;
}

template <class T>
void TNewStack<T>::SetMas(int _size, T* _mas)
{
  if (_size <= 0)
    throw -1;
  TStack<T>::size = _size;
  TStack<T>::mas = _mas;
}

template <class T>
int TNewStack<T>::GetTop()
{
  return TStack<T>::top;
}

template <class T>
int TNewStack<T>::GetSize()
{
  return TStack<T>::size;
}

template <class T>
void TNewStack<T>::Push(T _A)
{
  TStack<T>::mas[TStack<T>::top] = _A;
  TStack<T>::top++;
}

template <class T>
T TNewStack<T>::Pop() 
{
  TStack<T>::top--;
  return TStack<T>::mas[TStack<T>::top];
}

template <class T>
void TNewStack<T>::Print()
{
  for (int i =  0; i < TStack<T>::top; i++)
    cout << " " << TStack<T>::mas[i];
}