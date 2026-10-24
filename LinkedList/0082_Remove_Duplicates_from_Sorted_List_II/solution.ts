/*
82. Remove Duplicates from Sorted List II

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
*/

import { ListNode } from "../Common/ListNode";

function deleteDuplicates(head: ListNode | null): ListNode | null {
  if (head === null || head.next === null) {
    return head;
  }

  let dummy = new ListNode(-1);
  dummy.next = head;
  let prev = dummy;

  while (head !== null && head.next !== null) {
    if (head.val === head.next.val) {
      // find the last node of the duplicates
      let value = head.val;
      while (head !== null && head.val === value) {
        // remove the duplicates
        head = head.next;
      }
      prev.next = head;
    } else {
      head = head.next;
      prev = prev.next!;
    }
  }

  return dummy.next;
}
