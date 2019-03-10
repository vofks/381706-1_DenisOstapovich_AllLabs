#pragma once
#include "monomial.h"
#include <iostream>

class TPolynomial
{
protected:
	TMonomial* start;
	int size;
	int count;
public:
	TPolynomial(int _count = 3);
	TPolynomial(TPolynomial &A);
	int GetSize();
	TMonomial* GetStart();
	TPolynomial operator+(TPolynomial &A);
	TPolynomial operator-(TPolynomial &A);
	TPolynomial& operator=(const TPolynomial &A);
	bool operator==(const TPolynomial &A);
	TPolynomial operator*(TPolynomial &A);
	TPolynomial& operator+=(TMonomial &A);
	TPolynomial& operator-=(TMonomial &A);
	friend std::ostream& operator<<(std::ostream& ostr, TPolynomial& A);
};