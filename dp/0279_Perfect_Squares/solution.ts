/*
279. Perfect Squares

https://leetcode.com/problems/perfect-squares/
*/

/*
  Solution: 

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-279-perfect-squares/

  dp[i] 表示正整数i能少能由多个完全平方数组成，最差情况i可以由i个i组成
  dp[i] := ans
  dp[0] = 0
  dp[i] = min{dp[i – j * j] + 1} 1 <= j * j <= i

  dp[5] = min{
  dp[5 – 2 * 2] + 1 = dp[1] + 1 = (dp[1 – 1 * 1] + 1) + 1 = dp[0] + 1 + 1 = 2,
  dp[5 – 1 * 1] + 1 = dp[3] + 1 = (dp[3 – 1 * 1] + 1) + 1 = dp[1] + 2 = dp[1 – 1*1] + 1 + 2 = dp[0] + 3 = 3
  };

  dp[5] = 2

  Time complexity: O(n * sqrt(n))
  Space complexity: O(n)
*/

function numSquares(n: number): number {
  // the worst case, n 可以由 1 + 1 + 1... 组成
  const dp = new Array(n + 1).fill(n); // Initialize the array with the worst-case value
  dp[0] = 0;

  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j * j <= i; ++j) {
      // j is the perfect square before i
      dp[i] = Math.min(dp[i], dp[i - j * j] + 1); // +1 because i is split into i-j*j and j*j, where j*j is a perfect square
    }
  }

  return dp[n];
}
