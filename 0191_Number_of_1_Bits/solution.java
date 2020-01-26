package cn.huang.leetcode;

/*
191. Number of 1 Bits
 */
public class LC_0191_Numberof1Bits {
    public int hammingWeight(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) == 1) {
                count++;
            }
        }
        return count;
    }
}
