#pragma once
#include <iostream>

template <class T>
class TVector
{
protected:
	T* vector;
	int size;
public:
	TVector(int _size = 5);
	TVector(const TVector<T> &A);
	~TVector();
	int GetSize();
	T& operator[] (int index);
	bool operator==(const TVector<T> &A);
	TVector<T>& operator=(const TVector<T> &A);

	TVector<T> operator+(const T &num);
	TVector<T> operator-(const T &num);
	TVector<T> operator*(const T &num);

	TVector<T> operator+(const TVector<T> &A);
	TVector<T> operator-(const TVector<T> &A);
	T operator*(const TVector<T> &A);

	template <class T1>
	friend std::istream& operator >> (std::istream &istr, TVector<T1> &vecctor);

	template <class T1>
	friend std::ostream& operator << (std::ostream &ostr, TVector<T1> &vector);
}; 

template <class T>
TVector<T>::TVector(int _size)
{
	if (_size >= 0)
	{
		if (_size == 0)
		{
			size = 0;
			vector = NULL;
		}
		else
		{
			size = _size;
			vector = new T[size];
			for (int i = 0; i < size; i++)
			{
				vector[i] = 0;
			}
		}
	}
	else
		throw -1;
}

template <class T>
TVector<T>::TVector(const TVector &A)
{
	size = A.size;
	if (size != 0)
	{
		vector = new T[size];
		for (int i = 0; i < size; i++)
			vector[i] = A.vector[i];
	}
	else
		vector = NULL;
}

template <class T>
TVector<T>::~TVector()
{
	if (vector != 0)
		delete[] vector;
	vector = 0;
}

template <class T>
int TVector<T>::GetSize()
{
	return size;
}

template <class T>
T& TVector<T> ::operator[] (int index)
{
	if (index >= 0 && index < size)
		return vector[index];
	throw -1;
}

template <class T>
bool TVector<T>::operator==(const TVector<T> &A)
{
	if (size != A.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
			if (!(this->vector[i] == A.vector[i]))
				return false;
	}
	return true;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &A)
{
	if (this != &A)
	{
		size = A.size;
		if (size != 0)
		{
			if (vector != 0)
				delete[] vector;
			vector = new T[size];
			for (int i = 0; i < size; i++)
				vector[i] = A.vector[i];
		}
		else
		{
			if (vector != 0)
				delete[]vector;
			vector = 0;
		}
	}
	return *this;
}


template <class T>
TVector<T> TVector<T>::operator+(const T &num)
{
	TVector<T> rez(size);
	if (size == 0)
		vector = 0;
	else
	{
		for (int i = 0; i < size; i++)
			rez.vector[i] =vector[i] + num;
	}
	return rez;
}

template <class T>
TVector<T> TVector<T>::operator-(const T &num)
{
	TVector<T> rez(size);
	if (size == 0)
		vector = 0;
	else
	{
		for (int i = 0; i < size; i++)
			rez.vector[i] = vector[i]-num;
	}
	return rez;
}

template <class T>
TVector<T> TVector<T>::operator*(const T &num)
{
	TVector<T> rez(size);
	if (size == 0)
		vector = 0;
	else
	{
		for (int i = 0; i < size; i++)
			rez.vector[i] = vector[i]*num;
	}
	return rez;
}


template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &A)
{
	TVector<T> rez;
	if (size == A.size)
	{
		if (size == 0)
			rez.vector = 0;
		else
		{
			rez.size = size;
			rez.vector = new T[rez.size];
			for (int i = 0; i < rez.size; i++)
				rez.vector[i] = vector[i] + A.vector[i];
		}
	}
	else
		throw -1;
	return rez;
}

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &A)
{
	TVector<T> rez;
	if (size == A.size)
	{
		if (size == 0)
			rez.vector = 0;
		else
		{
			rez.size = size;
			rez.vector = new T[rez.size];
			for (int i = 0; i < rez.size; i++)
				rez.vector[i] = vector[i] - A.vector[i];
		}
	}
	else
		throw -1;
	return rez;
}

template <class T>
T TVector<T>::operator*(const TVector<T> &A)
{
	T rez=0;
	if (size == A.size)
	{
		if (size == 0)
			rez=0;
		else
		{
			for (int i = 0; i < size; i++)
				rez += (vector[i] * A.vector[i]);
		}
	}
	else
		throw -1;
	return rez;
}

template <class T1>
std::istream& operator >> (std::istream &istr, TVector<T1> &vector)
{
	std::cout << "Enter vector size: ";
	istr >> vector.size;
	vector.vector = new T1[vector.size];

	for (int i = 0; i < vector.size; i++)
	{
		std::cout << "Set vector[" << i << "] = ";
		istr >> vector.vector[i];
	}
	return istr;
}

template <class T1>
std::ostream& operator << (std::ostream &ostr, TVector<T1> &vector)
{
	for (int i = 0; i < vector.size - 1; i++)
		ostr << vector.vector[i] << ",";
	ostr << vector.vector[vector.size - 1];
	return ostr;
}