package cn.huang.leetcode;

import static java.lang.Math.max;

/*
    868	 Binary Gap
    Given a positive integer N, find and return the longest distance between two consecutive 1's in
    the binary representation of N.

    Example 2:

    Input: 5
    Output: 2
    Explanation:
    5 in binary is 0b101.


    Example 3:

    Input: 6
    Output: 1
    Explanation:
    6 in binary is 0b110.
 */
public class LC_0868_BinaryGap {
    public int binaryGap(int N) {
        int maxDis = 0;
        int bit = 0;            // current bit
        int lastOnePos = -1;    // position of last bit 1

        while (N > 0) {
            int lastBit = N & 0x00000001;
            if (lastBit == 1) {
                if (lastOnePos == -1)
                    lastOnePos = bit;
                // distance between two consecutive 1's, 1 and next 1
                maxDis = max(maxDis, bit - lastOnePos);
                lastOnePos = bit;
            }
            N >>= 1;
            bit++;
        }

        return maxDis;
    }
}
