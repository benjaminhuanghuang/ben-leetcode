/*
45. Jump Game II

https://leetcode.com/problems/jump-game-ii/
*/

/*
The differnec between this problem and leetcode_55_jump-game.ts is that 
this problem asks for the minimum number of jumps to reach the last index.
*/

/*
Hua Hua
https://zxi.mytechroad.com/blog/greedy/leetcode-45-jump-game-ii/

LeetCode DP终极学习计划！Day4 Jump Game I/II
https://www.youtube.com/watch?v=3mIc_mKP4yM

Solution: Greedy

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
  return 0;
}

export {};
