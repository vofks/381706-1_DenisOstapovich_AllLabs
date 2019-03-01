#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
  TVector<int> vector1(3), vector2(3), vector3(8);
  
	for (int i = 0; i < vector1.GetSize(); i++)
	{
		vector1[i] = i;
		vector2[i] = i + 2;
	}

	cout << vector1 << "\n";
	cout << vector2 << "\n";
	
	for (int i = 0; i < vector1.GetSize(); i++)
	{
		cout << "vector2[" << i << "] = " << vector2[i] << "\n";
	} 

	cout << "Скалярные операции: \n";
	vector1 = vector1 + 5;
	cout << "vector1 + 5 = " << vector1 << "\n";
	/*cout << "vector1 - 5 = " << (vector1 - 5) << "\n";
	cout << "vector1 * 5 = " << (vector1 * 5) << "\n";

	cout << "Векторные операции: \n";
	cout << "vector1 + vector2 = " << (vector1 + vector2) << "\n";
	cout << "vector1 - vector2 = " << (vector1 - vector2) << "\n";
	cout << "vector1 * vector2 = " << (vector1 + vector2) << "\n";

	cout << "Результат сравнения vector1 и vector2: " << (vector1 == vector2) << "\n";*/
}