// https://leetcode.com/problems/two-sum/
package leetcode0001

func twoSum(nums []int, target int) []int {
	valIndex := make(map[int]int, len(nums))

	for i, num := range nums {
		if j, ok := valIndex[target-num]; ok {
			return []int{j, i}
		}

		valIndex[num] = i
	}

	return []int{-1, -1}
}
