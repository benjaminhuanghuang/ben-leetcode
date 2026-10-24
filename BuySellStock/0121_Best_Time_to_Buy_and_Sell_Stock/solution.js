/*
121. Best Time to Buy and Sell Stock

Level: Easy

https://leetcode.com/problems/best-time-to-buy-and-sell-stock
*/

/*
  Solution: 
*/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let max_profit = 0;
    let lowest_price = Number.MAX_SAFE_INTEGER;

    for( let price of prices){
      if(price < lowest_price){
        lowest_price = price
      }
      let profit = price - lowest_price

      if (profit > max_profit){
        max_profit = profit
      }
    }
    return max_profit
};


export { maxProfit };