/*
441. Arranging Coins


*/
using System;

public class Solution441 {
    public int ArrangeCoins(int n) {
        int l =0;
        int r =n;
        while (l <= r)
        {
            long m = l + (r - l)/2;
            if(m * (m+1)/2 > n)
                r = (int)m -1;
            else
            {
                l = (int)m + 1;
            }
        }
        return r;
    }
    // x(x+1)/2 = n
    // x = sqrt(2 * n + 1/4) - 1/2
    public int ArrangeCoins_2(int n) {
         return (int)(Math.Sqrt(2 * (long)n + 0.25) - 0.5);
    }

}