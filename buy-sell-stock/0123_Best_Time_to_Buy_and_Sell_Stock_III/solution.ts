/*
123. Best Time to Buy and Sell Stock III

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Buy and sell stock at most 2 times
*/

/*

*/
function maxProfit(prices: number[], index: number): number {
  if (prices == null || prices.length <= 1) return 0;
  //local[j] tracks the maximum profit for the j-th transaction considering the current price difference.
  const local: number[] = new Array(3).fill(0);
  //global[j] tracks the maximum profit for the j-th transaction across all price differences seen so far.
  const global: number[] = new Array(3).fill(0);

  for (let i = 0; i < prices.length - 1; i++) {
    const diff = prices[i + 1] - prices[i];
    for (let j = 2; j >= 1; j--) {
      local[j] = Math.max(global[j - 1] + Math.max(diff, 0), local[j] + diff);
      global[j] = Math.max(global[j], local[j]);
    }
  }

  return global[2];
}

/*
Approach: DP

https://algo.monster/liteproblems/123
*/
