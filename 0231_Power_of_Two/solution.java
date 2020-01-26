package cn.huang.leetcode;
/*
    231. Power of Two
 */
public class LC_0231_PowerofTwo {
    //2的次方数都只有一个1，剩下的都是0
    public boolean isPowerOfTwo(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count == 1;
    }

    public boolean isPowerOfTwo2(int n) {
        return n>0 && (n&n-1)==0;
    }
}
