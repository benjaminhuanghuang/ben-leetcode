function minCoinCombinationBottomUp(coins: number[], target: number): number {
  // Initialize DP array with Infinity
  const dp: number[] = new Array(target + 1).fill(Infinity);

  // Base case: 0 coins needed to make target = 0
  dp[0] = 0;

  // Build up the DP table
  for (let t = 1; t <= target; t++) {
    for (const coin of coins) {
      if (coin <= t) {
        dp[t] = Math.min(dp[t], 1 + dp[t - coin]);
      }
    }
  }

  return dp[target] === Infinity ? -1 : dp[target];
}

/*

Time complexity: The time complexity of min_coin_combination_bottom_up is O(target · n) because
we loop through all n coins for each value between 1 and target.

Space complexity: The space complexity is O(target) due to the space occupied by the DP array,
which is of size target + 1.
*/
