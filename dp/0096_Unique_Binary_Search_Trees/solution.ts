/*
96. Unique Binary Search Trees

https://leetcode.com/problems/unique-binary-search-trees/

95. Unique Binary Search Trees II
*/

/*
Solution: DP
    https://www.youtube.com/watch?v=HWJEMKWzy-Q

    1 to n , every number x can be the root of the tree
    left sub tree can have (0 to n - 1) nodes, right sub tree can have n - 1 to 0 nodes
    so, dp[n] = dp[0] * dp[n - 1] + dp[1] * dp[n - 2] + ... + dp[n - 1] * dp[0]
*/
function numTrees(n: number): number {
  const dp: number[] = new Array(n + 1).fill(0);
  dp[0] = 1; // array is [], there is 1 solution
  dp[1] = 1; // array has 1 element

  for (let i = 2; i <= n; i++) {
    // total nodes
    for (let j = 0; j < i; j++) {
      // j =  node of left sub tree
      // i - j - 1 is the nodes of right sub tree
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }

  return dp[n];
}
