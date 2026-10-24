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