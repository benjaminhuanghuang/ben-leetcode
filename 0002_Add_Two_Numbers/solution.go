// https://leetcode.com/problems/add-two-numbers
package leetcode0002

import (
	. "../common"
)

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := ListNode{}
	p := &dummy
	carry := 0
	for l1 != nil || l2 != nil {
		sum := carry
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		p.Next = &ListNode{Val: sum % 10}
		carry = sum / 10
		p = p.Next
	}
	if carry > 0 {
		p.Next = &ListNode{Val: carry}
	}

	return dummy.Next
}
