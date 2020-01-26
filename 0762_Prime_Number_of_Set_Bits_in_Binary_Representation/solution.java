package cn.huang.leetcode;
/*
762. Prime Number of Set Bits in Binary Representation
 */
public class LC_0762_PrimeNumberofSetBitsinBinaryRepresentation {
    public int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int n = L; n <= R; ++n)
            if (isPrime(bits(n))) ++ans;
        return ans;
    }

    private boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        for (int i = 2; i <= (int)Math.sqrt(n); ++i)
            if (n % i == 0) return false;
        return true;
    }

    private int bits(int n) {
        int s = 0;
        while (n != 0) {
            s += n & 1;
            n >>= 1;
        }
        return s;
    }
}
