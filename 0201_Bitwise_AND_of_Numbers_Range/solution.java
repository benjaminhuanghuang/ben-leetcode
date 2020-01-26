package cn.huang.leetcode;
/*
201. Bitwise AND of Numbers Range


 */
public class LC_0201_BitwiseANDofNumbersRange {
    /*
    The key to solve this problem is bitwise AND consecutive numbers. You can use the following example to walk through the code.
    8  4  2  1
---------------
5 | 0  1  0  1
6 | 0  1  1  0
7 | 0  1  1  1



     */
    public int rangeBitwiseAnd(int m, int n) {
        while (n > m) {
            n = n & n - 1;
        }
        return m & n;
    }
    /*
        等价于 求 m 与 n 二进制编码中 同为1的前缀.
     */
    public int rangeBitwiseAnd2(int m, int n) {
        int bit = 0;
        while(m!=n) {
            m>>=1;
            n>>=1;
            bit++;
        }
        return m<<bit;
    }

    /*
    https://www.geeksforgeeks.org/bitwise-and-or-of-a-range/
     */

}
