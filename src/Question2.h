#pragma once

#include <vector>
#include <cstdint>

class Question2
{
public:
    /* @param T : target value that should not be exceeded */
    /* @param I : elements to test against T */
    /* @param elementsBelowT : elements below T */
    /* @return : true if I contains T, false otherwise*/
    bool discard_elements_above(uint32_t T, const std::vector<uint32_t> &I, std::vector<uint32_t> &elementsBelowT);

    /* @param T : target value used to split in two vectors */
    /* @param elements : elements to be splitted */
    /* @param elementsBelowT : elements below T */
    /* @return : true if T is even and T/2 has been found twice, false otherwise*/
    bool split_elements(uint32_t T, const std::vector<uint32_t> &elements, std::vector<uint32_t> &elementsBelowTOver2, std::vector<uint32_t> &elementsAboveTOver2);

    /* @param T : target value that should not be exceeded */
    /* @param I : elements to test against T */
    /* @param M : subset of elements of I containing the largest sum below T*/
    /* @param M : largest sum of elements of I below T*/
    void find_largest_sum(uint32_t T, const std::vector<uint32_t> &I, std::vector<uint32_t> &M, uint32_t &S);

private:
    /* @param T : target value that should not be exceeded */
    /* @param I : elements to test against T (every element should be below T/2)*/
    /* @param M : subset of elements of I containing the largest sum below T*/
    /* @param M : largest sum of elements of I below T*/
    void find_largest_sum_elements_below(uint32_t T, const std::vector<uint32_t> &I, std::vector<uint32_t> &M, uint32_t &S);
};