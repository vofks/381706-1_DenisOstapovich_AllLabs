#include "telem.h"
#include <iostream>
#include <locale>

using namespace std;

template <class T>
class TViewTable
{
protected:
  TElem<T> not_found;
  TElem<T>* mas;
  int size, count;

public:
  void SetSize (int _size);
  void SetCount (int _count);
  TElem<T>* GetMas();
  int GetSize();
  int GetCount();

  TViewTable (int _size = 0);
  TViewTable (TViewTable& A);
  void Put (string _key, T _data);
  void Put (TElem<T> A);
  void Del (string _key);
  TElem<T>& Search (string _key);
  T operator[](string _key);
  bool IsFull ();
  bool IsEmpty();

  friend ostream & operator << ( ostream &out, TViewTable &t)
  {
    for (int i = 0; i < t.GetCount(); i++)
      out << t.mas[i]<<"\n";
    return out;
  }

};


template <class T>
void TViewTable<T>::SetSize(int _size)
{
  size = _size;
}

template <class T>
void TViewTable<T>::SetCount(int _count)
{
  count = _count;
}

template <class T>
int TViewTable<T>::GetSize()
{
  return size;
}

template <class T>
int TViewTable<T>::GetCount()
{
  return count;
}

template <class T>
TElem<T>* TViewTable<T>::GetMas()
{
  return mas;
}

template <class T>
TViewTable<T>::TViewTable(int _size)
{
  if (_size < 0)
    throw -1;
  else
  {
    size = _size;
    mas = new TElem<T>[size];
    count = 0;
    for (int i = count; i < size; i++)
      mas[i] = not_found;
}
}

template <class T>
TViewTable<T>::TViewTable(TViewTable& A)
{
  size = A.size;
  count = A.count;
  mas = new TElem<T> [size];
  for (int i = 0; i < count; i++)
    mas[i] = A.mas[i];
  for (int i = count; i < size; i++)
    mas[i] = not_found;
}

template <class T>
void TViewTable<T>::Put(string _key, T _data)
{
  if (IsFull())
    throw -1;
  try
  {
    if (Search(_key) != not_found)
      throw -1;
    else
    {
      mas[count].SetKey(_key);
      mas[count].SetData(_data);
      count++;
    }
  }
  catch (...)
  {
    cout << "Ключи не могут повторяться!\n";
  }
}

template <class T>
void TViewTable<T>::Put(TElem<T> A)
{
  if (IsFull())
    throw -1;
  try
  {
    if (Search(A.GetKey()) != not_found)
      throw -1;
    else
    {
      mas[count] = A;
      count++;
    }
  }
  catch (...)
  {
    cout<<"Ключи не могут повторяться!\n";
  }
}

template <class T>
void TViewTable<T>::Del(string _key)
{
  if (IsEmpty())
    throw -1;
  TElem<T>& tmp = Search(_key);
  if (tmp != not_found)
    tmp = not_found;
}

template <class T>
TElem<T>& TViewTable<T>::Search(string _key)
{
  for (int i = 0; i < count; i++)
    if (mas[i].GetKey() == _key)
      return mas[i];
  return not_found;
}

template <class T>
T TViewTable<T>::operator [] (string _key)
{
  TElem<T>& tmp = Search(_key);
  if (tmp == not_found)
  {
    if (IsFull())
      throw -1;
    else
    {
      TElem<T> B(_key, NULL);
      Put(B);
      count++;
      return mas[count-1].GetData();
    }
  }
  else return tmp.GetData();
}

template <class T>
bool TViewTable<T>::IsFull()
{
  return (size == count);
}

template <class T>
bool TViewTable<T>::IsEmpty()
{
  return (count == 0);
}