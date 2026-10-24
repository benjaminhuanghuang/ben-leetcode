/*
http://www.cnblogs.com/grandyang/p/5888439.html
维护一个变量res，表示青蛙能跳到的最远的石头，这样最后我们看res是否到达最后一块石头就知道青蛙是否能过河了。
然后我们需要两个变量start和jump分别用来表示当前的石头位置和此时青蛙的弹跳力，我们遍历余下的所有石头，对于遍历到的石头，
我们计算到当前石头的距离dist，如果遍历到第二个石头，而距离不是1的话，则返回false，
*/

using System;

public class Solution403 {
    public bool CanCross(int[] stones) {
        int res = 0;
        helper(stones, 0, 1, ref res);
        return res == stones.Length - 1;
    }

    private void helper(int[] stones, int start, int jump, ref int res) {
        int n = stones.Length;
        if (res >= n - 1 || start >= n - 1) 
            return;
        for (int i = start + 1; i < n; ++i) 
        {
            int dist = stones[i] - stones[start];
            if (i == 1 && dist != 1) 
                return;
            if (jump == dist + 1 || jump == dist || jump == dist - 1) 
            {
                res = Math.Max(res, i);
                helper(stones, i, dist, ref res);
            } 
            else 
                break;
        }
    }
}


/*
[0,1,3,6,10,13,15,18]


*/