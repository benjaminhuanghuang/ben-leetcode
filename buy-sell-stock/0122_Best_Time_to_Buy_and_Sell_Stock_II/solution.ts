/*
122. Best Time to Buy and Sell Stock II

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

can complete as many transactions as you like 
*/

/*

*/
function maxProfit(prices: number[]): number {
  let maxProfit = 0;

  for (let i = 1; i < prices.length; i++) {
    if (prices[i] > prices[i - 1]) maxProfit += prices[i] - prices[i - 1];
  }
  return maxProfit;
}

export {};
