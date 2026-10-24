/*
70. Climbing Stairs

https://leetcode.com/problems/climbing-stairs/

step i = step i - 1 + step i - 2
*/

/*
 */
function climbStairs(n: number): number {
  if (n <= 2) return n;
  let one_step_before = 2;
  let two_step_before = 1;
  let all_ways = 0;

  for (let i = 2; i < n; i++) {
    all_ways = one_step_before + two_step_before;
    two_step_before = one_step_before;
    one_step_before = all_ways;
  }

  return all_ways;
}
/*
 */
function climbStairs_2(n: number): number {
  if (n <= 2) {
    return n;
  }
  const dp: number[] = new Array(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[1] = 2; // 1 step + 1 step or  2 steps

  for (let i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2]; // 1 step + dp[i-1] or 2 steps + dp[i-2]
  return dp[n];
}
