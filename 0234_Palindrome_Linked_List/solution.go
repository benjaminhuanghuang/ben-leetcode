/*
234. Palindrome Linked List

Level: Easy

https://leetcode.com/problems/palindrome-linked-list
*/
package leetcode0234

import (
	. "../common"
)

/*

 */
 func isPalindrome(head *ListNode) bool {
	nums := make([]int, 0, 64)
	for head != nil {
		nums = append(nums, head.Val)
		head = head.Next
	}

	l, r := 0, len(nums)-1
	for l < r {
		if nums[l] != nums[r] {
			return false
		}
		l++
		r--
	}
	return true
}
/*
time O(n), space O(1)
*/
func isPalindromeBetter(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}

	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}

	secondHead := slow.Next
	secondHead = reverseList(secondHead)

	for head != nil && secondHead !=nil {
		if head.Val != secondHead.Val {
			return false
		}
		head = head.Next
		secondHead = secondHead.Next
	}

	return true
}

func reverseList(head *ListNode)*ListNode{
	if head == nil || head.Next == nil {
		return head
	}

	var prev *ListNode
	for head != nil {
		next:= head.Next
		head.Next = prev
		prev = head
		head = next
	}

	return prev
}