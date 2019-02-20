#include <gtest.h>
#include "listonarray.h"

TEST(ListOnArray, can_create_list_with_not_specified_size)
{
  ASSERT_NO_THROW(TArrayList <int> L(3));
}

TEST(ListOnArray, can_create_list_with_specified_size)
{
  ASSERT_NO_THROW(TArrayList <int> L(3));
}

TEST(ListOnArray, can_create_copy_empty_list)
{
  TArrayList <int> L(1);
  L.PushFront(1);
  TArrayList <int> L2(L);
  ASSERT_EQ(L.PopFront(), L2.PopFront());
}

TEST(ListOnArray, can_create_copy_not_empty_list)
{
  TArrayList <int> L(3);

  ASSERT_NO_THROW(TArrayList <int> L2(L));
}

TEST(ListOnArray, throws_when_create_list_with_size_eq_zero)
{
  ASSERT_ANY_THROW(TArrayList <int> L(0));
}

TEST(ListOnArray, throws_when_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrayList <int> L(-1));
}

TEST(ListOnArray, can_get_and_put_start)
{
  TArrayList <int> L(2);
  L.PushFront(1);
  L.PushFront(2);
  ASSERT_EQ(2, L.PopFront());
  ASSERT_EQ(1, L.PopFront());
}

TEST(ListOnArray, can_put_and_get_end)
{
  TArrayList <int> L(2);
  L.PushBack(1);
  L.PushBack(2);
  ASSERT_EQ(2, L.PopBack());
  ASSERT_EQ(1, L.PopBack());
}

TEST(ListOnArray, can_use_full_check_false)
{
  TArrayList <int> L(1);
  ASSERT_FALSE(L.IsFull());
}

TEST(ListOnArray, can_use_full_check_true)
{
  TArrayList <int> L(1);
  L.PushFront(5);
  ASSERT_TRUE(L.IsFull());
}

TEST(ListOnArray, can_use_empty_check_false)
{
  TArrayList <int> L(1);
  L.PushFront(5);
  ASSERT_FALSE(L.IsEmpty());
}

TEST(ListOnArray, can_use_empty_check_true)
{
  TArrayList <int> L(1);
  ASSERT_TRUE(L.IsEmpty());
}

TEST(ListOnArray, throws_when_in_full_list_put_start_elem)
{
  TArrayList <int> L(1);
  L.PushFront(1);
  ASSERT_ANY_THROW(L.PushFront(2));
}

TEST(ListOnArray, throws_when_in_full_list_put_finish_elem)
{
  TArrayList <int> L(1);
  L.PushFront(1);
  ASSERT_ANY_THROW(L.PushBack(2));
}

TEST(ListOnArray, throws_when_in_empty_list_get_start_elem)
{
  TArrayList <int> L(1);
  ASSERT_ANY_THROW(L.PopFront());
}

TEST(ListOnArray, throws_when_in_empty_list_get_end_elem)
{
  TArrayList <int> L(1);
  ASSERT_ANY_THROW(L.PopBack());
}

TEST(ListOnArray, true_posledovatelnost_vivoda)
{
  TArrayList <int> L(5);
  L.PushFront(1); // 1
  L.PushBack(2);   // 1 2
  L.PushFront(3); // 3 1 2
  L.PushBack(4);   // 3 1 2 4
  L.PushFront(5); // 5 3 1 2 4 
  ASSERT_EQ(4, L.PopBack());     // 5 3 1 2  
  ASSERT_EQ(5, L.PopFront());   // 3 1 2
  ASSERT_EQ(2, L.PopBack());     // 3 1 
  ASSERT_EQ(3, L.PopFront());   // 1
  ASSERT_EQ(1, L.PopBack());     // empty
}

TEST(ListOnArray, throws_when_in_empty_list_get_elem)
{
  TArrayList <int> L(10);
  ASSERT_ANY_THROW(L.Get(3));
}

TEST(ListOnArray, throws_when_in_full_list_put_elem)
{
  TArrayList <int> L(3);
  L.PushBack(1);
  L.PushBack(1);
  L.PushBack(1);

  ASSERT_ANY_THROW(L.Insert(1, 6));
}

TEST(ListOnArray, throws_when_incurrent_index_when_list_put_elem)
{
  TArrayList <int> L(4);
  L.PushBack(1);
  L.PushBack(1);
  L.PushBack(1);

  ASSERT_ANY_THROW(L.Insert(10, 6));
}

TEST(ListOnArray, throws_when_incurrent_index_when_list_get_elem)
{
  TArrayList <int> L(3);
  L.PushBack(1);
  L.PushBack(1);
  L.PushBack(1);

  ASSERT_ANY_THROW(L.Get(10));
}

TEST(ListOnArray, can_get_elem)
{
  TArrayList <int> L(3);
  L.PushBack(1);
  L.PushBack(2);
  L.PushBack(3);

  ASSERT_EQ(L.Get(1), 2);
}

TEST(ListOnArray, can_put_elem)
{
  TArrayList <int> L(4);
  L.PushBack(1);
  L.PushBack(2);
  L.PushBack(3);
  L.Insert(2, 10);

  ASSERT_EQ(L.Get(1), 2);
  ASSERT_EQ(L.Get(1), 10);
}