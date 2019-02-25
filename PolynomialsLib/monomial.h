#pragma once
#include <iostream>

class TMonomial
{
protected:
	TMonomial* next;
	int* degree; // массив степеней
	int count; // число переменных
	double coefficient; // коэффициент
public:
	TMonomial();
	TMonomial(int _count, int* _degree, double _coefficient);
	TMonomial(const TMonomial &A);
	~TMonomial();
	TMonomial* GetNext();
	int* GetDegree();
	double GetCoefficient();
	int GetCount();
	void SetNext(TMonomial* _next);
	void SetDegree(int* _degree);
	void SetCoefficient(double _cofficient);
	void SetCount(int _count);
	TMonomial& operator=(const TMonomial &A);
	TMonomial operator+(TMonomial &A);
	TMonomial operator+=(TMonomial &A);
	TMonomial operator*(const TMonomial &A) const;
	TMonomial operator*=(TMonomial &A);
	TMonomial operator-(TMonomial &A);
	TMonomial operator-=(TMonomial &A);
	bool operator==(TMonomial &A);
	bool operator>(TMonomial &A);
	bool operator<(TMonomial &A);
	friend std::istream& operator>>(std::istream &istr, TMonomial &A);
	friend std::ostream& operator<<(std::ostream &ostr, TMonomial &A);
};