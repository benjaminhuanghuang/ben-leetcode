package cn.huang.leetcode;

/*
    172. Factorial Trailing Zeroes
 */
public class LC_0172_FactorialTrailingZeroes {
    /*
        也就是要找乘数中10的个数，而10可分解为2和5，而我们可知2的数量又远大于5的数量，那么此题即便为找出5的个数。
        仍需注意的一点就是，像25,125，这样的不只含有一个5的数字需要考虑进去。
     */
    public int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
}
