/*
198. House Robber

Level: Easy

https://leetcode.com/problems/house-robber
*/
package leetcode0198

/*

 */
func rob(nums []int) int {
	// even 对于偶数位上的最大值的记录
	// odd 对于奇数位上的最大值的记录
	var even, odd int
	for i, num := range nums {
		if i%2 == 0 {
			even = max(even+num, odd)
		} else {
			odd = max(even, odd+num)
		}
	}

	return max(even, odd)
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
