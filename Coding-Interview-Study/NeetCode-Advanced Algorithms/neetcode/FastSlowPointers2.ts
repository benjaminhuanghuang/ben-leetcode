/*
Q: Determine if a linked list has a cycle 
*/

// Determine if the linked list contains a cycle.
// Time: O(n), Space: O(1)
function hasCycle(head: ListNode | null): boolean {
  let slow = head;
  let fast = head;

  while (fast !== null && fast.next !== null) {
    slow = slow!.next;
    fast = fast.next.next;
    // 如果链表有环，快慢指针最终会在环内相遇。
    if (slow === fast) {
      return true;
    }
  }

  return false;
}
