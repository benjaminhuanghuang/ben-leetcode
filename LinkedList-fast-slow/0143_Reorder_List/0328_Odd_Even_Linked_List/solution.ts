/*
328. Odd Even Linked List

https://leetcode.com/problems/odd-even-linked-list/
*/

import { ListNode } from "../Common/ListNode";

function oddEvenList(head: ListNode | null): ListNode | null {
  if (!head) {
    return null;
  }

  let slow: ListNode = head; // Points to the last node in the odd list.
  let fast: ListNode | null = head.next; // Points to the first node in the even list.
  let evenHead: ListNode | null = head.next; // Keeps track of the head of the even list.

  while (fast && fast.next) {
    slow.next = fast.next; // Link next odd node.
    slow = slow.next; // Move odd pointer to the next node.
    fast.next = slow.next; // Link next even node.
    fast = fast.next; // Move even pointer to the next node.
  }

  slow.next = evenHead;

  return head;
}
