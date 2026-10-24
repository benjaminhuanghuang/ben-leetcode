/*
283. Move Zeroes

Level: Easy

https://leetcode.com/problems/move-zeroes
*/
package leetcode0283
/*
	
 */

func moveZeroes(nums []int)  {
	curr, last := 0, 0
	
	for curr < len(nums){
		if nums[curr] != 0 {
			nums[last] = nums[curr]
			last++
		}	
		curr++
	}
	i := last
	for i< len(nums) {
		nums[i] = 0
		i++
	}
}
