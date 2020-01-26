package cn.huang.leetcode;
/*
391. Perfect Rectangle

Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented
as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).

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

import java.util.HashSet;
import java.util.Set;

/*
给了一堆小矩形的坐标（左下角和右上角围成的），问其能否组合成一个完美的矩形（刚刚好，不多，不少，不交叉）。

核心思想就是:能够正好围成一个矩形的情况就是:
有且只有:

    最左下/最左上/最右下/最右上的四个点只出现过一次,其他肯定是出现两次和四次(保证完全覆盖)
    上面四个点围成的面积,正好等于所有子矩形的面积之和(保证不重复)

判断依据就是一个完美的正方形的4个顶点出现1次，其余的点都是出现偶数次，只需要做一个遍历即可完成，最后使用面积判断即可，
 */
public class LC_0391_PerfectRectangle {
    public boolean isRectangleCover(int[][] rectangles) {
        if(rectangles.length == 0 || rectangles[0].length == 0)
            return false;
        int x1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE;
        int y1 = Integer.MAX_VALUE;
        int y2 = Integer.MIN_VALUE;

        Set<String> set = new HashSet<>();
        int area = 0;
        for(int[] rect: rectangles){
            x1 = Math.min(rect[0],x1);
            y1 = Math.min(rect[1], y1);
            x2 = Math.max(rect[2], x2);
            y2 = Math.max(rect[3], y2);

            area += (rect[2] - rect[0])*(rect[3] - rect[1]);
            // the four corner node
            String s1 = rect[0]+" "+rect[1];
            String s2 = rect[0]+" "+rect[3];
            String s3 = rect[2]+" "+rect[3];
            String s4 = rect[2]+" "+rect[1];
            if(!set.add(s1)) set.remove(s1);//already have, then remove
            if(!set.add(s2)) set.remove(s2);
            if(!set.add(s3)) set.remove(s3);
            if(!set.add(s4)) set.remove(s4);
        }

        if(!set.contains(x1+" "+y1) || !set.contains(x1+" "+y2) || !set.contains(x2+" "+y1) || !set.contains(x2+" "+y2) || set.size()!=4)
            return false;

        return area == (x2 - x1) * (y2 - y1);
    }
}
