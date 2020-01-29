/*
121. Best Time to Buy and Sell Stock

Level: Easy

https://leetcode.com/problems/best-time-to-buy-and-sell-stock
*/
package leetcode0121

import (
	"math"
)

/*

 */

func maxProfit(prices []int) int {
	maxProfit := 0
	lowestPrice := math.MaxInt32

	for _, price := range prices {
		if price < lowestPrice {
			lowestPrice = price
		}
		profit := price - lowestPrice

		if profit > maxProfit {
			maxProfit = profit
		}
	}
	return maxProfit
}
