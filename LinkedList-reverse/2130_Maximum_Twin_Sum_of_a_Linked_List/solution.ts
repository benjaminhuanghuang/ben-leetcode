/*
2130. Maximum Twin Sum of a Linked List

https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
*/

import { ListNode } from "../Common/ListNode";

function pairSum(head: ListNode | null): number {
  let slow: ListNode | null = head;
  let fast: ListNode | null = head;

  // Move the fast pointer two nodes at a time and the slow pointer one node at a time. The loop ends when fast reaches the end of the list.
  while (fast && fast.next) {
    fast = fast.next.next;
    slow = slow!.next;
  }

  // Reverse the second half of the linked list, starting from the slow pointer.
  let prev: ListNode | null = null;
  while (slow) {
    const next: ListNode | null = slow.next;
    slow.next = prev;
    prev = slow;
    slow = next;
  }

  // The 'prev' pointer now points to the head of the reversed second half of the list. 'head' points to the beginning of the first half.

  let maxSum: number = 0;
  let left: ListNode | null = head;
  let right: ListNode | null = prev;

  while (left && right) {
    maxSum = Math.max(maxSum, left.val + right.val);
    left = left.next;
    right = right.next;
  }

  return maxSum;
}
