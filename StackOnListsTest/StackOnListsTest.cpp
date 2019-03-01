#include "gtest.h"
#include "stackonlists.h"

TEST(TStackList, can_create_stack)
{
  ASSERT_NO_THROW(TStackList<int> A);
}

TEST(TStackList, can_create_with_arg)
{
  ASSERT_NO_THROW(TStackList<int> A(3));
}

TEST(TStackList, can_create_with_negative_size)
{
  ASSERT_ANY_THROW(TStackList<int> A(-1));
}

TEST(TStackList, can_copy)
{
  TStackList<int> S(1);
  ASSERT_NO_THROW(TStackList<int> A(S));
}

TEST(TStackList, can_get_max_size)
{
  TStackList<int> S(15);
  ASSERT_EQ(S.GetMaxSize(), 15);
}

TEST(TStackList, can_get_size)
{
  TStackList<int> S(5);
  S.Push(1);
  S.Push(2);
  ASSERT_EQ(S.GetSize(), 2);
}

TEST(TStackList, can_push)
{
  TStackList<int> A;

  ASSERT_NO_THROW(A.PushFront(43));
}

TEST(TStackList, throws_when_in_full_stack_push_elem)
{
  TStackList<int> S(1);
  S.Push(2);
  ASSERT_ANY_THROW(S.Push(5));
}

TEST(TStackList, can_pop)
{
  TStackList<int> A;
  A.Push(42);
  EXPECT_EQ(42, A.Pop());
}

TEST(TStackList, throws_when_from_empty_stack_pop_elem)
{
  TStackList <int> S(5);
  ASSERT_ANY_THROW(S.Pop());
}

TEST(TStackList, can_use_empty_check_true)
{
  TStackList<int> S(5);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(TStackList, can_check_empty_print)
{
  TStackList<int> S(5);
  ASSERT_ANY_THROW(S.Print());
}

TEST(TStackList, can_use_empty_check_false)
{
  TStackList<int> S(1);
  S.Push(5);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(TStackList, proper_output_order)
{
  TStackList<int> S(3);
  S.Push(1), S.Push(2), S.Push(3);
  ASSERT_EQ(S.Pop(), 3);
  ASSERT_EQ(S.Pop(), 2);
  ASSERT_EQ(S.Pop(), 1);
}