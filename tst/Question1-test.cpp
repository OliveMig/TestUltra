#include "Question1.h"

#include "gtest/gtest.h"
#include <climits>

/*int Question1Mock::add(int a, int b)
{
    return add(a, b);
}*/

TEST(Add, test) 
{
    Question1 question1Mock;
    EXPECT_EQ (question1Mock.add(0,0), 0);
    EXPECT_EQ (question1Mock.add(12,10), 0);
    EXPECT_EQ (question1Mock.add(-13,16), 0);
    EXPECT_EQ (question1Mock.add(20,-24), 0);
    EXPECT_EQ (question1Mock.add(-26,-14), 0);
    EXPECT_EQ (question1Mock.add(INT_MAX, 1), 0);
}