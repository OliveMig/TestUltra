#include "Question1.h"

#include "gtest/gtest.h"
#include <climits>

TEST(add, Numbers) 
{
    Question1 question1Mock;
    EXPECT_EQ (question1Mock.add(7,5), 12);
    EXPECT_EQ (question1Mock.add(-13,16), 3);
    EXPECT_EQ (question1Mock.add(20,-24), -4);
    EXPECT_EQ (question1Mock.add(-26,-14), -40);
}

TEST(add, Overflow) 
{
    Question1 question1Mock;
    EXPECT_EQ (question1Mock.add(INT_MAX, 1), 0);
}