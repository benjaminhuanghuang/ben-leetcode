/*
237. Delete Node in a Linked List

Level: Easy

https://leetcode.com/problems/delete-node-in-a-linked-list
*/

package leetcode0237

import (
	. "../common"
)

/*

 */
func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}

func deleteNode2(node *ListNode) {
	*node = *node.Next
}
