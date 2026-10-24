/*
61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

https://leetcode.com/problems/rotate-list/
*/

import { ListNode } from "../Common/ListNode";

function rotateRight(head: ListNode | null, k: number): ListNode | null {
  if (head == null || k == 0) return head;
  let p = head;

  // get the length of the list
  let length = 1;
  while (p.next != null) {
    p = p.next;
    length++;
  }

  p.next = head; // make a cycle
  let step = length - (k % length);
  //new p.next points to head;
  for (let i = 0; i < step; i++) {
    p = p.next!;
  }
  head = p.next;
  p.next = null;
  return head;
}
