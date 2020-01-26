/*
391. Perfect Rectangle

Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a 
rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square 
is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
*/
using System;
using System.Collections.Generic;

public class Solution391 {
    //  - 最左下 最左上 最右下 最右上 的四个点只出现过一次,其他肯定是成对出现的(保证完全覆盖)
    //   - 上面四个点围成的面积,正好等于所有子矩形的面积之和(保证不重复)
    //http://blog.csdn.net/mebiuw/article/details/52354018
    //http://bookshadow.com/weblog/2016/08/28/leetcode-perfect-rectangle/ (python)
    public bool IsRectangleCover(int[,] rectangles) {
        long totalArea = 0;
        int bottom = int.MaxValue, left=int.MaxValue, right=int.MinValue, top = int.MinValue;
        HashSet<string> flags = new HashSet<string>();
        for (int i =0; i < rectangles.GetLength(0); i++)
        {
            left = Math.Min(left, rectangles[i,0]);
            bottom = Math.Min(bottom, rectangles[i,1]);
            right = Math.Max(right, rectangles[i,2]);
            top = Math.Max(top, rectangles[i,3]);
            
            totalArea += (rectangles[i,3]-rectangles[i,1])*(rectangles[i,2]-rectangles[i,0]);
            
            string pointLT = string.Format("{0} {1}",rectangles[i,0], rectangles[i,3]);
            string pointLB = string.Format("{0} {1}",rectangles[i,0], rectangles[i,1]);
            string pointRT = string.Format("{0} {1}",rectangles[i,2], rectangles[i,3]);
            string pointRB = string.Format("{0} {1}",rectangles[i,2], rectangles[i,1]);

            if (!flags.Contains(pointLT)) flags.Add(pointLT); else flags.Remove(pointLT);
            if (!flags.Contains(pointLB)) flags.Add(pointLB); else flags.Remove(pointLB);
            if (!flags.Contains(pointRT)) flags.Add(pointRT); else flags.Remove(pointRT);
            if (!flags.Contains(pointRB)) flags.Add(pointRB); else flags.Remove(pointRB);
        }
        
          string LT = string.Format("{0} {1}",left, top);
          string LB = string.Format("{0} {1}",left, bottom);
          string RT = string.Format("{0} {1}",right, top);
          string RB = string.Format("{0} {1}",right, bottom);


        if( flags.Count==4 && flags.Contains(LT) && flags.Contains(LB) && flags.Contains(RT) && flags.Contains(RB)){
            return totalArea == (right - left) * (top - bottom);
        }
        return false;   
    }

   
}


/*

var input = new int[,]{  
  {1,1,3,3},
  {3,1,4,2},
  {3,2,4,4},
  {1,3,2,4},
  {2,3,3,4}};

var input = new int[,]{
  {1,1,2,3},
  {1,3,2,4},
  {3,1,4,2},
  {3,2,4,4}
};

var s = new Solution391();
var result = s.IsRectangleCover(input);  

Console.WriteLine(result);
*/