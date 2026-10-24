/*
25. Reverse Nodes in k-Group

https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

import { ListNode } from "../Common/ListNode";

function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
  if (head === null || k === 1) {
    return head;
  }

  let dummyHead = new ListNode(0);
  dummyHead.next = head;
  let start: ListNode | null = dummyHead;

  while (start!.next !== null) {
    let end: ListNode | null = start;

    for (let i = 0; i < k - 1; i++) {
      end = end!.next;
      if (end!.next === null) {
        // If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
        return dummyHead.next;
      }
    }

    let endBuckup: ListNode | null = end!.next;
    let startBuckup: ListNode | null = start!.next;
    reverseBetween(start!.next, end!.next);
    start.next = endBuckup;
    start = startBuckup;
  }

  return dummyHead.next;
}

function reverseBetween(start: ListNode | null, end: ListNode | null) {
  var newHead = new ListNode(0);
  newHead.next = start;
  while (newHead.next != end) {
    var temp = start!.next;
    start!.next = temp!.next;
    temp!.next = newHead.next;
    newHead.next = temp;
  }
}

/*
 Solution: Two passes.

    First pass, get the length of the list.
    Second pass, swap in groups.

    Time complexity: O(n)
    Space complexity: O(1)
*/
function reverseKGroup_2pass(
  head: ListNode | null,
  k: number
): ListNode | null {
  if (!head || k === 1) {
    return head;
  }

  let dummy = new ListNode(0);
  dummy.next = head;

  // get length
  let len = 1;
  let curr = head;
  while (curr.next) {
    curr = curr.next;
    len++;
  }

  // reverse
  let pre: ListNode | null = dummy;
  for (let start = 0; start + k <= len; start += k) {
    curr = pre.next!;
    let next = curr!.next;
    for (let i = 1; i < k; ++i) {
      curr!.next = next!.next;
      next!.next = pre!.next;
      pre!.next = next;
      next = curr!.next;
    }
    pre = curr;
  }

  return dummy.next;
}
