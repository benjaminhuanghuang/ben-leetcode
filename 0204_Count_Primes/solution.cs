/*
204. Count Primes

Description:

Count the number of prime numbers less than a non-negative number, n.
*/
using System;
using System.Linq;

public class Solution204
{
    // https://miafish.wordpress.com/2015/08/05/leetcode-ojc-count-primes/
    public int CountPrimes(int n)
    {
        var isNotPrime = new bool[n];

        for (var i = 2; i < n; i++)
        {
            // loop though 2 to n – 1, for each 1, times 2, 3..n would not be prime. 
            if (isNotPrime[i]) continue;
            var start = i + i;
            while (start < n)
            {
                isNotPrime[start] = true;
                start += i;
            }
        }
        // remove 0 and 1
        return isNotPrime.Skip(2).Count(x => x == false);
    }

    public int CountPrimes_Easy(int n)
    {
        int count = 0;
        for (int i = 2; i < n; n++)
        {
            if (this.IsPrime(i))
                count++;
        }
        return count;
    }

    private bool IsPrime(int n)
    {
        if (n == 1) return false;
        if (n == 2) return true;

        var boundary = (int)Math.Sqrt(n);

        for (int i = 2; i <= boundary; ++i)
        {
            if (n % i == 0) return false;
        }

        return true;
    }

}