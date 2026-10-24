import { ListNode } from "../../common/ListNode";

function removeNodes(head: ListNode | null): ListNode | null {
  if (head == null) return null;

  head.next = removeNodes(head.next);
  return head.next != null && head.val < head.next.val ? head.next : head;
}

/*
Approach: Iterative traversal, reverse the list twice (no recursion/stack).

Reversing first lets us walk left-to-right over what were originally the
nodes to the right. Track the max value seen so far; a node survives only
if its value >= that max (otherwise some node further right, already
visited, is bigger). Reverse back to restore the original order.

Time complexity: O(n)
Space complexity: O(1) extra
*/
function reverseList(head: ListNode | null): ListNode | null {
  let prev: ListNode | null = null;
  let curr = head;

  while (curr !== null) {
    const next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

function removeNodes_Traversal(head: ListNode | null): ListNode | null {
  const reversed = reverseList(head);
  if (reversed === null) return null;

  let max = reversed.val;
  let curr = reversed;

  while (curr.next !== null) {
    if (curr.next.val < max) {
      curr.next = curr.next.next;
    } else {
      max = curr.next.val;
      curr = curr.next;
    }
  }

  return reverseList(reversed);
}
