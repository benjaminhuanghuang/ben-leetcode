/*
452. Minimum Number of Arrows to Burst Balloons

There are a number of spherical balloons spread in two-dimensional space. For each balloon, 
provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal,
 y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. 
 Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with 
xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number 
of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to 
find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and 
another arrow at x = 11 (bursting the other two balloons).
*/
using System;
using System.Collections.Generic;

public class Solution452 {
     class Balloon{
        public int Start {get; set;}
        public int End {get; set;}
    }

    //http://massivealgorithms.blogspot.com/2016/11/lettcode-452-minimum-number-of-arrows.html
    //http://xiadong.info/2016/11/leetcode-452-minimum-number-of-arrows-to-burst-balloons/
    //基本思路是每次尽可能多的刺破气球, 所以一开始从最左边的气球的右边缘发射一支箭, 否则最左边的气球就无法刺破了, 这样也能保证刺破尽可能多的气球
    //但是问题在于如何判断哪个气球在"最左边", 不能以左边缘来进行判断, 因为有这种情况: (1,10),(2,5), 第一支箭应该从x=5发出而不是x=10, 所以排序时应该使用每个气球的End来进行排序.
    public int FindMinArrowShots(int[,] points) {
        if(points.GetLength(0) == 0)
            return 0;
       
        List<Balloon> balloons = new List<Balloon>(); 
        for (int i = 0; i < points.GetLength(0); i++)
        {
            balloons.Add(new Balloon(){Start = points[i,0], End = points[i,1]});
        }
        int ans = 1;
        //ballonws.Sort((x,y)=>{int result = x.Start.CompareTo(y.Start); return (result == 0) ? x.End.CompareTo(y.End) : result;});
        balloons.Sort((x,y)=>{return x.End.CompareTo(y.End);});
        int arrow = balloons[0].End;
        for (int i= 0; i < balloons.Count ; i++)
        {
            if(balloons[i].Start > arrow){
                ans++;
                arrow = balloons[i].End;
            }
        }
        return ans;
    }
}