/*
141. Linked List Cycle

https://leetcode.com/problems/linked-list-cycle/
*/

import { ListNode } from "../Common/ListNode";

/*
    slow pointer moves 1 step, fast pointer moves 2 steps
    if there is a cycle, they will meet at some point
*/
function hasCycle(head: ListNode | null): boolean {
  if (head == null) return false;
  let slow = head;
  let fast = head;
  while (fast != null && fast.next != null) {
    slow = slow.next!;
    fast = fast.next.next!;
    if (slow == fast) return true;
  }
  return false;
}
