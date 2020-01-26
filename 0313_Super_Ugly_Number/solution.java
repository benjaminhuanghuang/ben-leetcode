package cn.huang.leetcode;
/*
313. Super Ugly Number

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12
             super ugly numbers given primes = [2,7,13,19] of size 4.

Note:

    1 is a super ugly number for any given primes.
    The given numbers in primes are in ascending order.
    0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
    The nth super ugly number is guaranteed to fit in a 32-bit signed integer.


 */

/*


给定因子Primes , 让你求第n个super ugly number。

super ugly number定义为：整数，且因子全部都在primes中。 注意1为特殊的super ugly number。

思路：和ugly number的思路差不多，都是保存给的几个素数在ugly序列中的位置，代表那个位置的ugly number乘以那个素数大于当前的数，这样每次就可以比较得到当前哪个相乘可以得到最小的ugly number.


 */
public class LC_0313_SuperUglyNumber {
    public int nthSuperUglyNumber(int n, int[] primes) {
        if (primes == null) {
            throw new NullPointerException();
        }
        if (n < 1 || primes.length == 0) {
            throw new IllegalArgumentException();
        }
        int[] list = new int[n]; // to store n super ugly numbers
        list[0] = 1;
        int primeCount = primes.length;
        int[] index = new int[primeCount];
        int[] candidates = new int[primeCount];

        for (int i = 1; i <= n - 1; ++i) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < primeCount; ++j) {
                candidates[j] = list[index[j]] * primes[j];
                if (min > candidates[j]) {
                    min = candidates[j];
                }
            }
            for (int j = 0; j < primeCount; ++j) {
                if (min == candidates[j]) {
                    ++index[j];
                }
            }
            list[i] = min;
        }
        return list[n - 1];
    }
}

