using System;
using System.Collections.Generic;

public class Solution539
{
    public int FindMinDifference(IList<string> timePoints)
    {
        if (timePoints == null || timePoints.Count < 2)
            return 0;

        int[] minutes = new int[timePoints.Count];
        for(int i =0 ;i < timePoints.Count; i++)
        {
            minutes[i] = int.Parse(timePoints[i].Split(':')[0]) * 60 + int.Parse(timePoints[i].Split(':')[1]);
        }
        int minDiff = Int32.MaxValue;
        Array.Sort(minutes);
        for(int i =1 ;i < timePoints.Count; i++)
        {
            int diff = minutes[i] - minutes[i-1];
            if (diff < minDiff)
                minDiff = diff;
        }

        return Math.Min(minDiff, minutes[0]+24*60 - minutes[timePoints.Count-1]);
    }
}