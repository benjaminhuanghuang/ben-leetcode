/*
1823. Find the Winner of the Circular Game

https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

import { ListNode } from "../Common/ListNode";

function findTheWinner(n: number, k: number): number {
  // If k equals 1, the winner is the last person
  if (k === 1) {
    return n;
  }

  let dummy: ListNode = new ListNode(0);
  let current = dummy;

  // Construct the circular linked list.
  for (let i = 1; i <= n; i++) {
    current.next = new ListNode(i);
    current = current.next;
  }
  // Complete the circular list by linking the last node back to the first node.
  current.next = dummy.next; // NOT current.next = dummy

  // Start with the dummy node, which is right before the first node.
  current = dummy;
  let count = 0;

  // when this 1 node left, this node will point to itself.
  while (current.next !== current) {
    count++;
    // If the count reaches k, remove the kth node.
    if (count === k) {
      current.next = current.next!.next;
      count = 0; // Reset count after elimination.
    } else {
      // Move to the next node.
      current = current.next!;
    }
  }

  return current.val;
}
