// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
package leetcode1317

import (
	"strconv"
	"strings"
)

/*

 */
func getNoZeroIntegers(n int) []int {
	for i := 1; i <= n/2; i++ {
		if hasZero(i) && hasZero(n-i) {
			return []int{i, n - i}
		}
	}
	return []int{}
}

func hasZero(x int) bool {
	if x == 0 {
		return true
	}
	for x > 0 {
		if x%10 == 0 {
			return true
		}
		x /= 10
	}
	return false
}

func hasZeroString(x int) bool {
	s := strconv.Itoa(x)
	return strings.Contains(s, "0")
}
