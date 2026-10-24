using System;
using System.Text;
using System.Collections.Generic;

public class Solution575
{
    //首先求出糖果种类，每人可获得糖果数为candies.Length / 2
    public int DistributeCandies(int[] candies) {
        if (candies == null || candies.Length == 0)
            return 0;
            
        var candySet = new HashSet<int>(candies);
        return Math.Min(candySet.Count, candies.Length / 2 );
    }
}
