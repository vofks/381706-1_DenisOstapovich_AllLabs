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
	
	cout << "Операции потокового вывода: \n";
	cout << "Моном 1: " << monom1 << "\n";
	cout << "Моном 2: " << monom2 << "\n";
	cout << "Моном 3: " << monom3 << "\n";	

	poly1 += monom1;
	poly1 += monom2;
	poly2 += monom2;
	poly2 += monom3;

	cout << "Полином 1 = Моном 1 + Моном 2: " << poly1 << "\n";
	cout << "Полином 2 = Моном 2 + Моном 3: " << poly2 << "\n";	
	
	resultPoly = poly1 + poly2;
	cout << "Полином 1 + Полином 2 = " << resultPoly << "\n";
	
	resultPoly = poly1 - poly2;
	cout << "Полином 1 - Полином 2 = " << resultPoly << "\n";
	
	resultPoly = poly1 * poly2;
	cout << "Полином 1 * Полином 2 = " << resultPoly << "\n";

	return 0;
}