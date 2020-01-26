// https://leetcode.com/problems/decompress-run-length-encoded-list
package leetcode1313

/*

 */
func decompressRLElist(nums []int) []int {
	answer := make([]int, 0)
	for i := 0; i < len(nums); i += 2 {
		for j := 0; j < nums[i]; j++ {
			answer = append(answer, nums[i+1])
		}
	}
	return answer
}

func decompressRLElistMy(nums []int) []int {
	var res []int

	for i := 0; i < len(nums); i += 2 {
		len := nums[i]
		n := nums[i+1]

		for len > 0 {
			res = append(res, n)
			len--
		}
	}
	return res
}
