function minCoinCombinationTopDown(coins: number[], target: number): number {
  const res = topDownDp(coins, target, {});
  return res === Infinity ? -1 : res;
}

function topDownDp(
  coins: number[],
  target: number,
  memo: Record<number, number>
): number {
  // Base case: no coins needed to make 0
  if (target === 0) {
    return 0;
  }

  // Return memoized result if exists
  if (memo[target] !== undefined) {
    return memo[target];
  }

  let minCoins = Infinity;

  for (const coin of coins) {
    if (coin <= target) {
      const subResult = topDownDp(coins, target - coin, memo);
      if (subResult !== Infinity) {
        minCoins = Math.min(minCoins, 1 + subResult);
      }
    }
  }

  memo[target] = minCoins;
  return memo[target];
}
/*

Time complexity:
• Without memoization, the time complexity of min_coin_combination_top_down would be
O(n^target/m), where n denotes the number of coins, and m denotes the smallest coin value. The
recursion tree has a branch factor of n because we make a recursive call for up to n coins. The
depth of the tree is target/m because in the worst case, we continually reduce the target
value by the smallest coin.
• With memoization, each subproblem is solved only once. Since there are at most target
subproblems, and we iterate through all n coins for each subproblem, the time complexity is
O(target • n).

space complexity: The space complexity is O(target) because, while the maximum depth of the
recursive call stack is only target/m, the memoization array stores up to target key-value pairs.
*/
