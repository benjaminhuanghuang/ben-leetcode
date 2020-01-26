package cn.huang.leetcode;

/*
483. Smallest Good Base


For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.

Now given a string representing n, you should return the smallest good base of n in string format.

Example 1:

Input: "13"
Output: "3"
Explanation: 13 base 3 is 111.

Example 2:

Input: "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.

Example 3:

Input: "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.

Note:

    The range of n is [3, 10^18].
    The string representing n is always valid and will not have leading zeros

 */
public class LC_0483_SmallestGoodBase {
    // n = k^m + k^(m-1) + ... + k + 1
// => n-1 = k (k^(m-1) + k^(m-2) + ... + k + 1) ...... [1]
// => n-k^m = k^(m-1) + k^(m-2) + ... + k + 1 ...... [2]
// (k^(m+1) - 1)/(k - 1) = n
// Thus ⌊m-th root of n⌋ is the only candidate that needs to be tested.
    public String smallestGoodBase(String n) {
        long num = Long.valueOf(n);

        for (int m = (int) (Math.log(num + 1) / Math.log(2)); m > 2; m--) {
            long l = (long) (Math.pow(num + 1, 1.0 / m));
            long r = (long) (Math.pow(num, 1.0 / (m - 1)));

            while (l <= r) {
                long k = l + ((r - l) >> 1);
                long f = 0L;
                for (int i = 0; i < m; i++, f = f * k + 1) ;

                if (num == f) {
                    return String.valueOf(k);
                } else if (num < f) {
                    r = k - 1;
                } else {
                    l = k + 1;
                }
            }
        }

        return String.valueOf(num - 1);
    }
}
