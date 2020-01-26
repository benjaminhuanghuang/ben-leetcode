/*
313. Super Ugly Number

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list 
primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the 
first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/
using System;
using System.Collections.Generic;

public class Solution313 {
    //super ugly number定义为：整数，且因子全部都在primes中。 注意1为特殊的super ugly number。
    // http://www.cnblogs.com/grandyang/p/5144918.html
    // http://www.cnblogs.com/Liok3187/p/5016076.html
    public int NthSuperUglyNumber(int n, int[] primes) {
        List<int> res = new List<int>();
        res.Add(1);

        int[] idx = new int[primes.Length];
        while (res.Count < n) 
        {
            List<int> tmp = new List<int>();
            int mn = int.MaxValue;
            for (int i = 0; i < primes.Length; ++i) {
                tmp.Add(res[idx[i]] * primes[i]);
            }
            for (int i = 0; i < primes.Length; ++i) {
                mn = Math.Min(mn, tmp[i]);
            }
            for (int i = 0; i < primes.Length; ++i) {
                if (mn == tmp[i]) 
                    ++idx[i];
            }
            res.Add(mn);
        }
        return res[res.Count - 1];
    }
}