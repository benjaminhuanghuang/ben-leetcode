/*
371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/

public class Solution371 {
    public int GetSum(int a, int b) {
        while ( b!=0 ) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }

    public int GetSum_Recursion(int a, int b) {
        return b == 0 ? a : GetSum_Recursion(a ^ b, (a & b) << 1);
    }
    // C# function causes infinite loop in python, because Python will convert int to long int when the left-shift result too big
    // def get_sum(a, b):
    // MAX_INT = 0x7FFFFFFF
    // MASK = 0xFFFFFFFF
    // while b:
    //     a, b = (a ^ b) & MASK, ((a & b) << 1) & MASK

    // # if a > MAX_INT means it is a negative number
    // # a & MAX_INT  cut 32 bits, but sign bit was changed to 0
    // # ~(a & MAX_INT)  change sign bit(s) to 1, and inverse all rest bits
    // # ~(a & MAX_INT) ^ MAX_INT inverse all rest bits, because all bits in MAX_INT are 1s,  1^0 =1, 1^1=0
    // return a if a <= MAX_INT else ~(a & MAX_INT) ^ MAX_INT
}