/*
403. Frog Jump

A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
*/

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