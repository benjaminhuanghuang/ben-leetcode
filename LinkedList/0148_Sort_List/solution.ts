/*
148. Sort List

https://leetcode.com/problems/sort-list/
*/

import { ListNode } from "../Common/ListNode";

function sortList(head: ListNode | null): ListNode | null {
  if (!head || !head.next) {
    return head;
  }

  let slow = head;
  let fast = head;
  let prev = null;
  // Split the list into two halves
  while (fast && fast.next) {
    prev = slow;
    slow = slow.next!;
    fast = fast.next.next!;
  }

  prev!.next = null; // Break the list into two halves

  const left = sortList(head);
  const right = sortList(slow);

  return merge(left, right);
}

function merge(left: ListNode | null, right: ListNode | null): ListNode | null {
  const dummy = new ListNode();
  let curr = dummy;

  while (left && right) {
    if (left.val < right.val) {
      curr.next = left;
      left = left.next;
    } else {
      curr.next = right;
      right = right.next;
    }
    curr = curr.next!;
  }

  if (left) {
    curr.next = left;
  }

  if (right) {
    curr.next = right;
  }

  return dummy.next;
}
