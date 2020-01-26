package cn.huang.leetcode;
/*
    371. Sum of Two Integers
 */
public class LC_0371_SumofTwoIntegers {
    public int getSum(int a, int b) {
        while (b != 0) {
            int c = a & b; //carry
            a ^= b; //add
            b = c << 1;
        }
        return a;
    }
}
