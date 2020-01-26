package cn.huang.leetcode;
/*
1012. Complement of Base 10 Integer

Every non-negative integer N has a binary representation.  For example, 5 can be represented as "101" in binary,
11 as "1011" in binary, and so on.  Note that except for N = 0, there are no leading zeroes in any binary representation.

The complement of a binary representation is the number in binary you get when changing every 1 to a 0 and 0 to a 1.
For example, the complement of "101" in binary is "010" in binary.

For a given number N in base-10, return the complement of it's binary representation as a base-10 integer.



Example 1:

Input: 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

Example 2:

Input: 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.

Example 3:

Input: 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.


 */
public class LC_1012_ComplementofBase10Integer
{
    /*
        N + complement(N) = 111111..
     */
    public int bitwiseComplement_math(int N) {
        // Find number of bits in the given integer
        int bitCount = (int) Math.floor(Math.log(N)/Math.log(2))+1;

        // XOR the given integer with math.pow(2,bitCount-1)
        return ((1 << bitCount) - 1) ^ N;
    }
    /*
         N + bitwiseComplement(N) = 11....11 = X
        Then bitwiseComplement(N) = X - N

     */
    public int bitwiseComplement2(int N) {
        int X = 1;
        while (N > X)
            X = X * 2 + 1;
        return X - N;
    }
    public int bitwiseComplement(int N) {
        if(N == 0)
        {
            return 1;
        }
        String complement = Integer.toBinaryString(N).replace('0', '2')
            .replace('1', '0').replace('2', '1');
        return Integer.parseInt(complement, 2);
    }
}
