/*
448. Find All Numbers Disappeared in an Array

Level: Easy

https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
*/
package leetcode0448
/*
	Time complexity: O(n)
	Space complexity: O(1)

  数组中的数字均满足1 ≤ a[i] ≤ n，也就是说其中的元素和数组的位置索引存在某种关联性。
	如果数组中不缺少数字，那么每一个元素就会与数组的位置索引所一一对应，nums[i] = i + 1
	
  利用这种关系,遍历数组，若元素存在num[i]，则将其看作位置索引，那么就把num[i]-1位置上的元素变为num[i]。
  最终遍历数组, 没有变为负数的元素所在的位置索引值，就是我们没有见过的数字。
 */
func findDisappearedNumbers(nums []int) []int {
	for i := 0; i < len(nums); i++ {
		for nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}

	res := make([]int, 0, len(nums))
	// compare the nums[i] and i + 1
	for i, n := range nums {
		if n != i+1 {
			res = append(res, i+1)
		}
	}

	return res
}