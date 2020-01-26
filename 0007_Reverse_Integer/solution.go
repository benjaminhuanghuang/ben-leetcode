// https://leetcode.com/problems/reverse-integer
package leetcode0007

import (
	"math"
	"strconv"
)

func reverse(x int) int {
	isNagitive := x < 0

	if isNagitive {
		x = -x
	}

	res := 0
	for x > 0 {
		digit := x % 10
		res = res*10 + digit
		x = x / 10
	}
	if isNagitive {
		res = -res
	}

	if res > math.MaxInt32 || res < math.MinInt32 {
		res = 0
	}

	return res
}

func reverseByString(x int) int {
	isNagitive := x < 0

	if isNagitive {
		x = -x
	}

	s := strconv.Itoa(x)
	val, err := strconv.Atoi(reverseString(s))
	if err != nil {
		return x
	}
	if isNagitive {
		val = -val
	}
	if val > math.MaxInt32 || val < math.MinInt32 {
		val = 0
	}
	return val
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
