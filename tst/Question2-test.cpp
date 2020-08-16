#include "gtest/gtest.h"
#include "Question2.h"

#include <numeric>

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

TEST(find_largest_sum, ContainingTarget)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 10, 10, 11, 15 ,18};
    std::vector<uint32_t> elementsSum;
    uint32_t sumResult = 0;
    question2Mock.find_largest_sum(15, elementsStart, elementsSum, sumResult);
    EXPECT_EQ(elementsSum, std::vector<uint32_t>({15}));
    EXPECT_EQ(sumResult, 15);
}

TEST(find_largest_sum, ContainingTwoPivotals)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {3, 5, 6, 8, 10, 10, 11, 15 ,18};
    std::vector<uint32_t> elementsSum;
    uint32_t sumResult = 0;
    question2Mock.find_largest_sum(20, elementsStart, elementsSum, sumResult);
    EXPECT_EQ(elementsSum, std::vector<uint32_t>({10, 10}));
    EXPECT_EQ(sumResult, 20);
}

TEST(find_largest_sum, MaxValue)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {8, 12, 14, 18, 22};
    std::vector<uint32_t> elementsSum;
    uint32_t sumResult = 0;
    question2Mock.find_largest_sum(15, elementsStart, elementsSum, sumResult);
    EXPECT_EQ(elementsSum, std::vector<uint32_t>({14}));
    EXPECT_EQ(sumResult, 14);
}

TEST(find_largest_sum, AllBelow)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {1, 2, 3, 4};
    std::vector<uint32_t> elementsSum;
    uint32_t sumResult = 0;
    question2Mock.find_largest_sum(10, elementsStart, elementsSum, sumResult);
    EXPECT_EQ(elementsSum, std::vector<uint32_t>({1, 2, 3, 4}));
    EXPECT_EQ(sumResult, 10);
}

TEST(find_largest_sum, NotEqual)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart = {2, 4, 7};
    std::vector<uint32_t> elementsSum;
    uint32_t sumResult = 0;
    question2Mock.find_largest_sum(12, elementsStart, elementsSum, sumResult);
    EXPECT_EQ(elementsSum, std::vector<uint32_t>({4, 7}));
    EXPECT_EQ(sumResult, 11);
}

TEST(find_largest_sum, ManyElements)
{
    Question2 question2Mock;
    std::vector<uint32_t> elementsStart(10000);
    std::iota(std::begin(elementsStart), std::end(elementsStart), 1);
    std::vector<uint32_t> elementsSum;
    uint32_t sumResult = 0;
    question2Mock.find_largest_sum(10000 * 10001 / 2, elementsStart, elementsSum, sumResult);
    EXPECT_EQ(elementsSum, elementsStart);
    EXPECT_EQ(sumResult, 10000 * 10001 / 2);
}