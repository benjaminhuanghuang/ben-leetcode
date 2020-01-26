package cn.huang.leetcode;
/*
338. Counting Bits

 */
public class LC_0338_CountingBits {
    // 一个数 * 2 就是把它的二进制全部左移一位，也就是说 1的个数是相等的。
    public int[] countBits(int num) {
        int[] res = new int[num+1];
        for(int i=1;i<=num;i++){
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
}
