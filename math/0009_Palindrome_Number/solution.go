// https://leetcode.com/problems/palindrome-number
package leetcode0009

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	reversed := 0
	tmp := x
	for tmp > 0 {
		digit := tmp % 10
		reversed = reversed*10 + digit
		tmp = tmp / 10
	}

	return reversed == x
}
