package cn.huang.leetcode;

import java.util.Arrays;

/*
757. Set Intersection Size At Least Two

 An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A
has size at least 2.

Example 1:

Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
Output: 3
Explanation:
Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.

Example 2:

Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
Output: 5
Explanation:
An example of a minimum sized set is {1, 2, 3, 4, 5}.

Note:

    intervals will have length in range [1, 3000].
    intervals[i] will have length 2, representing some integer interval.
    intervals[i][j] will be an integer in [0, 10^8].

 */
/*
一个集合S，使得S和每个区间的交集至少为2，即至少有两个相同的数字。
比如如果区间是[1,3], [5,6]的话，那么返回的集合长度是4，而不是5。
我们首先根据intervals的尾节点大小对intervals进行排序：尾节点越靠前的interval越排到前面。
 */
public class LC_0757_SetIntersectionSizeAtLeastTwo {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) ->
                a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);

        int[] todo = new int[intervals.length];
        Arrays.fill(todo, 2);
        int ans = 0, t = intervals.length;
        while (--t >= 0) {
            int s = intervals[t][0];
            int e = intervals[t][1];
            int m = todo[t];
            for (int p = s; p < s + m; ++p) {
                for (int i = 0; i <= t; ++i)
                    if (todo[i] > 0 && p <= intervals[i][1])
                        todo[i]--;
                ans++;
            }
        }
        return ans;
    }
}
