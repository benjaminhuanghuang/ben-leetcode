/*
322. Coin Change

https://leetcode.com/problems/coin-change/
*/

/*
huahua
https://www.youtube.com/watch?v=uUETHdijzkA

DFS + Pruning + Greedy
*/
function coinChange(coins: number[], amount: number): number {
  // Sort coins in descending order
  coins.sort((a, b) => b - a);
  let ans = Number.MAX_SAFE_INTEGER;

  function coinChangeHelper(
    coins: number[],
    startIndex: number,
    amount: number,
    count: number
  ) {
    if (amount === 0) {
      ans = Math.min(ans, count);
      return;
    }

    if (startIndex === coins.length) return;

    const coin = coins[startIndex];
    for (let k = Math.floor(amount / coin); k >= 0 && count + k < ans; k--) {
      coinChangeHelper(coins, startIndex + 1, amount - k * coin, count + k);
    }
  }
  return ans === Number.MAX_SAFE_INTEGER ? -1 : ans;
}

export {};
