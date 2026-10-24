/*
201. Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND 
of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

*/

public class Solution201
{
    // http://www.cnblogs.com/grandyang/p/4431646.html
    // 建立一个32位都是1的mask，然后每次向左移一位，比较m和n是否相同，不同再继续左移一位，直至相同，
    // 然后把m和mask相与就是最终结果
    public int RangeBitwiseAnd(int m, int n)
    {
        uint mask = 0xFFFFFFFF;
        while ((m & mask) != (n & mask))
        {
            mask <<= 1;
        }
        return (int)(m & mask);
    }

    // Time Limit Exceeded
    public int RangeBitwiseAnd_My(int m, int n)
    {
        uint mask = 0xFFFFFFFF;
        int res = m;
        for (int i = m + 1; i <= n; i++)
        {
            res &= i;
        }
        return (int)(res & mask);
    }

    // 不需要用mask，直接平移m和n，每次向右移一位，直到m和n相等，记录下所有平移的次数i，然后再把m左移i位即为最终结果
    public int RangeBitwiseAnd_2(int m, int n)
    {
        int p = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            p++;
        }
        return m << p;
    }


}