#include "polynomial.h"

TPolynomial::TPolynomial(int _count)
{
	if (_count <= 0)
		throw -1;
	count = _count;
	size = 0;
	start = NULL;
}

TPolynomial::TPolynomial(TPolynomial &A)
{
	count = A.count;
	size = A.size;
	if (A.start == 0)
		start = NULL;
	else
	{
		start = new TMonomial(*A.start);
		TMonomial* tmp1 = A.start;
		TMonomial* tmp2 = start;
		while (tmp1->GetNext() != 0)
		{
			tmp2->SetNext(new TMonomial(*(tmp1->GetNext())));
			tmp2 = tmp2->GetNext();
			tmp1 = tmp1->GetNext();
		}
		tmp2->SetNext(NULL);
	}
}

int TPolynomial::GetSize()
{
	return size;
}

TMonomial* TPolynomial::GetStart()
{
	return start;
}

TPolynomial TPolynomial::operator-(TPolynomial &A)
{
	if (this->count != A.count)
		throw -1;
	TPolynomial rez(count);
	TMonomial* tmp1 = start;
	TMonomial* tmp2 = A.start;
	TMonomial *tmp = rez.start;
	while ((tmp1 != 0) && (tmp2 != 0))
	{
		TMonomial *t;
		if ((*tmp1) == (*tmp2))
		{
			TMonomial k = (*tmp1);
			k -= (*tmp2);
			t = new TMonomial(k);
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) < (*tmp2))
		{
			t = new TMonomial((*tmp2));
			if (t->GetCoefficient() == 0)
				continue;
			t->SetCoefficient(t->GetCoefficient() * (-1));
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) > (*tmp2))
		{
			t = new TMonomial((*tmp1));
			if (t->GetCoefficient() == 0)
				continue;
			tmp1 = tmp1->GetNext();
		}
		if (t->GetCoefficient() == 0)
			continue;
		if (tmp == 0)
		{
			tmp = t;
			rez.start = t;
			rez.size++;
		}
		else
		{
			tmp->SetNext(t);
			rez.size++;
			tmp = tmp->GetNext();
		}
	}
	while (tmp1 != 0)
	{
		if (tmp1->GetCoefficient() == 0)
			continue;
		tmp->SetNext(new TMonomial(*tmp1));
		tmp1 = tmp1->GetNext();
		rez.size++;
		tmp = tmp->GetNext();
	}
	while (tmp2 != 0)
	{
		if (tmp2->GetCoefficient() == 0)
			continue;
		TMonomial t(*tmp2);
		t.SetCoefficient(t.GetCoefficient() * (-1));
		tmp->SetNext(&t);
		tmp2 = tmp2->GetNext();
		rez.size++;
		tmp = tmp->GetNext();
	}
	return rez;
}

TPolynomial TPolynomial::operator+(TPolynomial &A)
{
	if (this->count != A.count)
		throw -1;
	TPolynomial rez(count);
	TMonomial* tmp1 = start;
	TMonomial* tmp2 = A.start;
	TMonomial *tmp = rez.start;
	while ((tmp1 != 0) && (tmp2 != 0))
	{
		TMonomial *t;
		if ((*tmp1) == (*tmp2))
		{
			TMonomial k = (*tmp1);
			k += (*tmp2);
			t = new TMonomial(k);
			if (t->GetCoefficient() == 0)
				continue;
			tmp1 = tmp1->GetNext();
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) < (*tmp2))
		{
			t = new TMonomial((*tmp2));
			if (t->GetCoefficient() == 0)
				continue;
			tmp2 = tmp2->GetNext();
		}
		else if ((*tmp1) > (*tmp2))
		{
			t = new TMonomial((*tmp1));
			if (t->GetCoefficient() == 0)
				continue;
			tmp1 = tmp1->GetNext();
		}
		if (tmp == 0)
		{
			tmp = t;
			rez.start = t;
			rez.size++;
		}
		else
		{
			tmp->SetNext(t);
			rez.size++;
			tmp = tmp->GetNext();
		}
	}
	if (tmp1 == 0)
		tmp1 = tmp2;
	while (tmp1 != 0)
	{
		if (tmp1->GetCoefficient() == 0)
			continue;
		tmp->SetNext(new TMonomial(*tmp1));
		tmp1 = tmp1->GetNext();
		rez.size++;
		tmp = tmp->GetNext();
	}
	return rez;
}

TPolynomial& TPolynomial::operator=(const TPolynomial &A)
{
	if (*this == A)
		return *this;
	if (this->count != A.count)
		throw -1;
	else
	{
		size = A.size;
		TMonomial* tmp1 = start;
		TMonomial* tmp2 = start;
		while (tmp1 != 0)
		{
			tmp1 = tmp1->GetNext();
			delete tmp2;
			tmp2 = tmp1;
		}
		tmp1 = A.start->GetNext();
		tmp2 = new TMonomial(*A.start);
		start = tmp2;
		while (tmp1 != 0)
		{
			tmp2->SetNext(new TMonomial(*tmp1));
			tmp2 = tmp2->GetNext();
			tmp1 = tmp1->GetNext();
		}
		return *this;
	}
}

bool TPolynomial::operator==(const TPolynomial &A)
{
	if (this->count != A.count)
		throw -1;
	if (this->size != A.size)
		return false;
	TMonomial* tmp1 = start;
	TMonomial* tmp2 = A.start;
	while (tmp1 != 0)
	{
		if (!(*tmp1 == *tmp2))
			return false;
		if (tmp1->GetCoefficient() != tmp2->GetCoefficient())
			return false;
		tmp1 = tmp1->GetNext();
		tmp2 = tmp2->GetNext();
	}
	return true;
}

TPolynomial TPolynomial::operator*(TPolynomial &A)
{
	if (this->count != A.count)
		throw -1;
	TPolynomial rez(count);
	TMonomial* tmp1 = start;
	TMonomial* tmp2 = A.start;
	while (tmp1 != 0)
	{
		if (tmp1->GetCoefficient() == 0)
			continue;
		while (tmp2 != 0)
		{
			if (tmp2->GetCoefficient() == 0)
				continue;
			TMonomial tmp = (*tmp1);
			tmp *= (*tmp2);
			TMonomial* f = new TMonomial(tmp);
			f->SetNext(NULL);
			rez += *f;
			tmp2 = tmp2->GetNext();
		}
		tmp1 = tmp1->GetNext();
		tmp2 = A.start;
	}
	return rez;
}

TPolynomial& TPolynomial::operator+=(TMonomial &A)
{
	if (this->count != A.GetCount())
		throw -1;
	if (A.GetCoefficient() == 0)
		return *this;
	if (start == 0)
		start = new TMonomial(A);
	else
	{
		TMonomial* tmp1;
		TMonomial* tmp2;
		tmp1 = start;
		tmp2 = start->GetNext();
		if (*start < A)
		{
			TMonomial* tmp = new TMonomial(A);
			tmp->SetNext(start);
			start = tmp;
		}
		else if (*start == A)
		{
			*start += A;
			if (start->GetCoefficient() == 0)
			{
				TMonomial* temp = start->GetNext();
				delete[] start;
				start = temp;
			}
		}
		else
		{
			while (tmp2 != 0)
			{
				if (*tmp2 == A)
				{
					*tmp2 += A;
					if (tmp2->GetCoefficient() == 0)
					{
						start->SetNext(tmp2->GetNext());
						delete[] tmp2;
					}
					return *this;
				}
				if (*tmp2 < A)
				{
					TMonomial* tmp = new TMonomial(A);
					tmp1->SetNext(tmp);
					tmp->SetNext(tmp2);
					size++;
					return *this;
				}
				tmp1 = tmp2;
				tmp2 = tmp2->GetNext();
			}
			tmp1->SetNext(new TMonomial(A));
		}
	}
	size++;
	return *this;
}

TPolynomial& TPolynomial::operator-=(TMonomial &A)
{
	if (this->count != A.GetCount())
		throw -1;
	if (A.GetCoefficient() == 0)
		return *this;
	A.SetCoefficient(A.GetCoefficient() * (-1));
	if (start == 0)
		start = new TMonomial(A);
	else
	{
		TMonomial* tmp1;
		TMonomial* tmp2;
		tmp1 = start;
		tmp2 = start->GetNext();
		if (*start < A)
		{
			TMonomial* tmp = new TMonomial(A);
			tmp->SetNext(start);
			start = tmp;
		}
		else if (*start == A)
		{
			*start -= A;
			if (start->GetCoefficient() == 0)
			{
				TMonomial* temp = start->GetNext();
				delete[] start;
				start = temp;
			}
		}
		else
		{
			while (tmp2 != 0)
			{
				if (*tmp2 == A)
				{
					*tmp2 -= A;
					if (tmp2->GetCoefficient() == 0)
					{
						start->SetNext(tmp2->GetNext());
						delete[] tmp2;
					}
					size++;
					return *this;
				}
				if (*tmp2 < A)
				{
					TMonomial* tmp = new TMonomial(A);
					tmp1->SetNext(tmp);
					tmp->SetNext(tmp2);
					size++;
					return *this;
				}
				tmp1 = tmp2;
				tmp2 = tmp2->GetNext();
			}
			tmp1->SetNext(new TMonomial(A));
		}
	}
	size++;
	return *this;
}

std::ostream& operator<<(std::ostream& ostr, TPolynomial& A)
{
	TMonomial *tmp = A.start;
	if (tmp != 0)
	{
		ostr << *tmp;
		tmp = tmp->GetNext();
	}
	while (tmp != 0)
	{
		if (tmp->GetCoefficient() != 0)
			ostr << " + " << *tmp;
		tmp = tmp->GetNext();
	}
	return ostr;
}