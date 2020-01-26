package cn.huang.leetcode;
/*
461. Hamming Distance

 */
public class LC_0461_HammingDistance {
    public int hammingDistance(int x, int y) {
        int distance = 0;
        int z = x ^ y;
        for (int i = 0; i < 32; i++) {
            distance += (z >> i) & 1;
        }
        return distance;

    }

    public int hammingDistance2(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}
