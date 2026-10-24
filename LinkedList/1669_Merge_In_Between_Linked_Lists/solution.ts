/*
1669. Merge In Between Linked Lists

https://leetcode.com/problems/merge-in-between-linked-lists/
*/

import { ListNode } from "../Common/ListNode";

function mergeInBetween(
  list1: ListNode | null,
  a: number,
  b: number,
  list2: ListNode | null
): ListNode | null {
  // `preMergeNode` will eventually point to the node just before 'a'.
  let preMergeNode = list1;
  // `postMergeNode` will eventually point to the node just after 'b'.
  let postMergeNode = list1;

  // Find the `(a-1)`th node, to connect list2 to its next.
  while (--a > 0) {
    preMergeNode = preMergeNode!.next;
  }

  // Find the `b`th node, which list2 will be connected before.
  while (b-- > 0) {
    postMergeNode = postMergeNode!.next;
  }

  // Connect list2 to the next of `preMergeNode`.
  preMergeNode!.next = list2;

  // Iterate to the last node of list2.
  while (preMergeNode!.next) {
    preMergeNode = preMergeNode!.next;
  }

  // Connect the last node of list2 to the node after `postMergeNode`.
  preMergeNode!.next = postMergeNode!.next;
  return list1;
}
