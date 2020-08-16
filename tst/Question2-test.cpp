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

TEST(split_elements, Odd)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 10, 11, 15 ,18};
    std::vector<uint32_t> elementsBelow;
    std::vector<uint32_t> elementsAbove;
    EXPECT_FALSE(question2Mock.split_elements(21, elementsStart, elementsBelow, elementsAbove));
    EXPECT_EQ(elementsBelow, std::vector<uint32_t>({3, 5, 6, 8, 10}));
    EXPECT_EQ(elementsAbove, std::vector<uint32_t>({11, 15, 18}));
}

TEST(split_elements, EvenNoPivotal)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 9, 11, 15 ,18};
    std::vector<uint32_t> elementsBelow;
    std::vector<uint32_t> elementsAbove;
    EXPECT_FALSE(question2Mock.split_elements(20, elementsStart, elementsBelow, elementsAbove));
    EXPECT_EQ(elementsBelow, std::vector<uint32_t>({3, 5, 6, 8, 9}));
    EXPECT_EQ(elementsAbove, std::vector<uint32_t>({11, 15, 18}));
}

TEST(split_elements, EvenOnePivotal)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 10, 11, 15 ,18};
    std::vector<uint32_t> elementsBelow;
    std::vector<uint32_t> elementsAbove;
    EXPECT_FALSE(question2Mock.split_elements(20, elementsStart, elementsBelow, elementsAbove));
    EXPECT_EQ(elementsBelow, std::vector<uint32_t>({3, 5, 6, 8, 10}));
    EXPECT_EQ(elementsAbove, std::vector<uint32_t>({11, 15, 18}));
}

TEST(split_elements, EvenTwoPivotals)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 10, 10, 11, 15 ,18};
    std::vector<uint32_t> elementsBelow;
    std::vector<uint32_t> elementsAbove;
    EXPECT_TRUE(question2Mock.split_elements(20, elementsStart, elementsBelow, elementsAbove));
}