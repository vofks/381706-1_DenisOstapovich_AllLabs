#include "gtest.h"
#include "rpn.h"

TEST(RPN, can_check_isoperation)
{
	EXPECT_EQ(true, IsOperation('('));
	EXPECT_EQ(true, IsOperation(')'));
	EXPECT_EQ(true, IsOperation('+'));
	EXPECT_EQ(true, IsOperation('-'));
	EXPECT_EQ(true, IsOperation('*'));
	EXPECT_EQ(true, IsOperation('/'));
	EXPECT_EQ(false, IsOperation('5'));
	EXPECT_EQ(false, IsOperation('.'));
}

TEST(RPN, can_get_priority)
{
	EXPECT_EQ(1, GetPriority('('));
	EXPECT_EQ(1, GetPriority(')'));
	EXPECT_EQ(2, GetPriority('+'));
	EXPECT_EQ(2, GetPriority('-'));
	EXPECT_EQ(3, GetPriority('*'));
	EXPECT_EQ(3, GetPriority('/'));
}

TEST(RPN, can_convert_to_rpn)
{
	char str1[] = "5+4";
	TMyString str2(str1);
	TQueue<char> queue;
	queue = ConvertRPN(str2);
	EXPECT_EQ('[', queue.Pop());
	EXPECT_EQ('5', queue.Pop());
	EXPECT_EQ(']', queue.Pop());
	EXPECT_EQ('[', queue.Pop());
	EXPECT_EQ('4', queue.Pop());
	EXPECT_EQ(']', queue.Pop());
	EXPECT_EQ('+', queue.Pop());
}

TEST(RPN, can_add_correctly)
{
	char str1[] = "6+6";
	TMyString str2(str1);
	TQueue<char> queue;
	queue = ConvertRPN(str2);
	EXPECT_EQ(12, Result(queue));
}

TEST(RPN, can_subtract_correctly)
{
  char str1[] = "7-5";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertRPN(str2);
  EXPECT_EQ(2, Result(queue));
}

TEST(RPN, can_multiply_correctly)
{
  char str1[] = "3*3";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertRPN(str2);
  EXPECT_EQ(9, Result(queue));
}

TEST(RPN, can_divide_correctly)
{
  char str1[] = "20/4";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertRPN(str2);
  EXPECT_EQ(5, Result(queue));
}

TEST(RPN, can_solve_math_expresion_correctly)
{
  char str1[] = "(6+6*6)/2-3";
  TMyString str2(str1);
  TQueue<char> queue;
  queue = ConvertRPN(str2);
  EXPECT_EQ(18, Result(queue));
}

TEST(RPN, throw_when_math_expression_has_incorrect_symbol)
{
  char str1[] = "5:5";
  TMyString str2(str1);
  ASSERT_ANY_THROW(ConvertRPN(str2));
}

TEST(RPN, throw_when_math_expression_has_incorrect_number_of_brackets)
{
  char str1[] = "(56+3";
  TMyString str2(str1);
  ASSERT_ANY_THROW(ConvertRPN(str2));
}

TEST(RPN, throw_when_math_expression_has_incorrect_sign_in_start)
{
  char str1[] = "*22+5";
  TMyString str2(str1);
  ASSERT_ANY_THROW(ConvertRPN(str2));
}