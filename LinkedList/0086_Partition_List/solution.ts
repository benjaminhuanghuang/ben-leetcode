/*
86. Partition List
https://leetcode.com/problems/partition-list/
*/

import { ListNode } from "../Common/ListNode";

function partition(head: ListNode | null, x: number): ListNode | null {
  let headSmall = new ListNode(0);
  let headLarge = new ListNode(0);

  let pSmall = headSmall;
  let pLarge = headLarge;
  let curr = head;

  while (curr !== null) {
    if (curr.val < x) {
      pSmall.next = curr;
      pSmall = pSmall.next;
    } else {
      pLarge.next = curr;
      pLarge = pLarge.next;
    }
    curr = curr.next;
  }
  pLarge.next = null;
  pSmall.next = headLarge.next;
  return headSmall.next;
}
