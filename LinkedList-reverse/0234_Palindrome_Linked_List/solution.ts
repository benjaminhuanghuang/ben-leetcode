/*
234. Palindrome Linked List

https://leetcode.com/problems/palindrome-linked-list/
*/

import { ListNode } from "../Common/ListNode";

function isPalindrome(head: ListNode | null): boolean {
  if (head === null) return true;

  // get the length of the linked list. the length is used to find the middle of the linked list
  let length = 0;
  let start: ListNode | null = head;
  while (start !== null) {
    start = start.next;
    length++;
  }

  head = reverseBetween(head, Math.ceil(length / 2.0) + 1, length);

  let index = 1;
  let end: ListNode | null = head;
  while (index < Math.ceil(length / 2.0) + 1) {
    end = end!.next;
    index++;
  }

  start = head;
  while (end !== null) {
    if (start!.val !== end.val) {
      return false;
    }

    end = end.next;
    start = start!.next;
  }

  return true;
}

function reverseBetween(
  head: ListNode | null,
  startIndex: number,
  endIndex: number
): ListNode | null {
  const dummy = new ListNode(-1);
  dummy.next = head;

  let start: ListNode | null = dummy;
  let count = 1;
  while (count < startIndex) {
    start = start!.next;
    count++;
  }

  let next: ListNode | null = start!.next;
  while (count++ < endIndex) {
    const firstNode = next!.next;
    next!.next = firstNode!.next;
    firstNode!.next = start!.next;
    start!.next = firstNode;
  }

  return dummy.next;
}
