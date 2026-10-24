/*
143. Reorder List

https://leetcode.com/problems/reorder-list/
*/

import { ListNode } from "../Common/ListNode";

function reorderList(head: ListNode | null): void {
  if (!head || !head.next) {
    return;
  }

  // 1. 找中点 (slow/fast)
  let slow: ListNode | null = head;
  let fast: ListNode | null = head;
  while (fast.next !== null && fast.next.next !== null) {
    slow = slow!.next;
    fast = fast.next.next;
  }

  // 2. 反转后半部分
  let secondHead: ListNode | null = slow!.next;
  slow!.next = null; // 切断前半与后半的连接

  // reverse linked list
  let prev: ListNode | null = null;
  let curr: ListNode | null = secondHead;
  while (curr !== null) {
    const nextTemp = curr.next;
    curr.next = prev;
    prev = curr;
    curr = nextTemp;
  }

  // 3. 交替合并前半 (head) 与 后半 (prev)
  let first: ListNode | null = head;
  let second: ListNode | null = prev;
  while (second !== null) {
    const nextFirst: ListNode | null = first!.next;
    const nextSecond: ListNode | null = second.next;

    first!.next = second;
    second.next = nextFirst;

    first = nextFirst;
    second = nextSecond;
  }
}
