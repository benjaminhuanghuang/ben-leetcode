// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
package leetcode1290

import (
	. "../common"
)

/*

 */

func getDecimalValue(head *ListNode) int {
	ans := 0
	for head != nil {
		ans = ans*2 + head.Val
		head = head.Next
	}
	return ans
}
