#include "stdafx.h"
#include "../EquationRoots3/EquationRoots3.h"

using namespace std;

void IsRootsEqual(const double roots[3], const double expectedRoots[3], const unsigned expectedNumbRoots)
{
	for (size_t i = 0; i < expectedNumbRoots; i++)
	{
		BOOST_CHECK_CLOSE(roots[i], expectedRoots[i], 0.001);
	}
}

void CheckRoots(EquationRoots3 const& result, const unsigned expectedNumbRoots, const double expectedRoots[])
{
	BOOST_CHECK_EQUAL(result.numRoots, expectedNumbRoots);
	IsRootsEqual(result.roots, expectedRoots, expectedNumbRoots);
}

BOOST_AUTO_TEST_SUITE(Solve3Test)

BOOST_AUTO_TEST_CASE(coefficient_a_is_0)
{
	BOOST_CHECK_THROW(Solve3(0, 1, 2, 3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(equation_has_three_right_roots)
{
	double expectedRoots1[3] = {3, 2, -0.25};
	CheckRoots(Solve3(4, -19, 19, 6), 3, expectedRoots1);

}

BOOST_AUTO_TEST_CASE(equation_has_one_right_roots)
{
	double expectedRoots1[1] = { -1.65063 };
	CheckRoots(Solve3(1, 2, 3, 4), 1, expectedRoots1);

}

BOOST_AUTO_TEST_CASE(equation_no_has_right_roots)
{
	double expectedRoots1[1] = {-1};
	CheckRoots(Solve3(2, 2, 2, 2), 1, expectedRoots1);

}

BOOST_AUTO_TEST_SUITE_END()
