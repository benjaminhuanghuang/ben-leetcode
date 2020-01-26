package cn.huang.leetcode;

import java.util.*;

/*
403. Frog Jump

A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone.
The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the
river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog
can only jump in the forward direction.

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
public class LC_0403_FrogJump {
    public boolean canCross_TLE(int[] stones) {
        int k = 0;
        return helper(stones, 0, k);
    }

    private boolean helper(int[] stones, int index, int k) {
        if (index == stones.length - 1)
            return true;
        //选择k的步伐，范围k-1到k
        for (int i = k - 1; i <= k + 1; i++) {
            int nextJump = stones[index] + i;
            //看接下来有没有合适的石头可以跳过去，从接下来的位置中查找有没有nextJump的位置，有的话返回石头的编号
            int nextPosition = Arrays.binarySearch(stones, index + 1, stones.length, nextJump);
            if (nextPosition > 0) {
                if (helper(stones, nextPosition, i)) return true;
            }
        }
        return false;
    }

    public boolean canCross(int[] stones) {
        if (stones == null || stones.length < 2) return true;
        if (stones[0] != 0 || stones[1] != 1) return false;
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int stone : stones) {
            map.put(stone, new HashSet<>());
        }
        map.get(0).add(1);
        int len = stones.length;
        for (int stone : stones) {
            for (int step : map.get(stone)) {
                if (stone + step == stones[len - 1]) return true;
                Set<Integer> nextSet = map.get(stone + step);
                if (nextSet != null) {
                    if (step - 1 > 0) nextSet.add(step - 1);
                    nextSet.add(step);
                    nextSet.add(step + 1);
                }
            }
        }
        return false;
    }


}