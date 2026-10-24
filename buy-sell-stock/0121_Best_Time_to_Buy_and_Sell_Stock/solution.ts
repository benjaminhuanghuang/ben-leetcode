/*
121. Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

[Amazon]
*/

/*
only permitted to complete at most one transaction 
max profit means to buy at the lowest price and sell at the highest price(after buying)

We can think the lowestPrice is the left pointer, and prices[i] is the right pointer.
*/
function maxProfit(prices: number[]): number {
  let maxProfit = 0;
  let lowestPrice = prices[0];

  for (let i = 1; i < prices.length; i++) {
    if (prices[i] < lowestPrice) {
      lowestPrice = prices[i]; // update the lowest price
    }

    maxProfit = Math.max(maxProfit, prices[i] - lowestPrice);
  }
  return maxProfit;
}

/*
hua hua
https://www.youtube.com/watch?v=8pVhUpF1INw

DP

*/

export {};
