/*
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

import { ListNode } from "../Common/ListNode";

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
  let dummy = new ListNode(0);
  dummy.next = head;

  let start = dummy;
  let end = dummy;
  let i = 0;

  while (i < n) {
    end = end.next!;
    n--;
  }
  while (end.next !== null) {
    start = start.next!;
    end = end.next!;
  }

  start.next = start.next!.next;
  return dummy.next;
}
