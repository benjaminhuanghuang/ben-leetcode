// https://leetcode.com/problems/maximum-69-number
package leetcode1323

import (
	"strconv"
	"strings"
)

/*

 */
func maximum69Number(num int) int {
	s := strconv.Itoa(num)
	newStr := strings.Replace(s, "6", "9", 1)
	ans, err := strconv.Atoi(newStr)
	if err != nil {
		return num
	}
	return ans
}
