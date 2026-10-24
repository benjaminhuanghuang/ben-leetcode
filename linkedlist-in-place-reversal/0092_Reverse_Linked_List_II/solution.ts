/*
92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/

reverse the nodes of the list from position left to position right, and return the reversed list.
*/

import { ListNode } from "../Common/ListNode";

function reverseBetween(
  head: ListNode | null,
  left: number,
  right: number
): ListNode | null {
  if (!head || left === right) {
    return head;
  }

  const dummy = new ListNode(0);
  dummy.next = head;

  let prev = dummy;
  for (let i = 0; i < left - 1; i++) {
    prev = prev.next!;
  }
  // prev holds node before the left node

  let curr = prev.next;

  for (let i = 0; i < right - left; i++) {
    const next = curr!.next;
    curr!.next = next!.next;
    next!.next = prev.next;
    prev.next = next;
  }

  return dummy.next;
}
