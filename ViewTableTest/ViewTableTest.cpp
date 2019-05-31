#include "viewtable.h"

#include <gtest.h>

TEST(VIewTableLib, can_create_tab_with_positive_size)
{
  ASSERT_NO_THROW (TViewTable<int> s(1));
}

//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, throws_when_create_tab_with_negative_size)
{
  ASSERT_ANY_THROW (TViewTable<int> s(-8));
}


//-------------------------------------------------------------------------------------------------
TEST(VIewTableLib, can_copy_tab)
{
  TViewTable<int> A;
  ASSERT_NO_THROW (TViewTable<int> s(A));
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, can_put_to_tab)
{
  TViewTable<int> A(4);
  ASSERT_NO_THROW (A.Put("kig", 7));
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, throws_when_put_to_full_tab)
{
  TViewTable<int> A(1);
  A.Put("iun", 5);
  ASSERT_ANY_THROW (A.Put("dhj", 7));
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, can_get_from_tab)
{
  TViewTable<int> A(4);
  A.Put("kif", 98);
  int k;
  ASSERT_NO_THROW (k = A["kif"]);
}
//-------------------------------------------------------------------------------------------------
TEST(VIewTableLib, can_delete_from_tab)
{
  TViewTable<int> s(1);
  s.Put("kig", 7);
  ASSERT_NO_THROW (s.Del("kig"));
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, throws_when_delete_from_empty_Tab)
{
  TViewTable<int> A(1);
  ASSERT_ANY_THROW (A.Del("kj"));
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, get_gives_right_answer)
{
  TViewTable<int> A(2);
  A.Put("bol", 8);
  int k = A["bol"];
  EXPECT_EQ (8, k);
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, isfull_gives_right_true_answer)
{
  TViewTable<int> A(1);
  A.Put("kdgjh", 8);
  EXPECT_EQ (true, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, isfull_gives_right_false_answer)
{
  TViewTable<int> A(1);
  EXPECT_EQ (false, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, isempty_gives_right_true_answer)
{
  TViewTable<int> A(1);
  EXPECT_EQ (true, A.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (VIewTableLib, isempty_gives_right_false_answer)
{
  TViewTable<int> A(1);
  A.Put("kdgjh", 8);
  EXPECT_EQ (false, A.IsEmpty());
}