// https://leetcode.com/problems/find-numbers-with-even-number-of-digits
package leetcode1295

/*

 */

func findNumbers(nums []int) int {
	ans := 0
	for _, n := range nums {
		digits := getDigits(n)
		if digits%2 == 0 {
			ans++
		}
	}
	return ans
}

func getDigits(n int) int {
	digits := 0
	for n > 0 {
		n = n / 10
		digits++
	}
	return digits
}
