/*
141. Linked List Cycle

Level: Easy

https://leetcode.com/problems/linked-list-cycle
*/

package leetcode0141

import (
	. "../common"
)
/*

 */

func hasCycle(head *ListNode) bool {
	if head == nil {
		return false
	}
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil && slow != fast {
		slow, fast = slow.Next, fast.Next.Next
	}
	return slow == fast
}
