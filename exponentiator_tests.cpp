#include "gtest/gtest.h"
#include "exponentiator.h"

using exponentiator::Exponentiator;

/*
The exponentiator should exponentiate the parameter passed in based on
the modifier function it is constructed with.

Here we just use a straight pass though so:
5 -> 5^5 == 3125, as below
*/

unsigned long int (test_modifier)(unsigned long int val)
{
    return val;
}

TEST(Exponentiator, Trivial)
{
    Exponentiator exp(test_modifier);
    EXPECT_EQ("1", exp.run(1));
}

TEST(Exponentiator, SingleDigit)
{
    Exponentiator exp(test_modifier);
    EXPECT_EQ("3125", exp.run(5));
}

TEST(Exponentiator, DoubleDigit)
{
    Exponentiator exp(test_modifier);
    EXPECT_EQ("10000000000", exp.run(10));
}

TEST(Exponentiator, Large)
{
    Exponentiator exp(test_modifier);
    std::string result(exp.run(99999));
    EXPECT_EQ("3678812805", result.substr(0, 10));
    EXPECT_EQ(499995, result.length());
}
