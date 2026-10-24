package leetcode0169

import (
	"sort"
)

/*

 */
func majorityElement(nums []int) int {
	sort.Ints(nums)
	return nums[len(nums)/2]
}
