function climbingStairsBottomUp(n: number): number {
  if (n <= 2) {
    return n;
  }

  const dp: number[] = new Array(n + 1).fill(0);

  // Base cases
  dp[1] = 1;
  dp[2] = 2;

  // Build the dp table iteratively
  for (let i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

/*
Time complexity: The time complexity of climbing_stairs_bottom_up is O(n) as we Iterate
through n elements of the DP array.

Space complexity: The space complexity is O(n) due to the space taken up by the DP array, which
contains n + 1 elements.
*/
