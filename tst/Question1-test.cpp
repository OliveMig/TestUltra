#include "gtest/gtest.h"
#include "Question1.h"
#include <climits>

TEST(addTest, test) 
{
    EXPECT_EQ (add(0,0), 0);
    EXPECT_EQ (add(12,10), 0);
    EXPECT_EQ (add(-13,16), 0);
    EXPECT_EQ (add(20,-24), 0);
    EXPECT_EQ (add(-26,-14), 0);
    EXPECT_EQ (add(INT_MAX, 1), 0);
}