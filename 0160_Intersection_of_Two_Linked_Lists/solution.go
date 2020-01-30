/*
160. Intersection of Two Linked Lists

Level: Easy

https://leetcode.com/problems/intersection-of-two-linked-lists
*/
package leetcode0160

import (
	. "./common"
)

/*
	每一个链表走两遍，一个走完后指向另一个链表，保证走过的长度相同
 */

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	a, b := headA, headB
	hasLinkedToB, hasLinkedToA := false, false

	for a != nil && b != nil {
		if a == b {
			return b
		}
		a, b = a.Next, b.Next
		if a == nil && !hasLinkedToB {
			a = headB
			hasLinkedToB = true
		}
		if b == nil && !hasLinkedToA {
			b = headA
			hasLinkedToA = true
		}
	}
	return nil
}
