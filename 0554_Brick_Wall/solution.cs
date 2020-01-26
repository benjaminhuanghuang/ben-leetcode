/*
554. Brick Wall

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. 
The bricks have the same height but different width. You want to draw a vertical line from the 
top to the bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the 
width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need 
to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line 
will obviously cross no bricks.

Example:
Input: 
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
Explanation: 

Note:
The width sum of bricks in different rows are the same and won't exceed INT_MAX.
The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. 
Total number of bricks of the wall won't exceed 20,000.
 */

/*
一堵墙的砖块组成，每一层的宽度是一样的，数组中的每个数字代表砖块的宽度。题目要求我们找出垂直划线的情况
所穿越的最小砖块数，

对于墙的各层，如果一个完整的砖块以左（包含自己）长度相等，那么从此长度往下划线的时候就不会穿过此砖块，因此，
我们只需要记录同一个长度出现的次数，最终，如果以出现次数最多的长度往下划线，穿过的砖块数就越少。
 */

using System.Collections.Generic;
using System.Collections;
public class Solution554
{
    public int LeastBricks(IList<IList<int>> wall)
    {
        if (wall.Count == 0)
            return 0;
        Dictionary<int, int> map = new Dictionary<int, int>();
        int max = 0;
        foreach (List<int> list in wall)
        {
            int length = 0;
            for (int i = 0; i < list.Count - 1; i++)
            {
                length += list[i];
                int times;
                if (map.ContainsKey(length))
                {
                    times = map[length] + 1;
                }
                else
                {
                    times = 1;
                }
                map[length] = times;
                max = max < times ? times : max;
            }
        }
        return wall.Count - max;
    }
}