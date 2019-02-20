#pragma once
#include "queue.h"

template <class T>
class TArrayList
{
private:
  T* mas;                    //Массив элементов списка
  int *nextIndex;              //Массив индексов, указывающих на следюущий элемент списка
  int *prevIndex;              //Массив индексов, указывающих на предыдущий элемент списка
  int size;                  //Размер списка
  int count;                 //Количество элементов в списке
  int start;                 //Индекс первого элемента списка
  int end;                   //Индекс последнего элемента списка
  TQueue <int> freeElem;     //Очередь "пустых" ячеек в массиве,  
public:
  TArrayList(int _size = 10);  //Конструктор с параметром
  TArrayList(TArrayList<T> &A);  //Конструктор копирования
  ~TArrayList();               //Деструктор
  void Insert(int n, T elem);   //Добавить промежуточный элемент
  T Get(int n);              //Извлечь промежутьчный элемент 
  void PushFront(T elem);     //Положить в начало списка
  void PushBack(T elem);       //Положить в конец списка 
  T PopFront();              //Забрать из начала списка с удалением
  T PopBack();                //Забрать из конца списка с удалением
  bool IsFull();             //Проверка на полноту
  bool IsEmpty();            //Проверка на пустоту
  void Print();              //Печать списка
};

template <class T>
TArrayList<T>::TArrayList(int _size) : freeElem(_size)
{
  if (_size <= 0)
    throw -1;
  size = _size;
  count = 0;
  start = -1;
  end = -1;
  mas = new T[size];
  nextIndex = new int[size];
  prevIndex = new int[size];
  for (int i = 0; i < size; i++)
  {
    nextIndex[i] = -2;
    prevIndex[i] = -2;
    freeElem.Push(i);
  }
}

template <class T>
TArrayList<T>::TArrayList(TArrayList<T> &A)
{
  start = A.start;
  end = A.end;
  size = A.size;
  count = A.count;
  mas = new T[size];
  nextIndex = new int[size];
  prevIndex = new int[size];
  freeElem = A.freeElem;
  for (int i = 0; i < size; i++)
  {
    mas[i] = A.mas[i];
    nextIndex[i] = A.nextIndex[i];
    prevIndex[i] = A.prevIndex[i];
  }
}

template<class T>
inline TArrayList<T>::~TArrayList()
{
  delete[] mas;
  delete[] nextIndex;
  delete[] prevIndex;
}

template<class T>
void TArrayList<T>::Insert(int n, T elem)
{
  if (IsFull())
    throw -1;
  if (n < 1 || n > count - 1)
    throw -1;
  int ifree = freeElem.Pop();
  mas[ifree] = elem;
  int one = start;
  int two = nextIndex[start];
  for (int i = 0; i < n - 1; i++)
  {
    one = two;
    two = nextIndex[two];
  }
  nextIndex[ifree] = two;
  nextIndex[one] = ifree;

  prevIndex[ifree] = one;
  prevIndex[two] = ifree;
  count++;
}

template<class T>
T TArrayList<T>::Get(int n)
{
  if (IsEmpty())
    throw -1;
  if (n < 1 || n > count - 1)
    throw -1;
  int ind = start;
  for (int i = 0; i < n; i++)
    ind = nextIndex[ind];
  nextIndex[prevIndex[ind]] = nextIndex[ind];
  prevIndex[nextIndex[ind]] = prevIndex[ind];
  T temp = mas[ind];
  freeElem.Push(ind);
  count--;
  return temp;
}

template <class T>
void TArrayList<T>::PushFront(T elem)
{
  if (IsFull())
    throw -1;
  int ifree = freeElem.Pop();
  mas[ifree] = elem;
  nextIndex[ifree] = start;
  if (start != -1)
    prevIndex[start] = ifree;
  else
    end = ifree;
  start = ifree;
  count++;
}

template <class T>
void TArrayList<T>::PushBack(T elem)
{
  if (IsFull())
    throw -1;
  int ifree = freeElem.Pop();
  mas[ifree] = elem;
  if (end != -1)
    nextIndex[end] = ifree;
  else
  {
    start = ifree;
    prevIndex[ifree] = -1;
  }
  prevIndex[ifree] = end;
  end = ifree;
  count++;
}

template <class T>
T TArrayList<T>::PopFront()
{
  if (IsEmpty())
    throw -1;
  T elem = mas[start];
  freeElem.Push(start);
  int newstart = nextIndex[start];
  nextIndex[start] = prevIndex[start] = -2;
  if (newstart != -1)
    prevIndex[newstart] = -1;
  count--;
  start = newstart;
  return elem;
}

template <class T>
T TArrayList<T>::PopBack()
{
  if (IsEmpty())
    throw -1;
  T elem = mas[end];
  int newFinish = prevIndex[end];
  prevIndex[end] = nextIndex[end] = -2;
  freeElem.Push(end);
  end = newFinish;
  if (newFinish != -1)
    nextIndex[newFinish] = -1;
  else
    start = -1;
  count--;
  return elem;
}

template <class T>
bool TArrayList<T>::IsFull()
{
  if (count == size)
    return true;
  return false;
}

template <class T>
bool TArrayList<T>::IsEmpty()
{
  if (count == 0)
    return true;
  return false;
}

template<class T>
inline void TArrayList<T>::Print()
{
  int it = start;
  for (int i = 0; i < count; i++)
  {
    cout << mas[it] << " ";
    it = nextIndex[it];
  }
}