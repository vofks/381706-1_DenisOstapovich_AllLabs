#include "mystring.h"

TMyString::TMyString()
{
	length = 0;
	str = 0;
}

TMyString::TMyString(char* _str)
{
	if (_str == 0)
		throw -1;
	else
	{
		char tmp = 1;
		int size = 0;
		while (tmp != '\0')
		{
			size++;
			tmp = _str[size];
		}
		length = size + 1;
		str = new char[length];
		for (int i = 0; i < length - 1; i++)
			str[i] = _str[i];
		str[length - 1] = '\0';
	}
}

TMyString::TMyString(TMyString &A)
{
	length = A.length;
	if (length != 0)
	{
		str = new char[length];
		for (int i = 0; i < length; i++)
			str[i] = A.str[i];
	}
	else
		str = 0;
}

TMyString::~TMyString()
{
	if (str != 0)
		delete[] str;
	str = NULL;
}

int TMyString::GetLength()
{
	return length;
}

void TMyString::DeleteStr()
{
	if (str != 0)
		delete[] str;
	str = NULL;
}

TMyString TMyString::operator+(TMyString &A)
{
	TMyString rez;
	rez.length = length + A.length - 1;
	rez.str = new char[rez.length];
	for (int i = 0; i < length; i++)
		rez.str[i] = str[i];
	for (int i = length - 1; i < rez.length; i++)
		rez.str[i] = A.str[i - length + 1];
	return rez;
}

TMyString& TMyString::operator=(TMyString &A)
{
	if (this != &A)
	{
		length = A.length;
		if (length != 0)
		{
			if (str != 0)
				delete[] str;
			str = new char[length];
			for (int i = 0; i < length; i++)
				str[i] = A.str[i];
		}
		else
		{
			if (str != 0)
				delete[] str;
			str = NULL;
		}
	}
	return *this;
}

char& TMyString::operator[](int _index)
{
	if (_index < 0 || _index >= length)
		throw -1;
	return str[_index];
}

std::istream& operator>>(std::istream &istr, TMyString &A)
{
	char buf[256];
	for (int i = 0; i < 256; i++)
		buf[i] = 0;
	istr >> buf;
	char tmp = 1;
	int size = 0;
	while (tmp != '\0')
	{
		size++;
		tmp = buf[size];
	}
	A.length = size + 1;
	A.str = new char[A.length];
	for (int i = 0; i < A.length - 1; i++)
		A.str[i] = buf[i];
	A.str[A.length - 1] = '\0';
	return istr;
}

std::ostream& operator<<(std::ostream &ostr, const TMyString &A)
{
	ostr << A.str;
	return ostr;
}
