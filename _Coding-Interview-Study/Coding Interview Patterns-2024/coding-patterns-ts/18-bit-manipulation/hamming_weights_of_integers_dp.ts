/*


*/
function hamming_weights_of_integers_dp(n: number): number[] {
  // Base case: the number of set bits in 0 is just 0. We set dp[0] to
  // 0 by initializing the entire DP array to 0.
  const dp: number[] = new Array(n + 1).fill(0);

  for (let x = 1; x <= n; x++) {
    // 'dp[x]' is obtained using the result of 'dp[x >> 1]', plus
    // the LSB of 'x'.
    dp[x] = dp[x >> 1] + (x & 1);
  }

  return dp;
}
