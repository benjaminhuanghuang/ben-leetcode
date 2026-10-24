function knapsack(cap: number, weights: number[], values: number[]): number {
  const n = values.length;

  // Initialize DP table with 0s (size: (n+1) x (cap+1))
  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    new Array(cap + 1).fill(0)
  );

  // Populate the DP table bottom-up
  for (let i = n - 1; i >= 0; i--) {
    for (let c = 1; c <= cap; c++) {
      if (weights[i] <= c) {
        // Max of including or excluding the current item
        dp[i][c] = Math.max(
          values[i] + dp[i + 1][c - weights[i]],
          dp[i + 1][c]
        );
      } else {
        // Item doesn't fit → exclude it
        dp[i][c] = dp[i + 1][c];
      }
    }
  }

  return dp[0][cap];
}
/*
Time complexity: The time complexity of knapsack is O(n . cap) because each cell of the DP table
is populated once.
Space complexity: The space complexity is O(n • cap) because we maintain a DP table that stores
(n + 1) x (cap + 1) elements.
*/
