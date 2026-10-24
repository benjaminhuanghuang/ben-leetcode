import { ListNode } from "../../common/ListNode";

/*
Approach 1: Iterative 

prev  curr  next 
*/
function reverseList_Iteration(head: ListNode | null): ListNode | null {
  let prev = null;
  let curr = head;

  while (curr != null) {
    //1. next is the handle to the rest of the list
    const next = curr.next;
    //2. reverse the current node
    curr.next = prev;
    //2. step forward
    prev = curr;
    curr = next;
  }

  return prev;
}

/*
Approach: Recursive
Time complexity:  O(n) each node visited once.
Space complexity:  complexity: O(n) — recursion stack depth equals list length
*/
function reverseList(head: ListNode | null): ListNode | null {
  if (head == null || head.next == null) {
    return head;
  }

  const newHead = reverseList(head.next);
  // head.next is the tail of the reversed linked list,
  // connect the tail to head
  head.next.next = head;
  head.next = null;

  return newHead;
}
