function neighborhoodBurglary(houses: number[]): number {
  // Handle edge cases
  if (houses.length === 0) {
    return 0;
  }
  if (houses.length === 1) {
    return houses[0];
  }

  const dp: number[] = new Array(houses.length).fill(0);

  // Base cases
  dp[0] = houses[0];
  dp[1] = Math.max(houses[0], houses[1]);

  // Fill the rest of the DP table
  for (let i = 2; i < houses.length; i++) {
    // Either skip this house or rob it and add profit from two houses before
    dp[i] = Math.max(dp[i - 1], houses[i] + dp[i - 2]);
  }

  return dp[houses.length - 1];
}
/*
Time complexity: The time complexity of neighborhood_burglary is O(n), where n denotes the
number of houses. This is because each index of the DP array is populated at most once.

Space complexity: The space complexity is O(n) since we're maintaining a DP array that has n
elements.
*/
