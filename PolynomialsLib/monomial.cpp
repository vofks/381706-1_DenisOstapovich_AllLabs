#include "monomial.h"

TMonomial::TMonomial()
{
	next = NULL;
	degree = NULL;
	count = 0;
	coefficient = 0;
}

TMonomial::TMonomial(int _count, int* _degree, double _coefficient)
{
	if (_count < 0)
		throw -1;
	else if (_count == 0)
	{
		next = NULL;
		degree = NULL;
		count = _count;
		coefficient = _coefficient;
	}
	else
	{
		count = _count;
		coefficient = _coefficient;
		next = NULL;
		degree = new int[_count];
		for (int i = 0; i < _count; i++)
		{
			if (_degree[i] >= 0)
				degree[i] = _degree[i];
			else
				throw -1;
		}
	}
}

TMonomial::TMonomial(const TMonomial &A)
{
	count = A.count;
	coefficient = A.coefficient;
	next = A.next;
	degree = new int[count];
	for (int i = 0; i < count; i++)
		degree[i] = A.degree[i];
}

TMonomial::~TMonomial()
{
	if (degree != 0)
		delete[] degree;
	degree = NULL;
}

TMonomial* TMonomial::GetNext()
{
	return next;
}

int* TMonomial::GetDegree()
{
	return degree;
}

double TMonomial::GetCoefficient()
{
	return coefficient;
}

int TMonomial::GetCount()
{
	return count;
}

void TMonomial::SetNext(TMonomial* _next)
{
	next = _next;
}

void TMonomial::SetDegree(int* _degree)
{
	for (int i = 0; i < count; i++)
	{
		if (_degree[i] >= 0)
			degree[i] = _degree[i];
		else
			throw -1;
	}
}

void TMonomial::SetCoefficient(double _cofficient)
{
	coefficient = _cofficient;
}

void TMonomial::SetCount(int _count)
{
	if (_count < 0)
		throw -1;
	else if (_count == 0)
	{
		if (degree != 0)
			delete[] degree;
		degree = NULL;
		count = 0;
	}
	else
	{
		int *tmp = new int[count];
		for (int i = 0; i < count; i++)
			tmp[i] = degree[i];
		delete[] degree;
		degree = new int[_count];
		int i = 0;
		if (count < _count)
		{
			for (; i < count; i++)
				degree[i] = tmp[i];
			for (; i < _count; i++)
				degree[i] = 0;
		}
		if (_count < count)
			for (; i < _count; i++)
				degree[i] = tmp[i];
		count = _count;
	}
}

TMonomial& TMonomial::operator=(const TMonomial &A)
{
	if (count != A.count)
		throw -1;
	coefficient = A.coefficient;
	count = A.count;
	next = A.next;
	delete[] degree;
	degree = new int[count];
	for (int i = 0; i < count; i++)
		degree[i] = A.degree[i];
	return *this;
}

TMonomial TMonomial::operator+(TMonomial &A)
{
	TMonomial tmp(A);
	if (count != A.count)
		throw -1;
	if (!(*this == A))
		throw -1;
	tmp.coefficient = coefficient + A.coefficient;
	return tmp;
}

TMonomial TMonomial::operator+=(TMonomial &A)
{
	if (count != A.count)
		throw -1;
	if (!(*this == A))
		throw -1;
	coefficient += A.coefficient;
	return *this;
}

TMonomial TMonomial::operator*(const TMonomial &A) const
{
	if (count != A.count)
		throw -1;
	TMonomial tmp(A);
	tmp.coefficient = coefficient * A.coefficient;
	for (int i = 0; i < count; i++)
		tmp.degree[i] = degree[i] + A.degree[i];
	return tmp;
}

TMonomial TMonomial::operator*=(TMonomial &A)
{
	if (count != A.count)
		throw -1;
	coefficient = coefficient * A.coefficient;
	for (int i = 0; i < count; i++)
		degree[i] += A.degree[i];
	return *this;
}

TMonomial TMonomial::operator-(TMonomial &A)
{
	TMonomial tmp(A);
	if (count != A.count)
		throw -1;
	if (!(*this == A))
		throw -1;
	tmp.coefficient = coefficient - A.coefficient;
	return tmp;
}

TMonomial TMonomial::operator-=(TMonomial &A)
{
	if (count != A.count)
		throw -1;
	if (!(*this == A))
		throw -1;
	coefficient -= A.coefficient;
	return *this;
}

bool TMonomial::operator==(TMonomial &A)
{
	if (count != A.count)
		throw -1;
	for (int i = 0; i < count; i++)
		if (degree[i] != A.degree[i])
			return false;
	return true;
}

bool TMonomial::operator>(TMonomial &A)
{
	if (count != A.count)
		throw -1;
	if (*this == A)
		throw -1;
	for (int i = 0; i < count; i++)
	{
		if (degree[i] == A.degree[i])
			continue;
		else if (degree[i] > A.degree[i])
			return true;
		else
			return false;
	}
	return true;
}

bool TMonomial::operator<(TMonomial &A)
{
	if (count != A.count)
		throw -1;
	if (*this == A)
		throw -1;
	for (int i = 0; i < count; i++)
	{
		if (degree[i] == A.degree[i])
			continue;
		else if (degree[i] < A.degree[i])
			return true;
		else
			return false;
	}
	if (coefficient > A.coefficient)
		return false;
	return true;
}

std::istream& operator>>(std::istream &istr, TMonomial &A)
{
	istr >> A.coefficient;
	for (int i = 0; i < A.count; i++)
		istr >> A.degree[i];
	return istr;
}

std::ostream& operator<<(std::ostream &ostr, TMonomial &A)
{
	ostr << A.coefficient;
	if (A.coefficient != 0)
		for (int i = 0; i < A.count; i++)
			if (A.degree[i] != 0)
			{
				ostr << "*x" << i;
				if (A.degree[i] != 1)
					ostr << "^" << A.degree[i];
			}
	return ostr;
}