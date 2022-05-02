/*
141. Linked List Cycle

Level: Easy

https://leetcode.com/problems/linked-list-cycle
*/

/*
  Solution: 
*/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
 var hasCycle = function(head) {
  if (head == null)
    return false;
  let slow = head;
  let fast = head.next;

  while (fast && fast.next)
  {
    slow = slow.next;
    fast = fast.next.next;

    if (slow == fast)
      return true;
  }

  return false;
};

export { twoSum };