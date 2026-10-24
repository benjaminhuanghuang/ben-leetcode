/*
309. Best Time to Buy and Sell Stock with Cooldown

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

/*
买之前必须卖掉
每次买卖一股
不限制总共的买卖次数
卖完后必须cooldown一天才能再次买入

  Solution: DP
  https://www.youtube.com/watch?v=oL6mRyTn56M
  
  hold[i] = max(hold[i-1], rest[i-1], prices[i])
  sold[i] = hold[i-1] + prices[i]
  rest[i] = max(rest[i-1], sold[i-1])
  
  Time complexity: O(n)

  Space complexity: O(1)
*/

function maxProfit(prices: number[]): number {
  let sold = 0;
  let rest = 0;
  let hold = Number.MIN_SAFE_INTEGER;

  for (const price of prices) {
    const prevSold = sold;
    sold = hold + price;
    hold = Math.max(hold, rest - price);
    rest = Math.max(rest, prevSold);
  }

  return Math.max(rest, sold);
}
