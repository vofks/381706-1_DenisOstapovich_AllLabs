#include "gtest.h"
#include "polynomial.h"

TEST(Monomial, can_create_monomial)
{
	int degrees[] = { 1,2,3,4,5 };
	ASSERT_NO_THROW(TMonomial Monomial(5, degrees, 1));
}

TEST(Monomial, throw_when_create_monomial_with_negative_size)
{
	int degrees[] = { 1,2,3,4,5 };
	ASSERT_ANY_THROW(TMonomial Monomial(-5, degrees, 1));
}

TEST(Monomial, throw_when_create_monomial_with_negative_degrees)
{
	int degrees[] = { 1,2,-3,-4,5 };
	ASSERT_ANY_THROW(TMonomial Monomial(5, degrees, 1));
}

TEST(Monomial, can_create_copied_monomial)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial1(5, degrees, 1);
	ASSERT_NO_THROW(TMonomial Monomial2(Monomial1));
}

TEST(Monomial, can_set_next)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 1);
	ASSERT_NO_THROW(Monomial1.SetNext(&Monomial2));
}

TEST(Monomial, can_get_next)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 1);
	Monomial1.SetNext(&Monomial2);
	EXPECT_EQ(&Monomial2, Monomial1.GetNext());
}

TEST(Monomial, can_set_degree)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial(5, degrees1, 1);
	ASSERT_NO_THROW(Monomial.SetDegree(degrees2));
}

TEST(Monomial, can_get_degree)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial(5, degrees1, 1);
	Monomial.SetDegree(degrees2);
	EXPECT_EQ(degrees2[0], Monomial.GetDegree()[0]);
	EXPECT_EQ(degrees2[1], Monomial.GetDegree()[1]);
	EXPECT_EQ(degrees2[2], Monomial.GetDegree()[2]);
	EXPECT_EQ(degrees2[3], Monomial.GetDegree()[3]);
	EXPECT_EQ(degrees2[4], Monomial.GetDegree()[4]);
}

TEST(Monomial, can_set_count)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial(5, degrees, 1);
	ASSERT_NO_THROW(Monomial.SetCount(4));
}

TEST(Monomial, can_get_count)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial(5, degrees, 1);
	Monomial.SetCount(4);
	EXPECT_EQ(4, Monomial.GetCount());
}

TEST(Monomial, assign_operator_works_correctly)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 2);
	ASSERT_NO_THROW(Monomial1=Monomial2);
	EXPECT_EQ(degrees2[0], Monomial1.GetDegree()[0]);
	EXPECT_EQ(degrees2[1], Monomial1.GetDegree()[1]);
	EXPECT_EQ(degrees2[2], Monomial1.GetDegree()[2]);
	EXPECT_EQ(degrees2[3], Monomial1.GetDegree()[3]);
	EXPECT_EQ(degrees2[4], Monomial1.GetDegree()[4]);
	EXPECT_EQ(2, Monomial1.GetCoefficient());
}

TEST(Monomial, throw_when_assign_monomials_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(6, degrees2, 2);
	ASSERT_ANY_THROW(Monomial1 = Monomial2);
}

TEST(Monomial, can_add_monomials)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial1(5, degrees, 1);
	TMonomial Monomial2(5, degrees, 2);
	TMonomial Monomial3(5, degrees, 1);
	ASSERT_NO_THROW(Monomial1 + Monomial2);
	Monomial3 = Monomial1 + Monomial2;
	EXPECT_EQ(3, Monomial3.GetCoefficient());
}

TEST(Monomial, throw_when_add_different_monomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 2);
	ASSERT_ANY_THROW(Monomial1 + Monomial2);
}

TEST(Monomial, can_subtract_monomials)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial1(5, degrees, 3.4);
	TMonomial Monomial2(5, degrees, 2.0);
	TMonomial Monomial3(5, degrees, 1);
	ASSERT_NO_THROW(Monomial1 - Monomial2);
	Monomial3 = Monomial1 - Monomial2;
	EXPECT_EQ(1.4, Monomial3.GetCoefficient());
}

TEST(Monomial, throw_when_subtract_different_monomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 2);
	ASSERT_ANY_THROW(Monomial2 - Monomial1);
}

TEST(Monomial, can_multiply_monomials)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial1(5, degrees, 3.4);
	TMonomial Monomial2(5, degrees, 2.0);
	TMonomial Monomial3(5, degrees, 1);
	ASSERT_NO_THROW(Monomial1 * Monomial2);
	Monomial3 = Monomial1 * Monomial2;
	EXPECT_EQ(6.8, Monomial3.GetCoefficient());
}

TEST(Monomial, throw_when_multiply_different_monomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(6, degrees2, 1);
	ASSERT_ANY_THROW(Monomial1 * Monomial2);
}

TEST(Monomial, can_equal_monomials_correctly)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial1(5, degrees, 2.0);
	TMonomial Monomial2(5, degrees, 2.0);
	ASSERT_TRUE(Monomial1 == Monomial2);
}

TEST(Monomial, thorw_when_euqal_monomials_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 2.0);
	TMonomial Monomial2(6, degrees2, 2.0);
	ASSERT_ANY_THROW(Monomial1 == Monomial2);
}

TEST(Monomial, can_compare_monomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 3.1);
	TMonomial Monomial2(5, degrees2, 2.2);
	ASSERT_TRUE(Monomial2 > Monomial1);
}

TEST(Polynomial, can_create_polynomial)
{
	ASSERT_NO_THROW(TPolynomial Polynomial(5));
}

TEST(Polynomial, throw_when_create_polynomial_with_negative_size)
{
	ASSERT_ANY_THROW(TPolynomial Polynomial(-5));
}

TEST(Polynomial, can_create_copied_polynomial)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial(5,degrees,1);
	TPolynomial Polynomial1(5);
	Polynomial1 += Monomial;
	ASSERT_NO_THROW(TPolynomial Polynomial2(Polynomial1));
}

TEST(Polynomial, can_get_size)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial(5, degrees, 1);
	TPolynomial Polynomial(5);
	Polynomial += Monomial;
	EXPECT_EQ(1,Polynomial.GetSize());
}

TEST(Polynomial, can_add_polynomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 2);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(5);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_NO_THROW(Polynomial1+Polynomial2);
}

TEST(Polynomial, throw_when_add_different_polynomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(6, degrees2, 2);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(6);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_ANY_THROW(Polynomial1 + Polynomial2);
}

TEST(Polynomial, can_subtract_polynomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 2);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(5);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_NO_THROW(Polynomial1 - Polynomial2);
}

TEST(Polynomial, throw_when_subtract_different_polynomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(6, degrees2, 2);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(6);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_ANY_THROW(Polynomial2 - Polynomial1);
}

TEST(Polynomial, can_muliply_polynomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(5, degrees2, 2);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(5);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_NO_THROW(Polynomial1 * Polynomial2);
}

TEST(Polynomial, throw_when_multiply_different_polynomials)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(6, degrees2, 2);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(6);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_ANY_THROW(Polynomial2 * Polynomial1);
}

TEST(Polynomial, assign_operator_works_correctly)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial1(5, degrees, 1);
	TMonomial Monomial2(5, degrees, 4);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(5);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_NO_THROW(Polynomial1 = Polynomial2);
	TMonomial* tmp = Polynomial1.GetStart();
	ASSERT_TRUE(*tmp == Monomial1);
	ASSERT_EQ(4, tmp->GetCoefficient());
}

TEST(Polynomial, throw_when_assign_polynomials_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(6, degrees2, 4);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(6);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_ANY_THROW(Polynomial1 = Polynomial2);
}

TEST(Polynomial, can_equeal_polynomials)
{
	int degrees[] = { 1,2,3,4,5 };
	TMonomial Monomial(5, degrees, 1);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(5);
	Polynomial1 += Monomial;
	Polynomial2 += Monomial;
	ASSERT_TRUE(Polynomial1 == Polynomial2);
}

TEST(Polynomial, throw_when_equal_polynomials_with_different_sizes)
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 6,5,4,3,2,1 };
	TMonomial Monomial1(5, degrees1, 1);
	TMonomial Monomial2(6, degrees2, 4);
	TPolynomial Polynomial1(5);
	TPolynomial Polynomial2(6);
	Polynomial1 += Monomial1;
	Polynomial2 += Monomial2;
	ASSERT_ANY_THROW(Polynomial1 == Polynomial2);
}