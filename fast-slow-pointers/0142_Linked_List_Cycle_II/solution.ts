/*
142. Linked List Cycle II

https://leetcode.com/problems/linked-list-cycle-ii/
*/

import { ListNode } from "../Common/ListNode";

/*
     https://www.jianshu.com/p/0420720ce32f

     当fast和slow在Z点首次相遇时：
     fast移动的距离是：a + b + c + b
     slow移动的距离是：a + b
     因为fast的移动速度是slow的两倍，所以：
     (a + b + c + b) == 2 * (a + b)
     由此可以推出：
     a == c
     我们需要用上面的推论来寻找环的起点（Y）。
     当fast和slow首次相遇时，我们就到了Z点。
     由于a == c，也就是X到Y 与 Z到Y的距离相等。
     因此，如果我们让两个指针分别从起点（X）和相遇点（Z）出发，并且每次都移动一步，当它们相遇时，恰好就是环的起点Y。

   */

function detectCycle(head: ListNode | null): ListNode | null {
  if (!head || !head.next) {
    return null;
  }

  let fast: ListNode | null = head;
  let slow: ListNode | null = head;

  while (fast && fast.next) {
    fast = fast.next.next;
    slow = slow!.next;

    if (fast === slow) {
      fast = head;
      while (fast !== slow) {
        fast = fast!.next;
        slow = slow!.next;
      }
      return slow;
    }
  }
  return null;
}
