package cn.huang.leetcode;

/*
693. Binary Number with Alternating Bits

 */
public class LC_0693_BinaryNumberwithAlternatingBits {
    boolean hasAlternatingBits_v1(int n) {
        int bit = -1;
        while (n > 0) {
            if ((n & 1) == 1) {
                if (bit == 1) return false;
                bit = 1;
            } else {
                if (bit == 0) return false;
                bit = 0;
            }
            n >>= 1;
        }
        return true;
    }

    public boolean hasAlternatingBits(int n) {
        int last = n & 1;
        while (n != 0 && (n & 1) == last) {
            last = 1 - last; // good
            n >>= 1;
        }
        return n == 0;
    }
}
