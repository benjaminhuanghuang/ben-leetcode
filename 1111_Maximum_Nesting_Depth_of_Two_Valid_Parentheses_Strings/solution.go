/*
1111. Maximum Nesting Depth of Two Valid Parentheses Strings

Level: Medium

https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings
*/

package leetcode1111

/*

 */

func maxDepthAfterSplit(seq string) []int {
	max, count := 0, 0
	for i := 0; i < len(seq); i++ {
		if seq[i] == '(' {
			count++
			if count > max {
				max = count
			}
		} else {
			count--
		}
	}

	depth := max/2 + max%2
	ret := make([]int, len(seq))
	count = 0
	acount := 0
	for i := 0; i < len(seq); i++ {
		if seq[i] == '(' {
			count++
			if count <= depth {
				acount++
				ret[i] = 0
			} else {
				ret[i] = 1
			}
		} else {
			count--
			if acount > 0 {
				acount--
				ret[i] = 0
			} else {
				ret[i] = 1
			}
		}
	}
	return ret
}
