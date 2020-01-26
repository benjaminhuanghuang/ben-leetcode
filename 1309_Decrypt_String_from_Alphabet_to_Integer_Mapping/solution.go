// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
package leetcode1309

import (
	"strconv"
)

/*

 */

func freqAlphabets(s string) string {
	res, i, n := "", 0, len(s)
	for i < n {
		if i+2 < n && s[i+2] == '#' {
			//'10#' to '26#' map to j to z
			num, _ := strconv.Atoi(s[i : i+2])
			res += string(num + 96)
			i += 3
		} else {
			num := s[i] - '0'
			res += string(num + 96)
			i += 1
		}
	}
	return res
}
