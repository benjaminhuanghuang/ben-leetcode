/*
83. Remove Duplicates from Sorted List

https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

import { ListNode } from "../Common/ListNode";

function deleteDuplicates(head: ListNode | null): ListNode | null {
  let curr: ListNode | null = head;

  while (curr && curr.next) {
    if (curr.next.val === curr.val) {
      curr.next = curr.next.next;
    } else {
      curr = curr.next;
    }
  }

  return head;
}
