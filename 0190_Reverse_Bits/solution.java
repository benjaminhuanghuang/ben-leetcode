package cn.huang.leetcode;
/*
190	Reverse Bits
 */
public class LC_0190_ReverseBits {
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;

            ans = (ans << 1) + bit;
        }
        return ans;

    }
}
