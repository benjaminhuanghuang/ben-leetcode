/*
24. Swap Nodes in Pairs

https://leetcode.com/problems/swap-nodes-in-pairs/
*/

import { ListNode } from "../Common/ListNode";

function swapPairs(head: ListNode | null): ListNode | null {
  if (!head || !head.next) {
    return head;
  }

  let dummy = new ListNode(-1);
  dummy.next = head;
  head = dummy;

  // head -> n1 -> n2
  while (head && head.next && head.next.next) {
    let n1: ListNode | null = head.next;
    let n2: ListNode | null = n1.next;

    n1.next = n2!.next;
    n2!.next = n1;
    head.next = n2;

    head = n1;
  }

  return dummy.next;
}
