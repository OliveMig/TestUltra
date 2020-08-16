#include "Question1.h"

int Question1::add(int a, int b)
{
    int sum = a ^ b;
    int carry = a & b;
    while (carry != 0)
    {
        carry = carry << 1;
        int newSum = sum ^ carry, newCarry = sum & carry;
        sum = newSum, carry = newCarry;
    }
    return sum;
}