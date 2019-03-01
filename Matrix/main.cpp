#include <iostream>
#include "matrix.h"
#include <time.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

  TMatrix<double>  matrix1(6), matrix2(6), resultMatrix(6);
  for(int i=0;i<6;i++)
    for (int j = 0; j < 6 - i; j++)
    {
      matrix1[i][j] = double(i) + 1.0;
      matrix2[i][j] = double(i) + 6.0;
    }
  std::cout << "������ �������: \n" << matrix1 << "\n";
  std::cout << "������ �������: \n" << matrix2 << "\n";
  std::cout << "��������� ��������\n";

	resultMatrix = matrix1 + matrix2;
	std::cout << "matrix1 + matrix2: \n" << resultMatrix << "\n";
	resultMatrix = matrix1 - matrix2;
	std::cout << "matrix1 - matrix2: \n" << resultMatrix << "\n";
	resultMatrix = matrix1 * matrix2;
	std::cout << "matrix1 * matrix2: \n" << resultMatrix << "\n";
	resultMatrix = matrix1 / matrix2;
	std::cout << "matrix1 / matrix2: \n" << resultMatrix << "\n";
	 
  TVector<int> matrixInput(3);
  std::cout << "������� ������� ������� 3: \n";
  std::cin >> matrixInput;
  std::cout << "\n �������� �������: \n" << matrixInput << "\n";

  return 0;  
}