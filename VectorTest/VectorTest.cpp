#include <gtest.h>
#include <vector.h>

TEST(Vector, can_create_vector_with_positive_size)
{
  ASSERT_NO_THROW(TVector<int> vector);
}

TEST(Vector, throw_when_negative_size)
{
  ASSERT_ANY_THROW(TVector<int> vector(-10));
}

TEST(Vector, can_copy_vector)
{
  TVector<int> vector1(10);
  ASSERT_NO_THROW(TVector<int> vector2(vector1));
}

TEST(Vector, can_get_size)
{
  TVector<int> vector(10);
  EXPECT_EQ(10, vector.GetSize());
}

TEST(Vector, throw_when_negative_index)
{
  TVector<int> vector(10);
  ASSERT_ANY_THROW(vector[-1]);
}

TEST(Vector, throw_when_index_equal_size)
{
  TVector<int> vector(10);
  ASSERT_ANY_THROW(vector[10]);
}

TEST(Vector, throw_when__index_larger_than_size)
{
  TVector<int> vector(10);
  ASSERT_ANY_THROW(vector[11]);
}

TEST(Vector, can_write_and_return_element_via_index)
{
  TVector<int> vector(3);
  vector[0] = 0;
  int tmp = vector[0] + 2;
  EXPECT_EQ(2, tmp);
}

TEST(Vector, can_compare)
{
  TVector<int> vector1(10), vector2(10);
  for (int i = 0; i < vector1.GetSize(); i++)
  {
    vector1[i] = i;
    vector2[i] = i;
  }
  ASSERT_TRUE(vector1 == vector2);
}

TEST(Vector, can_compare_vectors_same_size)
{
  TVector<int> vector1(5), vector2(5);
  for (int i = 0; i < vector1.GetSize(); i++)
  {
    vector1[i] = i;
    vector2[i] = i+2;
  }
  ASSERT_FALSE(vector1 == vector2);
}

TEST(Vector, can_compare_vectors_with_different_size)
{
  TVector<int> vector1(10), vector2(11);
  ASSERT_FALSE(vector1 == vector2);
}

TEST(Vector, can_assign_vector)
{
  TVector<int> vector1(10), vector2(11);
  vector1 = vector2;
  ASSERT_TRUE(vector1 == vector2);
}

TEST(Vector, can_add_scalar_to_vector)
{
  TVector<int> vector(10);
  vector = vector +5;
  EXPECT_EQ(5, vector[6]);
  EXPECT_EQ(5, vector[8]);
  EXPECT_NE(9, vector[0]);
}

TEST(Vector, can_subtract_scalar)
{
  TVector<int> vector(10);
  vector = vector - 5;
  EXPECT_EQ(-5, vector[6]);
  EXPECT_EQ(-5, vector[8]);
  EXPECT_NE(0, vector[0]);
}

TEST(Vector, can_multiply_vector_on_scalar)
{
  TVector<int> vector(10);
  for (int i = 0; i < vector.GetSize(); i++)
    vector[i] = i;
  vector = vector * 2;
  EXPECT_EQ(12, vector[6]);
  EXPECT_EQ(16, vector[8]);
  EXPECT_NE(1, vector[0]);
}

TEST(Vector, can_add_two_vector_with_equal_size)
{
  TVector<int> vector1(3), vector2(3), tmp(3);
  for (int i = 0; i < vector1.GetSize(); i++)
  {
    vector1[i] = i;
    vector2[i] = vector2.GetSize() - i;
  }
  tmp = vector1 + vector2;
  ASSERT_TRUE(tmp == (vector1+ vector2));
}

TEST(Vector, throw_when_add_two_vectors_with_defferent_size)
{
  TVector<int> vector1(3), vector2(4);
  ASSERT_ANY_THROW(vector1 + vector2);
}

TEST(Vector, can_substract_two_vector_with_equal_size)
{
  TVector<int> vector1(3), vector2(3), tmp(3);
  for (int i = 0; i < vector1.GetSize(); i++)
  {
    vector1[i] = i;
    vector2[i] = vector2.GetSize() - i;
  }
  tmp = vector2 - vector1;
  ASSERT_TRUE(tmp == (vector2- vector1));
}

TEST(Vector, throw_when_substract_two_vectors_with_defferent_size)
{
  TVector<int> vector1(3), vector2(4);
  ASSERT_ANY_THROW(vector1 - vector2);
}

TEST(Vector, can_multiply_two_vector_with_equal_size)
{
  TVector<int> vector1(3), vector2(3);
  int tmp;
  for (int i = 0; i < vector1.GetSize(); i++)
  {
    vector1[i] = i;
    vector2[i] = vector2.GetSize() - i;
  }
  tmp = vector2 * vector1;
  EXPECT_EQ(4, tmp);
}

TEST(Vector, throw_when_multiply_two_vectors_with_defferent_size)
{
  TVector<int> vector1(3), vector2(4);
  ASSERT_ANY_THROW(vector1 * vector2);
}