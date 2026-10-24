using System;
using System.Collections.Generic;

public class Solution594
{
    public int FindLHS(int[] nums)
    {
        Dictionary<long, int> map = new Dictionary<long, int>();
        foreach (long num in nums)
        {
            if (!map.ContainsKey(num))
            {
                map[num] = 0;
            }

            map[num]++;
        }
        int result = 0;
        foreach (long key in map.Keys)
        {
            if (map.ContainsKey(key + 1))
            {
                result = Math.Max(result, map[key + 1] + map[key]);
            }
        }
        return result;
    }
}