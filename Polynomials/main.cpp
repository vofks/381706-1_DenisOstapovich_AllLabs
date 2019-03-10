#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int dgr1[] = { 1,2,3,4 };
	int dgr2[] = { 5,6,7,8 };
	int dgr3[] = { 6,0,5,9 };
	
	TMonomial monom1(4, dgr1, 3.5);
	TMonomial monom2(4, dgr2, 2.3);
	TMonomial monom3(4, dgr3, 5.6);
	TPolynomial poly1(4);
	TPolynomial poly2(4);
	TPolynomial resultPoly(4);
	
	cout << "�������� ���������� ������: \n";
	cout << "����� 1: " << monom1 << "\n";
	cout << "����� 2: " << monom2 << "\n";
	cout << "����� 3: " << monom3 << "\n";	

	poly1 += monom1;
	poly1 += monom2;
	poly2 += monom2;
	poly2 += monom3;

	cout << "������� 1 = ����� 1 + ����� 2: " << poly1 << "\n";
	cout << "������� 2 = ����� 2 + ����� 3: " << poly2 << "\n";	
	
	resultPoly = poly1 + poly2;
	cout << "������� 1 + ������� 2 = " << resultPoly << "\n";
	
	resultPoly = poly1 - poly2;
	cout << "������� 1 - ������� 2 = " << resultPoly << "\n";
	
	resultPoly = poly1 * poly2;
	cout << "������� 1 * ������� 2 = " << resultPoly << "\n";

	return 0;
}