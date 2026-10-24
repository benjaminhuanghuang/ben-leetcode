/*
75. Sort Colors

Level: Medium

https://leetcode.com/problems/sort-colors
*/

package leetcode0075

/*

 */
func sortColors(nums []int) {
	i, j, k := 0, 0, len(nums)-1

	// for 循环中， nums[i:j] 中始终全是 1
	// 循环结束后，
	// nums[:i] 中全是 0
	// nums[j:] 中全是 2
	for j <= k {
		switch nums[j] {
		case 0:
			nums[i], nums[j] = nums[j], nums[i]
			i++
			j++
		case 1:
			j++
		case 2:
			nums[j], nums[k] = nums[k], nums[j]
			k--
		}
	}
}
