#include "gtest.h"
#include "multistack.h"

TEST(TNewStack, throw_when_negative_size)
{
  int *a = NULL;
  ASSERT_ANY_THROW(TNewStack<int> S(-1, a));
}
 
TEST(TNewStack, can_create_stack)
{
  int *a = NULL;
  ASSERT_NO_THROW(TNewStack<int> S(2, a));
}

TEST(TNewStack, can_copy_stack)
{
  int *a = NULL;
  TNewStack<int> S(2, a);
  ASSERT_NO_THROW(TNewStack<int> S1(S));
}

TEST(TNewStack, can_get_free_memory)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Push(3);
  S.Push(2);
  ASSERT_EQ(3, S.GetFreeMemory());
}

TEST(TNewStack, can_get_top)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Push(3);
  S.Push(2);
  ASSERT_EQ(2, S.GetTop());
}

TEST(TNewStack, can_get_size)
{
  int *a = NULL;
  TNewStack<int> S(5, a);
  ASSERT_EQ(5, S.GetSize());
}

TEST(TNewStack, can_set_multistack)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  S.SetMas(10, b);
  ASSERT_EQ(10, S.GetSize());
}

TEST(TNewStack, throw_on_negative_size)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  ASSERT_ANY_THROW(S.SetMas(-1, b));
}

TEST(TNewStack, can_push_and_pop)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Push(3);
  S.Push(2);
  ASSERT_EQ(2, S.Pop());
  ASSERT_EQ(3, S.Pop());
}

TEST(TMultiStack, can_create_multistack)
{
  ASSERT_NO_THROW(TMultiStack<int> A(5, 25));
}

TEST(TMultiStack, throw_on_multistack_negative_len)
{
  ASSERT_ANY_THROW(TMultiStack<int> A(5, -1));
}

TEST(TMultiStack, throw_on_multistack_negative_col)
{
  ASSERT_ANY_THROW(TMultiStack<int> A(0, 10));
}

TEST(TMultiStack, can_copy_multistackstack)
{
  TMultiStack<int> A(5, 25);
  ASSERT_NO_THROW(TMultiStack<int> B(A));
}

TEST(TMultiStack, can_get_size)
{
  TMultiStack<int> A(5, 25);
  ASSERT_EQ(A.GetSize(), 25);
}

TEST(TMultiStack, can_set_element)
{
  TMultiStack<int> A(5, 25);
  ASSERT_NO_THROW(A.Set(1, 2));
}

TEST(TMultiStack, throws_when_set_element_in_full_mstack)
{
  TMultiStack<int> A(2, 4);
  A.Set(0, 1);
  A.Set(0, 2);
  A.Set(1, 3);
  A.Set(1, 4);
  ASSERT_ANY_THROW(A.Set(1,6));
}

TEST(TMultiStack, throws_when_set_element_in_negative_index)
{
  TMultiStack<int> A(5, 25);
  ASSERT_ANY_THROW(A.Set(-2, 2));
}

TEST(TMultiStack, can_get_element)
{
  TMultiStack<int> A(5, 25);
  A.Set(2, 43);
  ASSERT_EQ(43, A.Get(2));
}

TEST(TMultiStack, can_repack)
{
  TMultiStack<int> A(2, 6);
  A.Set(0, 1);
  A.Set(0, 2);
  A.Set(0, 3);
  A.Set(1, 3);
  ASSERT_NO_THROW(A.Set(0,10));
  ASSERT_EQ(A.Get(0), 10);
}

TEST(TMultiStack, throws_when_get_element_from_negative_index)
{
  TMultiStack<int> A(5, 25);
  A.Set(1, 43);
  ASSERT_ANY_THROW(A.Get(-1));
}

TEST(TMultiStack, throws_when_get_element_from_empty_mstack)
{
  TMultiStack<int> A(2, 5);
  ASSERT_ANY_THROW(A.Get(1));
}

TEST(TMultiStack, correct_order_return_value)
{
  TMultiStack <int> A(2, 5);
  A.Set(1, 1);
  A.Set(1, 2);
  A.Set(1, 3);
  ASSERT_EQ(3, A.Get(1));
  ASSERT_EQ(2, A.Get(1));
  ASSERT_EQ(1, A.Get(1));
}

TEST(TMultiStack, can_check_is_empty)
{
  TMultiStack<int> A(5, 25);
  ASSERT_TRUE(A.IsEmpty(1));
}

TEST(TMultiStack, can_check_is_no_empty)
{
  TMultiStack<int> A(5, 25);
  A.Set(1, 1);
  ASSERT_FALSE(A.IsEmpty(1));
}

TEST(TMultiStack, can_check_is_full)
{
  TMultiStack<int> A(5, 25);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  EXPECT_EQ(1, A.IsFull(1));
}

TEST(TMultiStack, can_check_is_no_full)
{
  TMultiStack<int> A(5, 25);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  ASSERT_FALSE(A.IsFull(1));
}

TEST(TMultiStack, throw_when_check_is_full_or_empty)
{
  TMultiStack<int> A(5, 25);
  ASSERT_ANY_THROW(A.IsFull(-1));
  ASSERT_ANY_THROW(A.IsEmpty(-1));
}