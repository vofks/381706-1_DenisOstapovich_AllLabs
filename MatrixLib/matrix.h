#pragma once
#include <iostream>
#include "vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
	TMatrix(int _size = 5);
	TMatrix(const TMatrix<T> &A);
	TMatrix(const TVector<TVector<T> > &A);
	bool operator==(const TMatrix<T> &A);
	TMatrix<T>& operator=(const TMatrix<T> &A);
	TMatrix<T> operator+(const TMatrix<T> &A);
	TMatrix<T> operator-(const TMatrix<T> &A);
	TMatrix<T> operator*(const TMatrix<T> &A);
	TMatrix<T> operator/(TMatrix<T> &A);

	template <class T1>
	friend std::istream& operator >> (std::istream &istr, TMatrix<T1> &matrix);

	template <class T1>
	friend std::ostream& operator << (std::ostream &ostr, TMatrix<T1> &matrix);
};

template <class T>
TMatrix<T>::TMatrix(int _size) : TVector<TVector<T> > (_size)
{
	if (_size <= 0)
		throw -1;
	else
		for (int i = 0; i < _size; i++)
			this->vector[i] = TVector<T>(_size - i);
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &A) : TVector<TVector<T> >(A) {}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &A) : TVector<TVector<T> >(A) {}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &A)
{
	return TVector<TVector<T> >::operator==(A);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &A)
{
	TVector<TVector<T> >::operator=(A);
	return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &A)
{
	if (this->size != A.size)
		throw -1;
	else
		return TVector<TVector<T> >::operator+(A);

}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &A)
{
	if (this->size != A.size)
		throw -1;
	else
		return TVector<TVector<T> >::operator-(A);
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &A)
{
	if (this->size != A.size)
		throw -1;
	else
	{
		TMatrix<T> res(this->size);
		for (int i = 0; i < this->size; i++)
			for (int j = i; j < this->size; j++)
				for (int k = i; k <= j; k++)
					res.vector[i][j - i] += this->vector[i][k - i] * A.vector[k][j - k];
		return res;
	}
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T> &A)
{
	if (this->size != A.size)
		throw -1;
	double determinant = 1;
	for (int i = 0; i < this->size; i++)
		determinant = determinant*this->vector[i][0];
	if (determinant == 0)
		throw -1;
	TMatrix<T> copyMat(A);
	TMatrix<T> res(this->size);
	TMatrix<T> copy(*this);
	for (int i = 0; i < this->size; i++)
	{
		res[i][0] = 1;
		T diag = copyMat[i][0];
		for (int j = 0; j < (this->size - i); j++)
		{
			copyMat[i][j] = copyMat[i][j]/diag;
			res[i][j] = res[i][j]/diag;
		}
	}
	for (int i = 1; i < this->size; i++)
		for (int j = 0; j < i; j++)
		{
			T tmp = copyMat[j][i - j];
			for (int k = i - j, l = 0; k < (this->size - j); k++)
			{
				copyMat[j][k] = copyMat[j][k] - copyMat[i][l] * tmp;
				res[j][k] = res[j][k] - res[i][l++] * tmp;
			}
		}
		res = copy * res;
		return res;
}

template <class T1>
std::istream& operator >> (std::istream &istr, TMatrix<T1> &matrix)
{
	for (int i = 0; i < matrix.size; i++)
		istr >> matrix.vector[i];
	return istr;
}

template <class T1>
std::ostream& operator << (std::ostream &ostr, TMatrix<T1> &matrix)
{
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 1; j <= i; j++)
			ostr << " ";
		ostr << matrix.vector[i];
		ostr << "\n";
	}
	return ostr;
}