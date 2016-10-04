#include "gtest/gtest.h"
#include "exponentiator.h"

using exponentiator::Exponentiator;

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
    EXPECT_EQ(11275585012758672893uL, std::hash<std::string>{}(exp.run(99999)));
}