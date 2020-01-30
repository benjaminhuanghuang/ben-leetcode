/*

53. Maximum Subarray

Level: Easy

https://leetcode.com/problems/maximum-subarray
*/

package leetcode0053

/*
	当前和为sum,如果sum >0,那么加上当前元素，否则sum=A[i] （即抛弃负数的sum，重新开始。因为负数的sum是累赘)
*/
func maxSubArray(nums []int) int {
	maxSoFar := nums[0]
	sum := 0
	for i := 0; i < len(nums); i++ {
		if sum > 0 {
			sum += nums[i]
		} else {
			sum = nums[i]
		}
		if sum > maxSoFar {
			maxSoFar = sum
		}
	}
	return maxSoFar
}
