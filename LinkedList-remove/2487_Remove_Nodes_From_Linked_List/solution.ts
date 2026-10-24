/*
2487. Remove Nodes From Linked List

https://leetcode.com/problems/remove-nodes-from-linked-list/
*/

import { ListNode } from "../Common/ListNode";

function removeNodes(head: ListNode | null): ListNode | null {
  if (head == null) return null;

  head.next = removeNodes(head.next);
  return head.next != null && head.val < head.next.val ? head.next : head;
}
