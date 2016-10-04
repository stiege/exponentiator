#include "gtest/gtest.h"
#include "reverse.h"

/*
The reverse function should take an integer and reverse it.
*/
TEST(Reverse, Trivial)
{
    EXPECT_EQ(0uL, reverse(0));
}

TEST(Reverse, BaseCase)
{
    EXPECT_EQ(1uL, reverse(1));
}

TEST(Reverse, DoubleDigit)
{
    EXPECT_EQ(21uL, reverse(12));
}

TEST(Reverse, MidRange)
{
    EXPECT_EQ(12345uL, reverse(54321));
}

TEST(Reverse, Max)
{
    EXPECT_EQ(99999uL, reverse(99999));
}
