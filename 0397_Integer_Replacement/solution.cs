/*
397. Integer Replacement

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:
    Input:
    8
    Output:
    3

    Explanation:
    8 -> 4 -> 2 -> 1

Example 2:
    Input:
    7
    Output:
    4

    Explanation:
    7 -> 8 -> 4 -> 2 -> 1
    or
    7 -> 6 -> 3 -> 2 -> 1
    */

//http://bookshadow.com/weblog/2016/09/11/leetcode-integer-replacement/
/*
当n为偶数时，下一次迭代n的取值确定为n / 2；
当n为奇数时，下一次迭代n的取值n + 1或者n - 1，由其二进制表示中的最低两位数决定：
若n的最低两位数为01，则令n = n - 1
否则，若n的最低两位数为11，则令n = n + 1
这样处理是为了使n的二进制表式中1的数目尽可能少，从而减少迭代次数
*/
using System;

public class Solution397 {
    public int integerReplacement_TLE(int n) {
        int c = 0;
        while (n != 1) {
            if ((n & 1) == 0) {
                // n is even, replace n = n/2
                n >>= 1;
            } 
            else if (n == 3 || ((n >> 1) & 1) == 0) {
                --n;
            } 
            else {
                ++n;
            }
            ++c;
        }
        return c;
    }

    // n = 2147483647, n+1 overflow
    public int IntegerReplacement_Error(int n) {
        if (n == 1)
            return 0;
        
        if ((n & 1) == 0) // even number 
            return IntegerReplacement(n / 2) + 1;
        return Math.Min(IntegerReplacement(n + 1), IntegerReplacement(n - 1)) + 1;
    }

    public int IntegerReplacement(int n) {
        if (n == 1)
            return 0;
        
        if ((n & 1) == 0) // even number 
            return (int)longReplacement((long)n / 2) + 1;
        // n +1 will overflow when n = 2147483647
        return (int)Math.Min(longReplacement((long)n + 1), longReplacement((long)n - 1)) + 1;
    }
    
    public long longReplacement(long n) {
        if( n < 3 ) 
            return n - 1;
        if(n%2 ==0) return longReplacement(n/2) + 1;
        else return Math.Min(longReplacement(n-1),longReplacement(n+1)) + 1;
    }

}