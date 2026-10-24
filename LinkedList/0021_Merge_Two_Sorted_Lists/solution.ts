/*
21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/description/
*/

import { ListNode } from "../Common/ListNode";

function mergeTwoLists(
  list1: ListNode | null,
  list2: ListNode | null
): ListNode | null {
  let dummy = new ListNode();
  let l = dummy;

  while (list1 && list2) {
    if (list1.val < list2.val) {
      l.next = list1;
      list1 = list1.next;
    } else {
      l.next = list2;
      list2 = list2.next;
    }
    l = l.next;
  }

  l.next = list1 || list2;

  return dummy.next;
}
