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
  std::cout << "Первая матрица: \n" << matrix1 << "\n";
  std::cout << "Вторая матрица: \n" << matrix2 << "\n";
  std::cout << "Матричные операции\n";

	resultMatrix = matrix1 + matrix2;
	std::cout << "matrix1 + matrix2: \n" << resultMatrix << "\n";
	resultMatrix = matrix1 - matrix2;
	std::cout << "matrix1 - matrix2: \n" << resultMatrix << "\n";
	resultMatrix = matrix1 * matrix2;
	std::cout << "matrix1 * matrix2: \n" << resultMatrix << "\n";
	resultMatrix = matrix1 / matrix2;
	std::cout << "matrix1 / matrix2: \n" << resultMatrix << "\n";
	 
  TVector<int> matrixInput(3);
  std::cout << "Введите матрицу размера 3: \n";
  std::cin >> matrixInput;
  std::cout << "\n Введённая матрица: \n" << matrixInput << "\n";

  return 0;  
}