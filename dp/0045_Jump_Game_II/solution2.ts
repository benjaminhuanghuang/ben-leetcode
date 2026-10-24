/*
45. Jump Game II

https://leetcode.com/problems/jump-game-ii/
*/

/*
The differnec between this problem and leetcode_55_jump-game.ts is that 
this problem asks for the minimum number of jumps to reach the last index.
*/

/*
HuaHua Solution: Greedy

Jump as far as possible but lazily.

[2, 3, 1, 1, 4]
i    nums[i]   steps   near   far
-      -         0       0     0
0      2         0       0     2
1      3         1       2     4
2      1         1       2     4
3      1         2       4     4
4      4         2       4     8

Time complexity: O(n)
Space complexity: O(1)
*/
function jump(nums: number[]): number {
  let steps = 0;
  let currReach = 0; // 当前能跳到的最远距离
  let lastReach = 0; // 上次最远可以跳到的距离
  for (let i = 0; i < nums.length; i++) {
    if (lastReach < i) {
      //lastReach < i , 说明跳上一次不到i，需要last++
      steps++;
      lastReach = currReach;
    }
    //
    currReach = Math.max(nums[i] + i, currReach);
  }
  return steps;
}

export {};
