#include "Question1.h"
#include <stdexcept>

int Question1::add(int a, int b)
{
    bool aIsNegative = a >> 31;
    bool bIsNegative = b >> 31;
    int sum = a ^ b;
    int carry = a & b;
    while (carry != 0)
    {
        carry = carry << 1;
        int newSum = sum ^ carry, newCarry = sum & carry;
        sum = newSum, carry = newCarry;
    }
    bool sumIsNegative = sum >> 31;
    if (!(aIsNegative ^ bIsNegative) && (aIsNegative ^ sumIsNegative)) // no overflow if a and b does not have the same sign, 
    {
        throw std::overflow_error(std::string("sum overflow"));
    }
    return sum;
}