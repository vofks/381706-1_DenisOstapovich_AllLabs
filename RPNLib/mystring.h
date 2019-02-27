#pragma once
#include <iostream>

class TMyString
{
protected:
	char* str;
	int length;
public:
	TMyString();
	TMyString(char* _str);
	TMyString(TMyString &A);
	~TMyString();
	int GetLength();
	void DeleteStr();
	TMyString operator+(TMyString &A);
	TMyString& operator=(TMyString &A);
	char& operator[](int _index);
	friend std::istream& operator>>(std::istream &istr, TMyString &A);
	friend std::ostream& operator<<(std::ostream &ostr, const TMyString &A);
};


