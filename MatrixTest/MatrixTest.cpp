#include <gtest.h>
#include <matrix.h>

TEST(Matrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(TMatrix<int> matrix(5));
}

TEST(Matrix, throw_when_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<TVector<int> >matrix(-5));
}

TEST(Matrix, can_create_copied_matrix)
{
	TMatrix<int> matrix1(5);
	ASSERT_NO_THROW(TMatrix<int> matrix2(matrix1));
}

TEST(Matrix, can_compare_matrices)
{
	TMatrix<int> matrix1(5), matrix2(5);
	for(int i=0;i<matrix1.GetSize();i++)
		for (int j = 0; j < matrix1.GetSize()-i; j++)
		{
			matrix1[i][j] = j;
			matrix2[i][j] = j;
		}
		ASSERT_TRUE(matrix1 == matrix2);
}

TEST(Matrix, can_compare_matrices_with_one_size_false)
{
	TMatrix<int> matrix1(5), matrix2(5);
	for (int i = 0; i < matrix1.GetSize(); i++)
		for (int j = 0; j < matrix1.GetSize() - i; j++)
		{
			matrix1[i][j] = i;
			matrix2[i][j] = j;
		}
		ASSERT_FALSE(matrix1 == matrix2);
}

TEST(Matrix, can_compare_compare_matrices_with_different_size_false)
{
	TMatrix<int> matrix1(5), matrix2(6);
	ASSERT_FALSE(matrix1 == matrix2);
}

TEST(Matrix, can_assign_matrix)
{
	TMatrix<int> matrix1(5), matrix2(6);
	matrix1 = matrix2;
	ASSERT_TRUE(matrix1 == matrix2);
}

TEST(Matrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> matrix1(5), matrix2(5),tmp(5);
	for (int i = 0; i < matrix1.GetSize(); i++)
		for(int j=0; j < matrix1.GetSize()-i; j++)
		{
			matrix1[i][j] = i;
			matrix2[i][j] = j;
			tmp[i][j] = i + j;
		}
		ASSERT_TRUE(tmp == (matrix1 + matrix2));
}

TEST(Matrix, throw_when_add_matrices_with_different_size)
{
	TMatrix<int> matrix1(5), matrix2(6);
	ASSERT_ANY_THROW(matrix1 + matrix2);
}

TEST(Matrix, can_substract_matrices_with_equal_size)
{
	TMatrix<int> matrix1(5), matrix2(5), tmp(5);
	for (int i = 0; i < matrix1.GetSize(); i++)
		for (int j = 0; j < matrix1.GetSize() - i; j++)
		{
			matrix1[i][j] = i;
			matrix2[i][j] = j;
			tmp[i][j] = i - j;
		}
		ASSERT_TRUE(tmp == (matrix1 - matrix2));
}

TEST(Matrix, throw_when_substract_matrices_with_different_size)
{
	TMatrix<int> matrix1(5), matrix2(6);
	ASSERT_ANY_THROW(matrix1 - matrix2);
}

TEST(Matrix, can_multiply_matrices_with_equal_size)
{
	TMatrix<int> matrix1(3), matrix2(3), tmp(3);
	for (int i = 0; i < matrix1.GetSize(); i++)
		for (int j = 0; j < matrix1.GetSize() - i; j++)
		{
			matrix1[i][j] = i;
			matrix2[i][j] = j;
		}
		tmp[0][0] = 0;
		tmp[0][1] = 0;
		tmp[0][2] = 0;
		tmp[1][0] = 0;
		tmp[1][1] = 1;
		tmp[2][0] = 0;
		ASSERT_TRUE(tmp == (matrix1 * matrix2));
}

TEST(Matrix, throw_when_multiply_matrices_with_different_size)
{
	TMatrix<int> matrix1(5), matrix2(6);
	ASSERT_ANY_THROW(matrix1 * matrix2);
}

TEST(Matrix, can_divide_matrices_with_equal_size)
{
	TMatrix<double> matrix1(3), matrix2(3), tmp(3);
	for (int i = 0; i < matrix1.GetSize(); i++)
		for (int j = 0; j < matrix1.GetSize() - i; j++)
		{
			matrix1[i][j] = double(i) + 1.0;
			matrix2[i][j] = double(j) + 2.0;
		}
		tmp[0][0] = 0.5;
		tmp[0][1] = -0.25;
		tmp[0][2] = -0.125;
		tmp[1][0] = 1;
		tmp[1][1] = -0.5;
		tmp[2][0] = 1.5;
		ASSERT_TRUE(tmp == (matrix1 / matrix2));
}

TEST(Matrix, throw_when_divide_matrices_with_different_size)
{
	TMatrix<int> matrix1(5), matrix2(6);
	ASSERT_ANY_THROW(matrix1 / matrix2);
}