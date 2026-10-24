/*
188. Best Time to Buy and Sell Stock IV

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

/*
  Solution: 
  https://blog.csdn.net/u012614906/article/details/61206474

  利用买股票问题的第三个变式，可以构造两个dp数组。

  sell[i]表示第i次卖出后最大持有的金钱

  buy[i]表示第i次买入后最大持有的金钱

  卖出的钱由买入的钱加上当前股票卖出的钱，买入的钱由前一次卖出的钱减去当前买股票花去的，因此可以得到两个转移方程

      sell[j] = max(sell[j], buy[j] + prices[i]);
      buy[j] = max(buy[j], sell[j-1] - prices[i]);
  
*/
function maxProfit(k: number, prices: number[]): number {
  if (k > prices.length) {
    let res = 0;
    for (let i = 1; i < prices.length; i++) {
      if (prices[i] > prices[i - 1]) {
        res += prices[i] - prices[i - 1];
      }
    }
    return res;
  }

  const sell: number[] = new Array(k + 1).fill(0);
  const buy: number[] = new Array(k + 1).fill(Number.MIN_SAFE_INTEGER);

  for (let i = 0; i < prices.length; i++) {
    for (let j = k; j > 0; j--) {
      sell[j] = Math.max(sell[j], buy[j] + prices[i]);
      buy[j] = Math.max(buy[j], sell[j - 1] - prices[i]);
    }
  }

  return sell[k];
}

export {};
