#include "gtest/gtest.h"
#include "Question2.h"

TEST(discard_elements_above, AllElementsBelow) 
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8};
    std::vector<uint32_t> elementsBelow;
    EXPECT_FALSE(question2Mock.discard_elements_above(12, elementsStart, elementsBelow));
    EXPECT_EQ(elementsStart, elementsBelow);
}

TEST(discard_elements_above, SomeElementsBelow) 
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 13};
    std::vector<uint32_t> elementsBelow;
    EXPECT_FALSE(question2Mock.discard_elements_above(12, elementsStart, elementsBelow));
    EXPECT_NE(elementsStart, elementsBelow);
}

TEST(discard_elements_above, ElementFound) 
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 12 ,13};
    std::vector<uint32_t> elementsBelow;
    EXPECT_TRUE(question2Mock.discard_elements_above(12, elementsStart, elementsBelow));
    EXPECT_NE(elementsStart, elementsBelow);
}